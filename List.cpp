#include <iostream>

#include "List.h"

template<class T>
void List<T>::push(T data){
	Node<T>* tmp = new Node<T>;
	tmp->value = data;
	tmp->next = head;
	head = tmp;
}

template<class T>
Node<T>* List<T>::getNth(int n) {
	Node<T>* h = head;
	int counter = 0;
	while (counter < n && h) {
		h = h->next;
		counter++;
	}
	return h;
}

template<class T>
T List<T>::pop() {
	Node<T>* prev = NULL;
	T val;
	if (head == NULL) {
		exit(-1);
	}
	prev = head;
	val = head->value;
	head = head->next;
	free(prev);
	return val;
}

template<class T>
void List<T>::insert(unsigned int n, T val) {
	Node<T>* h = head, *prev = head;

	unsigned int i = 0;
	Node<T> *tmp = NULL;
	while (i < n && h->next) {
		prev = h;
		h = h->next;
		i++;
	}
	tmp = new Node<T>;
	tmp->value = val;
	if (h->next) {
		tmp->next = h->next;
	}
	else {
		tmp->next = NULL;
	}
	if (i > 0) {
		prev->next = tmp;
	}
	else {
		head = tmp;
	}
}

template<class T>
T List<T>::delete_func(int n) {
	if (n == 0) {
		return pop();
	}
	else {
		Node<T> *prev = getNth(n - 1);
		Node<T> *elm = prev->next;
		T val = elm->value;

		prev->next = elm->next;
		free(elm);
		return val;
	}
}

template<class T>
void List<T>::deleteList() {
	Node<T>* prev = NULL;
	while (head) {
		prev = head;
		head = head->next;
		free(prev);
	}
}

template <class T>
List<T>::List() {
	head = NULL;
}

template <class T>
List<T>::List(T *arr, size_t size) {
	size_t i = size - 1;
	head = NULL;
	if (arr == NULL || size == 0) {
		return;
	}
	do {
		push(arr[i]);
	} while (i-- != 0);
}

template <class T>
List<T>::~List() {
	deleteList();
}
