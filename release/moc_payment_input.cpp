/****************************************************************************
** Meta object code from reading C++ file 'payment_input.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../payment_input.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'payment_input.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_payment_input_t {
    QByteArrayData data[12];
    char stringdata0[211];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_payment_input_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_payment_input_t qt_meta_stringdata_payment_input = {
    {
QT_MOC_LITERAL(0, 0, 13), // "payment_input"
QT_MOC_LITERAL(1, 14, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 28), // "on_pushButton_Search_clicked"
QT_MOC_LITERAL(4, 66, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(5, 90, 22), // "on_tableView_activated"
QT_MOC_LITERAL(6, 113, 11), // "QModelIndex"
QT_MOC_LITERAL(7, 125, 5), // "index"
QT_MOC_LITERAL(8, 131, 27), // "on_calendarWidget_activated"
QT_MOC_LITERAL(9, 159, 4), // "date"
QT_MOC_LITERAL(10, 164, 25), // "on_calendarWidget_clicked"
QT_MOC_LITERAL(11, 190, 20) // "on_tableView_clicked"

    },
    "payment_input\0on_pushButton_clicked\0"
    "\0on_pushButton_Search_clicked\0"
    "on_pushButton_2_clicked\0on_tableView_activated\0"
    "QModelIndex\0index\0on_calendarWidget_activated\0"
    "date\0on_calendarWidget_clicked\0"
    "on_tableView_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_payment_input[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    1,   52,    2, 0x08 /* Private */,
       8,    1,   55,    2, 0x08 /* Private */,
      10,    1,   58,    2, 0x08 /* Private */,
      11,    1,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QDate,    9,
    QMetaType::Void, QMetaType::QDate,    9,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void payment_input::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<payment_input *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_pushButton_Search_clicked(); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->on_tableView_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->on_calendarWidget_activated((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 5: _t->on_calendarWidget_clicked((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 6: _t->on_tableView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject payment_input::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_payment_input.data,
    qt_meta_data_payment_input,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *payment_input::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *payment_input::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_payment_input.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int payment_input::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
