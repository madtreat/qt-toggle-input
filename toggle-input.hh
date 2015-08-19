
#ifndef _IK_TOGGLE_INPUT_INC_
#define _IK_TOGGLE_INPUT_INC_

#include <QWidget>
#include <QPixmap>


class ToggleInput : public QWidget {

  Q_OBJECT

private:

    enum {
      POS_UP,
      POS_CENTER,
      POS_DOWN
    };

    static QPixmap *s_centerImage;
    static QPixmap *s_upImage;
    static QPixmap *s_downImage;

    int m_position;
    int m_defaultPosition;

    bool m_threePole;
    bool m_topLock;
    bool m_bottomLock;

public:

  enum {
    MOMENTARY,
    TOGGLE
  };

  ToggleInput(QWidget* parent = NULL);

  QSize sizeHint() const;
    
  void paintEvent(QPaintEvent*);
  void mousePressEvent(QMouseEvent*);
  void mouseReleaseEvent(QMouseEvent*);

  int arm_position();

  /* 
   * threePole - select two or three pole
   * topLock - top position locking
   * bottomLock - bottom position locking
   */
  void setMode(int threePole, int topLock, int bottomLock);

signals:

  void positionChange(ToggleInput*);
};

#endif // _IK_TOGGLE_INPUT_INC_

