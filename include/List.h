
/**
* @file List.h
* A singly circular linked list data structure populated by nodes 
* that are represented by circles
*
* @author Nick Collins
* @date 2012-09-24
*/
#include "Circle.h"

class List{

public:
	// The empty sentinel node used to mark the beginning of the list
	Circle* sentinel;

	/** Reverses the order of the linked list recursively
	 *  Takes in the sentinel node of the linked list
	 *  Implemented by the method described in class
	 */
    void reverse(Circle* sentinel);

	/**
     * Used to insert a new node into the list, after a given node
	 * Implemented using the insertAfter method described in class
	 *
	*/
    Circle* insertCircle(Circle* prevCir, ci::Vec2f position, float radius, ci::ColorA8u color, ci::ColorA8u child_color);
	
	/**
	* Tells if a point (x,y) is inside a circle node (cur)
	* Returns true if the point is inside the circle, false otherwise
	*/
	bool isInside(float x, float y, Circle* cur);
	
	/**
	* Pushes a circle (toPush) to the front of the linked list,
	* and to the back of the screen
	*/
	void pushBack(Circle* toPush);
 };