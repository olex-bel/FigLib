#include "ngon.h"
#define _USE_MATH_DEFINES
#include <cmath>


namespace FigLib {

    NGon::NGon()
        :bCulculated(false)
    {
    }

    void NGon::draw(float cx, float cy, float cz, GLenum mode)
    {
        if ( !bCulculated ) return;

        glBegin(mode);
            for ( size_t i = 0; i<points.size(); ++i)
                glVertex3f(cx + points[i].x, cy + points[i].y, cz);
        glEnd();
    }

    size_t NGon::size()
    {
        return bCulculated?points.size():0;
    }

    Point NGon::operator[](size_t i) const
    {
        return points[i];
    }

    void Polygon::calculate(size_t n, float radius, float angle)
    {
        bCulculated = false;
        points.clear();

        if ( n < 3 ) return;

        float rotAngle = angle * M_PI / 180.0f;
        float stepAngle = 2.0f * M_PI / n;

        points.resize(n);

        for ( size_t i = 0; i<n; ++i ){
            points[i].x = radius * cos(rotAngle);
            points[i].y = radius * sin(rotAngle);
            rotAngle += stepAngle;
        }

        bCulculated = true;
    }

    void Arc::calculate(float radius, float startAngle, float spanAngle, unsigned int quality)
    {
        bCulculated = false;
        points.clear();

        if ( quality < 3 ) return;

        float angle = startAngle * M_PI / 180.0f;
        float stepAngle = (spanAngle / quality)  * M_PI / 180.0f;

        points.resize(quality + 1);
        for ( unsigned int i = 0; i < points.size(); ++i ){
            points[i].x = radius * cos(angle);
            points[i].y = radius * sin(angle);
            angle += stepAngle;
        }

        bCulculated = true;
    }

    void Circle::calculate(float radius, unsigned int quality)
    {
        Polygon::calculate(quality, radius, 0.0f);
    }

    void RoundRect::calculate(float width, float height, float g)
    {
        Arc arcs[4];
        Point position[4];

        bCulculated = false;
        points.clear();

        float radius = g*width;
        float dbl_radius = 2 * radius;

        if ( dbl_radius > height || dbl_radius > width ) return;

        float w = (width - 2 * radius) / 2;
        float h = (height - 2 * radius) / 2;

        position[0].x = w;
        position[0].y = h;
        position[1].x = -w;
        position[1].y = h;
        position[2].x = -w;
        position[2].y = -h;
        position[3].x = w;
        position[3].y = -h;

        arcs[0].calculate(radius, 0.0f, 90.0f);
        arcs[1].calculate(radius, 90.0f, 90.0f);
        arcs[2].calculate(radius, 180.0f, 90.0f);
        arcs[3].calculate(radius, 270.0f, 90.0f);

        for ( size_t nArc = 0; nArc < 4; ++nArc ){
            for ( size_t i = 0; i<arcs[nArc].size(); ++i ){
                Point p = arcs[nArc][i];
                p.x += position[nArc].x;
                p.y += position[nArc].y;

                points.push_back(p);
            }
        }

        bCulculated = true;
    }

    void Ellipse::calculate(float width, float height, unsigned int quality)
    {
        bCulculated = false;
        points.clear();
        unsigned int n = quality;

        if ( n < 3 ) return;

        float rotAngle = 0.0f;
        float stepAngle = 2.0f * M_PI / n;

        points.resize(n);

        for ( size_t i = 0; i<n; ++i ){
            points[i].x = width * cos(rotAngle);
            points[i].y = height * sin(rotAngle);
            rotAngle += stepAngle;
        }

        bCulculated = true;
    }
};
