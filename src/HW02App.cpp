
/**
* @file HW02App.cpp
* Uses a singly circular linked list filled to manipulate nodes (Circles).
*
* Satisfies goals A, C, D, E, F, I
*
* @author Nick Collins
* @date 2012-09-24
*
*/
#include "cinder/Text.h"
#include "cinder/gl/TextureFont.h"
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "List.h"
#include "cinder/Utilities.h"
#include "cinder/app/AppNative.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class HW02App : public AppBasic {
  public:
	Circle* last;
	void setup();
	void mouseDown( MouseEvent event );	
	void keyDown( KeyEvent event );
	void update();
	void draw();
	void prepareSettings(Settings* settings);
	gl::TextureFontRef	mTextureFont;
	Font mFont;

  private:
	  List* CircleList;
	  static const int kAppWidth = 800;
	  static const int kAppHeight = 600;
	  static const int kTextureSize = 1024;
	  float theta;
	  float circX, circY;
	  int moveCount;
	  bool help;
};

void HW02App::prepareSettings(Settings* settings){
	(*settings).setWindowSize(800,600);
	(*settings).setResizable(false);

}

void HW02App::setup()
{
	help = true;
	#if defined( CINDER_COCOA_TOUCH )
	mFont = Font( "Cochin-Italic", 24 );
#elif defined( CINDER_COCOA )
	mFont = Font( "BigCaslon-Medium", 24 );
#else
	mFont = Font( "Times New Roman", 24 );
#endif
	mTextureFont = gl::TextureFont::create( mFont );
	
	// create the list
	CircleList = new List;
	CircleList ->sentinel = new Circle;
	CircleList->sentinel->next_ = CircleList->sentinel;
	
	// Populate the linked list with circles
	// Satisfies goal A
	last = CircleList->insertCircle(CircleList->sentinel, Vec2f(400.0, 150.0), 150.0, ColorA8u(255,0,0,75), ColorA8u(0,255,255,75));
	last = CircleList->insertCircle(last, Vec2f(550.0, 300.0), 150.0, ColorA8u(255,255,0,75), ColorA8u(0,150,150,75));
	last = CircleList->insertCircle(last, Vec2f(400.0, 450.0), 150.0, ColorA8u(0,255,0,75), ColorA8u(255,0,255,75));
	last = CircleList->insertCircle(last, Vec2f(250.0, 300.0), 150.0, ColorA8u(0,0,255,75), ColorA8u(150,0,0,75));

	theta = 0.0;
	circX = 0.0;
	circY = 0.0;
	moveCount = 10;

}

// If a key (not 'm' or 'n') is pressed on the keyboard, reverse the order of the nodes (goal E)
// Satisfies goals C and F.
// If 'm' is pressed, the circles move to the right.
// If 'n' is pressed, the circles move to the left.
void HW02App::keyDown(cinder::app::KeyEvent event)
{
	if(event.getChar() == '?'){
		gl::clear( Color( 0, 0, 0 ) ); 
		help = !(help);
	}
	if(event.getChar() == 'm'){
		if(moveCount <15){
			Circle* cur = CircleList->sentinel->next_;
			while(cur!=CircleList->sentinel){
				cur->position_.x = cur->position_.x +20.0;
				cur = cur->next_;
			}
		}
		moveCount = moveCount +1;
	}

	else if(event.getChar() == 'n'){
		if(moveCount>7){
			Circle* cur = CircleList->sentinel->next_;
			while(cur!=CircleList->sentinel){
				cur->position_.x = cur->position_.x -20.0;
				cur = cur->next_;
			}
		}
		moveCount = moveCount -1;
	}
	
	else if (event.getChar() == 'r'){
	CircleList->reverse(CircleList->sentinel);
	}

}

// If a circle is clicked, push that circle to the back (goal C)
void HW02App::mouseDown( MouseEvent event )
{
	Circle* cur = CircleList->sentinel->next_;
	while(cur!=CircleList->sentinel){
		if(CircleList->isInside(event.getX(), event.getY(), cur)){
			CircleList->pushBack(cur);
			cur = CircleList->sentinel;
		}
		else
		cur=cur->next_;
	}

}

// Takes care of changing the position of the child circles,
// which always move in a circular path (goal D)
void HW02App::update()
{
	theta = theta + 0.1;
	circX = 75*sin(theta);
	circY = 75*cos(theta);
}

void HW02App::draw()
{
	gl::enableAlphaBlending();
	// clear out the window with black
	gl::clear( Color( 0,0,0 ) ); 
	if (help==true){std::string str( "Press '?' to toggle instructions \n\ r: reverse \n\ m: right \n\ n: left \n\ Click a circle: send it to the back" );
	Rectf boundsRect( 40, mTextureFont->getAscent() + 40, getWindowWidth() - 40, getWindowHeight() - 40 );

	gl::color( ColorA( 1, 0.5f, 0.25f, .5f ) );

	mTextureFont->drawStringWrapped( str, boundsRect );
	}
	
	// Go through the list, and draw each circle to the screen
	Circle* cur = CircleList->sentinel->next_;
	while(cur!=CircleList->sentinel){
		gl::color(cur->color_);
		gl::drawSolidCircle(cur->position_, cur->radius_);

		// The following lines draw the child circles, which react to the parent's postion 
		// in the linked list order
		// Goal I
		gl::color(cur->child_color_);
		gl::drawSolidCircle(Vec2f(cur->position_.x+circX, cur->position_.y+circY),75.0);
		cur = cur->next_;

	}
}

CINDER_APP_BASIC( HW02App, RendererGl )