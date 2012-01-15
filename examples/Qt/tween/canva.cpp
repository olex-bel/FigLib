#include "canva.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include "utils.h"
#include <QTimer>

Canva::Canva(QWidget *parent) :
    QGLWidget(parent), step(0.0f)
{   
    resize(500, 500);

    house_points.resize(9);
    house_points[0].x = 0.0f;
    house_points[0].y = 0.0f;
    house_points[1].x = 0.0f;
    house_points[1].y = 25.0f;
    house_points[2].x = 15.0f;
    house_points[2].y = 35.0f;
    house_points[3].x = 30.0f;
    house_points[3].y = 25.0f;
    house_points[4].x = 30.0f;
    house_points[4].y = 0.0f;
    house_points[5].x = 20.0f;
    house_points[5].y = 0.0f;
    house_points[6].x = 20.0f;
    house_points[6].y = 10.0f;
    house_points[7].x = 10.0f;
    house_points[7].y = 10.0f;
    house_points[8].x = 10.0f;
    house_points[8].y = 0.0f;

    lettert_points.resize(9);
    lettert_points[0].x = 0.0f;
    lettert_points[0].y = 20.0f;
    lettert_points[1].x = 0.0f;
    lettert_points[1].y = 30.0f;
    lettert_points[2].x = 15.0f;
    lettert_points[2].y = 30.0f;
    lettert_points[3].x = 30.0f;
    lettert_points[3].y = 30.0f;
    lettert_points[4].x = 30.0f;
    lettert_points[4].y = 20.0f;
    lettert_points[5].x = 20.0f;
    lettert_points[5].y = 20.0f;
    lettert_points[6].x = 20.0f;
    lettert_points[6].y = 0.0f;
    lettert_points[7].x = 10.0f;
    lettert_points[7].y = 0.0f;
    lettert_points[8].x = 10.0f;
    lettert_points[8].y = 20.0f;

    start_points = &house_points;
    end_points = &lettert_points;

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(inc_step()));
    timer->start(200);
}

void Canva::initializeGL()
{
    glClearColor(0.0f, 0.0f, 0.7f, 1.0f);
}

void Canva::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100.0f, 100.0f, -100.0f, 100.0f, 100.0f, -100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Canva::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    std::vector<FigLib::Point> points;

    glBegin(GL_LINE_LOOP);
        FigLib::tween(*start_points, *end_points, points, step);
        for ( size_t i = 0; i<points.size(); ++i ){
            glVertex3f(points[i].x, points[i].y, 0.0f);
        }
    glEnd();
}

void Canva::inc_step()
{
    float delta = 0.1f;

    step += delta;

    if ( step > 1.0f + delta / 2.0f ) {
        step = 0.0f;
        start_points->swap(*end_points);
    }
    updateGL();
}
