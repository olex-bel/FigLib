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
    std::vector<FigLib::Point> house_points;
    std::vector<FigLib::Point> lettert_points;
    std::vector<FigLib::Point> *start_points;
    std::vector<FigLib::Point> *end_points;
    float step;

private slots:
    void inc_step();
};

#endif // CANVA_H

