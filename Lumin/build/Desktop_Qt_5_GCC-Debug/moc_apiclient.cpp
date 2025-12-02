/****************************************************************************
** Meta object code from reading C++ file 'apiclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../apiclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'apiclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ApiClient_t {
    QByteArrayData data[23];
    char stringdata0[238];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ApiClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ApiClient_t qt_meta_stringdata_ApiClient = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ApiClient"
QT_MOC_LITERAL(1, 10, 12), // "loginSuccess"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 3), // "str"
QT_MOC_LITERAL(4, 28, 4), // "str1"
QT_MOC_LITERAL(5, 33, 13), // "verifySuccess"
QT_MOC_LITERAL(6, 47, 4), // "User"
QT_MOC_LITERAL(7, 52, 4), // "user"
QT_MOC_LITERAL(8, 57, 14), // "tokenRefreshed"
QT_MOC_LITERAL(9, 72, 11), // "authExpired"
QT_MOC_LITERAL(10, 84, 13), // "refreshFailed"
QT_MOC_LITERAL(11, 98, 12), // "loginRequest"
QT_MOC_LITERAL(12, 111, 4), // "mail"
QT_MOC_LITERAL(13, 116, 4), // "pass"
QT_MOC_LITERAL(14, 121, 13), // "verifyRequest"
QT_MOC_LITERAL(15, 135, 6), // "verCod"
QT_MOC_LITERAL(16, 142, 12), // "sessionToken"
QT_MOC_LITERAL(17, 155, 15), // "registerRequest"
QT_MOC_LITERAL(18, 171, 5), // "first"
QT_MOC_LITERAL(19, 177, 4), // "last"
QT_MOC_LITERAL(20, 182, 20), // "updateProfileRequest"
QT_MOC_LITERAL(21, 203, 15), // "doUpdateProfile"
QT_MOC_LITERAL(22, 219, 18) // "refreshAccessToken"

    },
    "ApiClient\0loginSuccess\0\0str\0str1\0"
    "verifySuccess\0User\0user\0tokenRefreshed\0"
    "authExpired\0refreshFailed\0loginRequest\0"
    "mail\0pass\0verifyRequest\0verCod\0"
    "sessionToken\0registerRequest\0first\0"
    "last\0updateProfileRequest\0doUpdateProfile\0"
    "refreshAccessToken"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ApiClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       5,    1,   74,    2, 0x06 /* Public */,
       8,    0,   77,    2, 0x06 /* Public */,
       9,    0,   78,    2, 0x06 /* Public */,
      10,    0,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    2,   80,    2, 0x0a /* Public */,
      14,    2,   85,    2, 0x0a /* Public */,
      17,    4,   90,    2, 0x0a /* Public */,
      20,    2,   99,    2, 0x0a /* Public */,
      21,    2,  104,    2, 0x0a /* Public */,
      22,    0,  109,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   12,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   15,   16,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   18,   19,   12,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   18,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   18,   19,
    QMetaType::Void,

       0        // eod
};

void ApiClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ApiClient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->loginSuccess((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->verifySuccess((*reinterpret_cast< User(*)>(_a[1]))); break;
        case 2: _t->tokenRefreshed(); break;
        case 3: _t->authExpired(); break;
        case 4: _t->refreshFailed(); break;
        case 5: _t->loginRequest((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: _t->verifyRequest((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 7: _t->registerRequest((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 8: _t->updateProfileRequest((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 9: _t->doUpdateProfile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 10: _t->refreshAccessToken(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ApiClient::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ApiClient::loginSuccess)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ApiClient::*)(User );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ApiClient::verifySuccess)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ApiClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ApiClient::tokenRefreshed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ApiClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ApiClient::authExpired)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ApiClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ApiClient::refreshFailed)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ApiClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ApiClient.data,
    qt_meta_data_ApiClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ApiClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ApiClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ApiClient.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ApiClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void ApiClient::loginSuccess(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ApiClient::verifySuccess(User _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ApiClient::tokenRefreshed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ApiClient::authExpired()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ApiClient::refreshFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
