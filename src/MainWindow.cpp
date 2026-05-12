



#include "MainWindow.hpp"
#include "WeatherNowWidget.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , centralWidget(new QWidget(this))
    , centralLayout(new QVBoxLayout(this->centralWidget))
{
    this->setupWindow();

    QString locationName = "Example Location";
    WeatherNowWidget *weatherHeaderWidget = new WeatherNowWidget
    (
        locationName,
        32,
        50,
        16,
        'N',
        25,
        this->centralWidget
    );
    this->centralLayout->addStretch();
    this->centralLayout->addWidget(weatherHeaderWidget, 0, Qt::AlignCenter);
    this->centralLayout->addStretch();
}

void MainWindow::setupWindow() {
    this->setWindowTitle("Weather Dashboard");
    this->setMinimumSize(480, 270);
    this->setCentralWidget(this->centralWidget);
    this->centralWidget->setLayout(this->centralLayout);
}

// TODO: Start implementing the 7-day forecast

MainWindow::~MainWindow() {}