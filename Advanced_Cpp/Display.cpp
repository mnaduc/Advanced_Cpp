#include "Display.h"
#include "Setting.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Display::info()
{
	cout << left;
	cout << "    "
		<< setw(15) << "Display:"
		<< setw(20) << "Light"
		<< setw(20) << "Screen light"
		<< setw(20) << "Taplo light" << endl;
	cout << "    "
		<< setw(15) << ""
		<< setw(20) << light_level_
		<< setw(20) << screen_light_level_
		<< setw(20) << taplo_light_level_ << endl;
}

void Display::input()
{
	light_level_ = Setting::inputLevelNumber("Light level");
	screen_light_level_ = Setting::inputLevelNumber("Screen light level");
	taplo_light_level_ = Setting::inputLevelNumber("Taplo light level");
}

unsigned int Display::get_light_level()
{
	return light_level_;
}

unsigned int Display::get_screen_light_level()
{
	return screen_light_level_;
}

unsigned int Display::get_taplo_light_level()
{
	return taplo_light_level_;
}

void Display::set_light_level(unsigned int light_level)
{
	light_level_ = light_level;
}

void Display::set_screen_light_level(unsigned int screen_light_level)
{
	screen_light_level_ = screen_light_level;
}

void Display::set_taplo_light_level(unsigned int taplo_light_level)
{
	taplo_light_level_ = taplo_light_level;
}