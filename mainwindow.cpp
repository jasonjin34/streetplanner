#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString sinput_city = ui->QLineEdit_cityinput->text();

    QString sDebug_test = QString("the testing inpu value is %1").arg(sinput_city);

    qDebug() << sinput_city;

    //QMessagebox output
    QMessageBox testmsgbox;
    testmsgbox.setInformativeText("The Selection City");
    testmsgbox.setText(sinput_city);
    testmsgbox.exec();
}

/**
 * @brief MainWindow::on_actionExit_triggered
 * windows closed function
 */
void MainWindow::on_actionExit_triggered()
{
    close();
}

/**
 * @brief MainWindow::on_actionClear_Scene_triggered
 * the function to clear the Graphic
 */

void MainWindow::on_actionClear_Scene_triggered()
{
    scene.clear();
}

/**
 * @brief MainWindow::on_actionAbout_triggered
 * information message box
 */
void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msgBox_info;
    const QString title = "Street planner";
    const QString title_info = "finding the shortest distance between two cities by using Dijkstra Algorithem";
    msgBox_info.about(this,title,title_info);
}


void MainWindow::on_action_Add_City_triggered()
{
    hide();
    Dialog_Addcity dialog;
    dialog.setModal(false);

    bool test =dialog.exec();

    if(test) qDebug("dialog add city successfully created");
    else qDebug("fail");

    City added_city;
    added_city = dialog.getDialog_city();
    added_city.draw(scene);

    show();
}

void MainWindow::on_show_map_clicked()
{
    map.draw_city(scene);
    map.draw_street(scene);
}

/**
 * @brief MainWindow::on_actionOpen_triggered
 * the upload file button triggered function
 */
void MainWindow::on_actionOpen_triggered()
{
    QString filename_city = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "C://Users//erjin//OneDrive//Desktop//Qt_project//test//txtFiles",
                "All files (*.*)");
    QMessageBox::information(this,tr("file name"),filename_city);

    QString filename_street = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "C://Users//erjin//OneDrive//Desktop//Qt_project//test//txtFiles",
                "All files(*.*)");
    QMessageBox::information(this,tr("file name"), filename_street);

    MapIoFileinput* fileinput = new MapIoFileinput(filename_city, filename_street);
    fileinput->fillMap(map);

    // LineEdit autocomplet
    QStringList wordlist_city;

    QVector<City*>::iterator it;
    for(it = map.get_city_list().begin(); it < map.get_city_list().end(); ++it){
        wordlist_city.append((*it)->getCityname());
    }

    QCompleter *completer = new QCompleter(wordlist_city,this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->QLineEdit_cityinput->setCompleter(completer);
    ui->end_city->setCompleter(completer);
}

void MainWindow::on_shortest_way_clicked()
{
    map.draw_street(scene);
    QString city_begin, city_end;
    city_begin = ui->QLineEdit_cityinput->text();
    city_end = ui->end_city->text();
    City* city1 = map.find_city(city_begin);
    city1->draw(scene);

    City* city2 = map.find_city(city_end);
    city2->draw(scene);

    QVector<Street*> street_shortest;
    street_shortest = Dijkstra::search(map,city_begin,city_end);

    //draw all the street between two cities
    QVector<Street*>::iterator it = street_shortest.begin();
    do{
        (*it)->draw_red(scene);
        it++;
    }while(it <street_shortest.end());
}

