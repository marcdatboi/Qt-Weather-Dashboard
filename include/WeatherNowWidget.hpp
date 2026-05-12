



#pragma once

#include <QLabel>
#include <QVBoxLayout>

class WeatherNowWidget : public QWidget {
    Q_OBJECT

public:
    WeatherNowWidget
    (
        QString &locationName,
        int temperatureF,
        int precipitationChance,
        int windSpeedMPH,
        QChar windDirection, // N = north, E = east, S = south, W = west
        int weatherInfoFontSize,
        QWidget *parent = nullptr
    );
    ~WeatherNowWidget();

private:

    // Layouts
    QVBoxLayout *centralLayout;
    QHBoxLayout *centralWeatherInfoLayout;

    // Data
    const QString locationName;
    int temperatureF;
    int precipitationChance;
    int windSpeedMPH;
    int weatherInfoFontSize;
    QChar windDirection;

    // Visuals
    QLabel *locationNameLabel;
    QLabel *currentTemperatureLabel;
    QLabel *precipitationChanceLabel;
    QLabel *windDirectionAndSpeedLabel;
    QLabel *weatherNowIconLabel;

    void initWidget(); // Initializes the starting properties of the widget upon creation
    void initLocationWidget();
    void initWeatherInfo(); // Icon, Temperature, precipitation, wind direction, and wind speed

    // QStyleSheetz stuff
    void paintEvent(QPaintEvent *event) override;
    void colorWidget(); // Adds color to the class instance to make it look nice :D

    QSize sizeHint() const override; // Ensures sure the widget is correctly sized.

};