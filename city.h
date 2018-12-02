#ifndef CITY_H
#define CITY_H
#include <QString>
#include <QPen>
#include <QBrush>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QDebug>


class City
{
public:
    City();
    /**
     * @brief City constructor
     * @param city name, X coordinate, y coordinate
     */
    City(QString,int, int);

    //get the City informations functions
    const QString getCityname();
    int getCityLocationX();
    int getCityLocationY();

    void draw(QGraphicsScene& scene);

private:
     QString sName_city;
     int x_coor;
     int y_coor;
};

#endif // CITY_H
