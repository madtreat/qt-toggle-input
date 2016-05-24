
#include "toggle-input.hh"

#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

QPixmap *ToggleInput::s_centerImage = NULL;
QPixmap *ToggleInput::s_upImage     = NULL;
QPixmap *ToggleInput::s_downImage   = NULL;


ToggleInput::ToggleInput(QWidget* parent)
: QWidget(parent),
m_defaultPosition(POS_UP),
m_threePole(false),
m_topLock(false),
m_bottomLock(false) {

  Q_INIT_RESOURCE(qt_toggle_input);
  
  if(!s_centerImage) 
    s_centerImage = new QPixmap(":/toggle-input/png/toggle-center.png");

  if(!s_upImage) 
    s_upImage = new QPixmap(":/toggle-input/png/toggle-up.png");

  if(!s_downImage) 
    s_downImage = new QPixmap(":/toggle-input/png/toggle-down.png");

  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  m_position = POS_UP;
}

void ToggleInput::mousePressEvent(QMouseEvent *e) {
  
  int mx = e->x();
  int my = e->y();
  int ww = width();
  int wh = height();

  if(mx < ww / 2 - 45) return;
  if(mx > ww / 2 + 45) return;
  if(my < wh / 2 - 60) return;
  if(my > wh / 2 + 60) return;


  if(m_threePole) {
    int offset = my - (wh / 2 - 60);

    if(offset < 40) m_position = POS_UP;
    else
      if(offset < 80) m_position = POS_CENTER;
      else
        m_position = POS_DOWN;

  } else {

    if(m_position == POS_UP)
      m_position = POS_DOWN;
    else
      if(m_position == POS_DOWN) 
        m_position = POS_UP;
  }

  update();

}

void ToggleInput::mouseReleaseEvent(QMouseEvent *e) {

  if(m_bottomLock == false && m_position == POS_DOWN) {
    m_position = m_defaultPosition;
  }
  if(m_topLock    == false && m_position == POS_UP  ) { 
    m_position = m_defaultPosition; 
  }

  update();

  emit positionChanged(m_position == POS_UP);
}

void ToggleInput::paintEvent(QPaintEvent*) {

  QPainter p(this);

  int px = width()/2 - DEFAULT_WIDTH/2;
  int py = height()/2 - DEFAULT_HEIGHT/2;

  switch(m_position) {
    case POS_UP:     p.drawPixmap( px, py, *s_upImage );     break;
    case POS_DOWN:   p.drawPixmap( px, py, *s_downImage );   break;
    case POS_CENTER: p.drawPixmap( px, py, *s_centerImage ); break;
  }
}

int ToggleInput::arm_position() {
  return m_position;
}

void ToggleInput::setMode(int threePole, int topLock, int bottomLock) {

  if(threePole == false) {
//    if(topLock == false && bottomLock == false)
//      qWarning() << "ToggleInput: cant have bi-pole mode with no locking positions";

    if(topLock == false) {
       m_defaultPosition = POS_DOWN;
       m_position = POS_DOWN;
    }
    if(bottomLock == false) {
      m_defaultPosition = POS_UP;
    }

  } else {
    m_defaultPosition = POS_CENTER;
    m_position = POS_CENTER;
  }

  m_threePole  = threePole;
  m_bottomLock = bottomLock;
  m_topLock    = topLock;
}

void ToggleInput::setPosition(bool up) {
   m_position = up ? POS_UP : POS_DOWN;
   update();
}

QSize ToggleInput::sizeHint() const {
  return QSize( DEFAULT_WIDTH, DEFAULT_HEIGHT );
}
