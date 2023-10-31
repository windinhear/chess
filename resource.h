#ifndef RESOURCE_H
#define RESOURCE_H

#endif // RESOURCE_H



#define STONENUMS 32
//棋盘格子宽度和高度
#define BORDER 90

//棋子半径
#define POINT_R BORDER/3
//文本大小
#define TEXTSIZE int(POINT_R)
#define NOCHESS 0 //没有棋子
//黑
#define B_CAR 1 //车
#define B_MORSE 2 //马
#define B_ELEPHANT 3 //大象
#define B_BISHOP 4 //士
#define B_KING 5 //帅
#define B_CANON 6 //炮
#define B_PAWN 7 //兵

//红
#define R_CAR 10//车
#define R_MORSE 11 //马
#define R_ELEPHANT 12 //大象
#define R_BISHOP 13 //士
#define R_KING 14 //帅
#define R_CANON 9 //炮
#define R_PAWN 8 //兵
//判断
#define IsBlack(x) (x>=B_CAR&&x<=B_PAWN)
#define IsRed(x) (x>=R_PAWN&&x<=R_KING)
#define IsSameteam(x,y) (IsBlack(x)&&IsBlack(Y)||IsRed(x)&&IsRed(y))
static int chessBoard[12][11] = {
    {0,0, 0, 0, 0, 0, 0, 0, 0, 0,0},
    {0,1, 2, 3, 4, 5, 4, 3, 2, 1,0},
    {0,0, 0, 0, 0, 0, 0, 0, 0, 0,0},
    {0,0, 6, 0, 0, 0, 0, 0, 6, 0,0},
    {0,7, 0, 7, 0, 7, 0, 7, 0, 7,0},
    {0,0, 0, 0, 0, 0, 0, 0, 0, 0,0},
    {0,0, 0, 0, 0, 0, 0, 0, 0, 0,0},
    {0,8, 0, 8, 0, 8, 0, 8, 0, 8,0},
    {0,0, 9, 0, 0, 0, 0, 0, 9, 0,0},
    {0,0, 0, 0, 0, 0, 0, 0, 0, 0,0},
    {0,10, 11, 12, 13, 14, 13, 12, 11, 10,0},
    {0,0, 0, 0, 0, 0, 0, 0, 0, 0,0}
};
const short Init[]={1,2,3,4,5,4,3,2,1,6,6,7,7,7,7,7,8,8,8,8,8,9,9,10,11,12,13,14,13,12,11,10};
struct _chessposition{
    short x;
    short y;
};
struct _chessmove
{
    short chessID;
    _chessposition From;
    _chessposition To;
    int Score;
};





























