#include <QApplication>
#include <GL/glut.h>
#include "canva.h"

int main(int ac, char** av)
{
    QApplication app(ac, av);

    QGLFormat f = QGLFormat::defaultFormat();
    f.setSampleBuffers(true);
    QGLFormat::setDefaultFormat(f);

    Canva wnd;

    wnd.show();

    return app.exec();
}

