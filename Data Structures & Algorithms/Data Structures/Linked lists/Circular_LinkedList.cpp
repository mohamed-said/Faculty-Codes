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
	node (*next), (*prev);
	int data;
};

class CLL {

	node (*head), (*tail);
public:

	CLL() {
		head = tail = NULL;
	}

	void display() {
		node* temp = head;
		bool still = true;

		while (still && head) {
			cout << temp->data << " ";
			temp = temp->next;
			if (temp == head)
				still = false;
		}

		return;
	}

	void add(int value) {
		node* temp = new node;
		temp->data = value;

		if (!head) {
			head = tail = temp;
			head->next = head;
			head->prev = temp;
			tail = temp;
		} else {
			tail->next = temp;
			temp->next = head;
			temp->prev = tail;
			head->prev = temp;
			tail = temp;
		}
		return;
	}

	void remove(int value) {

		if (head->data == value) {
			node* n = head;
			tail->next = head->next;
			head = head->next;
			delete n;
			return;
		}

		node (*last) = head, (*temp) = head->next;

		while (temp != 0 && temp->data != value)
			last = temp, temp = temp->next;

		if (temp == head)
			return;

		///////////////////////////////
		if (tail->data == value) {
			temp = tail;
			last->next = head;
			tail = last;
			delete temp;
			return;
		}
		/////////////////////////////////
		last->next = temp->next;
		delete temp;
	}

	void _swap(int one, int two);
};

int main() {

	CLL list;

	list.add(2);
	list.add(4);
	list.add(6);
	list.add(8);

	list.display();
	cout << endl;

	list.remove(2);
	list.display();

	return 0;
}
