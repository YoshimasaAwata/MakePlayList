#include "filelist.h"

#include <qdir.h>

#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>

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

void FileList::EnableButtons() {
  auto list = selectedItems();
  bool remove_enable = false;
  bool up_enable = false;
  bool down_enable = false;
  if (!list.isEmpty()) {
    auto first_item = list.at(0);
    auto last_item = list.at(list.size() - 1);
    auto first_idx = row(first_item);
    auto last_idx = row(last_item);
    remove_enable = true;
    up_enable = first_idx > 0;
    down_enable = last_idx < (count() - 1);
  }
  emit RemoveEnabled(remove_enable);
  emit UpEnabled(up_enable);
  emit DownEnabled(down_enable);
  return;
}

void FileList::EnableCreateClearButton() {
  auto num = count();
  bool enable = num > 0;
  emit ButtonEnabled(enable);
  return;
}

void FileList::UpDownSelected(bool updown) {
  auto list = selectedItems();
  auto first_item = list.at(0);
  auto last_item = list.at(list.size() - 1);
  auto first_idx = row(first_item);
  auto last_idx = row(last_item);
  auto remove_idx = updown ? (first_idx - 1) : (last_idx + 1);
  auto insert_idx = updown ? last_idx : first_idx;
  auto move_item = takeItem(remove_idx);
  insertItem(insert_idx, move_item);
  emit Message2StatusBar(tr("選択したファイルを移動しました"));
  EnableButtons();
  return;
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

void FileList::AddFiles() {
  auto dir_name = QFileDialog::getExistingDirectory(this, tr("フォルダの選択"));
  if (!dir_name.isEmpty()) {
    QDir dir(dir_name);
    AddFilesInDir(dir);
    emit SetFolder(dir.path());
    emit SetFile(dir.dirName());
    emit Message2StatusBar(tr("ファイルの追加に成功しました"));
  }
  EnableCreateClearButton();
  return;
}

void FileList::clear() {
  auto yes_no = QMessageBox::question(this, tr("アイテムクリア"),
                                      tr("全てのファイルを削除しますか？"));
  if (yes_no == QMessageBox::Yes) {
    QListWidget::clear();
    emit Message2StatusBar(tr("ファイルを全て削除しました"));
  }
  EnableCreateClearButton();
  return;
}

void FileList::RemoveSelected() {
  auto yes_no = QMessageBox::question(this, tr("選択アイテムクリア"),
                                      tr("選択したファイルを削除しますか？"));
  if (yes_no == QMessageBox::Yes) {
    auto list = selectedItems();
    foreach (auto item, list) {
      auto idx = row(item);
      auto removed = takeItem(idx);
      delete removed;
    }
    emit Message2StatusBar(tr("選択したファイルを削除しました"));
  }
  EnableCreateClearButton();
  EnableButtons();
  return;
}
