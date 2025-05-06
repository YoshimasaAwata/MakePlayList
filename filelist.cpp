#include "filelist.h"

#include <qdir.h>

#include <QFileInfo>

const QStringList FileList::kVideoFilter = {"*.mp4",  "*.ts2", "*.avi",
                                            "*.mov",  "*.wmv", "*.flv",
                                            "*.webm", "*.mpg", "*.mkv"};

bool FileList::ContainsFile(QFileInfo& file_info) {
  bool exist = false;
  auto name = file_info.fileName();
  auto file_list =
      findItems(name, Qt::MatchFixedString | Qt::MatchCaseSensitive);
  foreach (auto file, file_list) {
    auto result =
        QString::compare(file->toolTip(), file_info.absoluteFilePath());
    if (result == 0) {
      exist = true;
    }
  }
  return exist;
}

void FileList::AddFile(QFileInfo& file_info) {
  auto exist = ContainsFile(file_info);
  if (!exist) {
    auto name = file_info.fileName();
    auto pitem = new QListWidgetItem(name);
    auto full_path = file_info.absoluteFilePath();
    pitem->setToolTip(full_path);
    addItem(pitem);
  }
  return;
}

void FileList::AddFilesInDir(QDir& dir) {
  auto file_list =
      dir.entryInfoList(kVideoFilter, QDir::Files | QDir::NoDotAndDotDot);
  foreach (auto file, file_list) {
    AddFile(file);
  }
}
