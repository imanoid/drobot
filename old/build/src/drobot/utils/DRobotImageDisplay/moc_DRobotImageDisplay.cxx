/****************************************************************************
** Meta object code from reading C++ file 'DRobotImageDisplay.h'
**
** Created: Wed Jun 5 15:49:22 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/drobot/utils/DRobotImageDisplay/DRobotImageDisplay.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DRobotImageDisplay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_drobot__DRobotImageDisplay[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   27,   27,   27, 0x05,
      42,   27,   27,   27, 0x05,

 // slots: signature, parameters, type, tag, flags
      51,   27,   27,   27, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_drobot__DRobotImageDisplay[] = {
    "drobot::DRobotImageDisplay\0\0dataUpdated()\0"
    "closed()\0display()\0"
};

void drobot::DRobotImageDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DRobotImageDisplay *_t = static_cast<DRobotImageDisplay *>(_o);
        switch (_id) {
        case 0: _t->dataUpdated(); break;
        case 1: _t->closed(); break;
        case 2: _t->display(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData drobot::DRobotImageDisplay::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject drobot::DRobotImageDisplay::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_drobot__DRobotImageDisplay,
      qt_meta_data_drobot__DRobotImageDisplay, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &drobot::DRobotImageDisplay::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *drobot::DRobotImageDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *drobot::DRobotImageDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_drobot__DRobotImageDisplay))
        return static_cast<void*>(const_cast< DRobotImageDisplay*>(this));
    return QWidget::qt_metacast(_clname);
}

int drobot::DRobotImageDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void drobot::DRobotImageDisplay::dataUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void drobot::DRobotImageDisplay::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
