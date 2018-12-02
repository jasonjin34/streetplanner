#include "map.h"
#include "math.h"

Map::Map()
{

}

Map::~Map(){

}

/**
 * @brief map::addCity add the cities to the map
 * @param city
 */
void Map::addCity(City* city){
    qDebug()<< QString("City %1 has added, location: in X (%2) and in Y (%3).").
               arg(city->getCityname()).arg(city->getCityLocationX()).arg(city->getCityLocationY());
    this->vCity_list.append(city);
}

/**
 * @brief map::draw all the city on the map
 */
void Map::draw_city(QGraphicsScene& scene){
    QVector<City*>::Iterator it;
    for( it = vCity_list.begin();it < vCity_list.end();it++){
        (*it)->draw(scene);
    }
}

/**
 * @brief Map::addStreet
 * @param streetptr
 * @return return false, if the street city can not find in the city list
 */
bool Map::addStreet(Street* streetptr){
    this->vStreet_list.append(streetptr);
    return true; // temp function
}

City* Map::find_city(const QString city_name) const{
    QVector<City*>::const_iterator it;
    for(it = vCity_list.begin(); it < vCity_list.end();it++){
        if ((*it)->getCityname() == city_name) return *it;
    }
    return nullptr;
}

void Map::draw_street(QGraphicsScene& scene){
    QVector<Street*>::Iterator it;
    for(it = vStreet_list.begin(); it < vStreet_list.end();it++){
        (*it)->draw(scene);
    }
}

QVector<Street*> Map::get_street_list(const City* city) const {
    QVector<Street*> Street_connect_city;
    QVector<Street*>::const_iterator it;
    for(it = vStreet_list.begin(); it < vStreet_list.end();it++){
        if((*it)->getcity1() == city || (*it)->getcity2() == city){
            Street_connect_city.append(*it);
        }
    }
    return Street_connect_city;
}

City* Map::get_opposite_city(const Street* street, const City* city) const{
   QVector<Street*>::const_iterator it;
    for(it = vStreet_list.begin();it< vStreet_list.end();it++){
        if((*it) == street)
        {
            if((*it)->getcity1() == city) //the city is on this street, check for the opposite street
            {
                return (*it)->getcity2();
            }
            else if((*it)->getcity2() == city)
            {
                return (*it)->getcity1();
            }
            else return nullptr;
        }
    }
    return nullptr;
}

double Map::get_length(const Street* street) const {
   Street street_temp = *street;
   City* first = street_temp.getcity1();
   City* second = street_temp.getcity2();
   double x_first = first->getCityLocationX();
   double y_first = first->getCityLocationY();
   double x_second = second->getCityLocationX();
   double y_second = second->getCityLocationY();
   return sqrt((x_first-x_second)*(x_first-x_second)+(y_first-y_second)*(y_first-y_second));
}
QVector<City*> Map::get_city_list(){
    return this->vCity_list;
}
