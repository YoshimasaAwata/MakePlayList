#include "mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setWindowIcon(QIcon(":/MakePlayList.ico"));
  GetPLSFiles().Folder(ui->folderLineEdit);
  GetPLSFiles().File(ui->fileNameLineEdit);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::EnableButtons(bool enable) {
  ui->upButton->setEnabled(enable);
  ui->downButton->setEnabled(enable);
  ui->removeButton->setEnabled(enable);
  return;
}

void MainWindow::EnableClearButton() {
  auto num = ui->fileListWidget->count();
  ui->clearButton->setEnabled(num > 0);
  return;
}

void MainWindow::on_closeButton_clicked() {
  close();
  return;
}

void MainWindow::on_addButton_clicked() {
  auto dir_name = QFileDialog::getExistingDirectory(this, tr("フォルダの選択"));
  if (!dir_name.isEmpty()) {
    QDir dir(dir_name);
    ui->fileListWidget->AddFilesInDir(dir);
    GetPLSFiles().ChangeFolder(dir.path());
    GetPLSFiles().ChangeFile(dir.dirName());
    ui->statusbar->showMessage(tr("ファイルの追加に成功しました"));
  }
  EnableClearButton();
  return;
}

void MainWindow::on_folderButton_clicked() {
  auto dir_name = QFileDialog::getExistingDirectory(this, tr("フォルダの選択"));
  if (!dir_name.isEmpty()) {
    QDir dir(dir_name);
    GetPLSFiles().ChangeFolder(dir.path(), true);
    GetPLSFiles().ChangeFile(dir.dirName());
    ui->statusbar->showMessage(tr("出力先フォルダを指定しました"));
  }
  return;
}

void MainWindow::on_fileNameLineEdit_editingFinished() {
  GetPLSFiles().FileSpecified(true);
  ui->statusbar->showMessage(tr("出力ファイル名を指定しました"));
  return;
}

void MainWindow::on_createPushButton_clicked() {
  auto rc = GetPLSFiles().CheckFileExist();
  if (rc) {
    auto msg_btn =
        QMessageBox::question(this, tr("上書きの確認"),
                              tr("ファイルが既に存在します\n上書きしますか？"));
    rc = (msg_btn == QMessageBox::Yes) ? false : true;
  }
  if (!rc) {
    rc = GetPLSFiles().OutPLSFile(ui->fileListWidget);
    if (rc) {
      auto msg = tr("ファイル出力成功");
      QMessageBox::about(this, tr("PLSファイル"), msg);
      ui->statusbar->showMessage(msg);
    } else {
      auto msg = tr("ファイル出力失敗");
      QMessageBox::about(this, tr("PLSファイル"), msg);
      ui->statusbar->showMessage(msg);
    }
  }
  return;
}

void MainWindow::on_fileListWidget_itemSelectionChanged() {
  auto items = ui->fileListWidget->selectedItems();
  EnableButtons(!items.isEmpty());
  return;
}

void MainWindow::on_clearButton_clicked() {
  auto yes_no = QMessageBox::question(this, tr("アイテムクリア"),
                                      tr("全てのファイルを削除しますか？"));
  if (yes_no == QMessageBox::Yes) {
    ui->fileListWidget->clear();
    ui->statusbar->showMessage(tr("ファイルを全て削除しました"));
  }
  EnableClearButton();
  return;
}

void MainWindow::on_removeButton_clicked() {
  auto yes_no = QMessageBox::question(this, tr("選択アイテムクリア"),
                                      tr("選択したファイルを削除しますか？"));
  if (yes_no == QMessageBox::Yes) {
    auto list = ui->fileListWidget->selectedItems();
    foreach (auto item, list) {
      auto idx = ui->fileListWidget->row(item);
      auto removed = ui->fileListWidget->takeItem(idx);
      delete removed;
    }
    ui->statusbar->showMessage(tr("選択したファイルを削除しました"));
  }
  EnableClearButton();
  return;
}
