#ifndef SOUND_H_
#define SOUND_H_

/*
	Class quản lý các thông tin cài đặt Sound
*/
class Sound
{
public:
	void info();
	void input();

	unsigned int get_media_level();
	unsigned int get_call_level();
	unsigned int get_navi_level();
	unsigned int get_notification_level();
	void set_media_level(unsigned int media_level);
	void set_call_level(unsigned int call_level);
	void set_navi_level(unsigned int navi_level);
	void set_notification_level(unsigned int notification_level);
private:
	unsigned int media_level_ = 0;
	unsigned int call_level_ = 0;
	unsigned int navi_level_ = 0;
	unsigned int notification_level_ = 0;
};

#endif // !SOUND_H_



