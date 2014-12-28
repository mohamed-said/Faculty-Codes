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

using namespace std;

#define Round(x) int(x + 0.5)
#define all(x) x.begin(),x.end()
#define rall(x) x.end(),x.begin()
#define pb push_back
#define sz(x) (int)x.size()
#define ins insert
#define getmax(a,b) ((a)>(b)?(a):(b))
#define OOR out_of_range

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef set<int> si;
typedef set<string> sets;
typedef set<char> setc;
typedef pair<int, int> pii;

class Card {
protected:
	string ownerName;
	string serialNumber;
	double balance;
public:

	Card(string name, string serial, double bal) {
		ownerName = name;
		serialNumber = serial;
		balance = bal;
	}

	void getOwnerName() {
		cout << ownerName << endl;
	}

	void getSerialNumber() {
		cout << serialNumber << endl;
	}

	bool addBalance(double add) {
		if (add < 0)
			return false;
		balance += add;
		return true;
	}

	virtual bool purchase(double with) {
		if (with < 0)
			return false;
		if (with < 500) {
			with = (with * 5) / 100;
			if (with > balance) {
				return false;
			} else
				balance -= with;
		} else if (with >= 500 && with < 1000) {
			with = (with * 7.5) / 1000;
			if (with > balance)
				return false;
			else
				balance -= with;
		} else if (with >= 1000) {
			with = (with * 10) / 100;
			if (with > balance)
				return false;
			else
				balance -= with;
		}
		return true;
	}

	double getBalance() {
		return balance;
	}

	virtual ~Card() {
	}
};

class CreditCard: public Card {
private:
	double limit;
public:
	CreditCard(string name, string serial, double lim) :
			Card(name, serial, 0) {
		limit = lim;
	}

	bool purchase(double with) {
		if (with < 0)
			return false;
		if (with < 500) {
			with = (with * 5) / 100;
			if (with < balance) {
				balance -= with;
			} else {
				if (with > limit)
					return false;
				else
					balance -= with;
			}
		} else if (with >= 500 && with < 1000) {
			with = (with * 7.5) / 1000;
			if (with < balance) {
				balance -= with;
			} else {
				if (with > limit)
					return false;
				else
					balance -= with;
			}
		} else if (with >= 1000) {
			with = (with * 10) / 100;
			if (with < balance)
				balance -= with;
			else {
				if (with > limit)
					return false;
				else
					balance -= with;
			}
		}
		return true;
	}
};

int main() {

	string name, serialNumber;
	double balance;

	vector<Card*> debit;
	Card *user1 = new Card("mohamed", "123456", 7000);
	Card *user2 = new Card("Hossam", "678910", 2000);
	Card *user3 = new Card("Mostafa", "101112", 4000);
	debit.pb(user1);
	debit.pb(user2);
	debit.pb(user3);

	vector<CreditCard*> credit;
	CreditCard *creditUser1 = new Card("mohamed", "123456", 7000);
	CreditCard *creditUser2 = new Card("Hossam", "678910", 2000);
	CreditCard *creditUser3 = new Card("Mostafa", "101112", 4000);
	CreditCard.pb(creditUser1);
	CreditCard.pb(creditUser2);
	CreditCard.pb(creditUser3);

	cin >> name;
	cin >> balance;

	int i;
	for (i = 0; i < sz(CreditCard); ++i) {
		if (credit[i]->ownerName == name) {
			if (credit[i]->purchase(balance)) {
				cout << "OK" << endl;
				break;
			}
		}
	}

	if (i == sz(credit))
		cout << "user not found" << endl;


	return 0;
}
