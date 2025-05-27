#include "about_dialog.h"

#include <QPixmap>

#include "ui_about_dialog.h"

#ifdef APP_VERSION
#define VERSION APP_VERSION
#else
#define VERSION "0.0.0"
#endif

AboutDialog::AboutDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::AboutDialog) {
  ui->setupUi(this);

  int w = ui->app_icon_label->width();
  int h = ui->app_icon_label->height();
  QIcon icon("MakePlayList.ico");
  QPixmap pixmap = icon.pixmap(w, h);
  ui->app_icon_label->setPixmap(pixmap);

  ui->versionLineEdit->setText(VERSION);
}

AboutDialog::~AboutDialog() { delete ui; }

void AboutDialog::accept() {
  close();
  return;
}
