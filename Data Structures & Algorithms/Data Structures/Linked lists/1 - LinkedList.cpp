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

struct node {
	int value;
	node* next;
	node() :
			next(0) {
	}
	node(int x) :
			value(x), next(0) {
	}
};

template<class T>
class LinkedList {
public:
	node* head;
	LinkedList() :
			head(0) {
	}

	void erase_head() {
		if (head == 0)
			return;
		else {
			node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void insertHead(int x) {
		node* n = new node(x);
		if (head == 0) {
			head = n;
		} else {
			n->next = head;
			head = n;
		}
	}

	void removeHead() {
		if (head == 0)
			return;
		node* n = head;
		head = head->next;
		delete n;
	}

	void removeTail() {
		if (head == 0) {
			return;
		} else {
			node (*temp) = head->next, (*last) = head;
			while (temp != 0 && temp->next != 0)
				last = temp, temp = temp->next;

			if (temp == 0) {
				delete head;
				head = 0;
			} else {
				last->next = 0;
				delete temp;
			}
		}

	}

	void removeFromIndex(int index) {
		if (head == 0)
			return;
		else if (index == 0)
			erase_head();
		else {
			node (*temp) = head->next, (*last) = head;
			int i;
			for (i = 0; i < index - 1 && temp->next != 0; i++) {
				if (temp == 0)
					return;
				last = temp;
				temp = temp->next;
			}

			if (i != index - 1 || temp == 0)
				return;

			last->next = temp->next;
			delete temp;
		}
	}

	void removeItem(T item) {
		if (head == 0)
			return;
		else if (head->value == item)
			erase_head();
		else {
			node (*temp) = head->next, (*last) = head;
			while (temp != 0 && temp->value != item)
				last = temp, temp = temp->next;

			if (temp == 0)
				return;
			else {
				last->next = temp->next;
				delete temp;
			}
		}
	}

	void printList() {
		node* temp = head;
		while(temp)
			cout << temp->value << " ", temp = temp->next;

		cout << endl;
	}
};

int main() {
	LinkedList<int> list;

	list.insertHead(2);
	list.insertHead(4);
	list.insertHead(6);
	list.insertHead(8);
	list.insertHead(10);
	list.insertHead(12);
	list.insertHead(14);
	list.insertHead(16);
	list.insertHead(18);

	list.printList();
	cout << endl;

	list.removeTail();
	cout << endl;

	list.erase_head();
	list.printList();
	cout << endl;

	list.removeFromIndex(2);
	list.printList();
	cout << endl;

	list.removeItem(12);
	list.printList();
	cout << endl;

	return 0;
}
