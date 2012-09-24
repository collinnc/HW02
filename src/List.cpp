/**
* @file List.cpp
* A singly circular linked list data structure populated by nodes 
* that are represented by circles
*
* @author Nick Collins
* @date 2012-09-24
*
*/
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

	Circle* List::insertCircle(Circle* prevCir, ci::Vec2f position, float radius, ColorA8u color, ColorA8u child_color){
		Circle* temp = new Circle;
		temp->next_ = prevCir->next_;
		prevCir->next_=temp;

		temp->position_ = position;
		temp->radius_ = radius;
		temp->color_ = color;
		temp->child_color_=child_color;

		
		return temp;
	}

	bool List::isInside(float x, float y, Circle* cur){
		float dist = sqrt((y-(cur->position_.y))*(y-(cur->position_.y))+(x-(cur->position_.x))*(x-(cur->position_.x)));
	    return (dist<=(cur->radius_));

	}

	void List::pushBack(Circle* toPush){
		Circle* prev = toPush->next_;
		for(int i = 0; i< 11; i++){
			if(prev->next_==toPush)
				i+=11;
			else
				prev = prev->next_;
		}
		prev->next_ = toPush->next_;
		toPush->next_=sentinel->next_;
		sentinel->next_=toPush;

	}