#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "MarbleDebug.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->resize(800, 600);

    MarbleDebug::setEnabled(true);

    // Create a Marble QWidget without a parent
    MarbleWidget *mapWidget = new MarbleWidget(this);
    // Load the OpenStreetMap map
    mapWidget->setMapThemeId(QStringLiteral("earth/openstreetmap/openstreetmap.dgml"));
    //    mapWidget->setMapThemeId(QStringLiteral("earth/vectorosm/vectorosm.dgml"));
    mapWidget->centerOn(11.19, 47.68);
    //    mapWidget->zoomView(2900);

    this->setCentralWidget(mapWidget);

    /*
       ui->widget->setMapThemeId(QStringLiteral("earth/openstreetmap/openstreetmap.dgml"));
        //    mapWidget->setMapThemeId(QStringLiteral("earth/vectorosm/vectorosm.dgml"));
        ui->widget->centerOn(11.19, 47.68);
        ui->widget->zoomView(2900);
     */
}

MainWindow::~MainWindow()
{
    delete ui;
}
