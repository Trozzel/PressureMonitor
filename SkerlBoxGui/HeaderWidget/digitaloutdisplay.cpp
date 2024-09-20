#include "digitaloutdisplay.hpp"

#include <filesystem>
#include <iostream>

using namespace std;

namespace fs = __fs::filesystem;

// CTOR
/******************************************************************************/
DigitalOutDisplay::DigitalOutDisplay(vector<int> ledColumnSizes,
                                     QWidget *parent) :
    QWidget(parent), _ledColumnSizes(ledColumnSizes)
{
    // INITIALIZE MEMBERS
    _mainLayout = new QVBoxLayout(this);
    this->setLayout(_mainLayout);
    if (fs::exists("../images/green-led-off.png")) {
        _ledOff.load("../images/green-led-off.png");
        _ledOn.load("../images/green-led-on.png");
    } else
        cerr << "Could not find file, '../images/green-led-off.png'" << endl;

    // CREATE LEDS
    QHBoxLayout* hLayout;
    QLabel* ledLabel; // Where the LED image is placed
    for (int numRows : _ledColumnSizes) {
        hLayout = new QHBoxLayout(this);
        _mainLayout->addLayout(hLayout);
        for (int i=0; i<numRows; ++i) {
            ledLabel = new QLabel(this);
            ledLabel->setPixmap(_ledOn);
            hLayout->addWidget(ledLabel);
            hLayout->setAlignment(ledLabel, Qt::AlignLeft);
            if (i == numRows-1)
                hLayout->addStretch(1);
            else if (numRows == 8 && i==3)
                hLayout->addSpacing(20);
        }
    }

}
