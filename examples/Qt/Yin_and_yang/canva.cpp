#include "canva.h"
#define _USE_MATH_DEFINES
#include <cmath>

Canva::Canva(QWidget *parent) :
    QGLWidget(parent)
{
    resize(500, 500);

    topArc.calculate(40.0f, 0.0f, 180.0f);
    bottomArc.calculate(40.0f, 180.0f, 180.0f);
    bigCircle.calculate(20.0f);
    smallCircle.calculate(5.0f);
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

    glColor3f(0.0f, 0.0f, 0.0f);
    topArc.draw(0.0f, 0.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    bottomArc.draw(0.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    bigCircle.draw(-20.0f, 0.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    bigCircle.draw(20.0f, 0.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    smallCircle.draw(-20.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    smallCircle.draw(20.0f, 0.0f, 0.0f);
}

