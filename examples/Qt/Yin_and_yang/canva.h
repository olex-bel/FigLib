#ifndef CANVA_H
#define CANVA_H

#include <QGLWidget>
#include "ngon.h"

class Canva : public QGLWidget
{
    Q_OBJECT
public:
    explicit Canva(QWidget *parent = 0);

protected:
    virtual void initializeGL();
    virtual void paintGL();
    virtual void resizeGL(int w, int h);

private:

    FigLib::Arc topArc;
    FigLib::Arc bottomArc;
    FigLib::Circle bigCircle;
    FigLib::Circle smallCircle;
};

#endif // CANVA_H

