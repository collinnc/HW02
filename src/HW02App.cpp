#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Circle.h"

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
	  Circle* circle_list_;
	  static const int kAppWidth = 800;
	  static const int kAppHeight = 600;
	  static const int kTextureSize = 1024;
};

void HW02App::prepareSettings(Settings* settings){
	(*settings).setWindowSize(800,600);
	(*settings).setResizable(false);

}

void HW02App::setup()
{
	circle_list_= new Circle(4, Vec2f(kAppWidth/2.0f, kAppHeight/2.0f), 100.0);

}


void HW02App::mouseDown( MouseEvent event )
{
}

void HW02App::update()
{
}

void HW02App::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 

	Circle* cur = circle_list_;
	if(cur != NULL){
		do{
			cur->draw(getMousePos());
			cur = cur->next_;
		} while (cur != circle_list_);
	}
}

CINDER_APP_BASIC( HW02App, RendererGl )