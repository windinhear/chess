
#ifndef CHESS_PLATFORM_H
#define CHESS_PLATFORM_H

#include<QPoint>

#include <QWidget>
#include<QMouseEvent>
#include"Stone.h"
#include"chessrule.h"
#include<vector>
#include<QPushButton>
#include<QObject>
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
     //悔棋
     void drawBackbuttton();
public slots:
     void getBack();


public:
     const short Init[32]{1,2,3,4,5,4,3,2,1,6,6,7,7,7,7,7,8,8,8,8,8,9,9,10,11,12,13,14,13,12,11,10};
    std::map<int,Stone> _s;

    std::vector<Stone> _olds;
    std::vector<int> steps;
    //当前第几步

    int chessBoard[12][11] = {
        {0,0, 0, 0, 0, 0, 0, 0, 0, 0,0},
        {0,1, 2, 3, 4, 5, 6, 7, 8, 9,0},
        {0,0, 0, 0, 0, 0, 0, 0, 0, 0,0},
        {0,0, 10, 0, 0, 0, 0, 0, 11, 0,0},
        {0,12, 0, 13, 0, 14, 0, 15, 0, 16,0},
        {0,0, 0, 0, 0, 0, 0, 0, 0, 0,0},
        {0,0, 0, 0, 0, 0, 0, 0, 0, 0,0},
        {0,17, 0, 18, 0, 19, 0, 20, 0, 21,0},
        {0,0, 22, 0, 0, 0, 0, 0, 23, 0,0},
        {0,0, 0, 0, 0, 0, 0, 0, 0, 0,0},
        {0,24, 25, 26, 27, 28, 29, 30, 31, 32,0},
        {0,0, 0, 0, 0, 0, 0, 0, 0, 0,0}
    };
    //判断谁执棋1红2黑
    int who=1;
    //规则
    chessRule rule;
    //正在活动的棋子
    Stone *acstone=nullptr;

    QPushButton *btn = new QPushButton;


signals:

public slots:

};

#endif // BOARD_H

