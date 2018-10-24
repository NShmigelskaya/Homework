#pragma once

template<class T>
struct Node {
	T value;
	struct Node* next;
};

template<class T>
class List {
private:
	struct Node<T> *head;

public:
	List();
	List(T *arr, size_t size);
	~List();

	void push(T data);
	Node<T>* getNth(int n);
	T pop();
	void insert(unsigned int n, T val);
	T delete_func(int n);
	void deleteList();
};

struct Patient {
	int id;
	std::string name;
	std::string surname;
	std::string city;
	int age;
	bool sex;
	int visit_count;
};

template class List<Patient*>;
