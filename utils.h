#ifndef UTILS_H
#define UTILS_H

#include "ngon.h"

namespace FigLib{

    void tween(const std::vector<Point>& start_points, const std::vector<Point>& end_points,
               std::vector<Point>& tween_points, float t);

}

#endif
