#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->resize(800, 600);

    // Create a Marble QWidget without a parent
    MarbleWidget *mapWidget = new MarbleWidget(this);

    // Load the OpenStreetMap map
    mapWidget->setMapThemeId(QStringLiteral("earth/openstreetmap/openstreetmap.dgml"));
    //    mapWidget->setMapThemeId(QStringLiteral("earth/vectorosm/vectorosm.dgml"));
    mapWidget->centerOn(11.19, 47.68);
    mapWidget->zoomView(2900);

    this->setCentralWidget(mapWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
