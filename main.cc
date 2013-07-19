
#include <QtGui>

#include "main-window.hh"

int main(int argc, char** argv) {
  QApplication a(argc, argv);

  MainWindow mw;
  
  return a.exec();
}

