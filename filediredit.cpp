#include "filediredit.h"

#include <QFileDialog>

void FileDirEdit::setText(const QString& name) {
  if (!Specified()) {
    QLineEdit::setText(name);
  }
  return;
}

void FileDirEdit::ForceSetText(const QString& name) {
  QLineEdit::setText(name);
  setSpecified(true);
  setStyleSheet("background-color: #FFEEFF;");
  return;
}

void FileDirEdit::TextSpecified() {
  setSpecified(true);
  setStyleSheet("background-color: #FFEEFF;");
  emit Message2StatusBar(tr("出力先ファイル名を指定しました"));
  return;
}

void FileDirEdit::SetFolder() {
  auto dir_name = QFileDialog::getExistingDirectory(this, tr("フォルダの選択"));
  if (!dir_name.isEmpty()) {
    QDir dir(dir_name);
    ForceSetText(dir.path());
    emit SetFile(dir.dirName());
    emit Message2StatusBar(tr("出力先フォルダを指定しました"));
  }
  return;
}
