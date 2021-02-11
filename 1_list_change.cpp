#include <iostream>
struct Node {
	int value;
	struct Node* next;
};
Node* head = NULL;
class List {
	void push(Node **head, int data) {
		Node *tmp = (Node*)malloc(sizeof(Node));
		tmp->value = data;
		tmp->next = (*head);
		(*head) = tmp;
	}
	Node* getNth(Node* head, int n) {
		int counter = 0;
		while (counter < n && head) {
			head = head->next;
			counter++;
		}
		return head;
	}
	int pop(Node **head) {
		Node* prev = NULL;
		int val;
		if (head == NULL) {
			exit(-1);
		}
		prev = (*head);
		val = prev->value;
		(*head) = (*head)->next;
		free(prev);
		return val;
	}
	void insert(Node *head, unsigned int n, int val) {
		unsigned int i = 0;
		Node* tmp = NULL;
		while (i < n and head->next) {
			head = head->next;
			i++;
		}
		tmp = (Node*)malloc(sizeof(Node));
		tmp->value = val;
		if (head->next) {
			tmp->next = head->next;
		}
		else {
			tmp->next = NULL;
		}
		head->next = tmp;
	}
	int delete_func(Node **head, int n) {
		if (n == 0) {
			return pop(head);
		}
		else {
			Node* prev = getNth(*head, n - 1);
			Node* elm = prev->next;
			int val = elm->value;

			prev->next = elm->next;
			free(elm);
			return val;
		}
	}
	void deleteList(Node **head) {
		while ((*head)->next) {
			pop(head);
			*head = (*head)->next;
		}
		free(*head);
	}
	void printLinkedList(const Node *head) {
		while (head) {
			printf("%d ", head->value);
			head = head->next;
		}
		printf("\n");
	}
	void fromArray(Node **head, int *arr, size_t size) {
		size_t i = size - 1;
		if (arr == NULL || size == 0) {
			return;
		}
		do {
			push(head, arr[i]);
		} while (i-- != 0);
	}
};


int main() {
	List l;
	Node* head = NULL;
	int arr[] = {4,8,6,7,8};
	l.fromArray();
	l.printLinkedList();
	l.printLinkedList();
	l.insert();
	l.printLinkedList();
	l.printLinkedList();
	l.printf("%d\n", pop());
	l.printLinkedList();
	l.printLinkedList();
	l.deleteList();
	return 0;
}