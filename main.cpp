#include <QApplication>
#include <QFile>

#include "mainwindow.h"

/**
 * @brief アプリケーションのスタイルシートの読み込み
 * @param[in] a アプリケーション
 */
void LoadStyleSheet(QApplication& a) {
  QFile file("MakePlayList.qss");
  auto rc = file.open(QIODevice::ReadOnly | QIODevice::Text);
  if (rc) {
    QTextStream stream(&file);
    QString styleSheet = stream.readAll();
    a.setStyleSheet(styleSheet);
    file.close();
  }
  return;
}

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  a.setApplicationVersion(APP_VERSION);
  // LoadStyleSheet(a);
  MainWindow w;
  w.show();
  return a.exec();
}
