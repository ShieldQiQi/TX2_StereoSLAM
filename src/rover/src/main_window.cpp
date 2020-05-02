/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date February 2011
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include "main_window.hpp"

#include <Eigen/Core>
#include <Eigen/Geometry>

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace rover {

using namespace Qt;
using namespace Eigen;

/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
	: QMainWindow(parent)
	, qnode(argc,argv)
{
	ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.
    QObject::connect(ui.actionAbout_Qt, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt())); // qApp is a global variable for the application

    ReadSettings();
	setWindowIcon(QIcon(":/images/icon.png"));
	ui.tab_manager->setCurrentIndex(0); // ensure the first tab is showing - qt-designer should have this already hardwired, but often loses it (settings?).
    QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));
    QObject::connect(&qnode, SIGNAL(slamStateChanged(char)), this, SLOT(changeStateIndicator(char)));
    QObject::connect(&qnode, SIGNAL(slamMapUpdated()), this, SLOT(updateMap()));
    QObject::connect(&qnode, SIGNAL(cloudUpdated()), this, SLOT(updateCloud()));
    QObject::connect(ui.customPlot,SIGNAL(mouseDoubleClick(QMouseEvent *)),this,SLOT(mouseDcEvent(QMouseEvent *)));

    QObject::connect(ui.commandLinkButton_1,SIGNAL(clicked()),this,SLOT(on_commandLinkButton_1_clicked()));
    QObject::connect(ui.commandLinkButton_2,SIGNAL(clicked()),this,SLOT(on_commandLinkButton_2_clicked()));
    QObject::connect(ui.commandLinkButton_3,SIGNAL(clicked()),this,SLOT(on_commandLinkButton_3_clicked()));
//    QObject::connect(ui.commandLinkButton_4,SIGNAL(clicked()),this,SLOT(on_commandLinkButton_4_clicked()));
    QObject::connect(ui.commandLinkButton_5,SIGNAL(clicked()),this,SLOT(on_commandLinkButton_5_clicked()));
    QObject::connect(ui.horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(on_horizontalSlider_valueChanged(int)));

	/*********************
	** Logging
	**********************/
    ui.view_logging_2->setModel(qnode.loggingModel());
    QObject::connect(&qnode, SIGNAL(loggingUpdated()), this, SLOT(updateLoggingView()));

    /*********************
    ** Auto Start
    **********************/
//    if ( ui.checkbox_remember_settings->isChecked() ) {
//    on_button_connect_clicked(true);
//    }

    // Init the Ros node
    if ( !qnode.init() ) {
        showNoMasterMessage();
    }

    // create graph and assign data to it:
    ui.customPlot->setInteraction(QCP::iRangeDrag, true);
    ui.customPlot->setInteraction(QCP::iRangeZoom, true);
    ui.customPlot->setInteraction(QCP::iSelectPlottables, true);
//    ui.customPlot->legend->setVisible(true);
//    ui.customPlot->legend->setBrush(QColor(255,255,255,0));

    ui.customPlot->addGraph();
    ui.customPlot->addGraph();
    ui.customPlot->addGraph();
    ui.customPlot->addGraph();
    ui.customPlot->addGraph();

    ui.customPlot->xAxis->setLabel("x");
    ui.customPlot->yAxis->setLabel("y");
}

MainWindow::~MainWindow() {}

/*****************************************************************************
** Implementation [Slots]
*****************************************************************************/

void MainWindow::showNoMasterMessage() {
	QMessageBox msgBox;
	msgBox.setText("Couldn't find the ros master.");
	msgBox.exec();
    close();
}

void MainWindow::on_commandLinkButton_1_clicked()
{
  // save map cmd
  qnode.cmdArray->data.at(0) = 1;
}
void MainWindow::on_commandLinkButton_2_clicked()
{
  // start map cmd
  qnode.cmdArray->data.at(1) = 1;
}
void MainWindow::on_commandLinkButton_3_clicked()
{
  // start map cmd
  qnode.cmdArray->data.at(1) = 0;
}
void MainWindow::on_commandLinkButton_4_clicked()
{
  // confirm goal
  if(QMessageBox::Yes == QMessageBox::question(this,"confirm it","are you sure to make this point a target?",QMessageBox::Yes | QMessageBox:: No))
  {
    qnode.cmdArray->data.at(2) = 1;
    // set goal x-y position
    qnode.cmdArray->data.at(4) = (int)(1000*goal_x);
    qnode.cmdArray->data.at(5) = (int)(1000*goal_y);
  }
  std::cout<<"/*/";
}
void MainWindow::on_commandLinkButton_5_clicked()
{
  // start to the goal
  qnode.cmdArray->data.at(2) = 2;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
  // change the cmd_vel
  qnode.cmdArray->data.at(3) = value;
}

void MainWindow::updateMap()
{
    QVector<double> x(qnode.cloudFused_xyz.width);
    QVector<double> y(qnode.cloudFused_xyz.width);
    for (int i=0; i<qnode.cloudFused_xyz.width; i++)
    {
      x[i] = qnode.cloudFused_xyz.at(i).x;
      y[i] = qnode.cloudFused_xyz.at(i).y;
    }
    ui.customPlot->graph(0)->setData(x, y);
    ui.customPlot->graph(0)->setPen(QPen(Qt::yellow));
    ui.customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui.customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssPlus, 2));

    QVector<double> x_pose(1), y_pose(1);
    x_pose[0] = qnode.carTF.pose.position.x;
    y_pose[0] = qnode.carTF.pose.position.y;
    ui.customPlot->graph(1)->setData(x_pose,y_pose);
    ui.customPlot->graph(1)->setPen(QPen(Qt::red));
    ui.customPlot->graph(1)->setLineStyle(QCPGraph::lsNone);
    ui.customPlot->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCrossCircle, 10));

    QVector<double> x_path(qnode.pathSolution->poses.size());
    QVector<double> y_path(qnode.pathSolution->poses.size());
    for (int i=0; i<qnode.pathSolution->poses.size(); i++)
    {
      x_path[i] = qnode.pathSolution->poses.at(i).pose.position.x;
      y_path[i] = qnode.pathSolution->poses.at(i).pose.position.y;
    }
    ui.customPlot->graph(4)->setData(x_path, y_path);
    ui.customPlot->graph(4)->setPen(QPen(Qt::black));
    ui.customPlot->graph(4)->setLineStyle(QCPGraph::lsNone);
    ui.customPlot->graph(4)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssPlus, 5));

    // set axes ranges, so we see all data:
//    ui.customPlot->xAxis->setRange(-1, 1);
//    ui.customPlot->yAxis->setRange(0, 1);
    ui.customPlot->replot();
}

void MainWindow::updateCloud()
{
  Quaterniond quaternion(qnode.carTFzed2.pose.orientation.w,
                         qnode.carTFzed2.pose.orientation.x,
                         qnode.carTFzed2.pose.orientation.y,
                         qnode.carTFzed2.pose.orientation.z);
  Matrix3d rotation_matrix;
  rotation_matrix=quaternion.toRotationMatrix();
  std::cout<<rotation_matrix<<std::endl;

  QVector<double> x(qnode.cloud_xyz.width), y(qnode.cloud_xyz.width); // initialize with entries 0..100
  for (int i=0; i<qnode.cloud_xyz.width; i++)
  {
    Vector3d position_(qnode.cloud_xyz.at(i).x,qnode.cloud_xyz.at(i).y,qnode.cloud_xyz.at(i).z);
    Vector3d position = rotation_matrix*position_;
    x[i] = position[0] + qnode.carTFzed2.pose.position.x;
    y[i] = position[1] + qnode.carTFzed2.pose.position.y;
  }

  ui.customPlot->graph(3)->setData(x, y);
  ui.customPlot->graph(3)->setPen(QPen(Qt::green));
  ui.customPlot->graph(3)->setLineStyle(QCPGraph::lsNone);
  ui.customPlot->graph(3)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssPlus, 2));

  ui.customPlot->replot();
}

void MainWindow::mouseDcEvent(QMouseEvent *event)
{
  double x = event->pos().x();
  double y = event->pos().y();
  goal_x = ui.customPlot->xAxis->pixelToCoord(x);
  goal_y = ui.customPlot->yAxis->pixelToCoord(y);

  QVector<double> x_pose(1), y_pose(1);
  x_pose[0] = goal_x;
  y_pose[0] = goal_y;
  ui.customPlot->graph(2)->setData(x_pose,y_pose);
  ui.customPlot->graph(2)->setPen(QPen(Qt::blue));
  ui.customPlot->graph(2)->setLineStyle(QCPGraph::lsNone);
  ui.customPlot->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCrossCircle, 10));

  ui.customPlot->replot();

//  QString *str = new QString;
//  *str = QString("X: Y:");
//  QToolTip::showText(cursor().pos(),*str);
}

void MainWindow::changeStateIndicator(char flag)
{
    std::cout << flag;
    switch(flag)
    {
    case 0:
      ui.label_2->setStyleSheet("image: url(:/images/sleep.png);");
      break;
    case 10:
      ui.label_2->setStyleSheet("image: url(:/images/run.png);");
      break;
    case 20:
      ui.label_2->setStyleSheet("image: url(:/images/stoping.png);");
      break;
    case 30:
      ui.label_2->setStyleSheet("image: url(:/images/stop.png);");
      break;
    }
}
/*
 * These triggers whenever the button is clicked, regardless of whether it
 * is already checked or not.
 */

//void MainWindow::on_button_connect_clicked(bool check ) {
//	if ( ui.checkbox_use_environment->isChecked() ) {
//  if ( !qnode.init() ) {
//      showNoMasterMessage();
//  } else {
//      ui.button_connect->setEnabled(false);
//  }
//	} else {
//		if ( ! qnode.init(ui.line_edit_master->text().toStdString(),
//				   ui.line_edit_host->text().toStdString()) ) {
//			showNoMasterMessage();
//		} else {
//			ui.button_connect->setEnabled(false);
//			ui.line_edit_master->setReadOnly(true);
//			ui.line_edit_host->setReadOnly(true);
//			ui.line_edit_topic->setReadOnly(true);
//		}
//	}
//}


//void MainWindow::on_checkbox_use_environment_stateChanged(int state) {
//	bool enabled;
//	if ( state == 0 ) {
//		enabled = true;
//	} else {
//		enabled = false;
//	}
//	ui.line_edit_master->setEnabled(enabled);
//	ui.line_edit_host->setEnabled(enabled);
//	ui.line_edit_topic->setEnabled(enabled);
//}

/*****************************************************************************
** Implemenation [Slots][manually connected]
*****************************************************************************/

/**
 * This function is signalled by the underlying model. When the model changes,
 * this will drop the cursor down to the last line in the QListview to ensure
 * the user can always see the latest log message.
 */
void MainWindow::updateLoggingView() {
        ui.view_logging_2->scrollToBottom();
}

/*****************************************************************************
** Implementation [Menu]
*****************************************************************************/

//void MainWindow::on_actionAbout_triggered() {
//    QMessageBox::about(this, tr("About ..."),
//                       tr("<h2>SLAM Robot Controller v1.0"
//                          "</h2><p>Copyright Hitwh_Qi</p><p>report bugs on <p>https://github.com/ShieldQiQi/TX2_StereoSLAM</p></p>"));
//}

void MainWindow::on_actionAbout_this_program_triggered() {
    QMessageBox::about(this, tr("About ..."),
                       tr("<h2>SLAM Robot Controller v1.0"
                          "</h2><p>Copyright Hitwh_Qi</p><p>report bugs on <p>https://github.com/ShieldQiQi/TX2_StereoSLAM</p></p>"));
}
/*****************************************************************************
** Implementation [Configuration]
*****************************************************************************/

void MainWindow::ReadSettings() {
//    QSettings settings("Qt-Ros Package", "rover");
//    restoreGeometry(settings.value("geometry").toByteArray());
//    restoreState(settings.value("windowState").toByteArray());
//    QString master_url = settings.value("master_url",QString("http://192.168.1.2:11311/")).toString();
//    QString host_url = settings.value("host_url", QString("192.168.1.3")).toString();
//    //QString topic_name = settings.value("topic_name", QString("/chatter")).toString();
//    ui.line_edit_master->setText(master_url);
//    ui.line_edit_host->setText(host_url);
//    //ui.line_edit_topic->setText(topic_name);
//    bool remember = settings.value("remember_settings", false).toBool();
//    ui.checkbox_remember_settings->setChecked(remember);
//    bool checked = settings.value("use_environment_variables", false).toBool();
//    ui.checkbox_use_environment->setChecked(checked);
//    if ( checked ) {
//    	ui.line_edit_master->setEnabled(false);
//    	ui.line_edit_host->setEnabled(false);
//    	//ui.line_edit_topic->setEnabled(false);
//    }
}

void MainWindow::WriteSettings() {
//    QSettings settings("Qt-Ros Package", "rover");
//    settings.setValue("master_url",ui.line_edit_master->text());
//    settings.setValue("host_url",ui.line_edit_host->text());
//    //settings.setValue("topic_name",ui.line_edit_topic->text());
//    settings.setValue("use_environment_variables",QVariant(ui.checkbox_use_environment->isChecked()));
//    settings.setValue("geometry", saveGeometry());
//    settings.setValue("windowState", saveState());
//    settings.setValue("remember_settings",QVariant(ui.checkbox_remember_settings->isChecked()));

}

void MainWindow::closeEvent(QCloseEvent *event)
{
	WriteSettings();
	QMainWindow::closeEvent(event);
}

}  // namespace rover

