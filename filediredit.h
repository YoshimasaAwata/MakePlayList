#ifndef FILEDIREDIT_H
#define FILEDIREDIT_H

#include <QLineEdit>

/**
 * @brief PLSファイルの出力フォルダやファイル名の指定
 */
class FileDirEdit : public QLineEdit {
  Q_OBJECT

 private:
  bool specified_ = false;  ///< PLSファイルやフォルダが直接指定された

 public:
  FileDirEdit(QWidget* parent = nullptr) : QLineEdit(parent) {};

  bool Specified() const { return specified_; }
  void setSpecified(bool newSpecified) { specified_ = newSpecified; }

 public slots:
  /**
   * @brief エディットエリアにフォルダもしくはファイル名をセット
   * @details オーバーライド
   * @param[in] name フォルダもしくはファイル名
   */
  void setText(const QString& name);

  /**
   * @brief エディットエリアにフォルダもしくはファイル名を強制的にセット
   * @param[in] name フォルダもしくはファイル名
   */
  void ForceSetText(const QString& name);

  /**
   * @brief エディットエリアにフォルダもしくはファイル名を強制的にセット
   */
  void TextSpecified();

  /**
   * @brief オープンダイアログでPLSファイルの出力フォルダを指定
   */
  void SetFolder();

 signals:
  /**
   * @brief ステータスバーにメッセージを表示するためのシグナル
   * @param text 表示するテキスト
   */
  void Message2StatusBar(QString text);

  /**
   * @brief PLSファイルを作成するファイルの名前を設定
   * @param name ファイル名
   */
  void SetFile(const QString& name);
};

#endif  // FILEDIREDIT_H
