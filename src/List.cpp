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

	Circle* List::insertCircle(Circle* prevCir, ci::Vec2f position, float radius, Color8u color){
		Circle* temp = new Circle;
		temp->position_ = position;
		temp->radius_ = radius;
		temp->color_ = color;
		temp->next_ = prevCir->next_;
		prevCir->next_=temp;

		return 0;
	}

	bool List::isInside(float x, float y, Circle* cur){
		float dist = sqrt((y-(cur->position_.y))*(y-(cur->position_.y))+(x-(cur->position_.x))*(x-(cur->position_.x)));
	    return (dist<=(cur->radius_));

	}
