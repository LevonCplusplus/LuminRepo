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
    QByteArrayData data[25];
    char stringdata0[263];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ApiClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ApiClient_t qt_meta_stringdata_ApiClient = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ApiClient"
QT_MOC_LITERAL(1, 10, 11), // "loginResult"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 11), // "LoginStatus"
QT_MOC_LITERAL(4, 35, 6), // "status"
QT_MOC_LITERAL(5, 42, 7), // "message"
QT_MOC_LITERAL(6, 50, 4), // "mail"
QT_MOC_LITERAL(7, 55, 7), // "session"
QT_MOC_LITERAL(8, 63, 13), // "verifySuccess"
QT_MOC_LITERAL(9, 77, 4), // "User"
QT_MOC_LITERAL(10, 82, 4), // "user"
QT_MOC_LITERAL(11, 87, 14), // "tokenRefreshed"
QT_MOC_LITERAL(12, 102, 11), // "authExpired"
QT_MOC_LITERAL(13, 114, 13), // "refreshFailed"
QT_MOC_LITERAL(14, 128, 12), // "loginRequest"
QT_MOC_LITERAL(15, 141, 4), // "pass"
QT_MOC_LITERAL(16, 146, 13), // "verifyRequest"
QT_MOC_LITERAL(17, 160, 6), // "verCod"
QT_MOC_LITERAL(18, 167, 12), // "sessionToken"
QT_MOC_LITERAL(19, 180, 15), // "registerRequest"
QT_MOC_LITERAL(20, 196, 5), // "first"
QT_MOC_LITERAL(21, 202, 4), // "last"
QT_MOC_LITERAL(22, 207, 20), // "updateProfileRequest"
QT_MOC_LITERAL(23, 228, 15), // "doUpdateProfile"
QT_MOC_LITERAL(24, 244, 18) // "refreshAccessToken"

    },
    "ApiClient\0loginResult\0\0LoginStatus\0"
    "status\0message\0mail\0session\0verifySuccess\0"
    "User\0user\0tokenRefreshed\0authExpired\0"
    "refreshFailed\0loginRequest\0pass\0"
    "verifyRequest\0verCod\0sessionToken\0"
    "registerRequest\0first\0last\0"
    "updateProfileRequest\0doUpdateProfile\0"
    "refreshAccessToken"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ApiClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   79,    2, 0x06 /* Public */,
       1,    3,   88,    2, 0x26 /* Public | MethodCloned */,
       1,    2,   95,    2, 0x26 /* Public | MethodCloned */,
       8,    1,  100,    2, 0x06 /* Public */,
      11,    0,  103,    2, 0x06 /* Public */,
      12,    0,  104,    2, 0x06 /* Public */,
      13,    0,  105,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    2,  106,    2, 0x0a /* Public */,
      16,    2,  111,    2, 0x0a /* Public */,
      19,    4,  116,    2, 0x0a /* Public */,
      22,    2,  125,    2, 0x0a /* Public */,
      23,    2,  130,    2, 0x0a /* Public */,
      24,    0,  135,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QString, QMetaType::QString,    4,    5,    6,    7,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QString,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   17,   18,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   20,   21,    6,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   20,   21,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   20,   21,
    QMetaType::Void,

       0        // eod
};

void ApiClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ApiClient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->loginResult((*reinterpret_cast< LoginStatus(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 1: _t->loginResult((*reinterpret_cast< LoginStatus(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 2: _t->loginResult((*reinterpret_cast< LoginStatus(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->verifySuccess((*reinterpret_cast< User(*)>(_a[1]))); break;
        case 4: _t->tokenRefreshed(); break;
        case 5: _t->authExpired(); break;
        case 6: _t->refreshFailed(); break;
        case 7: _t->loginRequest((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 8: _t->verifyRequest((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 9: _t->registerRequest((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 10: _t->updateProfileRequest((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 11: _t->doUpdateProfile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 12: _t->refreshAccessToken(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ApiClient::*)(LoginStatus , const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ApiClient::loginResult)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ApiClient::*)(User );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ApiClient::verifySuccess)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ApiClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ApiClient::tokenRefreshed)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ApiClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ApiClient::authExpired)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ApiClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ApiClient::refreshFailed)) {
                *result = 6;
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void ApiClient::loginResult(LoginStatus _t1, const QString & _t2, const QString & _t3, const QString & _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 3
void ApiClient::verifySuccess(User _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ApiClient::tokenRefreshed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ApiClient::authExpired()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void ApiClient::refreshFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
