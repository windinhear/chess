#include <QApplication>
#include "chess_platform.h"
#include<QWidget>
int main(int argc,char* argv[]){
       QApplication app(argc,argv);
       chess_platform w;
       w.resize(400,700);
       w.show();
       return app.exec();
}
