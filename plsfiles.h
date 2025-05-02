#ifndef PLSFILES_H
#define PLSFILES_H

#include <QObject>

/**
 * @brief PLSファイルの内容の管理と出力
 */
class PLSFiles {
  QString folder_name_ = "";            ///< PLSファイルを格納するフォルダ
  bool folder_name_specified_ = false;  ///< PLSファイルを格納するフォルダの指定
  QString file_name_ = "";              ///< PLSファイル名(拡張子なし)
  bool file_name_specified_ = false;    ///< PLSファイル名を指定

 public:
  PLSFiles();

  // Getter / Setter
  QString FolderName() const;
  void FolderName(const QString& new_folder_name);
  QString FileName() const;
  void FileName(const QString& new_file_name);
  bool FolderNameSpecified() const;
  void FolderNameSpecified(bool new_folder_name_specified);
  bool FileNameSpecified() const;
  void FileNameSpecified(bool new_file_name_specified);

  /**
   * @brief 指定したフォルダ内のファイルを追加
   * @details
   * フォルダが直接指定されていなければ、PLSファイルの格納フォルダをアップデート
   * また、ファイル名が直接指定されていなければ、PLSファイル名をフォルダ名にアップデート
   * フォルダ内のファイルは特定の動画ファイルのみを対象とする
   * @param new_folder フォルダ名
   * @return フォルダ名のアップデートがおこなわれた(true)
   */
  bool AddFolder(const QString& new_folder);

  /**
   * @brief PLSファイルを格納するフォルダを直接変更
   * @param new_folder フォルダ名
   */
  void ChangeFolderName(const QString& new_folder);

  /**
   * @brief PLSファイル名を直接変更
   * @details ファイル名には拡張子を付けない
   * @param new_file ファイル名
   */
  void ChangeFileName(const QString& new_file);
};

#endif  // PLSFILES_H
