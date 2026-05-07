



#pragma once

#include <QWidget>
#include <QString>
#include <QLabel>

class WeatherNowWidget : public QWidget {
    Q_OBJECT

public:
    WeatherNowWidget
    (
        QString& locationName,
        QString& pathToWeatherIcon, // Use forward slashes
        int temperatureF,
        int precipitationChance,
        int windSpeedMPH,
        char windDirection, // N = north, E = east, S = south, W = west
        QWidget *parent = nullptr
    );
    ~WeatherNowWidget();

private:

    // Data
    const QString locationName;
    const QString pathToWeatherIcon;
    int temperatureF;
    int precipitationChance;
    int windSpeedMPH;
    char windDirection;

    // Visuals
    QLabel *locationNameLabel;
    QLabel *weatherDataLabel; // Contains temperature, precipitation chance, wind direction, and wind speed
    QLabel *weatherIconLabel;

    void initWidget(); // Initializes the starting properties of the widget upon creation
};