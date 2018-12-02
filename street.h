#ifndef STREET_H
#define STREET_H

#include "city.h"
#include <QGraphicsScene>

class Street
{
public:
    Street();
    Street(City*, City*);
    void draw(QGraphicsScene &scene);
    void draw_red(QGraphicsScene &scene);

    City* getcity1();
    City* getcity2();

private:
    City *city1, *city2;
};

#endif // STREET_H
