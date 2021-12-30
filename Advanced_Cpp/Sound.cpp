#include "Sound.h"
#include "Setting.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Sound::info()
{
	cout << left;
	cout << "    "
		<< setw(15) << "Sound:"
		<< setw(20) << "Media"
		<< setw(20) << "Call"
		<< setw(20) << "Navigation"
		<< setw(20) << "Notification" << endl;
	cout << "    "
		<< setw(15) << ""
		<< setw(20) << media_level_
		<< setw(20) << call_level_
		<< setw(20) << navi_level_
		<< setw(20) << notification_level_ << endl;
}

void Sound::input()
{
	media_level_ = Setting::inputLevelNumber("Media volume level");
	call_level_ = Setting::inputLevelNumber("Call volume level");
	navi_level_ = Setting::inputLevelNumber("Navigation volume level");
	notification_level_ = Setting::inputLevelNumber("Notification volume level");
}

unsigned int Sound::get_media_level()
{
	return media_level_;
}

unsigned int Sound::get_call_level()
{
	return call_level_;
}

unsigned int Sound::get_navi_level()
{
	return navi_level_;
}

unsigned int Sound::get_notification_level()
{
	return notification_level_;
}

void Sound::set_media_level(unsigned int media_level)
{
	media_level_ = media_level;
}

void Sound::set_call_level(unsigned int call_level)
{
	call_level_ = call_level;
}

void Sound::set_navi_level(unsigned int navi_level)
{
	navi_level_ = navi_level;
}

void Sound::set_notification_level(unsigned int notification_level)
{
	notification_level_ = notification_level;
}
