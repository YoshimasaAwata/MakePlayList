#include "mainwindow.h"

#include <QFileDialog>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  plsfiles_.Folder(ui->folderLineEdit);
  plsfiles_.File(ui->fileNameLineEdit);
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
    plsfiles_.ChangeFolder(dir.path());
    plsfiles_.ChangeFile(dir.dirName());
  }
  return;
}

void MainWindow::on_folderButton_clicked() {
  auto dir_name = QFileDialog::getExistingDirectory(this, tr("フォルダの選択"));
  if (!dir_name.isEmpty()) {
    QDir dir(dir_name);
    plsfiles_.ChangeFolder(dir.path(), true);
    plsfiles_.ChangeFile(dir.dirName());
  }
  return;
}

void MainWindow::on_fileNameLineEdit_editingFinished() {
  plsfiles_.FileSpecified(true);
  return;
}

void MainWindow::on_createPushButton_clicked() {}
