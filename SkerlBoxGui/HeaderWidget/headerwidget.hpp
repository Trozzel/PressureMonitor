#ifndef HEADERWIDGET_HPP
#define HEADERWIDGET_HPP

#include <QWidget>
#include <QString>
#include <QThread>
#include <QDateTime>
#include <QListWidget>
#include <QCheckBox>
#include <QPicture>
#include <QPixmap>

#include <string>
#include <sstream>
#include <iostream>
#include <filesystem>

#include "timeupdater.hpp"
#include "digitaloutdisplay.hpp"
#include "iDioObserver.hpp"
#include "iObservableDevice.hpp"
#include "ancillary.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class HeaderWidget; }
QT_END_NAMESPACE

class HeaderWidget : public QWidget, public iDioObserver
{
    Q_OBJECT
private:
    Ui::HeaderWidget *ui;

    DigitalOutDisplay* _digitalOutDisplay;
    TimeUpdater* _timeUpdater;
    std::thread  _runThread;

    // HELPER FUNCTIONS
    void updateCurrentDate();
    void createWidgets();
    void killResources();

protected:
    void closeEvent(QCloseEvent *event) override;

public:
    HeaderWidget(QWidget *parent = nullptr,
                 iObservableDevice* pObservableDevice=nullptr);
    ~HeaderWidget();

    void openPorts() override;
    void closePorts() override;

    void update(const std::string& data) override;

public slots:
    void updateCurrentTime(const QString& currentTime);

private slots:
    void on_quitBtn_clicked();
};
#endif // HEADERWIDGET_HPP
