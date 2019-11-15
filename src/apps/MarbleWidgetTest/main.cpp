#include "mainwindow.h"

#include <QApplication>
#include <QLayout>
#include <QSlider>
#include <QLabel>
#include <QDebug>

#include <marble/MarbleWidget.h>

using namespace Marble;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //    MainWindow w;
    //    w.show();

    std::unique_ptr<QWidget> window(new QWidget);

    // Create a Marble QWidget without a parent
    MarbleWidget *mapWidget = new MarbleWidget(window.get());

    // Load the Plain map
    mapWidget->setMapThemeId(QCoreApplication::applicationDirPath() + QStringLiteral("/data/maps/earth/plain/plain.dgml"));

    // Hide the FloatItems: OverviewMap, ScaleBar and Compass
    mapWidget->setShowOverviewMap(false);
    mapWidget->setShowScaleBar(false);
    mapWidget->setShowCompass(false);

    // Set the map quality to gain speed
    mapWidget->setMapQualityForViewContext(NormalQuality, Still);
    mapWidget->setMapQualityForViewContext(LowQuality, Animation);

    // Create a horizontal zoom slider and set the default zoom
    QSlider *zoomSlider = new QSlider(Qt::Horizontal);
    zoomSlider->setMinimum(1000);
    zoomSlider->setMaximum(2400);

    mapWidget->zoomView(zoomSlider->value());

    // Create a label to show the geodetic position
    QLabel *positionLabel = new QLabel();
    positionLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    // Add all widgets to the vertical layout.
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(mapWidget);
    layout->addWidget(zoomSlider);
    layout->addWidget(positionLabel);

    // Center the map onto a given position
    GeoDataCoordinates home(-60.0, -10.0, 0.0, GeoDataCoordinates::Degree);
    mapWidget->centerOn(home);

    // Connect the map widget to the position label.
    QObject::connect(mapWidget, SIGNAL(mouseMoveGeoPosition(QString)),
                     positionLabel, SLOT(setText(QString)));

    // Connect the zoom slider to the map widget and vice versa.
    QObject::connect(zoomSlider, SIGNAL(valueChanged(int)),
                     mapWidget, SLOT(zoomView(int)));
    QObject::connect(mapWidget, SIGNAL(zoomChanged(int)),
                     zoomSlider, SLOT(setValue(int)));

    window->setLayout(layout);
    window->resize(800, 600);

    window->show();

    return a.exec();
}
