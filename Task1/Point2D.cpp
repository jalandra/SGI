#include "Point2D.h"
//constructor
Point2D::Point2D( float xarg, float yarg ) : x(xarg), y(yarg) {}

float Point2D::getXCoordinate() const
{
  return x;  
}

float Point2D::getYCoordinate() const
{
  return y;
}

//for comparison
bool Point2D::operator==( const Point2D& rhs)
{
  return x == rhs.x && y == rhs.y;
}