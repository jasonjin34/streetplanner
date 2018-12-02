#include "street.h"

Street::Street()
{

}

Street::Street(City* city1, City* city2){
    this->city1 = city1;
    this->city2 = city2;
}

void Street::draw(QGraphicsScene& scene){
    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::green);
    QLine line;
    line.setLine(city1->getCityLocationX(),city1->getCityLocationY(),
                 city2->getCityLocationX(),city2->getCityLocationY());
    scene.addLine(line,pen);
}

City* Street::getcity1(){
    return this->city1;
}

City* Street::getcity2(){
    return this->city2;
}

void Street::draw_red(QGraphicsScene& scene){
    QPen pen;
    pen.setWidth(4);
    pen.setColor(Qt::red);
    QLine line;
    line.setLine(city1->getCityLocationX(),city1->getCityLocationY(),
                 city2->getCityLocationX(),city2->getCityLocationY());
    scene.addLine(line,pen);
}
