#include "canva.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include "utils.h"
#include <QTimer>

Canva::Canva(QWidget *parent) :
    QGLWidget(parent)
{   
    resize(500, 500);

    ellipse1.calculate(20.0f, 10.0f);
    ellipse2.calculate(10.0f, 30.0f);
    rect1.calculate(50.0f, 30.0f, 0.2);
    rect2.calculate(20.0f, 60.0f, 0.1);
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

    glColor3f(1.0f, 1.0f, 0.0f);
    ellipse1.draw(10.0f, 10.0f, 0.0f);
    ellipse2.draw(40.0f, 40.0f, 0.0f);
    rect1.draw(-30.0f, -40.0f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    rect1.draw(-30.0f, 30.0f, 0.0f);
    ellipse1.draw(-50.0f, -10.0f, 0.0f);
    rect2.draw(70.0f, 50.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    ellipse2.draw(50.0, -50.0f, 0.0f);
    rect2.draw(25.0f, -30.0f, 0.0f);
}
