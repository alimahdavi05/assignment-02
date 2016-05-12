 /* ----------------------------------------------------------------------------
  * Copyright &copy; 2016 alimahdavi <alimahdavi05@csu.fullerton.edu>
  * Released under the [MIT License] (http://opensource.org/licenses/MIT)
  * ------------------------------------------------------------------------- */
  
  #include <iostream>
using namespace std;
void main()
{
int x, i, j, b;
for(x=1;x<=6;x++)
{
if(x==1 || x==6)
{
for(i=1;i<=7;i++)
{
if(i==3 || i==4 || i==5)
cout<<"*";
else
cout<<" ";
}
cout<<endl;
 }
 else
 if(x==2||x==5)
 {
 for(j=1;j<=7;j++)
 {
  if(j==2||j==6)
  cout<<"*";
  else
  cout<<" ";
  }
  cout<<endl;
  }
 else
 {
 for(b=1;b<=7;b++)
  {
 if(b==1||b==7)
   cout<<"*";
  else
  cout<<" ";
  }
  cout<<endl;
  }
  }
}
/* This marks the end of week1 program to draw an ellipse*/
 
 
 
 
 
 
/* This marks the beginning of the week 2 quiz
*/
#include "buffer.h"
#include "constants.h"
#include "neighborhood.h"
#include "shape.h"
#include <iostream.h>
#include <conio.h>
voidtest_buffer() {
    Buffer b(TERM_SIZE_X, TERM_SIZE_Y);
    // draw ellipse
for (int y=0; y <b.size_y; y++)
for (int x=0; x <b.size_x; x++)
if ( (x-40)*(x-40) + (y-10)*(y-10) == 50)
b.set(x, y, '*');
    // draw border
for (int y=0; y <b.size_y; y++) {
b.set(0, y, '|');
b.set(b.size_x-1, y, '|');
    }
for (int x=0; x <b.size_x; x++) {
b.set(x, 0, '-');
b.set(x, b.size_y-1, '-');
    }
    // render to screen
b.draw();
}
/**
 * Test the `Shape` object by creating one of each type (besides "empty"), and
 * tiling them on a buffer.
 */
voidtest_shape() {
    Buffer b(TERM_SIZE_X, TERM_SIZE_Y);
    Shape triangle("triangle");
    Shape square("square");
    // draw shapes
for (int y = 0; y <= b.size_y - Shape::size_y; y += Shape::size_y) {
for (int x = 0; x <= b.size_x - Shape::size_x*2; x += Shape::size_x*2) {
triangle.drawToBuffer(b, x + Shape::size_x*((y+0)%2), y);
square.drawToBuffer(b, x + Shape::size_x*((y+1)%2), y);
        }
    }
    // render to screen
b.draw();
}
// ----------------------------------------------------------------------------
int main() {
test_buffer();
test_shape();
animate  neighborhood
unsignedintsize_x = TERM_SIZE_X/Shape::size_x;
unsignedintsize_y = TERM_SIZE_Y/Shape::size_y;
Neighborhood(size_x, size_y).animate(1000);
return 0;  // success
}
//This is the neighbourhood.h file
#ifndefneighborhood_h
#define neighborhood_h
#endif  // neighborhood_h
// Neighbourhood.cpp
#include <random>
#include "neighborhood.h"
namespace {
unsignedintmtrand(unsigned int low, unsigned int high) {
static std::random_device rd;
staticstd::mt19937 mt(rd());  // engine (mersenne twister)
returnstd::uniform_int_distribution<unsigned int>(low, high)(mt);
}
}
