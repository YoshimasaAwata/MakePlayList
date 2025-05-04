#ifndef FILELIST_H
#define FILELIST_H

#include <QListWidget>

/**
 * @brief 動画ファイルのリストの管理
 * @details リストの表示もおこなう
 */
class FileList : public QListWidget {
  QStringList video_ext_ = {"mp4", "ts2",  "avi", "mov", "wmv",
                            "flv", "webm", "mpg", "mkv"};

 public:
  FileList() : QListWidget() {};

  /**
   * @brief ファイルをリストに追加
   * @param file_name 追加するファイル名
   */
  virtual void AddFile(QString& file_name);

  /**
   * @brief 指定のディレクトリ中のファイルをリストに追加
   * @param dir ディレクトリ
   */
  virtual void AddFilesInDir(QString& dir);
};

#endif  // FILELIST_H
