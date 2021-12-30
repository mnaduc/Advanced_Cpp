#ifndef SETTING_H_
#define SETTING_H_

#include <string>

using namespace std;

/*
	Class quản lý các thông tin chung
*/
class Setting {
public:
	Setting(string personal_key);
	virtual void info();
	/*
		Nhập thông tin của xe: Owner name, email, odo, remind service
	*/
	void inputData();
	
	bool setOwnerName(string owner_name);
	bool setEmail(string email);
	bool setODO(string odo_number);
	bool setRemindService(string remind_service);
	void setODO(unsigned int odo_number);
	void setRemindService(unsigned int remind_service);

	string getPersonalKey();
	string getOwnerName();
	string getEmail();
	int getODO();
	int getRemindService();

	/* 
		Kiểm tra định dạng Owner name
		@param str chuỗi cần kiểm tra, uppercase chuỗi str sau kiểm tra (aHn duc -> ANH DUC)
		@return true nếu đúng định dạng
	 */
	static bool checkOwnerName(string& str);
	static bool checkPersonalKey(string str);
	static bool checkEmail(string str);
	static bool checkUnsignedNumber(string str);
	/*
		Nhập cài đặt mức level
		@param data_name tên dữ liệu cần cài đặt
		@return mức level
	 */
	static int inputLevelNumber(string data_name);
private:
	string owner_name_;
	string personal_key_; 	// Chuoi 8 ky tu so
	string email_;			// email format abc@xyz.com
	int odo_number_;
	int remind_service_;
};
#endif /* SETTING_H_ */

