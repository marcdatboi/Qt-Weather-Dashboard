



#include "MainWindow.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , centralWidget(new QWidget(this))
    , centralLayout(new QVBoxLayout(this->centralWidget))
{

}

void MainWindow::setupWindow() {
    this->setWindowTitle("Weather Dashboard");
    this->setMinimumSize(480, 270);
    this->setCentralWidget(this->centralWidget);
    this->centralWidget->setLayout(this->centralLayout);
}

MainWindow::~MainWindow() {}