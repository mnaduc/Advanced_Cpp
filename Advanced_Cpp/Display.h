#ifndef DISPLAY_H_
#define DISPLAY_H_

/*
	Class quản lý các thông tin cài đặt Display
*/
class Display
{
public:
	void info();
	void input();

	unsigned int get_light_level();
	unsigned int get_screen_light_level();
	unsigned int get_taplo_light_level();

	void set_light_level(unsigned int light_level);
	void set_screen_light_level(unsigned int screen_light_level);
	void set_taplo_light_level(unsigned int taplo_light_level);
private:
	unsigned int light_level_ = 0;
	unsigned int screen_light_level_ = 0;
	unsigned int taplo_light_level_ = 0;
};

#endif // !DISPLAY_H_