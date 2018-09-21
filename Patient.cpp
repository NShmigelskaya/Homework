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
void AddPatient(int &patient_count, Patient patients[]) {
	int id = patient_count;
	patient_count++;
	std::cout << "Name:" << std::endl;
	std::cin >> patients[id].name;
	std::cout << "Surname:" << std::endl;
	std::cin >> patients[id].surname;
	std::cout << "City:" << std::endl;
	std::cin >> patients[id].city;
	std::cout << "Age:" << std::endl;
	std::cin >> patients[id].age;
	std::cout << "Если пол женский введите 1, иначе введите 0:" << std::endl;
	std::cout << "Sex:" << std::endl;
	std::cin >> patients[id].sex;
	std::cout << "Number of visitings:" << std::endl;
	std::cin >> patients[id].visit_count;
	std::cout << "ID" << id << std::endl;
}
void Info(int id, int patient_count, Patient patients[]) {

	if (id > patient_count) {
		std::cout << "Нет такого пациента!" << std::endl;
	}
	else {
		std::cout << "Name:" << patients[id].name << std::endl;
		std::cout << "Surname:" << patients[id].surname << std::endl;
		std::cout << "City:" << patients[id].city << std::endl;
		std::cout << "Sex:";
		if (patients[id].sex) {
			std::cout << "female" << std::endl;
		}
		else {
			std::cout << "male" << std::endl;
		}

		std::cout << "Visit count:" << patients[id].visit_count << std::endl;
	}
}
int main() {
	setlocale(LC_ALL, "Russian");
	int patient_count = 0;
	Patient patients[100];

	char digit = 'Y';
	for (;;) {
		std::cout << "Если хотите добавить пользователя , нажмите Y." << std::endl;
		std::cout << "Если хотите узнать информацию о пользователе, нажмите I." << std::endl;
		std::cout << "Если хотите выйти из программы , нажмите P." << std::endl;
		std::cin >> digit;
		if (digit == 'Y' or digit == 'y') {
			AddPatient(patient_count, patients);
		}
		else if (digit == 'I' or digit == 'i') {
			int id = 0;
			std::cout << "Введите id пациента:" << std::endl;
			std::cin >> id;
			Info(id, patient_count, patients);
		}
		else if (digit == 'P' or digit == 'p') {
			break;
		}
		else {
			std::cout << "Вы ввели неизвестную системе команду!" << std::endl;
		}
	}
