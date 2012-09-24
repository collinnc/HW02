#include "List.h"

void List::reverse(Circle* sentinel){
	if(sentinel!=sentinel->next_){
	Circle* first_mate = sentinel->next_;
	sentinel->next_=first_mate->next_;
	reverse(sentinel);
	first_mate->next_->next_=first_mate;
	first_mate->next_=sentinel;
	}
}

	Circle* List::insertCircle(Circle* prevCir, ci::Vec2f position, float radius){
		Circle* temp = new Circle;
		temp->next_ = prevCir->next_;
		prevCir->next_=temp;

		temp->position_ = position;
		temp->radius_ = radius;
		temp->color_ = cinder::Color8u(rand()*255, rand()*255, rand()*255);
		
		
		return temp;
	}

	bool List::isInside(float x, float y, Circle* cur){
		float dist = sqrt((y-(cur->position_.y))*(y-(cur->position_.y))+(x-(cur->position_.x))*(x-(cur->position_.x)));
	    return (dist<=(cur->radius_));

	}
