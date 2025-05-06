#ifndef FILELIST_H
#define FILELIST_H

#include <QFileInfo>
#include <QListWidget>

/**
 * @brief 動画ファイルのリストの管理
 * @details リストの表示もおこなう
 */
class FileList : public QListWidget {
 protected:
  /**
   * @brief ファイルがリストに含まれているか
   * @param file_info チェックするファイルの情報
   * @return ファイルがリストに含まれているか
   * @retval true ファイルがリストに含まれている
   * @retval false ファイルがリストに含まれていない
   */
  virtual bool ContainsFile(QFileInfo& file_info);

 public:
  FileList(QWidget* parent = nullptr) : QListWidget(parent) {};

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

  static const QStringList kVideoFilter;  ///< ビデオファイルのフィルタ
};

#endif  // FILELIST_H
