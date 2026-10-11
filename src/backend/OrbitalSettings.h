#pragma once

#include <QDir>
#include <QSettings>
#include <QString>

namespace Orbital {

// Fixed settings file shared by the whole app. systemd services get no $HOME,
// so QSettings' default (user) scope silently fails to persist there - an
// explicit path has no such dependency. First fixed in DisplayBackend; the
// plugin API and the terminal now use the same store so their settings stop
// resetting on every boot.
inline constexpr auto kSettingsFilePath = "/etc/orbital/Orbital.conf";

inline QSettings settings()
{
    QDir().mkpath(QStringLiteral("/etc/orbital"));
    return QSettings(QString::fromLatin1(kSettingsFilePath), QSettings::IniFormat);
}

} // namespace Orbital
