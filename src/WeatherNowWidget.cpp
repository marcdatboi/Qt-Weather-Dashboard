



#include <QStyleOption>
#include <QPainter>
#include "WeatherNowWidget.hpp"

WeatherNowWidget::WeatherNowWidget
(
        QString& locationName,
        int temperatureF,
        int precipitationChance,
        int windSpeedMPH,
        QChar windDirection, // N = north, E = east, S = south, W = west
        int weatherInfoFontSize,
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
    , weatherInfoFontSize(weatherInfoFontSize)
    , windDirection(windDirection)

    // Visuals
    , locationNameLabel(new QLabel(this->locationName,this))
    , currentTemperatureLabel(new QLabel(QString("Temperature: %1°F").arg(this->temperatureF), this))
    , precipitationChanceLabel(new QLabel(QString("Precipitation: %1%").arg(this->precipitationChance), this))
    , windDirectionAndSpeedLabel(new QLabel(QString("Wind: %1 MPH %2°").arg(this->windSpeedMPH).arg(this->windDirection),this))
    , weatherNowIconLabel(new QLabel(this))
{
    this->initWidget(); // This initializes everything
    this->setFixedHeight(this->sizeHint().height());
}

void WeatherNowWidget::initWidget()
{
    /*
     * @brief   Initializes the starting state of the widget
     */
    // Widget Properties
    this->setLayout(this->centralLayout);

    // Location Label
    this->initLocationWidget();

    // Weather Info
    this->initWeatherInfo();

    // Colors
    this->colorWidget();

}

void WeatherNowWidget::initLocationWidget()
{
    /*
     * @brief   Initializes the QLabel that displays the city's name (Seattle)
     */
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
    /*
     * @brief       Initializes all the weather info of the class instance including
     *              the weather icon.
     *
     * @details     This function sets up all the info for the widget like precipitation,
     *              wind speed, wind direction, temperature and weather icon.
     */
    float weatherIconSizeMultiplier = 1.1;


    // --- Weather Icon ---
    QPixmap weatherNowIconPixMap("C:/DevFolder/C++/qt_projects/Weather-Dashboard/weather_icons/SunnyIcon.png");
    if (weatherNowIconPixMap.isNull()) {
        qDebug() << "ERROR: Could not find or load the 'weatherNowIconPixMap' QPixmap object.";
    }
    this->weatherNowIconLabel->setFixedSize(this->weatherNowIconLabel->width() * weatherIconSizeMultiplier, this->weatherNowIconLabel->width() * weatherIconSizeMultiplier);
    this->weatherNowIconLabel->setPixmap(weatherNowIconPixMap.scaled(this->weatherNowIconLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    this->centralWeatherInfoLayout->addWidget(this->weatherNowIconLabel, 0);

    this->centralLayout->addLayout(this->centralWeatherInfoLayout); // Add Layout to main layout


    // --- Precipitation, Temperature, Wind Direction, Wind Speed ---
    QWidget *weatherInfoWidget = new QWidget(this);
    auto *weatherInfoLayout = new QVBoxLayout(weatherInfoWidget);
    weatherInfoWidget->setLayout(weatherInfoLayout);
    weatherInfoWidget->setFixedHeight(this->weatherNowIconLabel->height());

    this->currentTemperatureLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->precipitationChanceLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->windDirectionAndSpeedLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    // Setting Font Size
    this->currentTemperatureLabel->setStyleSheet(QString("QLabel { font-size: %1px; }").arg(this->weatherInfoFontSize));
    this->precipitationChanceLabel->setStyleSheet(QString("QLabel { font-size: %1px; }").arg(this->weatherInfoFontSize));
    this->windDirectionAndSpeedLabel->setStyleSheet(QString("QLabel { font-size: %1px; }").arg(this->weatherInfoFontSize));

    weatherInfoLayout->addWidget(this->currentTemperatureLabel, 0);
    weatherInfoLayout->addWidget(this->precipitationChanceLabel, 0);
    weatherInfoLayout->addWidget(this->windDirectionAndSpeedLabel, 0);

    centralWeatherInfoLayout->addWidget(weatherInfoWidget);
}

void WeatherNowWidget::colorWidget()
{
    /*
     *  @brief      Responsible for giving the widget its gradient color.
     */

    // --- Widget Colors ---
    this->setObjectName("weatherNowWidget");
    this->setStyleSheet(QString(
    "#weatherNowWidget {"
        "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #ff5f6d, stop:1 #ffc371);"
        "border-radius: 10px;"
        "border: 1px solid #ff5f6d"
    "}"
    ));


    // --- Weather location widget and weather info ---
    // To Be implemented xd
}



// --- Overrides ---
QSize WeatherNowWidget::sizeHint() const
{
    // This returns the minimum size the layout needs to keep everything organized
    return layout()->minimumSize();
}

void WeatherNowWidget::paintEvent(QPaintEvent *event)
{
    /*
     *  @brief      This override only exist to give this widget the ability to be colored.
     */
    QStyleOption opt;
    opt.initFrom(this);

    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

WeatherNowWidget::~WeatherNowWidget() {}
