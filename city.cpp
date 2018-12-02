#include "city.h"

/**
 * @brief City::City constructor
 * @param name_city
 * @param x_coor
 * @param y_coor
 */
City::City()
{

}

City::City(QString name_city, int x_coor, int y_coor)
{
    this->sName_city = name_city;
    this->x_coor = x_coor;
    this->y_coor = y_coor;
}

/**
 * @brief City::getCityLocationX
 * @return
 */
int City::getCityLocationX(){
    return this->x_coor;
}

int City::getCityLocationY(){
    return this->y_coor;
}

const QString City::getCityname(){
    return this->sName_city;
}

/*those three functions to get the city informations including x location y and city name*/


void City::draw(QGraphicsScene& scene)
{
    //setup QBrush and QPen for drawing the city
    QBrush pointcolor_city;
    pointcolor_city.setColor(Qt::red);
    pointcolor_city.setStyle(Qt::SolidPattern);

    QPen pen_city;
    pen_city.setColor(Qt::red);

    //add city to the scene
    scene.addEllipse(x_coor,y_coor,10,10,pen_city,pointcolor_city);

    QString string_debugcitydraw = QString("the city %1 was printed in position %2, %3 .").arg(this->sName_city).arg(this->x_coor).arg(this->y_coor);
    qDebug() << string_debugcitydraw;

    //set up the city text on the Graphicdisplay
    QGraphicsTextItem *city_text = new QGraphicsTextItem;
    city_text->setPos(x_coor-8,y_coor+6);

    city_text->setPlainText(sName_city);
    scene.addItem(city_text);
}
