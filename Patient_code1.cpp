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
	Patient *patients[100];
	int patient_count = 0;
public:
	void AddPatient() {
		int id = this->patient_count;
		this->patient_count++;
		patients[id] = new Patient();
		std::cout << "Name:" << std::endl;
		std::cin >> this->patients[id]->name;
		std::cout << "Surname:" << std::endl;
		std::cin >> this->patients[id]->surname;
		std::cout << "City:" << std::endl;
		std::cin >> this->patients[id]->city;
		std::cout << "Age:" << std::endl;
		std::cin >> this->patients[id]->age;
		std::cout << "���� ��� ������� ������� 1, ����� ������� 0:" << std::endl;
		std::cout << "Sex:" << std::endl;
		std::cin >> this->patients[id]->sex;
		std::cout << "Number of visitings:" << std::endl;
		std::cin >> this->patients[id]->visit_count;
		std::cout << "ID" << id << std::endl;
	}
	void Info(int id) {
		if (id > this->patient_count) {
			std::cout << "��� ������ ��������!" << std::endl;
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
	DataBase *dB1;
	DataBase *dB2;
	void copy(DataBase *dB2) {
		for (int id = 0; id = this->patient_count; id++) {
			dB2->patients[id] = this->patients[id];
		}
		dB2->patient_count = this->patient_count;
	}
	
};
int main() {
	setlocale(LC_ALL, "Russian");
	int patient_count = 0;
	Patient patients[100];
	DataBase dB;
	char digit = 'Y';
	
	for (;;) {
		std::cout << "���� ������ �������� ������������ , ������� Y." << std::endl;
		std::cout << "���� ������ ������ ���������� � ������������, ������� I." << std::endl;
		std::cout << "���� ������ ����� �� ��������� , ������� P." << std::endl;
		std::cin >> digit;
		int id = 0;
		switch (digit) {
		case 'Y':
		case 'y':
			dB.AddPatient();
			break;
		case 'i':
		case 'I':
			std::cout << "������� id ��������:" << std::endl;
			std::cin >> id;
			dB.Info(id);
			break;
		case 'P':
		case 'p':
			return 0;
		default:
			std::cout << "�� ����� ����������� ������� �������!" << std::endl;
		}
	}
}
