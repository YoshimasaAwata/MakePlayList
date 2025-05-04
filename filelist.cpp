#include "filelist.h"

#include <qdir.h>

#include <QFileInfo>

void FileList::AddFile(QString& file_name) {
  QFileInfo file_info(file_name);
  auto ext = file_info.suffix().toLower();
  if ((video_ext_.contains(ext)) && file_info.isFile()) {
    auto name = file_info.fileName();
    auto pitem = new QListWidgetItem(name);
    pitem->setToolTip(file_name);
    addItem(pitem);
  }
  return;
}

void FileList::AddFilesInDir(QString& dir) {
  QDir dir_info(dir);
  auto file_list = dir_info.entryList();
  foreach (auto file, file_list) {
    AddFile(file);
  }
}
