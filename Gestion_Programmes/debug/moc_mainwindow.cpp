/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[312];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 12), // "update_label"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 18), // "on_ajouter_clicked"
QT_MOC_LITERAL(4, 44, 20), // "on_Supprimer_clicked"
QT_MOC_LITERAL(5, 65, 19), // "on_Modifier_clicked"
QT_MOC_LITERAL(6, 85, 29), // "on_TableauAffichage_activated"
QT_MOC_LITERAL(7, 115, 5), // "index"
QT_MOC_LITERAL(8, 121, 16), // "on_Trier_clicked"
QT_MOC_LITERAL(9, 138, 22), // "on_ImporterPDF_clicked"
QT_MOC_LITERAL(10, 161, 21), // "on_Rechercher_clicked"
QT_MOC_LITERAL(11, 183, 8), // "sendMail"
QT_MOC_LITERAL(12, 192, 8), // "mailSent"
QT_MOC_LITERAL(13, 201, 6), // "browse"
QT_MOC_LITERAL(14, 208, 21), // "on_HISTORIQUE_clicked"
QT_MOC_LITERAL(15, 230, 18), // "on_Quitter_clicked"
QT_MOC_LITERAL(16, 249, 20), // "on_Quitter_2_clicked"
QT_MOC_LITERAL(17, 270, 20), // "on_Quitter_3_clicked"
QT_MOC_LITERAL(18, 291, 20) // "on_Quitter_4_clicked"

    },
    "MainWindow\0update_label\0\0on_ajouter_clicked\0"
    "on_Supprimer_clicked\0on_Modifier_clicked\0"
    "on_TableauAffichage_activated\0index\0"
    "on_Trier_clicked\0on_ImporterPDF_clicked\0"
    "on_Rechercher_clicked\0sendMail\0mailSent\0"
    "browse\0on_HISTORIQUE_clicked\0"
    "on_Quitter_clicked\0on_Quitter_2_clicked\0"
    "on_Quitter_3_clicked\0on_Quitter_4_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    0,   96,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    1,   98,    2, 0x08 /* Private */,
       8,    0,  101,    2, 0x08 /* Private */,
       9,    0,  102,    2, 0x08 /* Private */,
      10,    0,  103,    2, 0x08 /* Private */,
      11,    0,  104,    2, 0x08 /* Private */,
      12,    1,  105,    2, 0x08 /* Private */,
      13,    0,  108,    2, 0x08 /* Private */,
      14,    0,  109,    2, 0x08 /* Private */,
      15,    0,  110,    2, 0x08 /* Private */,
      16,    0,  111,    2, 0x08 /* Private */,
      17,    0,  112,    2, 0x08 /* Private */,
      18,    0,  113,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    7,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->update_label(); break;
        case 1: _t->on_ajouter_clicked(); break;
        case 2: _t->on_Supprimer_clicked(); break;
        case 3: _t->on_Modifier_clicked(); break;
        case 4: _t->on_TableauAffichage_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->on_Trier_clicked(); break;
        case 6: { int _r = _t->on_ImporterPDF_clicked();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->on_Rechercher_clicked(); break;
        case 8: _t->sendMail(); break;
        case 9: _t->mailSent((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->browse(); break;
        case 11: _t->on_HISTORIQUE_clicked(); break;
        case 12: _t->on_Quitter_clicked(); break;
        case 13: _t->on_Quitter_2_clicked(); break;
        case 14: _t->on_Quitter_3_clicked(); break;
        case 15: _t->on_Quitter_4_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
