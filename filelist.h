#ifndef FILELIST_H
#define FILELIST_H

#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QDragMoveEvent>
#include <QFileInfo>
#include <QListWidget>

/**
 * @brief 動画ファイルのリストの管理
 * @details リストの表示もおこなう
 */
class FileList : public QListWidget {
  Q_OBJECT

 protected:
  /**
   * @brief ファイルがリストに含まれているか
   * @param[in] file_info チェックするファイルの情報
   * @return ファイルがリストに含まれているか
   * @retval true ファイルがリストに含まれている
   * @retval false ファイルがリストに含まれていない
   */
  virtual bool ContainsFile(QFileInfo& file_info);

  /**
   * @brief Up, Down, Removeボタンの有効化 / 無効化
   */
  virtual void EnableButtons();

  /**
   * @brief リストボックス中のアイテム数に応じてクリアボタンを有効化 / 無効化
   */
  virtual void EnableCreateClearButton();

  /**
   * @brief 選択アイテムをアップ、ダウン
   * @param[in] updown アップ(true)するかダウン(false)するかの指示
   */
  virtual void UpDownSelected(bool updown);

  /**
   * @brief ドラッグしながら領域に入った時の動作
   * @details ドロップを許可して背景色を変化させる
   * @param pevent
   */
  virtual void dragEnterEvent(QDragEnterEvent* pevent) override;

  /**
   * @brief ドラッグしながら領域を移動する時の動作
   * @details ドロップを許可
   * @param pevent
   */
  virtual void dragMoveEvent(QDragMoveEvent* pevent) override;

  /**
   * @brief ドラッグしながら領域から出た時の動作
   * @details 背景色を戻す
   * @param pevent
   */
  virtual void dragLeaveEvent(QDragLeaveEvent* pevent) override;

  /**
   * @brief ドロップ時の動作
   * @details ドロップアイテムが動画のファイルやフォルダならリストに追加
   * @param pevent
   */
  virtual void dropEvent(QDropEvent* pevent) override;

 public:
  FileList(QWidget* parent = nullptr);

  /**
   * @brief ファイルをリストに追加
   * @param file_info 追加するファイルの情報
   */
  virtual void AddFile(QFileInfo& file_info);

  /**
   * @brief 指定のディレクトリ中のファイルをリストに追加
   * @param dir ディレクトリ
   */
  virtual void AddFilesInDir(QDir& dir);

 public slots:
  /**
   * @brief
   * オープンダイアログでPLSファイルの出力フォルダを指定し、フォルダ内のファイルをリストに追加
   */
  void AddFiles();

  /**
   * @brief 確認後、リストのクリア
   * @details QListWidget::clear()のオーバーライド
   */
  void clear();

  /**
   * @brief 選択したアイテム削除
   * @details 削除するかどうかのダイアログ表示
   */
  void RemoveSelected();

  /**
   * @brief 選択アイテムを1つアップ
   */
  void UpSelected() { UpDownSelected(true); };

  /**
   * @brief 選択アイテムを1つダウン
   */
  void DownSelected() { UpDownSelected(false); };

  /**
   * @brief アイテム選択に変更があったときにボタンの有効/無効を切り替える
   */
  void ItemsSelectChanged() { EnableButtons(); }

 signals:
  /**
   * @brief ステータスバーにメッセージを表示するためのシグナル
   * @param text 表示するテキスト
   */
  void Message2StatusBar(QString text);

  /**
   * @brief ボタンの有効/無効の指定のシグナル
   * @param enable 有効(true)か無効(false)か
   */
  void ButtonEnabled(bool enable);

  /**
   * @brief Removeボタンの有効/無効の指定のシグナル
   * @param enable 有効(true)か無効(false)か
   */
  void RemoveEnabled(bool enable);

  /**
   * @brief Upボタンの有効/無効の指定のシグナル
   * @param enable 有効(true)か無効(false)か
   */
  void UpEnabled(bool enable);

  /**
   * @brief Downボタンの有効/無効の指定のシグナル
   * @param enable 有効(true)か無効(false)か
   */
  void DownEnabled(bool enable);

  /**
   * @brief PLSファイルを作成するフォルダの名前を設定
   * @param name フォルダ名
   */
  void SetFolder(const QString& name);

  /**
   * @brief PLSファイルを作成するファイルの名前を設定
   * @param name ファイル名
   */
  void SetFile(const QString& name);

 public:
  static const QStringList kVideoFilter;  ///< ビデオファイルのフィルタ
};

#endif  // FILELIST_H
