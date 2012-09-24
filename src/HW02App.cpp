#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "List.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class HW02App : public AppBasic {
  public:
	
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	void prepareSettings(Settings* settings);

  private:
	  Surface* mySurface;
	  List* CircleList;
	  static const int kAppWidth = 800;
	  static const int kAppHeight = 600;
	  static const int kTextureSize = 1024;
	  float theta;
	  float circX, circY;
};

void HW02App::prepareSettings(Settings* settings){
	(*settings).setWindowSize(800,600);
	(*settings).setResizable(false);

}

void HW02App::setup()
{
	/*
	Circle* lastCir= new Circle(4, Vec2f(kAppWidth/2.0f, kAppHeight/2.0f), 100.0, Color8u(0,255,0));
	circle_list_= lastCir;
	circle_list_->insertAfter(new Circle(4, Vec2f(kAppWidth/2.0f +25.0f, kAppHeight/2.0f), 100.0, Color8u(0,0,255)), lastCir);
	*/
	CircleList = new List;
	CircleList ->sentinel = new Circle;
	CircleList->sentinel->next_ = CircleList->sentinel;
	Circle* last;
	last = CircleList->insertCircle(CircleList->sentinel, Vec2f(400.0, 150.0), 150.0);
	last = CircleList->insertCircle(last, Vec2f(550.0, 300.0), 150.0);

	theta = 0.0;
	circX = 0.0;
	circY = 0.0;

}


void HW02App::mouseDown( MouseEvent event )
{
}

void HW02App::update()
{
	theta = theta + 0.1;
	circX = 100*sin(theta);
	circY = 100*cos(theta);
}

void HW02App::draw()
{
	// clear out the window with black
	gl::clear( Color( 0,0,0 ) ); 

	Circle* cur = CircleList->sentinel->next_;
	while(cur!=CircleList->sentinel){
		gl::color(cur->color_);
		gl::drawSolidCircle(cur->position_, cur->radius_);
		cur = cur->next_;

	}





	/*if(cur != NULL){
		do{
			gl::color(Color8u(rand()*255, rand()*255, rand()*255));
			gl::drawSolidCircle(cur->position_, cur->radius_);
			cur = cur->next_;
		} while (cur->next_ != NULL);
	}
	*/

}

CINDER_APP_BASIC( HW02App, RendererGl )