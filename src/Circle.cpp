/*
*
* @author Nick Collins
*/ 



#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"
#include "Circle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Circle::Circle(int priority, Vec2f position, float radius, Color8u color){

	next_ = this;

	position_ = position;
	radius_ = radius;

	color_ = color;


}

bool Circle::isInside(float x, float y){

	float dist = sqrt((y-position_.y)*(y-position_.y)+(x-position_.x)*(x-position_.x));
	return (dist<=radius_);
}

void insertAfter(Circle* after_me, Circle* new_data){
	new_data->next_=after_me->next_;
	after_me->next_=new_data;

}
void Circle::update(cinder::Vec2f position, float r){


}

void Circle::draw(Vec2i mouse_pos){

	gl::color(color_);
	gl::drawSolidCircle( Vec2f(float(mouse_pos.x), float(mouse_pos.y)), radius_);

}