#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "plsfiles.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  PLSFiles plsfiles_; ///< PLSファイルの管理、出力
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
   * オープンダイアログでフォルダを指定し、フォルダ内のファイルをリストに追加
   */
  void on_addButton_clicked();

private:
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
