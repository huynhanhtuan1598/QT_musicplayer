/****************************************************************************
** Meta object code from reading C++ file 'musicload.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../musicload.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'musicload.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9MusicLoadE_t {};
} // unnamed namespace

template <> constexpr inline auto MusicLoad::qt_create_metaobjectdata<qt_meta_tag_ZN9MusicLoadE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "MusicLoad",
        "musicLoadDone",
        "",
        "musicFiles",
        "isPlayingChanged",
        "titleChanged",
        "artistChanged",
        "coverArtChanged",
        "positionChanged",
        "durationChanged",
        "shuffleChanged",
        "playNext",
        "playPrevious",
        "playOrPause",
        "setPosition",
        "pos",
        "loadMusicIntoPlayer",
        "setVolume",
        "value",
        "isPlaying",
        "title",
        "artist",
        "coverArt",
        "position",
        "duration",
        "isShuffle"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'musicLoadDone'
        QtMocHelpers::SignalData<void(const QStringList &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 3 },
        }}),
        // Signal 'isPlayingChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'titleChanged'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'artistChanged'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'coverArtChanged'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'positionChanged'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'durationChanged'
        QtMocHelpers::SignalData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'shuffleChanged'
        QtMocHelpers::SignalData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'playNext'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'playPrevious'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'playOrPause'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setPosition'
        QtMocHelpers::SlotData<void(qint64)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::LongLong, 15 },
        }}),
        // Slot 'loadMusicIntoPlayer'
        QtMocHelpers::SlotData<void(const QStringList &)>(16, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QStringList, 3 },
        }}),
        // Method 'setVolume'
        QtMocHelpers::MethodData<void(qreal)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 18 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'isPlaying'
        QtMocHelpers::PropertyData<bool>(19, QMetaType::Bool, QMC::DefaultPropertyFlags, 1),
        // property 'title'
        QtMocHelpers::PropertyData<QString>(20, QMetaType::QString, QMC::DefaultPropertyFlags, 2),
        // property 'artist'
        QtMocHelpers::PropertyData<QString>(21, QMetaType::QString, QMC::DefaultPropertyFlags, 3),
        // property 'coverArt'
        QtMocHelpers::PropertyData<QImage>(22, QMetaType::QImage, QMC::DefaultPropertyFlags, 4),
        // property 'position'
        QtMocHelpers::PropertyData<qint64>(23, QMetaType::LongLong, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 5),
        // property 'duration'
        QtMocHelpers::PropertyData<qint64>(24, QMetaType::LongLong, QMC::DefaultPropertyFlags, 6),
        // property 'isShuffle'
        QtMocHelpers::PropertyData<bool>(25, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable, 7),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<MusicLoad, qt_meta_tag_ZN9MusicLoadE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject MusicLoad::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9MusicLoadE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9MusicLoadE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9MusicLoadE_t>.metaTypes,
    nullptr
} };

void MusicLoad::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MusicLoad *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->musicLoadDone((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 1: _t->isPlayingChanged(); break;
        case 2: _t->titleChanged(); break;
        case 3: _t->artistChanged(); break;
        case 4: _t->coverArtChanged(); break;
        case 5: _t->positionChanged(); break;
        case 6: _t->durationChanged(); break;
        case 7: _t->shuffleChanged(); break;
        case 8: _t->playNext(); break;
        case 9: _t->playPrevious(); break;
        case 10: _t->playOrPause(); break;
        case 11: _t->setPosition((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 12: _t->loadMusicIntoPlayer((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 13: _t->setVolume((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (MusicLoad::*)(const QStringList & )>(_a, &MusicLoad::musicLoadDone, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (MusicLoad::*)()>(_a, &MusicLoad::isPlayingChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (MusicLoad::*)()>(_a, &MusicLoad::titleChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (MusicLoad::*)()>(_a, &MusicLoad::artistChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (MusicLoad::*)()>(_a, &MusicLoad::coverArtChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (MusicLoad::*)()>(_a, &MusicLoad::positionChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (MusicLoad::*)()>(_a, &MusicLoad::durationChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (MusicLoad::*)()>(_a, &MusicLoad::shuffleChanged, 7))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->getIsPlaying(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->getTitle(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->getArtist(); break;
        case 3: *reinterpret_cast<QImage*>(_v) = _t->getCoverArt(); break;
        case 4: *reinterpret_cast<qint64*>(_v) = _t->position(); break;
        case 5: *reinterpret_cast<qint64*>(_v) = _t->duration(); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->isShuffle(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 4: _t->setPosition(*reinterpret_cast<qint64*>(_v)); break;
        case 6: _t->setShuffle(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *MusicLoad::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MusicLoad::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9MusicLoadE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MusicLoad::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void MusicLoad::musicLoadDone(const QStringList & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void MusicLoad::isPlayingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MusicLoad::titleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MusicLoad::artistChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MusicLoad::coverArtChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MusicLoad::positionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void MusicLoad::durationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void MusicLoad::shuffleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
