/**
* @file Circle.h
* The circles make up the nodes that populate the
* linked list (List)
*
* @author Nick Collins
* @date 2012-09-24
*
*/


#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"
using namespace ci;
using namespace ci::app;
using namespace std;

class Circle{
public:

	
	Circle* next_;
	ci::Vec2f position_;
	float radius_;
	// Color of the larger "parent" circle
	cinder::ColorA8u color_;

	// Color of the smaller "child" circle
	cinder::ColorA8u child_color_;
	
};

