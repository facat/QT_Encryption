/****************************************************************************
** Meta object code from reading C++ file 'mainwindowencryption.h'
**
** Created: Sun Jun 10 10:42:55 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindowencryption.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindowencryption.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindowEncryption[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x08,
      49,   21,   21,   21, 0x08,
      84,   79,   21,   21, 0x08,
     135,   21,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindowEncryption[] = {
    "MainWindowEncryption\0\0on_pushButtonAdd_clicked()\0"
    "on_pushButtonRemove_clicked()\0item\0"
    "on_listWidgetDirList_itemClicked(QListWidgetItem*)\0"
    "on_pushButtonCheckOut_clicked()\0"
};

void MainWindowEncryption::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindowEncryption *_t = static_cast<MainWindowEncryption *>(_o);
        switch (_id) {
        case 0: _t->on_pushButtonAdd_clicked(); break;
        case 1: _t->on_pushButtonRemove_clicked(); break;
        case 2: _t->on_listWidgetDirList_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->on_pushButtonCheckOut_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindowEncryption::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindowEncryption::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindowEncryption,
      qt_meta_data_MainWindowEncryption, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindowEncryption::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindowEncryption::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindowEncryption::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindowEncryption))
        return static_cast<void*>(const_cast< MainWindowEncryption*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindowEncryption::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
