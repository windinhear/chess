
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

                _s[f]=Stone(f+1,Init[f],j,i);

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
    cout<<press.x()<<" "<<press.y()<<endl;
//选择棋子
    //判断点击点是否在棋盘外面

     if(press.x()>=1&&press.x()<10&&press.y()>=1&&press.y()<=10){
         //当前点击点的id
          int id=chessBoard[press.y()][press.x()]-1;

//          for(int i=0;i<12;i++){
//              cout<<endl;
//              for(int j=0;j<11;j++){
//                  cout<<chessBoard[i][j]<<" ";
//              }}
           //选子
           back:
          if(acstone==nullptr&&ev->button()==Qt::LeftButton){
              //选子 当前有棋子
              if(id!=-1){

                  if((IsRed(_s[id].gettype())&&who==1)||(IsBlack(_s[id].gettype())&&who==2)){

                               acstone=&_s[id];
                                acstone->setSelect(true);
                                 who=(who==2?1:2);


                  }


              }
              else{
             //选子 当前无棋子
                  return;
              }



          }
        //有活动棋子，开始落子
          else if (acstone!=nullptr){
              acstone->setSelect(false);
               Stone* dd=nullptr;
               if(id!=-1){
                   //落子 当前有棋子
                   dd=&_s[id];
                if(IsRed(dd->gettype())==IsRed(acstone->gettype())){
                   //落子 同子
                    //系统优化自动跳过这句话，无语，因为后面有  acstone=nullptr;
                  // acstone->setSelect(false);


                   acstone=nullptr;

                   who=1==who?2:1;
                   goto back;
                }
               }

              if( !rule.choseRule(acstone,&press,chessBoard))return;
                //合法
               chessBoard[acstone->getY()][acstone->getX()]=0;
               chessBoard[press.y()][press.x()]=acstone->getid();
               //cout<< chessBoard[press.y()][press.x()]<<endl;
               acstone->setX(press.x());
               acstone->setY(press.y());

               if(id!=-1){
               dd->setLive(false);
               dd->setX(-1);
               dd->setY(-1);


                }
               acstone=nullptr;
              dd=nullptr;
     }
          this->update();


}



}



