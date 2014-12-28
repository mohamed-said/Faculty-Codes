#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <cmath>
#include <set>
#include <utility>
#include <iterator>
#include <list>
#include <cmath>
#include <iomanip>
#include <memory>
#include <map>
#include <exception>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

#define Round(x) int(x + 0.5)
#define all(x) x.begin(),x.end()
#define rall(x) x.end(),x.begin()
#define pb push_back
#define sz(x) (int)x.size()
#define ins insert
#define getmax(a,b) ((a)>(b)?(a):(b))
#define getmin(a,b) ((a)>(b)?(b):(a))
#define OOR out_of_range

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef set<int> si;
typedef set<string> sets;
typedef set<char> setc;
typedef pair<int, int> pii;

#pragma once


template<class T>
class Node {
protected:
	T data;        		// to hold generic data of type T
	Node<T>* next;     	// to hold pointer to next item
	Node<T>* prev;      // to hold pointer for previous item
	int count;
public:
	Node() {
		next = prev = NULL;
		count = 0;
	}

	Node(T dataItem, Node<T>* nextPtr = NULL, Node<T>* prevPtr = NULL) {
		data = dataItem;
		next = nextPtr;
		prev = prevPtr;
	}

	Node<T>* getNext() {
		return next;
	}

	void setNext(Node<T>* ptr) {
		next = ptr;
	}

	Node<T>* getPrev() {
		return prev;
	}

	void setPrev(Node<T>* ptr) {
		prev = ptr;
	}

	T getData() {
		return data;
	}

	void setData(T dataItem) {
		data = dataItem;
	}

	template<class TT>
	friend ostream& operator<<(ostream& out, Node<TT> n);
};

template<class T>
ostream& operator<<(ostream& out, Node<T> node) {
	out << node.getData() << " -> "; // ---------> original
	return out;
}

template<class T>
class FCISLL {
private:
	Node<T> *head, *tail;
public:

	FCISLL() {
		head = NULL;
		tail = NULL;
	}

	~FCISLL() {
	}

	void addToHead(T item) {
		Node<T> *ptr = new Node<T>(item, head);
		head = ptr;
		if (tail == NULL)
			tail = ptr;
	}

	void addToTail(T item) {
		Node<T> *ptr = new Node<T>(item, NULL);
		if (head == NULL)
			head = tail = ptr;
		else {
			tail->setNext(ptr);
			tail = ptr;
		}
	}

	void addToIndex(T item, int index) {
		Node<T> *nPtr = new Node<T>(item, NULL);
		Node<T> *pPtr = head;
		for (int i = 0; pPtr != 0 && i < index - 1; i++)
			pPtr = pPtr->getNext();

		if (pPtr != 0 && !(index < 0))
			if (index == 0)
				addToHead(item);
			else {
				nPtr->setNext(pPtr->getNext());
				pPtr->setNext(nPtr);
			}
		if (tail == pPtr)
			tail = tail->getNext();
	}

	bool search(T item) {
		Node<T> *ptr = head;
		while (!(ptr == NULL) && item != ptr->getData())
			ptr = ptr->getNext();

		if (ptr != NULL)
			return true;
		else
			return false;
	}

	void removehead() {
		if (head == NULL)
			return;
		Node<T>* temp = head;
		head = head->getNext();
		delete temp;
	}

	void removeTail() {
		if (head == 0) {
			return;
		} else {
			Node<T> (*temp) = head->next, (*last) = head;
			while (temp != 0 && temp->getNext() != 0)
				last = temp, temp = temp->getNext();

			if (temp == 0) {
				delete head;
				head = 0;
			} else {
				last->getNext() = 0;
				delete temp;
			}
		}

	}

	void removeFromIndex(int index) {
		if (head == 0)
			return;
		else if (index == 0)
			removehead();
		else {
			Node<T> (*temp) = head->next, (*last) = head;
			int i;
			for (i = 0; i < index - 1 && temp->getNext() != 0; i++) {
				if (temp == 0)
					return;
				last = temp;
				temp = temp->getNext();
			}

			if (i != index - 1 || temp == 0)
				return;

			last->getNext() = temp->getNext();
			delete temp;
		}
	}

	void removeItem(T item) {
		if (head == 0)
			return;
		else if (head->value == item)
			removehead();
		else {
			Node<T> (*temp) = head->next, (*last) = head;
			while (temp != 0 && temp->getData() != item)
				last = temp, temp = temp->getNext();

			if (temp == 0)
				return;
			else {
				last->getNext() = temp->getNext();
				delete temp;
			}
		}
	}

//	void reverse() {
//		int counter = 0;
//		Node<T> *temp = head;
//		if (temp == 0)
//			return;
//
//		while (temp)
//			++counter;
//
//		Node<T> (*first) = head, (*last) = tail;
//	}

	void sort() {
		Node<T> *temp = new Node<T>();
		Node<T> *current;

		bool didSwap = true;

		while (didSwap) {
			didSwap = false;
			for (current = head; current->getNext() != NULL; current = current->getNext()) {
				if (current->getData() > current->getNext()->getData()) {
					temp->setData(current->getData());
					current->setData(current->getNext()->getData());
					current->getNext()->setData(temp->getData());
					didSwap = true;
				}
			}
		}
	}

	void getHeadAndTail() {
		cout << head->getData() << " " << tail->getData();
		cout << endl;
	}

	template<class TT>
	friend ostream& operator<<(ostream&, FCISLL<TT>);
};

//////////////////////////////

template<class T>
ostream& operator<<(ostream& stream, FCISLL<T> list) {
	if (list.head != 0) {
		Node<T>* ptr = list.head;
		stream << *ptr;
		while (ptr != list.tail) {
			ptr = ptr->getNext();
			stream << *ptr;
		}
		stream << "NULL" << endl;
	}
	return stream;
}

int main() {
	FCISLL<int> LinkedList;

	LinkedList.addToHead(2);
	LinkedList.addToHead(3);
	LinkedList.addToHead(4);
	LinkedList.addToHead(5);
	LinkedList.addToHead(2);
	LinkedList.addToHead(3);
	LinkedList.addToHead(4);
	LinkedList.addToHead(5);
	LinkedList.addToHead(2);
	LinkedList.addToHead(3);
	LinkedList.addToHead(4);
	LinkedList.addToHead(5);

//	LinkedList.addToTail(2);
//	LinkedList.addToTail(3);
//	LinkedList.addToTail(4);
//	LinkedList.addToTail(5);
//	LinkedList.addToTail(2);
//	LinkedList.addToTail(3);
//	LinkedList.addToTail(4);
//	LinkedList.addToTail(5);
//	LinkedList.addToTail(2);
//	LinkedList.addToTail(3);
//	LinkedList.addToTail(4);
//	LinkedList.addToTail(5);


	cout << LinkedList << endl;

	LinkedList.sort();
	cout << LinkedList << endl;

	LinkedList.getHeadAndTail();

	return 0;
}
