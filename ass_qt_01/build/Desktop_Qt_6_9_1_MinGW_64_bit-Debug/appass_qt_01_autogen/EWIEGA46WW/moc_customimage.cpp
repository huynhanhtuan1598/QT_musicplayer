/****************************************************************************
** Meta object code from reading C++ file 'customimage.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../customimage.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customimage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.1. It"
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
struct qt_meta_tag_ZN11CustomimageE_t {};
} // unnamed namespace

template <> constexpr inline auto Customimage::qt_create_metaobjectdata<qt_meta_tag_ZN11CustomimageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Customimage",
        "sourceChanged",
        "",
        "setSource",
        "source",
        "setImage",
        "image"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'sourceChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setSource'
        QtMocHelpers::SlotData<void(const QString &)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 4 },
        }}),
        // Slot 'setImage'
        QtMocHelpers::SlotData<void(QImage)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QImage, 6 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'source'
        QtMocHelpers::PropertyData<QString>(4, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Customimage, qt_meta_tag_ZN11CustomimageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Customimage::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickPaintedItem::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11CustomimageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11CustomimageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11CustomimageE_t>.metaTypes,
    nullptr
} };

void Customimage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Customimage *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->sourceChanged(); break;
        case 1: _t->setSource((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->setImage((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Customimage::*)()>(_a, &Customimage::sourceChanged, 0))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->source(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSource(*reinterpret_cast<QString*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *Customimage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Customimage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11CustomimageE_t>.strings))
        return static_cast<void*>(this);
    return QQuickPaintedItem::qt_metacast(_clname);
}

int Customimage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickPaintedItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void Customimage::sourceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
