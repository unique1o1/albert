// albert - a simple application launcher for linux
// Copyright (C) 2014-2015 Manuel Schneider
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <QDesktopServices>
#include "bookmark.h"
#include "albertapp.h"


/** ***************************************************************************/
QString ChromeBookmarks::Bookmark::text() const {
    return name_;
}



/** ***************************************************************************/
QString ChromeBookmarks::Bookmark::subtext() const {
    return url_;
}



/** ***************************************************************************/
QUrl ChromeBookmarks::Bookmark::icon() const {
    return QUrl("qrc:favicon");
}



/** ***************************************************************************/
void ChromeBookmarks::Bookmark::activate() {
    qApp->hideMainWindow();
    QDesktopServices::openUrl(QUrl(url_));
    ++usage_;
}



/** ***************************************************************************/
vector<QString> ChromeBookmarks::Bookmark::aliases() const {
    return std::vector<QString>({name_});
}