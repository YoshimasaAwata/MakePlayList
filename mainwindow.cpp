#include "mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>

#include "about_dialog.h"
#include "plsfiles.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setWindowIcon(QIcon("MakePlayList.ico"));
  connect(ui->fileListWidget, SIGNAL(SetFile(QString)), ui->fileNameLineEdit,
          SLOT(setText(QString)));
  connect(ui->fileListWidget, SIGNAL(SetFolder(QString)), ui->folderLineEdit,
          SLOT(setText(QString)));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::CreatePLSFile() {
  auto folder = ui->folderLineEdit->text();
  auto file = ui->fileNameLineEdit->text();
  PLSFiles plsfile(folder, file);
  auto rc = plsfile.CheckFileExist();
  if (rc) {
    auto msg_btn =
        QMessageBox::question(this, tr("上書きの確認"),
                              tr("ファイルが既に存在します\n上書きしますか？"));
    rc = (msg_btn == QMessageBox::Yes) ? false : true;
  }
  if (!rc) {
    rc = plsfile.OutPLSFile(ui->fileListWidget);
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

void MainWindow::ShowAboutDialog() {
  AboutDialog dialog;
  dialog.exec();
  return;
}
