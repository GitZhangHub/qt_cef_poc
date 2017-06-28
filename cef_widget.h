#ifndef QT_CEF_POC_CEFWIDGET_H_
#define QT_CEF_POC_CEFWIDGET_H_

#include <QtWidgets>
#include "include/cef_app.h"
#include "include/cef_browser.h"
#include "cef.h"

class CefWidget : public QWidget {
  Q_OBJECT
 public:
  CefWidget(Cef *cef, QWidget *parent = 0);
  ~CefWidget();

  void EmbedBrowser(QMainWindow *main_win,
                    QLineEdit *url_line_edit);
  void LoadUrl(const QString &url);

 protected:
  void moveEvent(QMoveEvent *event);
  void resizeEvent(QResizeEvent *event);

 private:
  void updateSize();

  Cef *cef_;
  CefRefPtr<CefBrowser> browser_;
};

#endif // QT_CEF_POC_CEFWIDGET_H_
