#include "General.h"
#include "Setting.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>

vector<string> General::timezone_list_;
vector<string> General::language_list_;

/*
	Kiểm tra str_input là một số trong khoảng 1~num_of_choices
	@param str_input chuỗi cần kiểm tra
	@param num_of_choices số lượng các lựa chọn
	@return 1~num_of_choices nếu kiểm tra hợp lệ
			-1 nếu kiểm tra không hợp lệ
*/
int CheckNumberSelection(string str_input, size_t num_of_choices) {
	if (Setting::checkUnsignedNumber(str_input))
	{
		unsigned int temp = stoi(str_input);
		if (temp > 0 && temp <= num_of_choices) return temp;
	}
	return -1;
}

void General::info()
{
	cout << left;
	cout << "    "
		<< setw(15) << "General:"
		<< setw(40) << "Timezone"
		<< setw(40) << "Language" << endl;
	cout << "    "
		<< setw(15) << ""
		<< setw(40) << timezone_
		<< setw(40) << language_ << endl;
}

void General::input()
{
	inputTimezone();
	inputLanguage();
}

string General::get_language()
{
	return language_;
}

string General::get_timezone()
{
	return timezone_;
}

void General::set_language(string language)
{
	language_ = language;
}

void General::set_timezone(string timezone)
{
	timezone_ = timezone;
}

void General::downloadTimezone(string file_path)
{
	while (true)
	{
		ifstream fin;
		fin.exceptions(ifstream::failbit | ifstream::badbit);
		try
		{
			fin.open(file_path);
			string str_temp = "";
			// Đọc file đến khi gặp ký tự kết thúc
			while (!fin.eof())
			{
				getline(fin, str_temp);
				if (str_temp != "")
				{
					// "(GMT-09:00) / Alaska" -> "(GMT-09:00) Alaska"
					str_temp.erase(12, 2);
					timezone_list_.push_back(str_temp);
				}
			}
			fin.close();
			if (timezone_list_.size() == 0)
				// File không có data
				throw ifstream::failure("");
			else
			{
				// Sắp xếp danh sách timezone theo UTC giảm dần
				sortTimezoneUTC();
				return;
			}
		}
		catch (const ifstream::failure&)
		{
			// File không tồn tại hoặc file rỗng
			// ghi lại file
			string timezone_data =
				"(GMT-12:00) / International Date Line West\n"
				"(GMT-11:00) / Midway Island, Samoa\n"
				"(GMT-10:00) / Hawaii\n"
				"(GMT-09:00) / Alaska\n"
				"(GMT-08:00) / Tijuana, Baja California\n"
				"(GMT-07:00) / Chihuahua, La Paz, Mazatlan - New\n"
				"(GMT-06:00) / Guadalajara, Mexico City, Monterrey - New\n"
				"(GMT-05:00) / Eastern Time(US and Canada)\n"
				"(GMT-04:00) / Atlantic Time(Canada)\n"
				"(GMT-03:30) / Newfoundland\n"
				"(GMT-02:00) / Mid - Atlantic\n"
				"(GMT-01:00) / Azores\n"
				"(GMT-00:00) / Monrovia, Reykjavik\n"
				"(GMT+01:00) / Belgrade, Bratislava, Budapest, Ljubljana, Prague\n"
				"(GMT+02:00) / Minsk\n"
				"(GMT+03:00) / Moscow, St.Petersburg, Volgograd\n"
				"(GMT+04:00) / Abu Dhabi, Muscat\n"
				"(GMT+04:30) / Kabul\n"
				"(GMT+05:00) / Tashkent\n"
				"(GMT+05:30) / Chennai, Kolkata, Mumbai, New Delhi\n"
				"(GMT+05:45) / Kathmandu\n"
				"(GMT+06:00) / Astana, Dhaka\n"
				"(GMT+06:30) / Yangon(Rangoon) /\n"
				"(GMT+07:00) / Bangkok, Hanoi, Jakarta\n"
				"(GMT+08:00) / Beijing, Chongqing, Hong Kong, Urumqi\n"
				"(GMT+08:00) / Irkutsk, Ulaanbaatar\n"
				"(GMT+09:00) / Seoul\n"
				"(GMT+09:30) / Adelaide\n"
				"(GMT+10:00) / Canberra, Melbourne, Sydney\n"
				"(GMT+11:00) / Magadan, Solomon Islands, New Caledonia\n"
				"(GMT+12:00) / Fiji, Kamchatka, Marshall Is.\n"
				"(GMT+13:00) / Nuku'alofa";
			ofstream fout(file_path, ios::out | ios::trunc);
			fout << timezone_data;
			fout.close();
		}
	}
}

void General::downloadLanguage(string file_path)
{
	while (true)
	{
		ifstream fin;
		fin.exceptions(ifstream::failbit | ifstream::badbit);
		try
		{
			fin.open(file_path);
			string str_temp = "";
			// Đọc file đến khi gặp ký tự kết thúc
			while (!fin.eof())
			{
				getline(fin, str_temp);
				if (str_temp != "")
				{
					if (str_temp[1] == ' ') str_temp.insert(0, "0");
					language_list_.push_back(str_temp);
				}
			}
			fin.close();
			if (language_list_.size() == 0)
				// File không có data
				throw ifstream::failure("");
			else
			{
				// Sắp xếp danh sách language theo index mặc định
				sortString(language_list_);
				return;
			}
		}
		catch (const ifstream::failure&)
		{
			// File không tồn tại hoặc file rỗng
			// ghi lại file
			string language_data =
				"1 / Mandarin(entire branch)\n"
				"2 / Spanish\n"
				"3 / English\n"
				"4 / Hindi\n"
				"5 / Arabic\n"
				"6 / Portuguese\n"
				"7 / Bengali\n"
				"8 / Russian\n"
				"9 / Japanese\n"
				"10 / Punjabi\n"
				"11 / German\n"
				"12 / Javanese\n"
				"13 / Wu(inc.Shanghainese)\n"
				"14 / Malay(inc.Indonesian and Malaysian)\n"
				"15 / Telugu\n"
				"16 / Vietnamese\n"
				"17 / Korean\n"
				"18 / French\n"
				"19 / Marathi\n"
				"20 / Tamil\n"
				"21 / Urdu\n"
				"22 / Turkish\n"
				"23 / Italian\n"
				"24 / Yue(inc.Cantonese)\n"
				"25 / Thai\n"
				"26 / Gujarati\n"
				"27 / Jin\n"
				"28 / Southern Min\n"
				"29 / Persian\n"
				"30 / Polish";
			ofstream fout(file_path, ios::out | ios::trunc);
			fout << language_data;
			fout.close();
		}
	}
}

void General::inputTimezone()
{
	// Lặp đến khi lựa chọn timezone thành công
	while (true)
	{
		// Hiển thị danh sách timezone
		system("cls");
		cout << "--- SELECT TIMEZONE DATA ---" << endl;
		cout << right;
		for (size_t i = 0; i < timezone_list_.size(); i++)
		{
			cout << setw(2) << i + 1 << ": ";
			cout << timezone_list_[i] << endl;
		}
		// Hiển thị lựa chọn sắp xếp
		cout << "Enter: -u to sort by UTC-Timezone" << endl;
		cout << "       -a to sort by Alphabet-Zonename" << endl;
		cout << "Your selection: ";
		string str_input = "";
		bool is_valid = false;
		// Lặp nếu nhập không hợp lệ
		while (!is_valid)
		{
			is_valid = true;
			getline(cin, str_input);
			// Kiểm tra chuỗi nhập vào
			if (str_input == "-u" || str_input == "-U")
				// Sắp xếp UTC giảm dần 
				sortTimezoneUTC();
			else if (str_input == "-a" || str_input == "-A")
				// Sắp xếp alphabet theo zonename
				sortString(timezone_list_, 12);
			else
			{
				int index = CheckNumberSelection(str_input, timezone_list_.size());
				if (index != -1)
				{
					// Đã lựa chọn timezone thành công
					timezone_ = timezone_list_[index - 1].substr(1, 9); //chỉ lấy UTC-timezone
					return; // thoát lựa chọn timezone
				}
				else
				{
					// Nhập không hợp lệ, in thông báo và thực hiện nhập lại
					cout << "  * Invalid Selection! Your selection: ";
					is_valid = false;
				}
			}
			// Nếu nhập các lựa chọn sắp xếp thì thực hiện in lại danh sách
		}
	}
}

void General::inputLanguage()
{
	// Lặp đến khi lựa chọn language thành công
	while (true)
	{
		// Hiển thị danh sách language
		system("cls");
		cout << "--- SELECT LANGUAGE DATA ---" << endl;
		cout << right;
		for (size_t i = 0; i < language_list_.size(); i++)
		{
			cout << setw(2) << i + 1 << ": ";
			cout << language_list_[i].substr(5) << endl;
		}
		// Hiển thị lựa chọn sắp xếp
		cout << "Enter: -d to sort by Default" << endl;
		cout << "       -a to sort by Alphabet" << endl;
		cout << "Your selection: ";
		string str_input = "";
		bool is_valid = false;
		// Lặp nếu nhập không hợp lệ
		while (!is_valid)
		{
			is_valid = true;
			getline(cin, str_input);
			// Kiểm tra chuỗi nhập vào
			if (str_input == "-d" || str_input == "-D")
				// Sắp xếp theo index mặc định
				sortString(language_list_);
			else if (str_input == "-a" || str_input == "-A")
				// Sắp xếp alphabet theo tên language
				sortString(language_list_, 5);
			else
			{
				int index = CheckNumberSelection(str_input, language_list_.size());
				if (index != -1)
				{
					// Đã lựa chọn language thành công
					language_ = language_list_[index - 1].substr(5);
					return; // thoát lựa chọn language
				}
				else
				{
					// Nhập không hợp lệ, in thông báo và thực hiện nhập lại
					cout << "  * Invalid Selection! Your selection: ";
					is_valid = false;
				}
			}
			// Nếu nhập các lựa chọn sắp xếp thì thực hiện in lại danh sách
		}
	}
}

void General::sortTimezoneUTC()
{
	sort(timezone_list_.begin(), timezone_list_.end(), [](const string& l, const string& r)
		{
			if (l[4] < r[4])
				// so sánh vị trí dấu +/-
				return true;
			else if (l[4] == r[4])
			{
				if (l > r)
				{
					if (l[4] == '+')
						return true;
				}
				else
				{
					if (l[4] == '-')
						return true;
				}
			}
			return false;
		});
}

void General::sortString(vector<string>& v, int pos_begin)
{
	sort(v.begin(), v.end(), [pos_begin](const string& l, const string& r) {
			return l.substr(pos_begin) < r.substr(pos_begin);
		});
}
