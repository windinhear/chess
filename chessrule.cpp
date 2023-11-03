
#include "chessrule.h"

chessRule::chessRule()
{

}




//判断落子是否合法（走棋规则）
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
        return B_bishopRule(&f,s);
    case 13:
        return R_bishopRule(&f,s);
    case 5:
        return B_kingRule(&f,s);
    case 14:
        return R_kingRule(&f,s);
    case 7:
        return B_pawnRule(&f,s);
    case 8:
        return R_pawnRule(&f,s);
    }

    return false;

}




bool chessRule::carRule(QPoint* f,QPoint* s,int map[12][11]){
       //if(is_cham(map[f->x()][f->y()])==is_cham(map[s->x()][s->y()])) return true;
       int *dx=nullptr;
       int i=1;
       if(f->x()!=s->x()&&f->y()==s->y()){//x方向
            dx=map[f->y()];
            i=f->x()>s->x()?-1:1;
            for(int j=f->x()+i;j!=s->x();j+=i){
                if(dx[j]!=0){
                    return false;
                }
            }
return true;
       }
       if(f->y()!=s->y()&&f->x()==s->x()){//y方向

            i=f->y()>s->y()?-1:1;
            for(int j=f->y()+i;j!=s->y();j+=i){
                if(map[j][f->x()]!=0){
                    return false;
                }
            }
            return true;

       }
       return false;

}
bool chessRule::morseRule(QPoint* f,QPoint* s,int map[12][11]){
        int lx=f->x()-s->x();
        int ly=f->y()-s->y();
        int dx=0;
        int dy=0;
        if((lx==1&&ly==2)||(lx==-1&&ly==2)){
              dx=0;dy=-1;
        }else if((lx==2&&ly==1)||(lx==2&&ly==-1)){
                dx=-1;dy=0;
        }else if((lx==1&&ly==-2)||(lx==-1&&ly==-2)){
                dx=0;dy=1;
        }else if((lx==-2&&ly==-1)||(lx==-2&&ly==1)){
                dx=1;dy=0;
        }else {
return false;
}
        if(map[f->y()+dy][f->x()+dx]==0){
            return true;
        }
        return false;
}
bool chessRule::canonRule(QPoint* f,QPoint* s,int map[12][11]){
    int *dx=nullptr;
    int i=1;
    int da=0;
    if(f->x()!=s->x()&&f->y()==s->y()){//x方向
         dx=map[f->y()];
         i=f->x()>s->x()?-1:1;
         for(int j=f->x()+i;j!=s->x();j+=i){
             if(dx[j]!=0){
                 if(map[s->y()][s->x()]!=0){
                         return true;
                     }
                 return false;
             }
         }
    }
    else if(f->y()!=s->y()&&f->x()==s->x()){//y方向

         i=f->y()>s->y()?-1:1;
         for(int j=f->y()+i;j!=s->y();j+=i){
             if(map[j][f->x()]!=0){
                 if(map[s->y()][s->x()]!=0){
                         return true;
                     }
                    return false;
             }
         }
    }else{return false;}
    if(map[s->y()][s->x()]!=0){
         return false;
    }

    return true;

}

bool chessRule::R_elephantRule(QPoint* f,QPoint* s,int map[12][11]){
      if(s->y()<5) return false;
    int dx=(f->x()-s->x());
    int dy=(f->y()-s->y());
    int fx=(f->x()+s->x())/2;
    int fy=(f->y()+s->y())/2;
    if(!((dx==-2&&dy==2)||(dx==2&&dy==-2)||(dx==-2&&dy==-2)||(dx==2&&dy==2)) ){
        return false;
    }
    if(map[fy][fx]==0){
        return true;
    }
    return false;
}
bool chessRule::R_bishopRule(QPoint* f,QPoint* s){
        if(!(s->x()<=6&&s->x()>=4&&s->y()>=8)) return false;
        int dx=(f->x()-s->x());
        int dy=(f->y()-s->y());
        if((dx==-1&&dy==1)||(dx==1&&dy==1)||(dx==1&&dy==-1)||(dx==-1&&dy==-1)) return true;
        return false;
}
bool chessRule::R_kingRule(QPoint* f,QPoint* s){
    if(!(s->x()<=6&&s->x()>=4&&s->y()>=8)) return false;
    int dx=(f->x()-s->x());
    int dy=(f->y()-s->y());
    if((dx==-1&&dy==0)||(dx==0&&dy==1)||(dx==1&&dy==0)||(dx==0&&dy==-1)) return true;
        return false;
}
bool chessRule::R_pawnRule(QPoint* f,QPoint* s){
    int dx=(f->x()-s->x());
    int dy=(f->y()-s->y());
    if(f->y()>=6&&dx!=0){
        return false;
    }
    if((dx==-1&&dy==0)||(dx==0&&dy==1)||(dx==1&&dy==0)) return true;
    return false;
}

bool chessRule::B_elephantRule(QPoint* f,QPoint* s,int map[12][11]){
    if(s->y()>5) return false;
  int dx=(f->x()-s->x());
  int dy=(f->y()-s->y());
  int fx=(f->x()+s->x())/2;
  int fy=(f->y()+s->y())/2;
  if(!((dx==-2&&dy==2)||(dx==2&&dy==-2)||(dx==-2&&dy==-2)||(dx==2&&dy==2)) ){
      return false;
  }
  if(map[fy][fx]==0){
      return true;
  }
  return false;
}
bool chessRule::B_bishopRule(QPoint* f,QPoint* s){
    if(!(s->x()<=6&&s->x()>=4&&s->y()<=3)) return false;
    int dx=(f->x()-s->x());
    int dy=(f->y()-s->y());
    if((dx==-1&&dy==1)||(dx==1&&dy==1)||(dx==1&&dy==-1)||(dx==-1&&dy==-1)) return true;
    return false;
}
bool chessRule::B_kingRule(QPoint* f,QPoint* s){
    if(!(s->x()<=6&&s->x()>=4&&s->y()<=3)) return false;
    int dx=(f->x()-s->x());
    int dy=(f->y()-s->y());
    if((dx==-1&&dy==0)||(dx==0&&dy==1)||(dx==1&&dy==0)||(dx==0&&dy==-1)) return true;
        return false;
    return true;
}
bool chessRule::B_pawnRule(QPoint* f,QPoint* s){
    int dx=(f->x()-s->x());
    int dy=(f->y()-s->y());
    if(f->y()<=5&&dx!=0){
        return false;
    }
    if((dx==-1&&dy==0)||(dx==0&&dy==-1)||(dx==1&&dy==0)) return true;
    return false;
}

































