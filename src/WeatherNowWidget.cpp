



#include "WeatherNowWidget.hpp"

WeatherNowWidget::WeatherNowWidget
(
        QString& locationName,
        QString& pathToWeatherIcon, // Use forward slashes
        int temperatureF,
        int precipitationChance,
        int windSpeedMPH,
        char windDirection, // N = north, E = east, S = south, W = west
        QWidget *parent
)
    : QWidget(parent)

    // Data
    , locationName(locationName)
    , pathToWeatherIcon(pathToWeatherIcon)
    , temperatureF(temperatureF)
    , precipitationChance(precipitationChance)
    , windSpeedMPH(windSpeedMPH)
    , windDirection(windDirection)

    // Visuals
    , locationNameLabel(new QLabel(this))
    , weatherDataLabel(new QLabel(this))
    , weatherIconLabel(new QLabel(this))
{
    /*
     * TODO:
     * Implement the initialize function
     * Implement destructor
     */
}