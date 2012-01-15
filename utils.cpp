#include "utils.h"

namespace FigLib {

    void tween(const std::vector<Point>& start_points, const std::vector<Point>& end_points,
               std::vector<Point> &tween_points, float t)
    {
        tween_points.clear();

        if ( t > 1.0f && t < 0.0f ) return;
        if ( start_points.size() != end_points.size() ) return;

        tween_points.resize(start_points.size());

        for ( size_t i = 0; i<start_points.size(); ++i ){
            tween_points[i].x = (1 - t) * start_points[i].x + t * end_points[i].x;
            tween_points[i].y = (1 - t) * start_points[i].y + t * end_points[i].y;
        }
    }

};
