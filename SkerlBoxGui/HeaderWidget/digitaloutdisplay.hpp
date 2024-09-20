#ifndef DIGITALOUTDISPLAY_HPP
#define DIGITALOUTDISPLAY_HPP

#include <vector>

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QHBoxLayout>
#include <QVBoxLayout>

class DigitalOutDisplay : public QWidget
{
    Q_OBJECT

private:
    std::vector<int> _ledColumnSizes;
    QVBoxLayout* _mainLayout;
    QPixmap _ledOff;
    QPixmap _ledOn;

public:
    explicit DigitalOutDisplay(std::vector<int> ledColumnSizes,
                               QWidget *parent = nullptr);

signals:

};

#endif // DIGITALOUTDISPLAY_HPP
