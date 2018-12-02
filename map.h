#ifndef MAP_H
#define MAP_H
#include <QVector>
#include <QDebug>
#include <QGraphicsScene>

#include "abstractmap.h"
#include "city.h"
#include "street.h"

class Map :public AbstractMap
{
public:
    Map();
    ~Map();
    virtual void addCity(City*);
    virtual bool addStreet(Street*);
    virtual City* find_city(const QString city_name) const;
    void draw_city(QGraphicsScene& scene);
    void draw_street(QGraphicsScene& scene);

    virtual QVector<Street*> get_street_list(const City* city) const;

    QVector<City*> get_city_list();

    virtual City* get_opposite_city(const Street* street, const City* city) const;

    virtual double get_length(const Street* street) const;


private:
    QVector<City*> vCity_list;
    QVector<Street*> vStreet_list;
};

#endif // MAP_H
