



#pragma once

#include <QLabel>
#include <QVBoxLayout>

class WeatherNowWidget : public QWidget {
    Q_OBJECT

public:
    WeatherNowWidget
    (
        QString &locationName,
        QString &pathToWeatherIcon, // Use forward slashes
        int temperatureF,
        int precipitationChance,
        int windSpeedMPH,
        QChar windDirection, // N = north, E = east, S = south, W = west
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

};