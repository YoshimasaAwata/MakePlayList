#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "plsfiles.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  PLSFiles plsfiles_;  ///< PLSファイルの管理、出力
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  /**
   * @brief クローズボタンのクリックでアプリケーションの終了
   */
  void on_closeButton_clicked();

  /**
   * @brief
   * オープンダイアログでPLSファイルの出力フォルダを指定し、フォルダ内のファイルをリストに追加
   */
  void on_addButton_clicked();

  /**
   * @brief オープンダイアログでPLSファイルの出力フォルダを指定
   */
  void on_folderButton_clicked();

  /**
   * @brief ファイル名を編集したことを通知
   */
  void on_fileNameLineEdit_editingFinished();

  /**
   * @brief PLSファイル生成ボタンクリック
   */
  void on_createPushButton_clicked();

 private:
  Ui::MainWindow *ui;
};
#endif  // MAINWINDOW_H
