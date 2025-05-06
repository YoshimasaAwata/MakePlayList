#ifndef PLSFILES_H
#define PLSFILES_H

#include <QLineEdit>
#include <QObject>

/**
 * @brief PLSファイルの内容の管理と出力
 */
class PLSFiles {
  QLineEdit* pfolder_;             ///< PLSファイルを格納するフォルダ
  bool folder_specified_ = false;  ///< PLSファイルを格納するフォルダの指定
  QLineEdit* pfile_;               ///< PLSファイル名(拡張子なし)
  bool file_specified_ = false;    ///< PLSファイル名を指定

 public:
  PLSFiles() {}

  // Getter / Setter
  QLineEdit* Folder() const { return pfolder_; };
  void Folder(QLineEdit* pfolder) { pfolder_ = pfolder; };
  QLineEdit* File() const { return pfile_; };
  void File(QLineEdit* pfile) { pfile_ = pfile; };
  bool FolderSpecified() const { return folder_specified_; };
  void FolderSpecified(bool folder_specified) {
    folder_specified_ = folder_specified;
  };
  bool FileSpecified() const { return file_specified_; };
  void FileSpecified(bool file_specified) { file_specified_ = file_specified; };

  /**
   * @brief PLSファイルを格納するフォルダを直接変更
   * @details UIのfolderLineEditの内容を変更
   * @param folder フォルダ名
   * @param force フォルダの変更を強制
   */
  void ChangeFolder(const QString& folder, bool force = false);

  /**
   * @brief PLSファイル名を直接変更
   * @details ファイル名には拡張子を付けない<br>
   *          UIのfileNameLineEditの内容を変更
   * @param file ファイル名
   * @param force ファイルの変更を強制
   */
  void ChangeFile(const QString& file, bool force = false);

  static const QString ext_;  ///< PLSファイルの拡張子
};

#endif  // PLSFILES_H
