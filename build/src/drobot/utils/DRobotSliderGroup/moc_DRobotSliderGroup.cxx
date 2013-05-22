/****************************************************************************
** Meta object code from reading C++ file 'DRobotSliderGroup.h'
**
** Created: Wed May 22 17:20:30 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/drobot/utils/DRobotSliderGroup/DRobotSliderGroup.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DRobotSliderGroup.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_drobot__DRobotSliderGroup[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   26,   26,   26, 0x0a,
      34,   26,   26,   26, 0x0a,
      41,   26,   26,   26, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_drobot__DRobotSliderGroup[] = {
    "drobot::DRobotSliderGroup\0\0save()\0"
    "load()\0reset()\0"
};

void drobot::DRobotSliderGroup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DRobotSliderGroup *_t = static_cast<DRobotSliderGroup *>(_o);
        switch (_id) {
        case 0: _t->save(); break;
        case 1: _t->load(); break;
        case 2: _t->reset(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData drobot::DRobotSliderGroup::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject drobot::DRobotSliderGroup::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_drobot__DRobotSliderGroup,
      qt_meta_data_drobot__DRobotSliderGroup, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &drobot::DRobotSliderGroup::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *drobot::DRobotSliderGroup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *drobot::DRobotSliderGroup::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_drobot__DRobotSliderGroup))
        return static_cast<void*>(const_cast< DRobotSliderGroup*>(this));
    return QWidget::qt_metacast(_clname);
}

int drobot::DRobotSliderGroup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
