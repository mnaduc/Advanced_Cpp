#ifndef CAR_H_
#define CAR_H_

#include "Setting.h"
#include <string>
#include "Display.h"
#include "Sound.h"
#include "General.h"

/*
	class quản lý một xe bao gồm thông tin chung và các dữ liệu cài đặt
*/
class Car : public Setting
{
public:
	/* Một xe phải có personal key để phân biệt */
	Car(string personal_key);
	~Car();
	void info();
	void infoDisplay();
	void infoSound();
	void infoGeneral();
	Display* getDisplay();
	Sound* getSound();
	General* getGeneral();
	/* Số xe đã khởi tạo */
	static int count();
private:
	Display* display_;
	Sound* sound_;
	General* general_;
	/* Lưu số xe đã khởi tạo */
	static int count_;
};

#endif // !CAR_H_




