/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindowDesign
{
public:
    QAction *action_Quit;
    QAction *action_Preferences;
    QAction *actionSave_file;
    QAction *actionLoad_file;
    QAction *actionAbout_this_program;
    QAction *actionAbout_Qt;
    QAction *actionAbout_program_maintainer;
    QWidget *centralwidget;
    QHBoxLayout *hboxLayout;
    QGroupBox *groupBox_1;
    QFrame *frame_2;
    QCheckBox *checkBox;
    QCommandLinkButton *commandLinkButton_1;
    QCommandLinkButton *commandLinkButton_2;
    QCommandLinkButton *commandLinkButton_3;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_9;
    QCheckBox *checkBox_10;
    QCheckBox *checkBox_11;
    QCheckBox *checkBox_12;
    QFrame *frame;
    QFrame *frame_3;
    QLabel *label;
    QLabel *label_2;
    QFrame *frame_4;
    QCommandLinkButton *commandLinkButton_4;
    QCommandLinkButton *commandLinkButton_5;
    QSlider *horizontalSlider;
    QLabel *label_3;
    QTabWidget *tab_manager;
    QWidget *tab_status;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QListView *view_logging_2;
    QWidget *slam_status;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_2;
    QListView *view_logging_3;
    QWidget *slam_map;
    QHBoxLayout *horizontalLayout_4;
    QCustomPlot *customPlot;
    QWidget *tab;
    QMenuBar *menubar;
    QMenu *menu_Setting;
    QMenu *menu_file;
    QMenu *menu_about;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowDesign)
    {
        if (MainWindowDesign->objectName().isEmpty())
            MainWindowDesign->setObjectName(QString::fromUtf8("MainWindowDesign"));
        MainWindowDesign->resize(1290, 781);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowDesign->setWindowIcon(icon);
        MainWindowDesign->setAutoFillBackground(true);
        MainWindowDesign->setStyleSheet(QString::fromUtf8(""));
        MainWindowDesign->setLocale(QLocale(QLocale::English, QLocale::Australia));
        action_Quit = new QAction(MainWindowDesign);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        action_Quit->setCheckable(false);
        action_Quit->setShortcutContext(Qt::ApplicationShortcut);
        action_Preferences = new QAction(MainWindowDesign);
        action_Preferences->setObjectName(QString::fromUtf8("action_Preferences"));
        action_Preferences->setCheckable(false);
        actionSave_file = new QAction(MainWindowDesign);
        actionSave_file->setObjectName(QString::fromUtf8("actionSave_file"));
        actionSave_file->setCheckable(false);
        actionLoad_file = new QAction(MainWindowDesign);
        actionLoad_file->setObjectName(QString::fromUtf8("actionLoad_file"));
        actionLoad_file->setCheckable(false);
        actionAbout_this_program = new QAction(MainWindowDesign);
        actionAbout_this_program->setObjectName(QString::fromUtf8("actionAbout_this_program"));
        actionAbout_this_program->setCheckable(false);
        actionAbout_Qt = new QAction(MainWindowDesign);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        actionAbout_Qt->setCheckable(false);
        actionAbout_program_maintainer = new QAction(MainWindowDesign);
        actionAbout_program_maintainer->setObjectName(QString::fromUtf8("actionAbout_program_maintainer"));
        actionAbout_program_maintainer->setCheckable(false);
        centralwidget = new QWidget(MainWindowDesign);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        hboxLayout = new QHBoxLayout(centralwidget);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        groupBox_1 = new QGroupBox(centralwidget);
        groupBox_1->setObjectName(QString::fromUtf8("groupBox_1"));
        groupBox_1->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_1->sizePolicy().hasHeightForWidth());
        groupBox_1->setSizePolicy(sizePolicy);
        groupBox_1->setAutoFillBackground(true);
        groupBox_1->setStyleSheet(QString::fromUtf8(""));
        groupBox_1->setFlat(false);
        frame_2 = new QFrame(groupBox_1);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(2, 61, 241, 404));
        frame_2->setAutoFillBackground(true);
        frame_2->setStyleSheet(QString::fromUtf8("border-radius:20px; \n"
"border:1px solid;\n"
"border-color: rgb(46, 52, 54);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        checkBox = new QCheckBox(frame_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(10, 20, 100, 24));
        checkBox->setAutoFillBackground(true);
        checkBox->setStyleSheet(QString::fromUtf8("border-radius:7px; "));
        commandLinkButton_1 = new QCommandLinkButton(frame_2);
        commandLinkButton_1->setObjectName(QString::fromUtf8("commandLinkButton_1"));
        commandLinkButton_1->setGeometry(QRect(10, 240, 221, 41));
        commandLinkButton_1->setAutoFillBackground(true);
        commandLinkButton_1->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.455399 rgba(255, 255, 255, 0), stop:1 rgba(198, 183, 0, 255));\n"
"border-radius:10px; \n"
"border:1px solid;\n"
"border-color: rgb(85, 87, 83);"));
        commandLinkButton_2 = new QCommandLinkButton(frame_2);
        commandLinkButton_2->setObjectName(QString::fromUtf8("commandLinkButton_2"));
        commandLinkButton_2->setGeometry(QRect(10, 290, 221, 41));
        commandLinkButton_2->setAutoFillBackground(true);
        commandLinkButton_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.338028 rgba(27, 43, 255, 0), stop:1 rgba(255, 5, 100, 255));\n"
"border-radius:10px; \n"
"border:1px solid;\n"
"border-color: rgb(85, 87, 83);"));
        commandLinkButton_3 = new QCommandLinkButton(frame_2);
        commandLinkButton_3->setObjectName(QString::fromUtf8("commandLinkButton_3"));
        commandLinkButton_3->setGeometry(QRect(10, 340, 221, 41));
        commandLinkButton_3->setAutoFillBackground(true);
        commandLinkButton_3->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.183099 rgba(27, 43, 255, 0), stop:1 rgba(23, 5, 255, 255));\n"
"border-radius:10px; \n"
"border:1px solid;\n"
"border-color: rgb(85, 87, 83);"));
        checkBox_2 = new QCheckBox(frame_2);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(10, 50, 100, 24));
        checkBox_2->setAutoFillBackground(true);
        checkBox_2->setStyleSheet(QString::fromUtf8("border-radius:7px; "));
        checkBox_3 = new QCheckBox(frame_2);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(130, 20, 100, 24));
        checkBox_3->setAutoFillBackground(true);
        checkBox_3->setStyleSheet(QString::fromUtf8("border-radius:7px; "));
        checkBox_4 = new QCheckBox(frame_2);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(130, 50, 100, 24));
        checkBox_4->setAutoFillBackground(true);
        checkBox_4->setStyleSheet(QString::fromUtf8("border-radius:7px; "));
        checkBox_5 = new QCheckBox(frame_2);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setGeometry(QRect(10, 80, 100, 24));
        checkBox_5->setAutoFillBackground(true);
        checkBox_5->setStyleSheet(QString::fromUtf8("border-radius:7px; "));
        checkBox_6 = new QCheckBox(frame_2);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setGeometry(QRect(10, 110, 100, 24));
        checkBox_6->setAutoFillBackground(true);
        checkBox_6->setStyleSheet(QString::fromUtf8("border-radius:7px; "));
        checkBox_7 = new QCheckBox(frame_2);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));
        checkBox_7->setGeometry(QRect(130, 80, 100, 24));
        checkBox_7->setAutoFillBackground(true);
        checkBox_7->setStyleSheet(QString::fromUtf8("border-radius:7px; "));
        checkBox_8 = new QCheckBox(frame_2);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));
        checkBox_8->setGeometry(QRect(130, 110, 100, 24));
        checkBox_8->setAutoFillBackground(true);
        checkBox_8->setStyleSheet(QString::fromUtf8("border-radius:7px; "));
        checkBox_9 = new QCheckBox(frame_2);
        checkBox_9->setObjectName(QString::fromUtf8("checkBox_9"));
        checkBox_9->setGeometry(QRect(10, 140, 100, 24));
        checkBox_9->setAutoFillBackground(true);
        checkBox_9->setStyleSheet(QString::fromUtf8("border-radius:7px; "));
        checkBox_10 = new QCheckBox(frame_2);
        checkBox_10->setObjectName(QString::fromUtf8("checkBox_10"));
        checkBox_10->setGeometry(QRect(10, 170, 100, 24));
        checkBox_10->setAutoFillBackground(true);
        checkBox_10->setStyleSheet(QString::fromUtf8("border-radius:7px; "));
        checkBox_11 = new QCheckBox(frame_2);
        checkBox_11->setObjectName(QString::fromUtf8("checkBox_11"));
        checkBox_11->setGeometry(QRect(130, 140, 100, 24));
        checkBox_11->setAutoFillBackground(true);
        checkBox_11->setStyleSheet(QString::fromUtf8("border-radius:7px; "));
        checkBox_12 = new QCheckBox(frame_2);
        checkBox_12->setObjectName(QString::fromUtf8("checkBox_12"));
        checkBox_12->setGeometry(QRect(130, 170, 100, 24));
        checkBox_12->setAutoFillBackground(true);
        checkBox_12->setStyleSheet(QString::fromUtf8("border-radius:7px; "));
        frame = new QFrame(frame_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 5, 241, 201));
        frame->setAutoFillBackground(true);
        frame->setStyleSheet(QString::fromUtf8("border-radius:20px; \n"
"border:1px solid;\n"
"border-color: rgb(85, 87, 83);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(0, 220, 241, 181));
        frame_3->setAutoFillBackground(false);
        frame_3->setStyleSheet(QString::fromUtf8("border-radius:20px; \n"
"border:1px solid;\n"
"border-color: rgb(85, 87, 83);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        frame->raise();
        frame_3->raise();
        checkBox->raise();
        commandLinkButton_1->raise();
        commandLinkButton_2->raise();
        commandLinkButton_3->raise();
        checkBox_2->raise();
        checkBox_3->raise();
        checkBox_4->raise();
        checkBox_5->raise();
        checkBox_6->raise();
        checkBox_7->raise();
        checkBox_8->raise();
        checkBox_9->raise();
        checkBox_10->raise();
        checkBox_11->raise();
        checkBox_12->raise();
        label = new QLabel(groupBox_1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 30, 250, 31));
        label->setAutoFillBackground(true);
        label->setStyleSheet(QString::fromUtf8("image: url(:/images/logo_2.png);"));
        label_2 = new QLabel(groupBox_1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(180, 0, 81, 18));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/images/sleep.png);"));
        frame_4 = new QFrame(groupBox_1);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(0, 480, 241, 221));
        frame_4->setAutoFillBackground(true);
        frame_4->setStyleSheet(QString::fromUtf8("border-radius:20px; \n"
"border:1px solid;\n"
"border-color: rgb(85, 87, 83);"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        commandLinkButton_4 = new QCommandLinkButton(frame_4);
        commandLinkButton_4->setObjectName(QString::fromUtf8("commandLinkButton_4"));
        commandLinkButton_4->setGeometry(QRect(10, 20, 221, 41));
        commandLinkButton_4->setAutoFillBackground(true);
        commandLinkButton_4->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.183099 rgba(27, 43, 255, 0), stop:1 rgba(23, 5, 255, 255));\n"
"border-radius:10px; \n"
"border:1px solid;\n"
"border-color: rgb(85, 87, 83);"));
        commandLinkButton_5 = new QCommandLinkButton(frame_4);
        commandLinkButton_5->setObjectName(QString::fromUtf8("commandLinkButton_5"));
        commandLinkButton_5->setGeometry(QRect(10, 80, 221, 41));
        commandLinkButton_5->setAutoFillBackground(true);
        commandLinkButton_5->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.183099 rgba(27, 43, 255, 0), stop:1 rgba(23, 5, 255, 255));\n"
"border-radius:10px; \n"
"border:1px solid;\n"
"border-color: rgb(85, 87, 83);"));
        horizontalSlider = new QSlider(frame_4);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(10, 180, 221, 20));
        horizontalSlider->setAutoFillBackground(true);
        horizontalSlider->setStyleSheet(QString::fromUtf8("border:none"));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(frame_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(14, 140, 151, 31));
        label_3->setAutoFillBackground(true);
        label_3->setStyleSheet(QString::fromUtf8("border:none"));

        hboxLayout->addWidget(groupBox_1);

        tab_manager = new QTabWidget(centralwidget);
        tab_manager->setObjectName(QString::fromUtf8("tab_manager"));
        tab_manager->setMinimumSize(QSize(100, 0));
        tab_manager->setAutoFillBackground(true);
        tab_manager->setStyleSheet(QString::fromUtf8(""));
        tab_manager->setLocale(QLocale(QLocale::English, QLocale::Australia));
        tab_status = new QWidget();
        tab_status->setObjectName(QString::fromUtf8("tab_status"));
        horizontalLayout = new QHBoxLayout(tab_status);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox_2 = new QGroupBox(tab_status);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        groupBox_2->setAutoFillBackground(true);
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        view_logging_2 = new QListView(groupBox_2);
        view_logging_2->setObjectName(QString::fromUtf8("view_logging_2"));
        view_logging_2->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        view_logging_2->setAutoFillBackground(true);
        view_logging_2->setStyleSheet(QString::fromUtf8("border:1px solid;\n"
"background-color: rgba(44, 0, 30, 255);\n"
""));
        view_logging_2->setSelectionMode(QAbstractItemView::ContiguousSelection);

        gridLayout_3->addWidget(view_logging_2, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_2);

        tab_manager->addTab(tab_status, QString());
        slam_status = new QWidget();
        slam_status->setObjectName(QString::fromUtf8("slam_status"));
        horizontalLayout_3 = new QHBoxLayout(slam_status);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        groupBox_3 = new QGroupBox(slam_status);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy1);
        groupBox_3->setAutoFillBackground(true);
        horizontalLayout_2 = new QHBoxLayout(groupBox_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        view_logging_3 = new QListView(groupBox_3);
        view_logging_3->setObjectName(QString::fromUtf8("view_logging_3"));
        view_logging_3->setEnabled(true);
        view_logging_3->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        view_logging_3->setAutoFillBackground(true);
        view_logging_3->setStyleSheet(QString::fromUtf8("border:1px solid;\n"
"background-color: rgba(44, 0, 30, 255);\n"
""));
        view_logging_3->setSelectionMode(QAbstractItemView::ContiguousSelection);

        horizontalLayout_2->addWidget(view_logging_3);


        horizontalLayout_3->addWidget(groupBox_3);

        tab_manager->addTab(slam_status, QString());
        slam_map = new QWidget();
        slam_map->setObjectName(QString::fromUtf8("slam_map"));
        horizontalLayout_4 = new QHBoxLayout(slam_map);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        customPlot = new QCustomPlot(slam_map);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        customPlot->setEnabled(true);
        sizePolicy1.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy1);
        customPlot->setAutoFillBackground(true);
        customPlot->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(customPlot);

        tab_manager->addTab(slam_map, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tab_manager->addTab(tab, QString());

        hboxLayout->addWidget(tab_manager);

        MainWindowDesign->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowDesign);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1290, 23));
        menu_Setting = new QMenu(menubar);
        menu_Setting->setObjectName(QString::fromUtf8("menu_Setting"));
        menu_file = new QMenu(menubar);
        menu_file->setObjectName(QString::fromUtf8("menu_file"));
        menu_about = new QMenu(menubar);
        menu_about->setObjectName(QString::fromUtf8("menu_about"));
        MainWindowDesign->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowDesign);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindowDesign->setStatusBar(statusbar);

        menubar->addAction(menu_Setting->menuAction());
        menubar->addAction(menu_file->menuAction());
        menubar->addAction(menu_about->menuAction());
        menu_Setting->addAction(action_Preferences);
        menu_Setting->addSeparator();
        menu_Setting->addSeparator();
        menu_Setting->addAction(action_Quit);
        menu_file->addAction(actionSave_file);
        menu_file->addAction(actionLoad_file);
        menu_about->addAction(actionAbout_this_program);
        menu_about->addAction(actionAbout_Qt);
        menu_about->addAction(actionAbout_program_maintainer);

        retranslateUi(MainWindowDesign);
        QObject::connect(action_Quit, SIGNAL(triggered()), MainWindowDesign, SLOT(close()));

        tab_manager->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindowDesign);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowDesign)
    {
        MainWindowDesign->setWindowTitle(QApplication::translate("MainWindowDesign", "SLAM Robot Controller", 0, QApplication::UnicodeUTF8));
        action_Quit->setText(QApplication::translate("MainWindowDesign", "&Quit", 0, QApplication::UnicodeUTF8));
        action_Quit->setShortcut(QApplication::translate("MainWindowDesign", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        action_Preferences->setText(QApplication::translate("MainWindowDesign", "&Preferences", 0, QApplication::UnicodeUTF8));
        actionSave_file->setText(QApplication::translate("MainWindowDesign", "Load file", 0, QApplication::UnicodeUTF8));
        actionLoad_file->setText(QApplication::translate("MainWindowDesign", "Save file", 0, QApplication::UnicodeUTF8));
        actionAbout_this_program->setText(QApplication::translate("MainWindowDesign", "About this program", 0, QApplication::UnicodeUTF8));
        actionAbout_Qt->setText(QApplication::translate("MainWindowDesign", "About Qt", 0, QApplication::UnicodeUTF8));
        actionAbout_program_maintainer->setText(QApplication::translate("MainWindowDesign", "About program maintainer", 0, QApplication::UnicodeUTF8));
        groupBox_1->setTitle(QApplication::translate("MainWindowDesign", "Control Panel                          ", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("MainWindowDesign", "Load map", 0, QApplication::UnicodeUTF8));
        commandLinkButton_1->setText(QApplication::translate("MainWindowDesign", "Save map", 0, QApplication::UnicodeUTF8));
        commandLinkButton_2->setText(QApplication::translate("MainWindowDesign", "Start", 0, QApplication::UnicodeUTF8));
        commandLinkButton_3->setText(QApplication::translate("MainWindowDesign", "Stop", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("MainWindowDesign", "CheckBox", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("MainWindowDesign", "Load map", 0, QApplication::UnicodeUTF8));
        checkBox_4->setText(QApplication::translate("MainWindowDesign", "CheckBox", 0, QApplication::UnicodeUTF8));
        checkBox_5->setText(QApplication::translate("MainWindowDesign", "Load map", 0, QApplication::UnicodeUTF8));
        checkBox_6->setText(QApplication::translate("MainWindowDesign", "CheckBox", 0, QApplication::UnicodeUTF8));
        checkBox_7->setText(QApplication::translate("MainWindowDesign", "Load map", 0, QApplication::UnicodeUTF8));
        checkBox_8->setText(QApplication::translate("MainWindowDesign", "CheckBox", 0, QApplication::UnicodeUTF8));
        checkBox_9->setText(QApplication::translate("MainWindowDesign", "Load map", 0, QApplication::UnicodeUTF8));
        checkBox_10->setText(QApplication::translate("MainWindowDesign", "CheckBox", 0, QApplication::UnicodeUTF8));
        checkBox_11->setText(QApplication::translate("MainWindowDesign", "Load map", 0, QApplication::UnicodeUTF8));
        checkBox_12->setText(QApplication::translate("MainWindowDesign", "CheckBox", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_2->setText(QString());
        commandLinkButton_4->setText(QApplication::translate("MainWindowDesign", "confirm the Goal", 0, QApplication::UnicodeUTF8));
        commandLinkButton_5->setText(QApplication::translate("MainWindowDesign", "Go to the goal", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindowDesign", "Set the Speed", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindowDesign", "  This terminal show the topic and msgs", 0, QApplication::UnicodeUTF8));
        tab_manager->setTabText(tab_manager->indexOf(tab_status), QApplication::translate("MainWindowDesign", "Ros Communications", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindowDesign", "  This terminal show the feature points and status during mapping", 0, QApplication::UnicodeUTF8));
        tab_manager->setTabText(tab_manager->indexOf(slam_status), QApplication::translate("MainWindowDesign", "SLAM Status", 0, QApplication::UnicodeUTF8));
        tab_manager->setTabText(tab_manager->indexOf(slam_map), QApplication::translate("MainWindowDesign", "Dynamic 2D map", 0, QApplication::UnicodeUTF8));
        tab_manager->setTabText(tab_manager->indexOf(tab), QApplication::translate("MainWindowDesign", "Dynamic Values", 0, QApplication::UnicodeUTF8));
        menu_Setting->setTitle(QApplication::translate("MainWindowDesign", "&App", 0, QApplication::UnicodeUTF8));
        menu_file->setTitle(QApplication::translate("MainWindowDesign", "File", 0, QApplication::UnicodeUTF8));
        menu_about->setTitle(QApplication::translate("MainWindowDesign", "About", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowDesign: public Ui_MainWindowDesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
