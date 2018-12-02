#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QString>
#include <QDebug>
#include <QList>
#include <QFileDialog>
#include <QWidget>
#include <QVector>
#include <QCompleter>
#include <QStringList>

#include "abstractmap.h"
#include "map.h"
#include "dialog_addcity.h"
#include "mapio.h"
#include "mapionrw.h"
#include "street.h"
#include "mapiofileinput.h"
#include "dijkstra.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_actionExit_triggered();

    void on_actionClear_Scene_triggered();

    void on_actionAbout_triggered();

    void on_action_Add_City_triggered();

    void on_show_map_clicked();

    void on_actionOpen_triggered();

    void on_shortest_way_clicked();

private:
    Ui::MainWindow *ui;
    /**
     * @brief scene the GrpahicsScene is used to add more features to the GUI
     */
    QGraphicsScene scene;
    QGraphicsView view;
    Map map;
    MapIo* mapio;
};

#endif // MAINWINDOW_H
