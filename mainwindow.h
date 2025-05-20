#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 private:
  // PLSFiles plsfiles_;  ///< PLSファイルの管理、出力

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  // PLSFiles &PLSfiles() { return plsfiles_; }
  // void setPlsfiles(const PLSFiles &newPlsfiles) { plsfiles_ = newPlsfiles; }

 protected:
  /**
   * @brief Up, Down, Removeボタンの有効化 / 無効化
   */
  // void EnableButtons();

  /**
   * @brief リストボックス中のアイテム数に応じてクリアボタンを有効化 / 無効化
   */
  // void EnableCreateClearButton();

 private slots:
  /**
   * @brief クローズボタンのクリックでアプリケーションの終了
   */
  //  void on_closeButton_clicked();

  /**
   * @brief
   * オープンダイアログでPLSファイルの出力フォルダを指定し、フォルダ内のファイルをリストに追加
   */
  // void on_addButton_clicked();

  /**
   * @brief オープンダイアログでPLSファイルの出力フォルダを指定
   */
  // void on_folderButton_clicked();

  /**
   * @brief ファイル名を編集したことを通知
   */
  // void on_fileNameLineEdit_editingFinished();

  /**
   * @brief PLSファイル生成ボタンクリック
   */
  void CreatePLSFile();
  // void on_createPushButton_clicked();

  /**
   * @brief ファイルリストで選択が変化した場合
   * @details 選択されていればUp, Down, Removeボタンを有効化
   * @details 選択されていなければUp, Down, Removeボタンを無効化
   */
  // void on_fileListWidget_itemSelectionChanged();

  // /**
  //  * @brief クリアボタンクリックで全リストアイテム削除
  //  * @details クリアするかどうかのダイアログ表示
  //  */
  // void on_clearButton_clicked();

  // /**
  //  * @brief リムーブボタンクリックで選択したアイテム削除
  //  * @details 削除するかどうかのダイアログ表示
  //  */
  // void on_removeButton_clicked();

  // /**
  //  * @brief アップボタンクリックで選択アイテムを1つアップ
  //  */
  // void on_upButton_clicked();

  // /**
  //  * @brief ダウンボタンクリックで選択アイテムを1つダウン
  //  */
  // void on_downButton_clicked();

 private:
  Ui::MainWindow *ui;
};
#endif  // MAINWINDOW_H
