#ifndef CHESS_PLATFORM_H
#define CHESS_PLATFORM_H

#include<QPoint>

#include <QWidget>
#include<QMouseEvent>
#include"Stone.h"
#include"chessrule.h"
class chess_platform : public QWidget
{
    Q_OBJECT
public:
    explicit chess_platform(QWidget *parent=nullptr );
   void drawMap(QPainter &painter);
    void paintEvent(QPaintEvent *);
    void createStones();
    void drawStone(QPainter &painter);
     void mouseReleaseEvent(QMouseEvent *);
     QPoint center(int x,int y);
     void CsetX(QPoint *p,int x);
     void CsetY(QPoint* p,int y);
     void CsetX(Stone* p,int x);
     void CsetY(Stone* p,int y);
public:
     const short Init[32]{1,2,3,4,5,4,3,2,1,6,6,7,7,7,7,7,8,8,8,8,8,9,9,10,11,12,13,14,13,12,11,10};
    Stone _s[STONENUMS];
    //判断谁执棋1红2黑
    int who=1;
    //规则
   chessRule rule;
    //正在活动的棋子
    Stone *acstone=nullptr;

signals:

public slots:

};

#endif // BOARD_H
