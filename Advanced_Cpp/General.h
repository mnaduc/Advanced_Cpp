#ifndef GENERAL_H_
#define GENERAL_H_

#include <string>
#include <vector>
using namespace std;

/*
	Class quản lý các thông tin cài đặt General
*/
class General
{
public:
	void info();
	void input();
	string get_language();
	string get_timezone();
	void set_language(string language);
	void set_timezone(string timezone);
	/*
		Đọc dữ liệu timezone từ file
		@param file_path đường dẫn file hoặc tên file nếu cùng folder
	*/
	static void downloadTimezone(string file_path);
	/*
		Đọc data language từ file
		@param file_path đường dẫn file hoặc tên file nếu cùng folder
	*/
	static void downloadLanguage(string file_path);
private:
	string timezone_ = "GMT-00:00";
	string language_ = "English";
	void inputTimezone();
	void inputLanguage();
	/*
		Định dạng chuỗi	timezone_list_: (UTC-00:00) Monrovia, Reykjavik
	*/
	static vector<string> timezone_list_;
	/*
		Định dạng chuỗi	language_list_: 06 / Portuguese
	*/
	static vector<string> language_list_;
	/* Sắp xếp giảm dần timezone_list_ theo UTC */
	static void sortTimezoneUTC();
	/*
		Sắp xếp theo alphabet mảng vector<string>
		@param v Tham chiếu mảng vector<string>
		@param pos_begin vị trí bắt đầu sắp xếp trong chuỗi, bỏ qua các ký tự trước đó
	*/
	static void sortString(vector<string>& v, int pos_begin = 0);
};


#endif // !GENERAL_H_


