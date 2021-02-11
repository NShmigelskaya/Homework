#include <iostream>
#include <fstream>
#include <string>
#include "List.h"

class DataBase {
private:
	List<Patient*> patients;
	int patient_id = 1;
public:
    DataBase() { }

	void AddPatient() {
	    Patient* patient = new Patient;
        patient->id = patient_id++;
        std::cout << "Name:" << std::endl;
		std::cin >> patient->name;
		std::cout << "Surname:" << std::endl;
		std::cin >> patient->surname;
		std::cout << "City:" << std::endl;
		std::cin >> patient->city;
		std::cout << "Age:" << std::endl;
		std::cin >> patient->age;
		std::cout << "Если пол женский введите 1, иначе введите 0:" << std::endl;
		std::cout << "Sex:" << std::endl;
		std::cin >> patient->sex;
		std::cout << "Number of visitings:" << std::endl;
		std::cin >> patient->visit_count;
		std::cout << "ID" << patient->id << std::endl;
		patients.push(patient);
	}

    Patient* FindPatient(int id) {
	    for (unsigned int i = 0; ; i++) {
			Node<Patient*>* node = patients.getNth(i);
			if (node == NULL) {
				break;
			}
			Patient* patient = node->value;
            if (patient->id == id) {
                return patient;
            }
        }
        return NULL;
	}

	void Info(int id) {
		Patient* patient = FindPatient(id);
		if (patient == NULL) {
			std::cout << "Нет такого пациента!" << std::endl;
		}
		else {
			std::cout << "Name:" << patient->name << std::endl;
			std::cout << "Surname:" << patient->surname << std::endl;
			std::cout << "City:" << patient->city << std::endl;
			std::cout << "Sex:";
			if (patient->sex) {
				std::cout << "female" << std::endl;
			}
			else {
				std::cout << "male" << std::endl;
			}
			std::cout << "Visit count:" << patient->visit_count << std::endl;
		}
	}

	void RemovePatient(int id) {
        for (unsigned int i = 0; ; i++) {
			Node<Patient*>* node = patients.getNth(i);
			if (node == NULL) {
				break;
			}
			Patient* patient = node->value;
            if (patient == NULL) {
                break;
            }
            if (patient->id == id) {
                patients.delete_func(i);
                free(patient);
                break;
            }
        }
	}

	void Copy(DataBase *dB2) {
		dB2->patients.deleteList();
		for (unsigned int i = 0; ; i++) {
			Node<Patient*>* node = patients.getNth(i);
			if (node == NULL) {
				break;
			}
			Patient* patient = node->value;
			Patient* patient2 = new Patient;
			patient2->name = patient->name;
			patient2->surname = patient->surname;
			patient2->age = patient->age;
			patient2->city = patient->city;
			patient2->sex = patient->sex;
			patient2->visit_count = patient->visit_count;
			dB2->patients.push(patient2);
		}
		dB2->patient_id = this->patient_id;
	}

	void LoadFrom(std::string filename) {
		patients.deleteList();

		std::ifstream f(filename);
		std::string line;
		while (std::getline(f, line)) {
			Patient* patient = new Patient;
			size_t start_offset = 0;
			for (int i = 0; i < 7; i++) {
				size_t end_offset = line.find(';', start_offset);
				std::string data = line.substr(start_offset, end_offset - start_offset);
				switch (i) {
                case 0:
                    patient->id = std::stoi(data);
                    this->patient_id = patient->id + 1;
                    break;
                case 1:
                    patient->name = data;
                    break;
                case 2:
                    patient->surname = data;
                    break;
                case 3:
                    patient->age = std::stoi(data);
                    break;
                case 4:
                    patient->city = data;
                    break;
                case 5:
                    patient->sex = std::stoi(data);
                    break;
                case 6:
                    patient->visit_count = std::stoi(data);
                    break;
				}
				start_offset = end_offset + 1;
			}
			this->patients.push(patient);
		}
		f.close();
	}

    void SaveTo(std::string filename) {
        std::ofstream f(filename, std::ios_base::trunc);
        for (unsigned int i = 0; ; i++) {
            Node<Patient*>* node = patients.getNth(i);
            if (node == NULL) {
                break;
            }
            Patient* patient = node->value;
            f << patient->id << ";";
            f << patient->name << ";";
            f << patient->surname << ";";
            f << patient->age << ";";
            f << patient->city << ";";
            f << patient->sex << ";";
            f << patient->visit_count << ";";
            f << std::endl;
        }
        f.close();
    }
};

int main() {
	setlocale(LC_ALL, "Russian");
	DataBase dB;
	char digit = 'Y';

	for (;;) {
		std::cout << "Если хотите добавить пользователя, нажмите Y." << std::endl;
        std::cout << "Если хотите удалить пользователя, нажмите R." << std::endl;
		std::cout << "Если хотите загрузить данные из файла, нажмите L." << std::endl;
        std::cout << "Если хотите сохранить данные в файл, нажмите S." << std::endl;
		std::cout << "Если хотите узнать информацию о пользователе, нажмите I." << std::endl;
		std::cout << "Если хотите выйти из программы , нажмите P." << std::endl;
		std::cin >> digit;
		int id = 0;
		std::string filename;
		switch (digit) {
		case 'Y':
		case 'y':
			dB.AddPatient();
			break;
        case 'R':
        case 'r':
            std::cout << "Введите id пациента:" << std::endl;
            std::cin >> id;
            dB.RemovePatient(id);
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
		case 'L':
		case 'l':
            std::cout << "Введите название файла:" << std::endl;
			std::cin >> filename;
			dB.LoadFrom(filename);
			break;
        case 'S':
        case 's':
            std::cout << "Введите название файла:" << std::endl;
            std::cin >> filename;
            dB.SaveTo(filename);
			break;
		default:
			std::cout << "Вы ввели неизвестную системе команду!" << std::endl;
		}
	}
}
