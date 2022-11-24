#include "include/cub3d.h"
double fix_angle(double angle)
{
    if (angle > 2 * M_PI)
        angle -= 2 * M_PI;
    if (angle < 0)
        angle += 2 * M_PI;
    return angle;
}
