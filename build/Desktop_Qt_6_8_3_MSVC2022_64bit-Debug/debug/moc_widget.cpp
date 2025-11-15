/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../widget.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN6WidgetE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN6WidgetE = QtMocHelpers::stringData(
    "Widget",
    "openPortRequested",
    "",
    "portName",
    "QSerialPort::BaudRate",
    "baudRate",
    "QSerialPort::DataBits",
    "dataBits",
    "QSerialPort::StopBits",
    "stopBits",
    "QSerialPort::Parity",
    "parity",
    "closePortRequested",
    "writeDataRequested",
    "data",
    "initcombo",
    "onDataReceived",
    "updateDisplay",
    "onErrorOccurred",
    "error",
    "onPortOpened",
    "success",
    "onPortRefresh",
    "QList<QSerialPortInfo>",
    "ports",
    "on_btnOpen_clicked",
    "on_btnClose_clicked",
    "on_btnRefresh_clicked",
    "on_btnSend_clicked",
    "on_btnClearReceive_clicked",
    "on_btnPauseReceive_clicked",
    "on_checkAutoSend_stateChanged",
    "arg1",
    "on_radioHexReceive_toggled",
    "checked",
    "on_btnSaveReceive_clicked",
    "on_radioAsciiReceive_toggled",
    "on_radioHexSend_toggled",
    "on_radioAsciiSend_toggled",
    "autoSendTimerTimeout"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN6WidgetE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    5,  146,    2, 0x06,    1 /* Public */,
      12,    0,  157,    2, 0x06,    7 /* Public */,
      13,    1,  158,    2, 0x06,    8 /* Public */,
      15,    0,  161,    2, 0x06,   10 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      16,    1,  162,    2, 0x08,   11 /* Private */,
      17,    0,  165,    2, 0x08,   13 /* Private */,
      18,    1,  166,    2, 0x08,   14 /* Private */,
      20,    1,  169,    2, 0x08,   16 /* Private */,
      22,    1,  172,    2, 0x08,   18 /* Private */,
      25,    0,  175,    2, 0x08,   20 /* Private */,
      26,    0,  176,    2, 0x08,   21 /* Private */,
      27,    0,  177,    2, 0x08,   22 /* Private */,
      28,    0,  178,    2, 0x08,   23 /* Private */,
      29,    0,  179,    2, 0x08,   24 /* Private */,
      30,    0,  180,    2, 0x08,   25 /* Private */,
      31,    1,  181,    2, 0x08,   26 /* Private */,
      33,    1,  184,    2, 0x08,   28 /* Private */,
      35,    0,  187,    2, 0x08,   30 /* Private */,
      36,    1,  188,    2, 0x08,   31 /* Private */,
      37,    1,  191,    2, 0x08,   33 /* Private */,
      38,    1,  194,    2, 0x08,   35 /* Private */,
      39,    0,  197,    2, 0x08,   37 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4, 0x80000000 | 6, 0x80000000 | 8, 0x80000000 | 10,    3,    5,    7,    9,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   14,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   32,
    QMetaType::Void, QMetaType::Bool,   34,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   34,
    QMetaType::Void, QMetaType::Bool,   34,
    QMetaType::Void, QMetaType::Bool,   34,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ZN6WidgetE.offsetsAndSizes,
    qt_meta_data_ZN6WidgetE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN6WidgetE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Widget, std::true_type>,
        // method 'openPortRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QSerialPort::BaudRate, std::false_type>,
        QtPrivate::TypeAndForceComplete<QSerialPort::DataBits, std::false_type>,
        QtPrivate::TypeAndForceComplete<QSerialPort::StopBits, std::false_type>,
        QtPrivate::TypeAndForceComplete<QSerialPort::Parity, std::false_type>,
        // method 'closePortRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'writeDataRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'initcombo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDataReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'updateDisplay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onErrorOccurred'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onPortOpened'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'onPortRefresh'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<QSerialPortInfo>, std::false_type>,
        // method 'on_btnOpen_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnClose_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnRefresh_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnSend_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnClearReceive_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnPauseReceive_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_checkAutoSend_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_radioHexReceive_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_btnSaveReceive_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_radioAsciiReceive_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_radioHexSend_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_radioAsciiSend_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'autoSendTimerTimeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Widget *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->openPortRequested((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QSerialPort::BaudRate>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QSerialPort::DataBits>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QSerialPort::StopBits>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QSerialPort::Parity>>(_a[5]))); break;
        case 1: _t->closePortRequested(); break;
        case 2: _t->writeDataRequested((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 3: _t->initcombo(); break;
        case 4: _t->onDataReceived((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 5: _t->updateDisplay(); break;
        case 6: _t->onErrorOccurred((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->onPortOpened((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: _t->onPortRefresh((*reinterpret_cast< std::add_pointer_t<QList<QSerialPortInfo>>>(_a[1]))); break;
        case 9: _t->on_btnOpen_clicked(); break;
        case 10: _t->on_btnClose_clicked(); break;
        case 11: _t->on_btnRefresh_clicked(); break;
        case 12: _t->on_btnSend_clicked(); break;
        case 13: _t->on_btnClearReceive_clicked(); break;
        case 14: _t->on_btnPauseReceive_clicked(); break;
        case 15: _t->on_checkAutoSend_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 16: _t->on_radioHexReceive_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 17: _t->on_btnSaveReceive_clicked(); break;
        case 18: _t->on_radioAsciiReceive_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 19: _t->on_radioHexSend_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 20: _t->on_radioAsciiSend_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 21: _t->autoSendTimerTimeout(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (Widget::*)(const QString & , QSerialPort::BaudRate , QSerialPort::DataBits , QSerialPort::StopBits , QSerialPort::Parity );
            if (_q_method_type _q_method = &Widget::openPortRequested; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (Widget::*)();
            if (_q_method_type _q_method = &Widget::closePortRequested; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (Widget::*)(const QByteArray & );
            if (_q_method_type _q_method = &Widget::writeDataRequested; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (Widget::*)();
            if (_q_method_type _q_method = &Widget::initcombo; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN6WidgetE.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void Widget::openPortRequested(const QString & _t1, QSerialPort::BaudRate _t2, QSerialPort::DataBits _t3, QSerialPort::StopBits _t4, QSerialPort::Parity _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Widget::closePortRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Widget::writeDataRequested(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Widget::initcombo()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
