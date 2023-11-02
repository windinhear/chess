#include "Stone.h"
#include<iostream>
using namespace std;
Stone::Stone(int id,int type,int x,int y):_id(id),_type(type),_x(x),_y(y)
{

}

Stone::~Stone(){

}

//画自己的方法
void Stone::drawpoint(int type,QPoint p,QPainter &painter){
    if(!this->getLive()) return;
    QString str="";
    if (IsBlack(type)){
        painter.setPen(Qt::black);
    }
    if(IsRed(type)){
        painter.setPen(Qt::red);

    }

        switch (type) {
            case 1:
            case 10:
                str="车";
                break;
            case 2:
            case 11:
                 str="马";
                break;
            case 3:
             case 12:
                 str="象";
                break;
            case 4:
              case 13:
                 str="仕";
                break;
            case 5:
             case 14:
                 str="帅";
                break;
            case 6:
             case 9:
                 str="炮";
                break;
            case 7:
             case 8:
                 str="兵";
                break;
        }


     painter.drawEllipse(p,POINT_R,POINT_R);
      painter.drawText(QPoint(p.x()-TEXTSIZE*3/4,p.y()+TEXTSIZE/3),str);
}

bool Stone::isInside(QPoint p){

     return this->getX()==p.x()&&this->getY()==p.y();
}

QPoint Stone::center(int x,int y){
    return QPoint((x)*BORDER,(y)*BORDER);

}

void Stone::setSelect(bool m){
    _select=m;
}
bool Stone::getSelect(){
    return _select;
}
int Stone:: getX(){
    return _x;
}
int Stone:: getY(){
    return _y;
}

void Stone::setX(int x){_x=x;}
void Stone::setY(int y){_y=y;}
bool Stone::getLive(){
    return _islive;
}
void Stone::setLive(bool live){
    this->_islive=live;

}
int Stone:: getid(){
    return _id;
}
void Stone::setid(int id){
    this->_id=id;
}
int Stone:: gettype(){return  _type;}
void Stone::settype(int type){this->_type=type;}
