/****************************************************************************
** Meta object code from reading C++ file 'DRobotTimePlotter.h'
**
** Created: Wed Jun 5 15:49:22 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/drobot/utils/DRobotTimePlotter/DRobotTimePlotter.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DRobotTimePlotter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_drobot__DRobotTimePlotter[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      27,   26,   26,   26, 0x05,

 // slots: signature, parameters, type, tag, flags
      41,   26,   26,   26, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_drobot__DRobotTimePlotter[] = {
    "drobot::DRobotTimePlotter\0\0dataUpdated()\0"
    "replot()\0"
};

void drobot::DRobotTimePlotter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DRobotTimePlotter *_t = static_cast<DRobotTimePlotter *>(_o);
        switch (_id) {
        case 0: _t->dataUpdated(); break;
        case 1: _t->replot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData drobot::DRobotTimePlotter::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject drobot::DRobotTimePlotter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_drobot__DRobotTimePlotter,
      qt_meta_data_drobot__DRobotTimePlotter, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &drobot::DRobotTimePlotter::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *drobot::DRobotTimePlotter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *drobot::DRobotTimePlotter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_drobot__DRobotTimePlotter))
        return static_cast<void*>(const_cast< DRobotTimePlotter*>(this));
    return QObject::qt_metacast(_clname);
}

int drobot::DRobotTimePlotter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void drobot::DRobotTimePlotter::dataUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
