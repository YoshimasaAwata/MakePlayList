#include "plsfiles.h"

const QString PLSFiles::ext_(".pls");

void PLSFiles::ChangeFolder(const QString& folder, bool force) {
  if (force || !FolderSpecified()) {
    Folder()->setText(folder);
    FolderSpecified(force || FolderSpecified());
  }
  return;
}

void PLSFiles::ChangeFile(const QString& file, bool force) {
  if (force || !FileSpecified()) {
    File()->setText(file);
    FileSpecified(force || FileSpecified());
  }
  return;
}
