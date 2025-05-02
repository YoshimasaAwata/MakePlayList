#include "mainwindow.h"

#include <QFileDialog>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_closeButton_clicked() {
  close();
  return;
}

void MainWindow::on_addButton_clicked() {
  auto dir = QFileDialog::getExistingDirectory(this, tr("フォルダの選択"));
  if (!dir.isEmpty()) {
    plsfiles_.F
  }
}
