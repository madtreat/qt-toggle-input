
#ifndef _IK_MAINWINDOW_INC_
#define _IK_MAINWINDOW_INC_

#include <QtGui>
#include "toggle-input.hh"

class MainWindow : public QMainWindow {
  
  Q_OBJECT

private:

  // three pole
  ToggleInput *ti_1;
  ToggleInput *ti_2;
  ToggleInput *ti_3;
  ToggleInput *ti_4;

  // two pole
  ToggleInput *ti_5;
  ToggleInput *ti_6;
  ToggleInput *ti_7;

  QTabWidget tabSelector;
  //QHBoxLayout *threePoleLayout;

  void buildHorizontalThreePoleTab();
  void buildHorizontalTwoPoleTab();


public:

  MainWindow(QWidget *w = NULL);

public slots:

  void toggleChanged(ToggleInput *);
};

#endif /* _IK_MAINWINDOW_INC_ */

