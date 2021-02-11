#include <iostream>
#include <string>
struct Patient {
	std::string name;
	std::string surname;
	std::string city;
	int age;
	bool sex;
	int visit_count;
};
class DataBase {
	private:
	int id;
	int *ptr;
	Patient *patients[100];
	int patient_count = 0;
	public:
	DataBase(){}
	DataBase(const DataBase &object){}
	~DataBase(){}

	void AddPatient(DataBase object) {
		int id = this->patient_count;
		this->patient_count++;
		patients[id] = new Patient();
		std::cout << "Name:" << std::endl;
		std::cin >> this-> patients[id]->name;
		std::cout << "Surname:" << std::endl;
		std::cin >> this->patients[id]->surname;
		std::cout << "City:" << std::endl;
		std::cin >> this->patients[id]->city;
		std::cout << "Age:" << std::endl;
		std::cin >> this->patients[id]->age;
		std::cout << "Если пол женский введите 1, иначе введите 0:" << std::endl;
		std::cout << "Sex:" << std::endl;
		std::cin >> this->patients[id]->sex;
		std::cout << "Number of visitings:" << std::endl;
		std::cin >> this->patients[id]->visit_count;
		std::cout << "ID" << id << std::endl;
	}
	void Info(int id) {
		if (id > this->patient_count) {
			std::cout << "Нет такого пациента!" << std::endl;
		}
		else {
			std::cout << "Name:" << this->patients[id]->name << std::endl;
			std::cout << "Surname:" << this->patients[id]->surname << std::endl;
			std::cout << "City:" << this->patients[id]->city << std::endl;
			std::cout << "Sex:";
			if (this->patients[id]->sex) {
				std::cout << "female" << std::endl;
			}
			else {
				std::cout << "male" << std::endl;
			}

			std::cout << "Visit count:" << this->patients[id]->visit_count << std::endl;
		}
	}
};
class DataBase1 {

};
int main() {
	setlocale(LC_ALL, "Russian");
	int patient_count = 0;
	Patient patients[100];
	DataBase dB;
	char digit = 'Y';
	for (;;) {
		std::cout << "Если хотите добавить пользователя , нажмите Y." << std::endl;
		std::cout << "Если хотите узнать информацию о пользователе, нажмите I." << std::endl;
		std::cout << "Если хотите выйти из программы , нажмите P." << std::endl;
		std::cin >> digit;
		DataBase obj1;
		DataBase obj2 = obj1;
		int id = 0;
		switch (digit) {
			case 'Y':
			case 'y':
			dB.AddPatient(obj1);
			break;
			case 'i':
			case 'I':
			std::cout << "Введите id пациента:" << std::endl;
			std::cin >> id;
			dB.Info(id);
			break;
			case 'P':
			case 'p':
			return 0;
		default:
			std::cout << "Вы ввели неизвестную системе команду!" << std::endl;
		}
	}
}
