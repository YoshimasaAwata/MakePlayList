#include "mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>

#include "plsfiles.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setWindowIcon(QIcon(":/MakePlayList.ico"));
  // PLSFiles().setFolder(ui->folderLineEdit);
  // PLSFiles().setFile(ui->fileNameLineEdit);
  connect(ui->fileListWidget, SIGNAL(SetFile(QString)), ui->fileNameLineEdit,
          SLOT(setText(QString)));
  connect(ui->fileListWidget, SIGNAL(SetFolder(QString)), ui->folderLineEdit,
          SLOT(setText(QString)));
}

MainWindow::~MainWindow() { delete ui; }

// void MainWindow::EnableButtons() {
//   auto list = ui->fileListWidget->selectedItems();
//   bool remove_enable = false;
//   bool up_enable = false;
//   bool down_enable = false;
//   if (!list.isEmpty()) {
//     auto first_item = list.at(0);
//     auto last_item = list.at(list.size() - 1);
//     auto first_idx = ui->fileListWidget->row(first_item);
//     auto last_idx = ui->fileListWidget->row(last_item);
//     remove_enable = true;
//     up_enable = first_idx > 0;
//     down_enable = last_idx < (ui->fileListWidget->count() - 1);
//   }
//   ui->removeButton->setEnabled(remove_enable);
//   ui->upButton->setEnabled(up_enable);
//   ui->downButton->setEnabled(down_enable);
//   return;
// }

// void MainWindow::EnableCreateClearButton() {
//   auto num = ui->fileListWidget->count();
//   bool enable = num > 0;
//   ui->clearButton->setEnabled(enable);
//   ui->createPushButton->setEnabled(enable);
//   return;
// }

// void MainWindow::on_closeButton_clicked() {
//   close();
//   return;
// }

// void MainWindow::on_addButton_clicked() {
//   auto dir_name = QFileDialog::getExistingDirectory(this,
//   tr("フォルダの選択")); if (!dir_name.isEmpty()) {
//     QDir dir(dir_name);
//     ui->fileListWidget->AddFilesInDir(dir);
//     GetPLSFiles().ChangeFolder(dir.path());
//     GetPLSFiles().ChangeFile(dir.dirName());
//     ui->statusbar->showMessage(tr("ファイルの追加に成功しました"));
//   }
//   EnableCreateClearButton();
//   return;
// }

// void MainWindow::on_folderButton_clicked() {
//   auto dir_name = QFileDialog::getExistingDirectory(this,
//   tr("フォルダの選択")); if (!dir_name.isEmpty()) {
//     QDir dir(dir_name);
//     GetPLSFiles().ChangeFolder(dir.path(), true);
//     GetPLSFiles().ChangeFile(dir.dirName());
//     ui->statusbar->showMessage(tr("出力先フォルダを指定しました"));
//   }
//   return;
// }

// void MainWindow::on_fileNameLineEdit_editingFinished() {
//   GetPLSFiles().FileSpecified(true);
//   ui->statusbar->showMessage(tr("出力ファイル名を指定しました"));
//   return;
// }

// void MainWindow::on_createPushButton_clicked() {
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

// void MainWindow::on_fileListWidget_itemSelectionChanged() {
//   EnableButtons();
//   return;
// }

// void MainWindow::on_clearButton_clicked() {
//   auto yes_no = QMessageBox::question(this, tr("アイテムクリア"),
//                                       tr("全てのファイルを削除しますか？"));
//   if (yes_no == QMessageBox::Yes) {
//     ui->fileListWidget->clear();
//     ui->statusbar->showMessage(tr("ファイルを全て削除しました"));
//   }
//   EnableCreateClearButton();
//   return;
// }

// void MainWindow::on_removeButton_clicked() {
//   auto yes_no = QMessageBox::question(this, tr("選択アイテムクリア"),
//                                       tr("選択したファイルを削除しますか？"));
//   if (yes_no == QMessageBox::Yes) {
//     auto list = ui->fileListWidget->selectedItems();
//     foreach (auto item, list) {
//       auto idx = ui->fileListWidget->row(item);
//       auto removed = ui->fileListWidget->takeItem(idx);
//       delete removed;
//     }
//     ui->statusbar->showMessage(tr("選択したファイルを削除しました"));
//   }
//   EnableCreateClearButton();
//   EnableButtons();
//   return;
// }

// void MainWindow::on_upButton_clicked() {
//   auto list = ui->fileListWidget->selectedItems();
//   auto first_item = list.at(0);
//   auto last_item = list.at(list.size() - 1);
//   auto first_idx = ui->fileListWidget->row(first_item);
//   auto last_idx = ui->fileListWidget->row(last_item);
//   auto move_item = ui->fileListWidget->takeItem(first_idx - 1);
//   ui->fileListWidget->insertItem(last_idx, move_item);
//   ui->statusbar->showMessage(tr("選択したファイルを移動しました"));
//   EnableButtons();
//   return;
// }

// void MainWindow::on_downButton_clicked() {
//   auto list = ui->fileListWidget->selectedItems();
//   auto first_item = list.at(0);
//   auto last_item = list.at(list.size() - 1);
//   auto first_idx = ui->fileListWidget->row(first_item);
//   auto last_idx = ui->fileListWidget->row(last_item);
//   auto move_item = ui->fileListWidget->takeItem(last_idx + 1);
//   ui->fileListWidget->insertItem(first_idx, move_item);
//   ui->statusbar->showMessage(tr("選択したファイルを移動しました"));
//   EnableButtons();
//   return;
// }
