/**
 * @file /include/rover/main_window.hpp
 *
 * @brief Qt based gui for rover.
 *
 * @date November 2010
 **/
#ifndef rover_MAIN_WINDOW_H
#define rover_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"
#include "qcustomplot.h"

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace rover {

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow {
Q_OBJECT

public:
	MainWindow(int argc, char** argv, QWidget *parent = 0);
	~MainWindow();

	void ReadSettings(); // Load up qt program settings at startup
	void WriteSettings(); // Save qt program settings when closing

	void closeEvent(QCloseEvent *event); // Overloaded function
	void showNoMasterMessage();

public Q_SLOTS:
	/******************************************
	** Auto-connections (connectSlotsByName())
	*******************************************/
//	void on_actionAbout_triggered();
    void on_actionAbout_this_program_triggered();
//	void on_button_connect_clicked(bool check );
//	void on_checkbox_use_environment_stateChanged(int state);
    void mouseDcEvent(QMouseEvent *event);

    /******************************************
    ** Manual connections
    *******************************************/
    void updateLoggingView(); // no idea why this can't connect automatically
    void changeStateIndicator(char flag);
    void updateMap();
    void updateCloud();
    void updatePath();

    void on_commandLinkButton_1_clicked();
    void on_commandLinkButton_2_clicked();
    void on_commandLinkButton_3_clicked();
    void on_commandLinkButton_4_clicked();
    void on_commandLinkButton_5_clicked();

    void on_horizontalSlider_valueChanged(int value);

private:
	Ui::MainWindowDesign ui;
	QNode qnode;
    double goal_x;
    double goal_y;
};

}  // namespace rover

#endif // rover_MAIN_WINDOW_H
