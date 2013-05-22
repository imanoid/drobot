/****************************************************************************
** Meta object code from reading C++ file 'DRobotColorRangeSelector.h'
**
** Created: Wed May 22 17:20:30 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/drobot/utils/DRobotColorRangeSelector/DRobotColorRangeSelector.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DRobotColorRangeSelector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_drobot__DRobotColorRangeSelector[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      34,   33,   33,   33, 0x0a,
      58,   33,   33,   33, 0x0a,
      84,   33,   33,   33, 0x0a,
     109,   33,   33,   33, 0x0a,
     133,   33,   33,   33, 0x0a,
     159,   33,   33,   33, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_drobot__DRobotColorRangeSelector[] = {
    "drobot::DRobotColorRangeSelector\0\0"
    "lowerRedSliderChanged()\0"
    "lowerGreenSliderChanged()\0"
    "lowerBlueSliderChanged()\0"
    "upperRedSliderChanged()\0"
    "upperGreenSliderChanged()\0"
    "upperBlueSliderChanged()\0"
};

void drobot::DRobotColorRangeSelector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DRobotColorRangeSelector *_t = static_cast<DRobotColorRangeSelector *>(_o);
        switch (_id) {
        case 0: _t->lowerRedSliderChanged(); break;
        case 1: _t->lowerGreenSliderChanged(); break;
        case 2: _t->lowerBlueSliderChanged(); break;
        case 3: _t->upperRedSliderChanged(); break;
        case 4: _t->upperGreenSliderChanged(); break;
        case 5: _t->upperBlueSliderChanged(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData drobot::DRobotColorRangeSelector::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject drobot::DRobotColorRangeSelector::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_drobot__DRobotColorRangeSelector,
      qt_meta_data_drobot__DRobotColorRangeSelector, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &drobot::DRobotColorRangeSelector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *drobot::DRobotColorRangeSelector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *drobot::DRobotColorRangeSelector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_drobot__DRobotColorRangeSelector))
        return static_cast<void*>(const_cast< DRobotColorRangeSelector*>(this));
    if (!strcmp(_clname, "Ui_DRobotColorRangeSelectorWidget"))
        return static_cast< Ui_DRobotColorRangeSelectorWidget*>(const_cast< DRobotColorRangeSelector*>(this));
    return QWidget::qt_metacast(_clname);
}

int drobot::DRobotColorRangeSelector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
