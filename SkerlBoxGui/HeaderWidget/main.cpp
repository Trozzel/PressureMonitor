#include "headerwidget.hpp"

#include <QThread>
#include <QApplication>

#include <thread>

#include "ancillary.hpp"
#include "DummyDevice.hpp"
#include "DummyObserver.hpp"
#include "Ruska.hpp"
#include "MccDio96H.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    Ruska ruska {"/dev/tty.usbserial-A6031LVH"};
//    DummyDevice ruska;
    MccDio96H digDevice(&ruska);

    QApplication a(argc, argv);
    HeaderWidget w(nullptr, &ruska);

    thread t(&Ruska::run, &ruska, 5000);

    w.show();
    int res = a.exec();
    t.join();
    return res;
}
