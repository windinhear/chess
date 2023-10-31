#include "chess_platform.h"
#include<iostream>
using namespace std;
chess_platform::chess_platform(QWidget *parent):QWidget (parent)
{
    this->createStones();
    this->rule;
    cout<<"初始化棋盘"<<endl;


}
void chess_platform::paintEvent(QPaintEvent *){
     QPainter painter(this);
      drawMap(painter);
       drawStone(painter);
}
void chess_platform::drawMap(QPainter &painter){

// 画9竖线
    painter.drawLine(QPoint(BORDER,BORDER),QPoint(BORDER,10*BORDER));
  for(int i=1;i<8;++i){
     painter.drawLine(QPoint(i*BORDER+BORDER,BORDER),QPoint(i*BORDER+BORDER,5*BORDER));
      painter.drawLine(QPoint(i*BORDER+BORDER,6*BORDER),QPoint(i*BORDER+BORDER,10*BORDER));

  }
  painter.drawLine(QPoint(9*BORDER,BORDER),QPoint(9*BORDER,10*BORDER));
   // 画10横线
    for(int j=0; j<10; ++j)
    {
        painter.drawLine(QPoint(BORDER,j*BORDER+BORDER),QPoint(9*BORDER,j*BORDER+BORDER));
    }

 //画斜线
  painter.drawLine(QPoint(4*BORDER,BORDER),QPoint(6*BORDER,3*BORDER));
   painter.drawLine(QPoint(6*BORDER,BORDER),QPoint(4*BORDER,3*BORDER));
    painter.drawLine(QPoint(4*BORDER,8*BORDER),QPoint(6*BORDER,10*BORDER));
     painter.drawLine(QPoint(6*BORDER,8*BORDER),QPoint(4*BORDER,10*BORDER));


}
void chess_platform::createStones(){
//    for(int i=0;i<STONENUMS;i++){
//        _s[i].setid(short(i));
//        _s[i].settype(Init[i]);
//        _s[i].setX(0);
//        _s[i].setY(0);
//    }
    short f=0;

    for(short i=1;i<11;i++){
        for(short j=1;j<10;j++){
            if(chessBoard[i][j]!=0){
                _s[f].setid(f);
                _s[f].settype(Init[f]);
                _s[f].setX(j);
                _s[f].setY(i);
                ++f;


            }


        }
    }

}


void chess_platform::drawStone(QPainter &painter){
    QFont paint("仿宋",TEXTSIZE,QFont::Bold, true);
    painter.setFont(paint);

    QColor color(232, 184, 106);
     color.setAlpha(270);



    for(int i=0;i<32;i++){
        if(_s[i].getSelect()==true){
            color.setRgb(200,200,200);
        }else{
            color.setRgb(232, 184, 106);
        }
         QBrush brush(color);
          painter.setBrush(brush);

        _s[i].drawpoint(_s[i].gettype(),_s[i].center(_s[i].getX(),_s[i].getY()),painter);
            //this->update();
    }

}


//void chess_platform::mousePressEvent(QMouseEvent *ev){

//    cout<<"release"<<endl;
//    if(this->acstone!=nullptr&&ev->button() == Qt::LeftButton)
//       {

//             acstone->setMove(false);
//            this->acstone=nullptr;
//       }


//}


void chess_platform:: CsetX(QPoint* p,int x){
      if(x%BORDER>BORDER*(0.6666))
           p->setX(x/BORDER+1);
      else if(x%BORDER<BORDER*(0.3333)){
          p->setX(x/BORDER);
      }
}
void chess_platform:: CsetY(QPoint* p,int y){
   if(y%BORDER>BORDER*(0.6666))
         p->setY(y/BORDER+1);
   else if(y%BORDER<BORDER*(0.3333)){
       p->setY(y/BORDER);
   }
}

void chess_platform:: CsetX(Stone *p,int x){
    if(x%BORDER>BORDER*(0.6666))
         p->setX(x/BORDER+1);
    else if(x%BORDER<BORDER*(0.3333)){
        p->setX(x/BORDER);
    }
}
void chess_platform:: CsetY(Stone *p,int y){
    if(y%BORDER>BORDER*(0.6666))
          p->setY(y/BORDER+1);
    else if(y%BORDER<BORDER*(0.3333)){
        p->setY(y/BORDER);
    }
}
void chess_platform::mouseReleaseEvent(QMouseEvent *ev){


    QPoint press(0,0);
    QPoint p=ev->pos();
    this->CsetX(&press,int(p.x()));
    this->CsetY(&press,int(p.y()));
//选择棋子
   back:
    if(acstone==nullptr&&ev->button()==Qt::LeftButton){

        for(short i=0;i<32;i++){
             if(_s[i].getLive()==false)continue;
            if(_s[i].isInside(press)){

                 cout <<"gettype: "<<IsRed(_s[i].gettype())<<"  who:"<<who<<endl;

                if(IsRed(_s[i].gettype())&&who==1){
                        cout <<"selectchess2: "<<who<<endl;
                     _s[i].setSelect(true);
                     acstone=&_s[i];
                       who=2;
                      break;
                }
                else if(IsBlack(_s[i].gettype())&&who==2){
                            cout <<"selectchess2: "<<who<<endl;
                            _s[i].setSelect(true);
                            acstone=&_s[i];
                              who=1;
                             //cout <<"acss"<<acstone->gettype()<<endl;
                             break;

                       }

            }


        }
    }


    else if (acstone!=nullptr){
        //判断位置是否合法

        if(!rule.choseRule(acstone,&press,chessBoard)){
                return;
    }


//开始落子

        cout <<"downchess: "<<who<<endl;
        if(press.x()>=1&&press.x()<10&&press.y()>=1&&press.y()<=10){
            Stone* dd=nullptr;
            for(short i=0;i<32;i++){
                //if(_s[i].getLive()==false)continue;
                if(_s[i].isInside(press)){


                         dd=&_s[i];
                }
            }
            //不为空白

            if(dd){
                 chessBoard[acstone->getX()][acstone->getY()]=0;
               // cout <<"dd"<<dd->gettype()<<endl;
                //同类型
                if(IsRed(acstone->gettype())==IsRed(dd->gettype())){
                        acstone->setSelect(false);
                        acstone=nullptr;
                        dd=nullptr;
                        who=1==who?2:1;
                             goto back;

                }else {

                    dd->setLive(false);
                    dd->setX(-1);
                    dd->setY(-1);
                    dd=nullptr;
                    acstone->setX(press.x());
                    acstone->setY(press.y());
                    chessBoard[acstone->getX()][acstone->getY()]=acstone->gettype();

                }
            }
            else{
                acstone->setX(press.x());
                acstone->setY(press.y());
                chessBoard[acstone->getX()][acstone->getY()]=acstone->gettype();
            }

       // rule.choseRule(who,press,acstone);
        }else{

            acstone->setSelect(false);
            acstone=nullptr;
            who=1==who?2:1;
             goto back;
        }

                acstone->setSelect(false);
                acstone=nullptr;

    }

this->update();
}






















