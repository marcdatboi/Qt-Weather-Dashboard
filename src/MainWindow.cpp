



#include "MainWindow.hpp"
#include "WeatherNowWidget.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , centralWidget(new QWidget(this))
    , centralLayout(new QVBoxLayout(this->centralWidget))
{
    this->setupWindow();

    QString locationName = "Example Location";
    QString weatherIconPath = "not/implemented/yet/lol";
    WeatherNowWidget *weatherHeaderWidget = new WeatherNowWidget
    (
        locationName,
        weatherIconPath,
        32,
        50,
        16,
        'N',
        this->centralWidget
    );
    this->centralLayout->addWidget(weatherHeaderWidget, 0, Qt::AlignCenter);
    this->centralWidget->setStyleSheet("QWidget { border: 2px solid lime; }");
}

void MainWindow::setupWindow() {
    this->setWindowTitle("Weather Dashboard");
    this->setMinimumSize(480, 270);
    this->setCentralWidget(this->centralWidget);
    this->centralWidget->setLayout(this->centralLayout);
}

// TODO: Figure out why the fuck your widget is in the goddamn corner

MainWindow::~MainWindow() {}