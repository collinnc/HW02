#include "Circle.h"






class List{

public:
	Circle* sentinel;
    void reverse(Circle* sentinel);
    Circle* insertCircle(Circle* prevCir, ci::Vec2f position, float radius, Color8u color);
	bool isInside(float x, float y, Circle* cur);
 };