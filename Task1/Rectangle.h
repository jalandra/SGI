/* 2D Rectangle Class with floating point coordinates */


#include "Point2D.h"

class Rectangle
{
private:
  //Stores coordinates of the Rectangle
  Point2D bottomLeft;
  Point2D bottomRight;
  Point2D topLeft;
  Point2D topRight;
  // len & breadth of Rectangle
  float length;
  float breadth;

public:
  // Methods for constructing a Rectangle with initial size and coordinates
  Rectangle(float, float , float , float );
  Rectangle(const Point2D&, const Point2D&);

  // Copy Constructor
  Rectangle(const Rectangle&);

  // Assignment operator
  Rectangle& operator=(const Rectangle&);
  
  // check for equialency
  bool operator == (const Rectangle&);
  
  // Algorithm that checks whether or not a 2D point is contained in an axis-aligned Rectangle
  bool isPointInsideRectangle(Point2D&);
  
  // Algorithm that checks whether or not two axis-aligned Rectangles intersect
  bool isRectangleIntersects(Rectangle& rectangle);
  
  //for Testing
  void printRectangle();
};