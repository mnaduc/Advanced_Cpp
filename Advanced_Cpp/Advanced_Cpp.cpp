#include <iostream>
#include <regex>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Car.h"

// screen lưu id màn hình hiện thời
enum class Screen { kScreen1, kScreen2, kScreen3 };
Screen screen = Screen::kScreen1;
bool is_running = true;

vector<Car*> car;

void menu();
unsigned int inputSelection(unsigned int num_of_choices);
bool YNQuestion();

void inputDisplay();
void inputSound();
void inputGeneral();
vector<Car*>::iterator inputDataCar();

void printDisplay();
void printSound();
void printGeneral();
void printAllSetting();

void carSort();
void writeDataToFile();
void readDataFromFile();

int main()
{
	General::downloadLanguage("languages.txt");
	General::downloadTimezone("timezones.txt");
	readDataFromFile();
	while (is_running) menu();
	system("cls");
	cout << "--- GOODBYE, SEE YOU LATER! ---" << endl;
	return 0;
}

/*
	Hiển thị menu và xử lý chuyển màn hình
*/
void menu()
{
	system("cls");
	switch (screen)
	{
	case Screen::kScreen1:
		cout << "--- SECLECT MENU ---\n";
		cout << "1. Input setting information\n";
		cout << "2. Print setting information\n";
		cout << "3. Exit\n";
		// Nhập lựa chọn
		switch (inputSelection(3))
		{
		case 1:
			screen = Screen::kScreen2;
			break;
		case 2:
			screen = Screen::kScreen3;
			break;
		case 3:
			is_running = false;
			break;
		}
		break;
	case Screen::kScreen2:
		cout << "--- SECLECT MENU ---\n";
		cout << "1. Display setting\n";
		cout << "2. Sound setting\n";
		cout << "3. General setting\n";
		cout << "4. Exit\n";
		// Nhập lựa chọn
		switch (inputSelection(4))
		{
		case 1:
			inputDisplay();
			break;
		case 2:
			inputSound();
			break;
		case 3:
			inputGeneral();
			break;
		case 4:
			screen = Screen::kScreen1;
			break;
		}
		break;
	case Screen::kScreen3:
		cout << "--- SECLECT MENU ---\n";
		cout << "1. Print Display setting information\n";
		cout << "2. Print Sound setting information\n";
		cout << "3. Print General setting information\n";
		cout << "4. Print all setting information\n";
		cout << "5. Exit\n";
		// Nhập lựa chọn
		switch (inputSelection(5))
		{
		case 1:
			system("cls");
			cout << "--- Display setting ---\n";
			carSort();
			printDisplay();
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "--- Sound setting ---" << endl;
			carSort();
			printSound();
			system("pause");
			break;
		case 3:
			system("cls");
			cout << "--- General setting ---" << endl;
			carSort();
			printGeneral();
			system("pause");
			break;
		case 4:
			system("cls");
			cout << "--- All setting ---" << endl;
			carSort();
			printAllSetting();
			system("pause");
			break;
		case 5:
			screen = Screen::kScreen1;
			break;
		}
		break;
	}
}

/*
	Yêu cầu nhập và kiểm tra lựa chọn menu
	@param num_of_choices số lượng các lựa chọn
	@return vị trí lựa chọn
*/
unsigned int inputSelection(unsigned int num_of_choices)
{
	string selection = "";
	while (true)
	{
		cout << "Your selection: ";
		getline(cin, selection);
		// Kiểm tra nhập hợp lệ
		if (regex_match(selection, regex("[1-" + to_string(num_of_choices) + "]")))
		{
			return stoi(selection);
		}
		else
			cout << "  * Invalid! ";
	}
}

/*
	Yêu cầu nhập và kiểm tra lựa chọn Y/N
	@return true nếu chọn yes (y/Y)
	@return false nếu chọn no (n/N)
*/
bool YNQuestion()
{
	string temp = "";
	while (true)
	{
		cout << "Your selection: ";
		getline(cin, temp);
		if (temp == "n" || temp == "N")
			return false;
		else if (temp == "y" || temp == "Y")
			return true;
		else
			cout << "  * Invalid! ";
	}
}

void inputDisplay()
{
	while (true)
	{
		system("cls");
		cout << "--- Input Display setting ---" << endl;

		// Nhập thông tin của xe
		cout << "Data Car:" << endl;
		vector<Car*>::iterator it = inputDataCar();
		// Nhập cài đặt display
		cout << "Display setting:" << endl;
		(*it)->getDisplay()->input();

		// Thông báo kết quả
		system("cls");
		cout << "--- Input Display setting ---" << endl;
		cout << "Car index: " << it - car.begin() << endl;
		(*it)->Setting::info();
		(*it)->getDisplay()->info();
		//Cập nhật vào file
		writeDataToFile();

		cout << "Will you input for next car (y/n)?" << endl;
		if (YNQuestion() == false)
		{
			// Lựa chọn no chuyển về màn hình 1
			screen = Screen::kScreen1;
			return;
		}
	}
}

void inputSound()
{
	while (true)
	{
		system("cls");
		cout << "--- Input Sound setting ---" << endl;

		// Nhập thông tin xe
		cout << "Data Car:" << endl;
		vector<Car*>::iterator it = inputDataCar();
		// Nhập cài đặt Sound
		cout << "Sound setting:" << endl;
		(*it)->getSound()->input();

		// Thông báo kết quả
		system("cls");
		cout << "--- Input Sound setting ---" << endl;
		cout << "Car index: " << it - car.begin() << endl;
		(*it)->Setting::info();
		(*it)->getSound()->info();
		// Cập nhật vào file
		writeDataToFile();

		cout << "Will you input for next car (y/n)?" << endl;
		if (YNQuestion() == false)
		{
			// Lựa chọn no chuyển về màn hình 1
			screen = Screen::kScreen1;
			return;
		}
	}
}

void inputGeneral()
{
	while (true)
	{
		system("cls");
		cout << "--- Input General setting ---" << endl;

		// Nhập thông tin xe
		cout << "Data Car:" << endl;
		vector<Car*>::iterator it = inputDataCar();
		system("pause");
		// Nhập cài đặt General
		(*it)->getGeneral()->input();

		// Thông báo kết quả
		system("cls");
		cout << "--- Input General setting ---" << endl;
		cout << "Car index: " << it - car.begin() << endl;
		(*it)->Setting::info();
		(*it)->getGeneral()->info();
		// Cập nhật vào file
		writeDataToFile();

		cout << "Will you input for next car (y/n)?" << endl;
		if (YNQuestion() == false)
		{
			// Lựa chọn no chuyển về màn hình 1
			screen = Screen::kScreen1;
			return;
		}
	}
}

/*
	Nhập thông tin chung của xe
	@return iterator xe đã nhập
*/
vector<Car*>::iterator inputDataCar()
{
	//Nhập và kiểm tra Key number
	string key_number = "";
	cout << "   Key number: ";
	getline(cin, key_number);
	while (!Car::checkPersonalKey(key_number))
	{
		cout << "     * Invalid! Key number: ";
		getline(cin, key_number);
	}
	// Tìm kiếm xe trong mảng
	string msg = "";
	vector<Car*>::iterator it;
	it = find_if(car.begin(), car.end(), [key_number](Car* first)
		{
			return key_number == first->getPersonalKey();
		});
	if (it != car.end())
	{
		msg = "--> This car has already existed, data will be overriten";
	}
	else
	{
		msg = "--> This is a new car, data will be appended to your list";
		it = car.insert(car.end(), new Car(key_number));
	}
	// Nhập các thông tin khác
	// Cập nhật cho xe cũ hoặc nhập cho xe mới
	(*it)->inputData();
	cout << msg << endl;
	return it;
}

void printDisplay()
{
	system("cls");
	cout << "--- Display setting ---" << endl;
	cout << left;
	cout << setw(20) << "Owner name"
		<< setw(25) << "Email"
		<< setw(15) << "Key"
		<< setw(10) << "ODO"
		<< setw(15) << "Service(km)"
		<< setw(10) << "Light"
		<< setw(10) << "Screen"
		<< setw(10) << "Taplo" << endl;
	for (auto item : car)
		item->infoDisplay();
}

void printSound()
{
	system("cls");
	cout << "--- Sound setting ---" << endl;
	cout << left;
	cout << setw(20) << "Owner name"
		<< setw(25) << "Email"
		<< setw(15) << "Key"
		<< setw(10) << "ODO"
		<< setw(15) << "Service(km)"
		<< setw(10) << "Media"
		<< setw(10) << "Call"
		<< setw(10) << "Navi"
		<< setw(10) << "Notify" << endl;
	for (auto item : car)
		item->infoSound();
}

void printGeneral()
{
	system("cls");
	cout << "--- General setting ---" << endl;
	cout << left;
	cout << setw(20) << "OWNER NAME"
		<< setw(25) << "Email"
		<< setw(15) << "Key"
		<< setw(10) << "ODO"
		<< setw(15) << "Service(km)"
		<< setw(20) << "TimeZone"
		<< setw(20) << "Language" << endl;

	for (auto item : car)
		item->infoGeneral();
}

void printAllSetting()
{
	system("cls");
	cout << "--- All setting ---" << endl;
	for (size_t i = 0; i < car.size(); i++)
	{
		cout << "*" << i + 1 << "*" << endl;
		car.at(i)->info();
	}
}

/*
	Hiển thị lựa chọn và sắp xếp xe theo personal key hoặc owner name
*/
void carSort()
{
	cout << "1. Sort by Personal Key\n";
	cout << "2. Sort by Owner Name\n";
	if (inputSelection(2) == 1)
	{
		// Sắp xếp theo Personal key
		sort(car.begin(), car.end(), [](Car* l, Car* r)
			{
				return l->getPersonalKey() < r->getPersonalKey();
			});
	}
	else
	{
		// Sắp xếp theo Owner name
		sort(car.begin(), car.end(), [](Car* l, Car* r)
			{
				return l->getOwnerName() < r->getOwnerName();
			});
	}
}

void writeDataToFile()
{
	// Mở file xóa toàn bộ data và ghi lại
	// Nếu file không tồn tại thì tạo file mới
	ofstream file;
	file.exceptions(ofstream::failbit | ofstream::badbit);
	try
	{
		file.open("Setting.txt", ios::out | ios::trunc);
		for (auto item : car)
		{
			file << "Common: "
				<< item->getPersonalKey() << ","
				<< item->getOwnerName() << ","
				<< item->getEmail() << ","
				<< item->getODO() << ","
				<< item->getRemindService() << "; ";
			Display* display = item->getDisplay();
			file << "Display: "
				<< display->get_light_level() << ","
				<< display->get_screen_light_level() << ","
				<< display->get_taplo_light_level() << "; ";
			Sound* sound = item->getSound();
			file << "Sound: "
				<< sound->get_media_level() << ","
				<< sound->get_call_level() << ","
				<< sound->get_navi_level() << ","
				<< sound->get_notification_level() << "; ";
			General* general = item->getGeneral();
			file << "General: "
				<< general->get_timezone() << ","
				<< general->get_language() << "\n";
		}
	}
	catch (const ofstream::failure&)
	{
		cout << "--> Failed to write data to the file" << endl;
		system("pause");
	}
}

void readDataFromFile()
{
	ifstream file("Setting.txt");
	// Nếu không có file thì không đọc
	if (file.fail()) return;
	string temp = "";
	while (!file.eof())
	{
		getline(file, temp, ' ');
		if (temp == "Common:")
		{
			// Personal key
			getline(file, temp, ',');
			car.push_back(new Car(temp));
			// Owner name
			getline(file, temp, ',');
			car.back()->setOwnerName(temp);
			// Email
			getline(file, temp, ',');
			car.back()->setEmail(temp);
			// ODO
			getline(file, temp, ',');
			car.back()->setODO(temp);
			// Remind service
			getline(file, temp, ';');
			car.back()->setRemindService(temp);

			// DISPLAY
			Display* display = car.back()->getDisplay();
			file.seekg(10, ios::cur);
			getline(file, temp, ',');
			display->set_light_level(stoi(temp));
			getline(file, temp, ',');
			display->set_screen_light_level(stoi(temp));
			getline(file, temp, ';');
			display->set_taplo_light_level(stoi(temp));

			//SOUND
			Sound* sound = car.back()->getSound();
			file.seekg(8, ios::cur);
			getline(file, temp, ',');
			sound->set_media_level(stoi(temp));
			getline(file, temp, ',');
			sound->set_call_level(stoi(temp));
			getline(file, temp, ',');
			sound->set_navi_level(stoi(temp));
			getline(file, temp, ';');
			sound->set_notification_level(stoi(temp));

			//GENERAL
			General* general = car.back()->getGeneral();
			file.seekg(10, ios::cur);
			getline(file, temp, ',');
			general->set_timezone(temp);
			getline(file, temp);
			general->set_language(temp);
		}
	}
}