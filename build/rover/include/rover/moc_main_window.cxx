/****************************************************************************
** Meta object code from reading C++ file 'main_window.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rover/include/rover/main_window.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rover__MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   58,   58,   58, 0x0a,
      59,   86,   58,   58, 0x0a,
      92,   58,   58,   58, 0x0a,
     112,  139,   58,   58, 0x0a,
     144,   58,   58,   58, 0x0a,
     156,   58,   58,   58, 0x0a,
     170,   58,   58,   58, 0x0a,
     183,   58,   58,   58, 0x0a,
     216,   58,   58,   58, 0x0a,
     249,   58,   58,   58, 0x0a,
     282,   58,   58,   58, 0x0a,
     315,   58,   58,   58, 0x0a,
     348,  386,   58,   58, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_rover__MainWindow[] = {
    "rover::MainWindow\0"
    "on_actionAbout_this_program_triggered()\0"
    "\0mouseDcEvent(QMouseEvent*)\0event\0"
    "updateLoggingView()\0changeStateIndicator(char)\0"
    "flag\0updateMap()\0updateCloud()\0"
    "updatePath()\0on_commandLinkButton_1_clicked()\0"
    "on_commandLinkButton_2_clicked()\0"
    "on_commandLinkButton_3_clicked()\0"
    "on_commandLinkButton_4_clicked()\0"
    "on_commandLinkButton_5_clicked()\0"
    "on_horizontalSlider_valueChanged(int)\0"
    "value\0"
};

void rover::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_actionAbout_this_program_triggered(); break;
        case 1: _t->mouseDcEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: _t->updateLoggingView(); break;
        case 3: _t->changeStateIndicator((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 4: _t->updateMap(); break;
        case 5: _t->updateCloud(); break;
        case 6: _t->updatePath(); break;
        case 7: _t->on_commandLinkButton_1_clicked(); break;
        case 8: _t->on_commandLinkButton_2_clicked(); break;
        case 9: _t->on_commandLinkButton_3_clicked(); break;
        case 10: _t->on_commandLinkButton_4_clicked(); break;
        case 11: _t->on_commandLinkButton_5_clicked(); break;
        case 12: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData rover::MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rover::MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_rover__MainWindow,
      qt_meta_data_rover__MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rover::MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rover::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rover::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rover__MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int rover::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
