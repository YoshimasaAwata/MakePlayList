#include "mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  GetPLSFiles().Folder(ui->folderLineEdit);
  GetPLSFiles().File(ui->fileNameLineEdit);
}

MainWindow::~MainWindow() { delete ui; }

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
  }
  return;
}

void MainWindow::on_folderButton_clicked() {
  auto dir_name = QFileDialog::getExistingDirectory(this, tr("フォルダの選択"));
  if (!dir_name.isEmpty()) {
    QDir dir(dir_name);
    GetPLSFiles().ChangeFolder(dir.path(), true);
    GetPLSFiles().ChangeFile(dir.dirName());
  }
  return;
}

void MainWindow::on_fileNameLineEdit_editingFinished() {
  GetPLSFiles().FileSpecified(true);
  return;
}

void MainWindow::on_createPushButton_clicked() {
  auto rc = GetPLSFiles().CheckFileExist();
  if (rc) {
    auto msg_btn =
        QMessageBox::question(this, tr("上書きの確認"),
                              tr("ファイルが既に存在します\n上書きしますか"));
    rc = (msg_btn == QMessageBox::Yes) ? false : true;
  }
  if (!rc) {
    rc = GetPLSFiles().OutPLSFile(ui->fileListWidget);
    if (rc) {
      QMessageBox::about(this, tr("PLSファイル"), tr("ファイル出力成功"));
    } else {
      QMessageBox::about(this, tr("PLSファイル"), tr("ファイル出力成功"));
    }
  }
  return;
}
