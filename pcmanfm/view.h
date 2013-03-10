/*

    Copyright (C) 2013  Hong Jen Yee (PCMan) <pcman.tw@gmail.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/


#ifndef PCMANFM_FOLDERVIEW_H
#define PCMANFM_FOLDERVIEW_H

#include "folderview.h"
#include "filemenu.h"
#include "foldermenu.h"

namespace PCManFM {

class Settings;

class View : public Fm::FolderView {
Q_OBJECT
public:

  enum OpenDirTargetType {
    OpenInCurrentView,
    OpenInNewWindow,
    OpenInNewTab
  };

  explicit View(Fm::FolderView::ViewMode _mode = IconMode, QWidget* parent = 0);
  virtual ~View();

  void updateFromSettings(Settings& settings);

Q_SIGNALS:
  void openDirRequested(FmPath* path, int target);

protected Q_SLOTS:
  void onFileClicked(int type, FmFileInfo* fileInfo);
  void onPopupMenuHide();

  virtual void prepareFileMenu(Fm::FileMenu* menu);
  virtual void prepareFolderMenu(Fm::FolderMenu* menu);

private:
  
};

};
#endif // PCMANFM_FOLDERVIEW_H
