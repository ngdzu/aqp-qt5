/*
    Copyright (c) 2009-10 Qtrac Ltd. All rights reserved.

    This program or module is free software: you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation, either version 3 of
    the License, or (at your option) any later version. It is provided
    for educational purposes and is distributed in the hope that it will
    be useful, but WITHOUT ANY WARRANTY; without even the implied
    warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See
    the GNU General Public License for more details.
*/

#include "jingleaction.hpp"
#include <QSound>


bool JingleAction::s_mute = false;


JingleAction::JingleAction(const QString &jingleFile,
        const QString &text, QObject *parent)
    : QAction(text, parent)
{
    setJingleFile(jingleFile);
}


JingleAction::JingleAction(const QString &jingleFile,
        const QIcon &icon, const QString &text, QObject *parent)
    : QAction(icon, text, parent)
{
    setJingleFile(jingleFile);
}


void JingleAction::setJingleFile(const QString &jingleFile)
{
    if (!m_jingleFile.isEmpty())
        disconnect(this, SIGNAL(triggered(bool)), this, SLOT(play()));
    m_jingleFile = jingleFile;
    if (!m_jingleFile.isEmpty())
        connect(this, SIGNAL(triggered(bool)), this, SLOT(play()));
}


void JingleAction::play()
{
    if (!s_mute && !m_jingleFile.isEmpty())
        QSound::play(m_jingleFile);
}
