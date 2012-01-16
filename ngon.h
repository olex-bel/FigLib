#ifndef NGON_H
#define NGON_H

#include <GL/gl.h>
#include <vector>


namespace FigLib{

    struct Point{
        float x, y;
    };

    class NGon{
    protected:
        std::vector<Point> points;
        bool bCulculated;

    public:
        NGon();
        void draw(float cx, float cy, float cz, GLenum mode = GL_POLYGON);
        size_t size();
        Point operator[](size_t i) const;
    };

    class Polygon: public NGon
    {
    public:
        void calculate(size_t n, float radius, float angle);
    };

    class Arc: public NGon
    {
    public:
        void calculate(float radius, float startAngle, float spanAngle, unsigned int quality = 50);
    };

    class Circle: public Polygon
    {
    public:
        void calculate(float radius, unsigned int quality = 50);
    };

    class RoundRect: public NGon
    {
    public:
        void calculate(float width, float height, float g);
    };

    class Ellipse: public NGon
    {
    public:
        void calculate(float width, float height, unsigned int quality = 50);
    };
};

#endif // NGON_H
