#ifndef DIALOG_ADDCITY_H
#define DIALOG_ADDCITY_H

#include <QPushButton>
#include <QLineEdit>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QString>
#include <QDialog>
#include "city.h"

namespace Ui {
class Dialog_Addcity;
}

class Dialog_Addcity : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Addcity(QWidget *parent = nullptr);
    ~Dialog_Addcity();
    City getDialog_city();


private slots:
    void on_add_city_clicked();

private:
    Ui::Dialog_Addcity *ui;
    City dialog_city;

};

#endif // DIALOG_ADDCITY_H
