#include <iostream>
using namespace std;

template <class T>
class LinkedList
{
private:
	int count;
	struct Node {
		T data;
	Node *next;
	};
	Node *worker;
	Node *worker2;
	Node *head;
public:
	LinkedList(const LinkedList &list);
	LinkedList(T data);
	~LinkedList();
	void append(T data);
	void prepend(T data);
	void operator=(LinkedList &list);
	int extract(T data); //Returns the amount of items extracted.
	void insertAfter(T data, int num);
	void insertBefore(T data, int num);
	//int pull();	
	T getFirst();
	T getLast();
};


template <class T>
LinkedList<T>::LinkedList(const LinkedList &list)
{
	Node *temp1 = new Node;
	temp1->data = list.head->data;
	worker = list.head;
	head = temp1;
	if (worker->next == NULL)
		head->next = NULL;
	else
	{
		while (worker->next != NULL)
		{
			worker = worker->next;
			temp1->next = new Node;
			temp1 = temp1->next;
			temp1->data = worker->data;
		}
		temp1->next = NULL;
	}
	count = list.count;
}

template <class T>
LinkedList<T>::LinkedList(T data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->next = NULL;
	count = 1;
	head = temp;
}

template <class T>
LinkedList<T>::~LinkedList()
{
	if (head) {
		do {
			worker = head;
			head = head->next;
			delete worker;
		} while (head);
	}
}

template <class T>
void LinkedList<T>::append(T data)
{
	if (head->next == NULL && head->data == 0)
	{
		head->data = data;
	}
	else {
		worker = head;
		while (worker->next != NULL)
		{
			worker = worker->next;
		}
		Node *temp = new Node;
		temp->data = data;
		temp->next = NULL;
		count++;
		worker->next = temp;
	}
}

template <class T>
void LinkedList<T>::prepend(T data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->next = head;
	count++;
	head = temp;
}

template <class T>
void LinkedList<T>::operator=(LinkedList &list)
{
	if (head) {
		do {
			worker = head;
			head = head->next;
			delete worker;
		} while (head);
	}
	Node *temp1 = new Node;
	temp1->data = list.head->data;
	worker = list.head;
	head = temp1;
	while (worker->next != NULL)
	{
		worker = worker->next;
		temp1->next = new Node;
		temp1 = temp1->next;
		temp1->data = worker->data;
	}
	temp1->next = NULL;
	count = list.count;
}

template <class T>
int LinkedList<T>::extract(T data)
{
	int temp = 0;
	worker = head;
	worker2 = head;
	while (worker->next != NULL)
	{
		if (worker->data == data)
		{
			temp++;
			Node *temp = new Node;
			temp = worker;
			worker = worker->next;
			delete temp;
			count--;
			worker2->next = worker;
		}
		if (worker == head)
		{
			worker = worker->next;
		}
		else {
			worker = worker->next;
			worker2 = worker2->next;
		}
	}
	if (worker->data == data)
	{
		temp++;
		Node *temp = new Node;
		temp = worker;
		worker = worker->next;
		delete temp;
		count--;
		worker2->next = worker;
	}
	return temp;
}

template <class T>
void LinkedList<T>::insertAfter(T data, int num)
{
	if (num > count) {
		cout << "ERROR: Not that many items in the list" << endl;
	}
	else {
		worker = head;
		for (int i = 1; i <= num; i++)
		{
			if (worker->next == NULL);
			else
				worker = worker->next;
		}
		Node *temp = new Node;
		if (worker->next == NULL) {
			temp->data = data;
			count++;
			temp->next = NULL;
			worker->next = temp;
		}
		else {
			worker2 = worker->next;
			temp->data = data;
			count++;
			temp->next = worker2;
			worker->next = temp;
		}
	}
}

template <class T>
void LinkedList<T>::insertBefore(T data, int num)
{
	if (num > count) {
		cout << "ERROR: Not that many items in the list" << endl;
	}
	else {
		worker = head;
		worker2 = head;
		for (int i = 1; i <= num; i++)
		{
			if (worker == head) {
				worker = worker->next;
			}
			else {
				worker = worker->next;
				worker2 = worker2->next;
			}
		}
		Node *temp = new Node;
		temp->data = data;
		count++;
		if (worker2 == head) {
			temp->next = worker2;
			head = temp;
		}
		else {
			temp->next = worker;
			worker2->next = temp;
		}
	}
}

template <class T>
T LinkedList<T>::getFirst()
{
	return head->data;
}

template <class T>
T LinkedList<T>::getLast()
{
	worker = head;
	while (worker->next != NULL)
	{
		worker = worker->next;
	}
	return worker->data;
}