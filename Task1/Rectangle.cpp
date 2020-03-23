/*Rectangle.cpp*/

#include "Rectangle.h"
#include <iostream>
#include <cmath>

using namespace std;
//Method: Create a rectangle given len, breadth and bottomLeft coordinates
//Assumption: length, breadth and bottom left coordinate would be given
Rectangle::Rectangle(float aLength, float aBreadth, float bottomLeftX, float bottomLeftY)
  : length(aLength), breadth(aBreadth)
{
  bottomLeft = Point2D(bottomLeftX, bottomLeftY);
  bottomRight = Point2D(bottomLeftX + length, bottomLeftY);
  topLeft = Point2D(bottomLeftX, bottomLeftY + breadth);
  topRight = Point2D(bottomLeftX + length, bottomLeftY + breadth);
}

//Method: Create a rectangle given two points
//Assumption: The two points would be diagonally opposite points
Rectangle::Rectangle(const Point2D& p1, const Point2D& p2)
{
  length = abs(p1.getXCoordinate() - p2.getXCoordinate());
  breadth = abs(p1.getYCoordinate() - p2.getYCoordinate());

  // Find the coordinates of the rectangle
  if (p1.getXCoordinate() <= p2.getXCoordinate()) {
    if (p1.getYCoordinate() <= p2.getYCoordinate()) {
      bottomLeft = p1;
      topRight = p2;
      bottomRight = Point2D(topRight.getXCoordinate(), bottomLeft.getYCoordinate());
      topLeft = Point2D(bottomLeft.getXCoordinate(), topRight.getYCoordinate());
    } else {
      topLeft = p1;
      bottomRight = p2;
      bottomLeft = Point2D(topLeft.getXCoordinate(), bottomRight.getYCoordinate());
      topRight = Point2D(bottomRight.getXCoordinate(), topLeft.getYCoordinate());
    }
  } else {
    if (p1.getYCoordinate() <= p2.getYCoordinate()) {
      bottomRight = p1;
      topLeft = p2;
      bottomLeft = Point2D(topLeft.getXCoordinate(), bottomRight.getYCoordinate());
      topRight = Point2D(bottomRight.getXCoordinate(), topLeft.getYCoordinate());
    } else {
      topRight = p1;
      bottomLeft = p2;
      bottomRight = Point2D(topRight.getXCoordinate(), bottomLeft.getYCoordinate());
      topLeft = Point2D(bottomLeft.getXCoordinate(), topRight.getYCoordinate());
    }
  }
}

// Method: Copy Constructor
Rectangle::Rectangle(const Rectangle& rhs)
{
  length = rhs.length;
  breadth = rhs.breadth;
  bottomLeft = rhs.bottomLeft;
  bottomRight = rhs.bottomRight;
  topLeft = rhs.topLeft;
  topRight = rhs.topRight;
}

// Method: Assignment operator
Rectangle& Rectangle::operator=(const Rectangle& rhs)
{
  bool is_equal = (*this == rhs);
  if( !is_equal ) {
    length = rhs.length;
    breadth = rhs.breadth;
    bottomLeft = rhs.bottomLeft;
    bottomRight = rhs.bottomRight;
    topLeft = rhs.topLeft;
    topRight = rhs.topRight;
  }
  return *this;
}

//Method: operator for equivalency checking
bool Rectangle::operator == (const Rectangle& rhs)
{
  return length == rhs.length && breadth == rhs.breadth
    && bottomLeft == rhs.bottomLeft
    && bottomRight == rhs.bottomRight
    && topLeft == rhs.topLeft
    && topRight == rhs.topRight;
}


// Method: Algorithm that checks whether or not a 2D point is contained in an axis-aligned Rectangle
// One more Algo could be to check if a point intersects the rectagnle twice or once
bool Rectangle::isPointInsideRectangle(Point2D& p)
{
  if ( (bottomLeft.getXCoordinate() <= p.getXCoordinate() && bottomRight.getXCoordinate() >= p.getXCoordinate())
    && (bottomLeft.getYCoordinate() <= p.getYCoordinate() && topLeft.getYCoordinate() >= p.getYCoordinate()) ) {
    return true;
  } else {
    return false;
  }
}

// Method: Algorithm that checks whether or not two axis-aligned Rectangles intersect
bool Rectangle::isRectangleIntersects(Rectangle& rec)
{
  if ( (isPointInsideRectangle(rec.bottomLeft)
    || isPointInsideRectangle(rec.bottomRight)
    || isPointInsideRectangle(rec.topLeft)
    || isPointInsideRectangle(rec.topRight)) 
    || (rec.isPointInsideRectangle(this->bottomLeft) //where given rectangle is smaller breadth
    || rec.isPointInsideRectangle(this->bottomRight)
    || rec.isPointInsideRectangle(this->topLeft)
    || rec.isPointInsideRectangle(this->topRight)) )
  {
    return true;
  } else {
    return false;
  }
}

void Rectangle::printRectangle()
{
  std::cout << "(" <<  topLeft.getXCoordinate() << ", " << topLeft.getYCoordinate() << "), (" <<
          topRight.getXCoordinate() << ", " << topRight.getYCoordinate() << "), (" <<
          bottomRight.getXCoordinate() << ", " << bottomRight.getYCoordinate() << "), (" <<
          bottomLeft.getXCoordinate() << ", " << bottomRight.getYCoordinate() << ")" << endl; 
}