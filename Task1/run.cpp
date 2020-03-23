
#include "Rectangle.h"

using namespace std;

// Simple test code that drives the Rectangle implementaion
int main( )
{
  cout<< "Rectangle Testing Loading..."<<endl;
  sleep(1);
  cout << "Testing Framework loaded.." << endl;
  Point2D quad1 = Point2D(2.5, 2.7);
  Point2D quad2 = Point2D(-1, 2);
  Point2D quad3 = Point2D(2.2, -1.4);
  Point2D quad4 = Point2D(-1.5 , -1.5);
  
  Rectangle test_rectangle1 = Rectangle(1.1, 2.2, 2, 2); //len, breadth, bottom left
  Rectangle test_rectangle2 = Rectangle(quad1, quad2);
  Rectangle test_rectangle3 = Rectangle(quad2, quad3);
  Rectangle test_rectangle4 = Rectangle(quad4, quad1);
 
  cout<<"\nTesting rectangle generation using length, breadth & bottom left coord:"<<endl;
  
  cout << "Expected Coordinates ---> (2, 4.2), (3.1, 4.2), (3.1, 2), (2, 2)" << endl;
  cout << "Calculated Coordinates --> ";
  test_rectangle1.printRectangle();

  sleep(2);
  cout << "\nTesting rectangle generation using two diagonally opposite points:" << endl;
  
  cout << "Expected Coordinates --> (-1, 2.7), (2.5, 2.7), (2.5, 2), (-1, 2)" << endl;
  cout << "Calculated Coordinates --> ";
  test_rectangle2.printRectangle();
  
  cout << "Expected Coordinates --> (-1, 2), (2.2, 2), (2.2, -1.4), (-1, -1.4)" << endl;
  cout << "Calculated Coordinates --> ";
  test_rectangle3.printRectangle();
  
  cout << "Expected Coordinates --> (-1.5, 2.7), (2.5, 2.7), (2.5, -1.5), (-1.5, -1.5)" << endl;
  cout << "Calculated Coordinates --> ";
  test_rectangle4.printRectangle();
 
  sleep(2);
  cout << "\nTesting whether a point lies inside a rectangle or not" << endl;
  cout << "Point1 Expected --> Yes"<<endl;
  if (test_rectangle1.isPointInsideRectangle(quad1))
  {
    cout << "Computed --> Yes" << endl;
  } else {
    cout << "Computed --> No" << endl;
  }
  
   cout << "Point2 Expected --> No"<<endl;
  if (test_rectangle1.isPointInsideRectangle(quad2))
  {
    cout << "Computed --> Yes" << endl;
  } else {
    cout << "Computed --> No" << endl;
  }

  cout << "Point3 Expected --> No"<<endl;
  if (test_rectangle1.isPointInsideRectangle(quad3))
  {
    cout << "Computed --> Yes" << endl;
  } else {
    cout << "Computed --> No" << endl;
  }
  
  cout << "Point4 Expected --> No"<<endl;
  if (test_rectangle1.isPointInsideRectangle(quad4))
  {
    cout << "Computed --> Yes" << endl;
  } else {
    cout << "Computed --> No" << endl;
  }

  sleep(2);
  cout << "\nTesting intersection of two rectangles.." << endl;

  cout << "If rectangle1 intersects with rectangle2" << endl;
  cout << "Expected: Yes"<<endl;
  test_rectangle1.isRectangleIntersects(test_rectangle2) ? (cout << "Computed: Yes"<<endl) : (cout << "Computed: No" << endl);

  cout << "If rectangle1 intersects with rectangle3" << endl;
  cout << "Expected: Yes"<<endl;
  test_rectangle1.isRectangleIntersects(test_rectangle3) ? (cout << "Computed: Yes"<<endl) : (cout << "Computed: No" << endl);

  cout << "If rectangle3 intersects with rectangle4" << endl;
  cout << "Expected: Yes"<<endl;
  test_rectangle3.isRectangleIntersects(test_rectangle4) ? (cout << "Computed: Yes"<<endl) : (cout << "Computed: No" << endl);
  
  cout<<"Testing Ended..Thanks for your patience\n";
  return 0;
}