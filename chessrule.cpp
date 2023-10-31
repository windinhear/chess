#include "chessrule.h"

chessRule::chessRule()
{

}

/*
            //不为空白

            if(dd){
               // cout <<"dd"<<dd->gettype()<<endl;
                //同类型
                if(IsRed(acstone->gettype())==IsRed(dd->gettype())){

                }else {
                    dd->setLive(&false);
                    dd->setX(-1);
                    dd->setY(-1);
                    dd=nullptr;
                    acstone->setX(press.x());
                    acstone->setY(press.y());
                }
            }
            else{
                acstone->setX(press.x());
                acstone->setY(press.y());
            }
*/

/*

who:红黑
acstone:活动棋子:
dd:目标位置：目标位置在上一层已经确定了一定在棋盘内部
 */

bool chessRule::choseRule(Stone* acstone,QPoint* s,int map[12][11]){
    //判断目标位置是否合法
    QPoint f(0,0);
    f.setX(acstone->getX());
    f.setY(acstone->getY());
    switch (acstone->gettype()) {
    case 1:
    case 10:
        return carRule(&f,s,map);

    case 2:
    case 11:
        return morseRule(&f,s,map);
    case 6:
    case 9:
        return canonRule(&f,s,map);

    case 3:
        return B_elephantRule(&f,s,map);
    case 12:
        return R_elephantRule(&f,s,map);
    case 4:
        return B_bishopRule(&f,s,map);
    case 13:
        return R_bishopRule(&f,s,map);
    case 5:
        return B_kingRule(&f,s,map);
    case 14:
        return R_kingRule(&f,s,map);
    case 7:
        return B_pawnRule(&f,s,map);
    case 8:
        return R_pawnRule(&f,s,map);
    }

    return false;

}




bool chessRule::carRule(QPoint* f,QPoint* s,int map[12][11]){
    //Y方向
    if(f->x()==s->x()&&f->y()!=s->y()){

    }
    //return ()||(f->x()!=s->x()&&f->y()==s->y());
}
bool chessRule::morseRule(QPoint* f,QPoint* s,int map[12][11]){
        int dx=s->x()-f->x();
        int dy=s->y()-f->y();
        if(dx==1){
            if(dy==2){
                //_s[f->x()][f->y()-1]
            }
        }
}
bool chessRule::canonRule(QPoint* f,QPoint* s,int map[12][11]){
    return true;
}

bool chessRule::R_elephantRule(QPoint* f,QPoint* s,int map[12][11]){
return true;
}
bool chessRule::R_bishopRule(QPoint* f,QPoint* s,int map[12][11]){
return true;
}
bool chessRule::R_kingRule(QPoint* f,QPoint* s,int map[12][11]){
return true;
}
bool chessRule::R_pawnRule(QPoint* f,QPoint* s,int map[12][11]){
return true;
}

bool chessRule::B_elephantRule(QPoint* f,QPoint* s,int map[12][11]){
return true;
}
bool chessRule::B_bishopRule(QPoint* f,QPoint* s,int map[12][11]){
return true;
}
bool chessRule::B_kingRule(QPoint* f,QPoint* s,int map[12][11]){
return true;
}
bool chessRule::B_pawnRule(QPoint* f,QPoint* s,int map[12][11]){
return true;
}
















