/*
Task 1 Specification:
Design and Implement a C++ program that implements the following:
• 2D Rectangle Class with floating point coordinates
  o Include methods for constructing an axis-aligned Rectangle with initial size and coordinates
  o Include a Copy constructor and an Assignment operator
• Algorithm that checks whether or not a 2D point is contained in an axis-aligned Rectangle
• Algorithm that checks whether or not two axis-aligned Rectangles intersect
• Simple test code that creates instances of your class and tests your implementation
*/

/* class Point2D.h
handles x,y points for a rectagle
*/
#include<iostream>

class Point2D
{
  float x;
  float y;
public:
  Point2D(){}
  Point2D(float xarg, float yarg);
  
  float getXCoordinate() const;
  float getYCoordinate() const;
  bool operator== (const Point2D& rhs);
};