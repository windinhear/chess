
#ifndef  CHESSRULE_H
#define CHESSRULE_H

#include "Stone.h"
#include<QPoint>
#include <map>

class chessRule
{
public:
    chessRule();

 bool choseRule(Stone *acstone,QPoint *s, int map[12][11]);
//车马炮红黑一样
 bool carRule(QPoint* f,QPoint* s,int map[12][11]);
 bool morseRule(QPoint* f,QPoint* s,int map[12][11]);
 bool canonRule(QPoint* f,QPoint* s,int map[12][11]);
 bool R_elephantRule(QPoint* f,QPoint* s,int map[12][11]);

 bool R_bishopRule(QPoint* f,QPoint* s);
 bool R_kingRule(QPoint* f,QPoint* s);
 bool R_pawnRule(QPoint* f,QPoint* s);

 bool B_elephantRule(QPoint* f,QPoint* s,int map[12][11]);
 bool B_bishopRule(QPoint* f,QPoint* s);
 bool B_kingRule(QPoint* f,QPoint* s);
 bool B_pawnRule(QPoint* f,QPoint* s);

 bool is_cham(int a){
     return a<=16;
 }
};
#endif
