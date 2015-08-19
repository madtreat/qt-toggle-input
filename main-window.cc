
#include "main-window.hh"

#include <QWidget>
#include <QHBoxLayout>

#include "toggle-input.hh"

MainWindow::MainWindow(QWidget* w) : QMainWindow(w), tabSelector(this) {


  buildHorizontalTwoPoleTab();
  buildHorizontalThreePoleTab();

  resize(400, 200);
  setCentralWidget( &tabSelector );

  setWindowTitle( "Toggle switch demo" );

  show();
}

void MainWindow::buildHorizontalThreePoleTab() {

  QWidget *w = new QWidget;

  QHBoxLayout *l = new QHBoxLayout( w );

  ti_1 = new ToggleInput(w);
  ti_2 = new ToggleInput(w);
  ti_3 = new ToggleInput(w);
  ti_4 = new ToggleInput(w);

  l->addWidget(ti_1, 1);
  l->addWidget(ti_2, 1);
  l->addWidget(ti_3, 1);
  l->addWidget(ti_4, 1);

  ti_1->setMode( true,  true,  true );
  ti_2->setMode( true, false,  true );
  ti_3->setMode( true,  true, false );
  ti_4->setMode( true, false, false );

  w->setLayout( l );

  tabSelector.addTab( w, "Three Pole" );

}

void MainWindow::buildHorizontalTwoPoleTab() {

  QWidget *w = new QWidget;

  QHBoxLayout *l = new QHBoxLayout( w );

  ti_5 = new ToggleInput(w);
  ti_6 = new ToggleInput(w);
  ti_7 = new ToggleInput(w);

  l->addWidget(ti_5);
  l->addWidget(ti_6);
  l->addWidget(ti_7);

  ti_5->setMode( false,  true,  true );
  ti_6->setMode( false, false,  true );
  ti_7->setMode( false,  true, false );

  w->setLayout( l );

  tabSelector.addTab( w, "Two Pole" );
}

void MainWindow::toggleChanged(ToggleInput *ti) {

}

