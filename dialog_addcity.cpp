#include "dialog_addcity.h"
#include "ui_dialog_addcity.h"

Dialog_Addcity::Dialog_Addcity(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Addcity)
{
    ui->setupUi(this);
}

Dialog_Addcity::~Dialog_Addcity()
{
    delete ui;
}

void Dialog_Addcity::on_add_city_clicked()
{
   QString city_name = ui->dialog_city->text();
   int x = ui->dialog_city_x->text().toInt();
   int y = ui->dialog_city_y->text().toInt();

   City added_city(city_name, x,y);
   this->dialog_city = added_city;
}

City Dialog_Addcity::getDialog_city(){
    return this->dialog_city;
}
