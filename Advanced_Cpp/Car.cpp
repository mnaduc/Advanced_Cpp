#include "Car.h"
#include <iostream>
#include <iomanip>

int Car::count_ = 0;

Car::Car(string personal_key) :Setting(personal_key)
{
	count_++;
	// Khởi tạo các cài đặt
	display_ = new Display();
	sound_ = new Sound();
	general_ = new General();
}

Car::~Car()
{
	// Giải phóng vùng nhớ đã cấp phát
	delete display_;
	delete sound_;
	delete general_;
}

void Car::info()
{
	Setting::info();
	getDisplay()->info();
	getSound()->info();
	getGeneral()->info();
}

void Car::infoDisplay()
{
	// Xuất cả thông tin xe và display setting
	cout << left;
	cout << setw(20) << getOwnerName()
		<< setw(25) << getEmail()
		<< setw(15) << getPersonalKey()
		<< setw(10) << getODO()
		<< setw(15) << getRemindService()
		<< setw(10) << display_->get_light_level()
		<< setw(10) << display_->get_screen_light_level()
		<< setw(10) << display_->get_taplo_light_level() << endl;
}

void Car::infoSound()
{
	// Xuất cả thông tin xe và sound setting
	cout << left;
	cout << setw(20) << getOwnerName()
		<< setw(25) << getEmail()
		<< setw(15) << getPersonalKey()
		<< setw(10) << getODO()
		<< setw(15) << getRemindService()
		<< setw(10) << sound_->get_media_level()
		<< setw(10) << sound_->get_call_level()
		<< setw(10) << sound_->get_navi_level()
		<< setw(10) << sound_->get_notification_level() << endl;
}

void Car::infoGeneral()
{
	// Xuất cả thông tin xe và general setting
	cout << left;
	cout << setw(20) << getOwnerName()
		<< setw(25) << getEmail()
		<< setw(15) << getPersonalKey()
		<< setw(10) << getODO()
		<< setw(15) << getRemindService()
		<< setw(20) << general_->get_timezone()
		<< setw(20) << general_->get_language() << endl;
}

Display* Car::getDisplay()
{
	return display_;
}

Sound* Car::getSound()
{
	return sound_;
}

General* Car::getGeneral()
{
	return general_;
}

int Car::count()
{
	return count_;
}
