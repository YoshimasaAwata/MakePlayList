#ifndef PLSFILES_H
#define PLSFILES_H

#include <QLineEdit>
#include <QListWidget>
#include <QObject>

/**
 * @brief PLSファイルの内容の管理と出力
 */
class PLSFiles {
 private:
  QString folder_;  ///< PLSファイルを格納するフォルダ
  QString file_;    ///< PLSファイル名(拡張子なし)

 public:
  /**
   * @brief コンストラクタ
   * @param[in] folder PLSファイルの出力先フォルダ
   * @param[in] file PLSファイル名(拡張子なし)
   */
  PLSFiles(const QString& folder, const QString& file)
      : folder_(folder), file_(file) {}

  // Getter / Setter
  const QString& Folder() const { return folder_; };
  void setFolder(const QString& folder) { folder_ = folder; };
  const QString& File() const { return file_; };
  void setFile(const QString& file) { file_ = file; };

  /**
   * @brief PLSファイルを格納するフォルダを直接変更
   * @details UIのfolderLineEditの内容を変更
   * @param folder フォルダ名
   * @param force フォルダの変更を強制
   */
  // virtual void ChangeFolder(const QString& folder, bool force = false);

  /**
   * @brief PLSファイル名を直接変更
   * @details ファイル名には拡張子を付けない<br>
   *          UIのfileNameLineEditの内容を変更
   * @param file ファイル名
   * @param force ファイルの変更を強制
   */
  // virtual void ChangeFile(const QString& file, bool force = false);

  /**
   * @brief PLSファイル出力
   * @param plist ファイルリスト
   * @return ファイル出力の成否
   * @retval true 出力成功
   * @retval false 出力失敗
   */
  virtual bool OutPLSFile(const QListWidget* plist) const;

  /**
   * @brief PLSファイルが存在するかどうかのチェック
   * @return PLSファイルが存在するかどうか
   * @retval trua 存在する
   * @retval false 存在しない
   */
  virtual bool CheckFileExist() const;

 protected:
  /**
   * @brief 実際のプレイリストをファイルに出力
   * @param stream ファイルに出力するためのストリーム
   * @param plist ファイルリスト
   * @return 出力されたリストの数
   */
  virtual int OutPlayList(QTextStream& stream, const QListWidget* plist) const;

  /**
   * @brief PLSファイル名の絶対パスを取得
   * @return PLSファイル名の絶対パス
   */
  virtual QString GetAbsoludePath() const;

  static const QString kExt;      ///< PLSファイルの拡張子
  static const QString kHeader;   ///< PLSファイルのヘッダー
  static const QString kNumber;   ///< PLSファイルのリスト数
  static const QString kVersion;  ///< PLSファイルのバージョン
  static const QString kFile;     ///< PLSファイルのファイル指定
  static const QString kTitle;    ///< PLSファイルのタイトル指定
  static const QString kLength;   ///< PLSファイルの長さ指定
};

#endif  // PLSFILES_H
