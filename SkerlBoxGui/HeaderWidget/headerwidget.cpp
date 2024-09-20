#include "headerwidget.hpp"
#include "./ui_headerwidget.h"

using namespace std;
namespace fs = __fs::filesystem;

// UPDATE CURRENT DATE: (not in thread)
/******************************************************************************/
void HeaderWidget::updateCurrentDate()
{
    QDate today = QDate::currentDate();
    ui->dateLabel->setText(today.toString());
}

// CREATE DIGITAL PORT INDICATOR
/******************************************************************************/
void HeaderWidget::createWidgets()
{
    // 1. ADD DIGITAL OUT DISPLAY
    std::vector<int> rowNums = {8,8,4,4};
    _digitalOutDisplay = new DigitalOutDisplay(rowNums, this);
    ui->ledLayout->addWidget(_digitalOutDisplay);

}

// KILL RESOURCES
/******************************************************************************/
void HeaderWidget::killResources()
{
    _timeUpdater->stopTimeLoop();
    _pObservableDevice->stopDevice();
}

// CLOSE WINDOW OVERRIDE
/******************************************************************************/
void HeaderWidget::closeEvent(QCloseEvent *event)
{
    killResources();
    QWidget::closeEvent(event);
}

// CTOR
/******************************************************************************/
HeaderWidget::HeaderWidget(QWidget *parent,
                           iObservableDevice* pObservableDevice)
    : QWidget(parent),
      iDioObserver(pObservableDevice),
      ui(new Ui::HeaderWidget)
{
    ui->setupUi(this);
    createWidgets();

    _timeUpdater = new TimeUpdater();

    updateCurrentDate();

    QThread* timeThread = new QThread();
    _timeUpdater->moveToThread(timeThread);
    connect(timeThread, SIGNAL(started()), _timeUpdater, SLOT(startTime()));
    connect(_timeUpdater, SIGNAL(timeUpdated(const QString&)), this,
            SLOT(updateCurrentTime(const QString&)));

    timeThread->start();

    // ASSIGN THE OBSERVABLE DEVICE TO FOLLOW
    if (_pObservableDevice)
    {
        this->addObservable(_pObservableDevice);
        _pObservableDevice->loadObserver(this);
    }
    else
        throw runtime_error("_pObservableDevice is NULL");
}

// DTOR
/******************************************************************************/
HeaderWidget::~HeaderWidget()
{
    delete ui;
}

// UPDATE CURRENT TIME
/******************************************************************************/
void HeaderWidget::updateCurrentTime(const QString& currentTime)
{
    ui->timeLabel->setText(currentTime);
}

// OPEN PORTS - override
/******************************************************************************/
void HeaderWidget::openPorts()
{
    return;
}

// QUIT BUTTON SOCKET - Stop Timer
/******************************************************************************/
void HeaderWidget::closePorts()
{
    return;
}

// UPDATE - override
// Called from within the the iDioObservable device
/******************************************************************************/
void HeaderWidget::update(const std::string& data)
{
    stringstream ss;
    ss << data;
    float pressure;
    ss >> pressure;
    // Clear eof flag from stringstream
    ss.str(string());
    ss.clear();
    ui->pressureLcd->display(pressure);
    return;
}

// QUIT BUTTON SOCKET - Stop Timer
/******************************************************************************/
void HeaderWidget::on_quitBtn_clicked()
{
    killResources();
    close();
}



























