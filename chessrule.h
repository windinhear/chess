#ifndef CHESSRULE_H
#define CHESSRULE_H

#include "Stone.h"
#include<QPoint>

class chessRule
{
public:
    chessRule();

 bool choseRule(Stone *acstone,QPoint *s);
//车马炮红黑一样
 bool carRule(QPoint* f,QPoint* s);
 bool morseRule(QPoint* f,QPoint* s);
 bool canonRule(QPoint* f,QPoint* s);

 bool R_elephantRule(QPoint* f,QPoint* s);
 bool R_bishopRule(QPoint* f,QPoint* s);
 bool R_kingRule(QPoint* f,QPoint* s);
 bool R_pawnRule(QPoint* f,QPoint* s);

 bool B_elephantRule(QPoint* f,QPoint* s);
 bool B_bishopRule(QPoint* f,QPoint* s);
 bool B_kingRule(QPoint* f,QPoint* s);
 bool B_pawnRule(QPoint* f,QPoint* s);
};

#endif // CHESSRULE_H
