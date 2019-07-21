#include "application.h"
#include <iostream>

static const cinder::ivec2 WindowSize{640, 480};

Application::Application() 
{}

void Application::prepareSettings(Settings* settings)
{
	settings->setWindowSize(WindowSize);
	settings->setFrameRate(35.0f);
	settings->setResizable(false);
	settings->setFullScreen(false);
}

void Application::keyDown(ci::app::KeyEvent event)
{
	if( event.getCode() == ci::app::KeyEvent::KEY_RIGHT ) {
		mGame.right();
	} else if( event.getCode() == ci::app::KeyEvent::KEY_LEFT ) {
		mGame.left();
	} else if( event.getCode() == ci::app::KeyEvent::KEY_UP ) {
		mGame.up();
	} else if( event.getCode() == ci::app::KeyEvent::KEY_DOWN ) {
		mGame.down();
	}
}

void Application::setup()
{
	mGame.setup();
	std::cout << "Setup." << std::endl;
	/* cinder::app::console() << "Key." << std::endl; */
}

void Application::draw()
{

	mGame.draw();
	/* cinder::app::console() << "Key." << std::endl; */
}

void Application::update()
{

	/* std::cout << "update." << std::endl; */
	/* cinder::app::console() << "Key." << std::endl; */
	/* std::cout << "update." << std::endl; */
}

CINDER_APP(Application, ci::app::RendererGl(ci::app::RendererGl::Options().msaa(16)), &Application::prepareSettings)
