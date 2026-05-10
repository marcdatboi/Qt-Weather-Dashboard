



#include "WeatherNowWidget.hpp"

WeatherNowWidget::WeatherNowWidget
(
        QString& locationName,
        QString& pathToWeatherIcon, // Use forward slashes
        int temperatureF,
        int precipitationChance,
        int windSpeedMPH,
        QChar windDirection, // N = north, E = east, S = south, W = west
        QWidget *parent
)
    : QWidget(parent)

    // Layouts
    , centralLayout(new QVBoxLayout(this))
    , centralWeatherInfoLayout(new QHBoxLayout(this))

    // Data
    , locationName(locationName)
    , temperatureF(temperatureF)
    , precipitationChance(precipitationChance)
    , windSpeedMPH(windSpeedMPH)
    , windDirection(windDirection)

    // Visuals
    , locationNameLabel(new QLabel(this->locationName,this))
    , currentTemperatureLabel(new QLabel(QString("Temperature: %1°F").arg(this->temperatureF), this))
    , precipitationChanceLabel(new QLabel(QString("Precipitation: %1%").arg(this->precipitationChance), this))
    , windDirectionAndSpeedLabel(new QLabel(QString("Wind: %1 MPH %2°").arg(this->windSpeedMPH).arg(this->windDirection),this))
    , weatherNowIconLabel(new QLabel(this))
{
    this->initWidget();

}

void WeatherNowWidget::initWidget()
{
    // Widget Properties
    this->setFixedHeight(500);
    this->setLayout(this->centralLayout);

    // Location Label
    this->initLocationWidget();

    // Weather Info
    this->initWeatherInfo();

}

void WeatherNowWidget::initLocationWidget()
{
    this->locationNameLabel->setStyleSheet(QString(
        "QLabel {"
        "   font-size: 30px;"
        "}"
    ));
    this->locationNameLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->centralLayout->addWidget(this->locationNameLabel, 0, Qt::AlignLeft);
}

void WeatherNowWidget::initWeatherInfo()
{
    float weatherIconSizeMultiplier = 1.1;


    // --- Weather Icon ---
    QPixmap weatherNowIconPixMap("C:/DevFolder/C++/qt_projects/Weather-Dashboard/weather_icons/SunnyIcon.png");
    if (weatherNowIconPixMap.isNull()) {
        qDebug() << "ERROR: Could not find or load the 'weatherNowIconPixMap' QPixmap object.";
    }
    this->weatherNowIconLabel->setFixedSize(this->weatherNowIconLabel->width() * weatherIconSizeMultiplier, this->weatherNowIconLabel->width() * weatherIconSizeMultiplier);
    this->weatherNowIconLabel->setPixmap(weatherNowIconPixMap.scaled(this->weatherNowIconLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    this->centralWeatherInfoLayout->setContentsMargins(0, 10,0,0);
    this->centralWeatherInfoLayout->addWidget(this->weatherNowIconLabel, 0, Qt::AlignLeft | Qt::AlignTop);

    this->centralLayout->addLayout(this->centralWeatherInfoLayout, 0); // Add Layout to main layout


    // --- Precipitation, Temperature, Wind Direction, Wind Speed ---
    this->currentTemperatureLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->precipitationChanceLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->windDirectionAndSpeedLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    auto *weatherInfoLayout = new QVBoxLayout(this);
    weatherInfoLayout->addWidget(this->currentTemperatureLabel, 0);
    weatherInfoLayout->addWidget(this->precipitationChanceLabel, 0);
    weatherInfoLayout->addWidget(this->windDirectionAndSpeedLabel, 0);

    centralWeatherInfoLayout->addLayout(weatherInfoLayout);
    // TODO: Put 'weatherInfoLayout' in a widget so everything within it is sized correctly :3
}
WeatherNowWidget::~WeatherNowWidget() {}