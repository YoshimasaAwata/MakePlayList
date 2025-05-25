#include "plsfiles.h"

#include <QDir>
#include <QFile>

const QString PLSFiles::kExt(".pls");
const QString PLSFiles::kHeader("[playlist]");
const QString PLSFiles::kNumber("NumberOfEntries=");
const QString PLSFiles::kVersion("Version=2");
const QString PLSFiles::kFile("File");
const QString PLSFiles::kTitle("Title");
const QString PLSFiles::kLength("Length");

bool PLSFiles::OutPLSFile(const QListWidget* plist) const {
  auto pls_file_name = GetAbsoludePath();
  QFile pls_file(pls_file_name);
  auto rc = pls_file.open(QIODeviceBase::WriteOnly | QIODeviceBase::Text);
  if (rc) {
    QTextStream stream(&pls_file);
    stream << kHeader << "\n";
    auto num = OutPlayList(stream, plist);
    stream << kNumber << num << "\n";
    stream << kVersion << "\n";
    pls_file.close();
  }
  return rc;
}

QString PLSFiles::GetAbsoludePath() const {
  auto pls_file_name = Folder() + "/" + File() + kExt;
  return pls_file_name;
}

bool PLSFiles::CheckFileExist() const {
  auto pls_file_name = GetAbsoludePath();
  QFile file(pls_file_name);
  auto rc = file.exists();
  return rc;
}

int PLSFiles::OutPlayList(QTextStream& stream, const QListWidget* plist) const {
  QDir curr_dir(Folder());
  for (int i = 0; i < plist->count(); ++i) {
    auto pitem = plist->item(i);
    auto title = pitem->text();
    auto path = pitem->toolTip();
    auto relative = curr_dir.relativeFilePath(path);
    int idx = i + 1;
    stream << kFile << idx << "=" << relative << "\n";
    stream << kTitle << idx << "=" << title << "\n";
    stream << kLength << idx << "=-1\n";
  }
  return plist->count();
}
