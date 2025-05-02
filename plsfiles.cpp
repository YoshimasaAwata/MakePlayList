#include "plsfiles.h"

QString PLSFiles::FolderName() const { return folder_name_; }

void PLSFiles::FolderName(const QString& new_folder_name) {
  folder_name_ = new_folder_name;
}

QString PLSFiles::FileName() const { return file_name_; }

void PLSFiles::FileName(const QString& new_file_name) {
  file_name_ = new_file_name;
}

bool PLSFiles::FolderNameSpecified() const { return folder_name_specified_; }

void PLSFiles::FolderNameSpecified(bool new_folder_name_specified) {
  folder_name_specified_ = new_folder_name_specified;
}

bool PLSFiles::FileNameSpecified() const { return file_name_specified_; }

void PLSFiles::FileNameSpecified(bool new_file_name_specified) {
  file_name_specified_ = new_file_name_specified;
}

PLSFiles::PLSFiles() {}
