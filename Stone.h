
#ifndef STONE_H
#define STONE_H
#include"resource.h"
#include <QPainter>
#include<QFont>
#include<QBrush>
#include<QString>
#include<math.h>
#include<iostream>

class Stone
{
public:
    Stone(){}
    Stone(int id,int type,int x,int y);
    ~Stone();
    int getid();
    void setid(int id);
    int gettype();
    void settype(int type);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);

    bool getLive();
     void setLive(bool live);
     QPoint center(int x,int y);

    //画自己的方法

 void drawpoint(int type,QPoint p,QPainter &painter);
 bool isInside(QPoint p);
    void setSelect(bool m);
   bool getSelect();
   int _id;

   //类型
   int _type;
   int _x;
   int _y;

       bool _select=false;
    bool _islive=true;
};

#endif // CHESSPOINT_H
