#include "Point.hpp"

/*--------------------------------------------------------------*/
/*  area = abs(xa*(yb - yc) + xb*(yc - ya) + xc*(ya - yb)) / 2  */
/*--------------------------------------------------------------*/

static float getArea(Point const &a, Point const &b, Point const &c)
{
    return std::abs(
        a.GetX().toFloat() * (b.GetY().toFloat() - c.GetY().toFloat()) +
        b.GetX().toFloat() * (c.GetY().toFloat() - a.GetY().toFloat()) +
        c.GetX().toFloat() * (a.GetY().toFloat() - b.GetY().toFloat())
    ) / 2.0f;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    if (point == a || point == b || point == c) 
        return false;
    float epsilon = 0.00001f;
    float abc = getArea(a, b, c);
    float abp = getArea(a, b, point);
    float apc = getArea(a, point, c);
    float pcb = getArea(point, b, c);
    if (abp == 0 || apc == 0 || pcb == 0) 
        return false;
    return std::abs(abc - (abp + apc + pcb)) < epsilon;
}
