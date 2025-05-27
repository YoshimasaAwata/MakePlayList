#ifndef ABOUT_DIALOG_H
#define ABOUT_DIALOG_H

#include <QDialog>

namespace Ui {
class AboutDialog;
}

class AboutDialog : public QDialog {
  Q_OBJECT

 public:
  explicit AboutDialog(QWidget *parent = nullptr);
  ~AboutDialog();

 public slots:
  /**
   * @brief OKがクリックされた時の動作
   */
  virtual void accept() override;

 private:
  Ui::AboutDialog *ui;
};

#endif  // ABOUT_DIALOG_H
