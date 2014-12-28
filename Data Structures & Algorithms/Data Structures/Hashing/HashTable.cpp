#include "HashTable.h"

using namespace std;

template<class tableKeyType, class tableDataType>
int Table<tableKeyType, tableDataType>::hash(const tableKeyType & key) {
	return key % MAX_TABLE;
}

template<class tableKeyType, class tableDataType>
bool Table<tableKeyType, tableDataType>::search(Link & slotPointer,
		const tableKeyType & target) {
}

template<class tableKeyType, class tableDataType>
Table<tableKeyType, tableDataType>::Table() // implementation of Table constructor
{
	int i;
	for (i = 0; i < MAX_TABLE; i++)
		T[i] = 0;
}

template<class tableKeyType, class tableDataType>
void Table<tableKeyType, tableDataType>::insert(const tableKeyType & key,
		const tableDataType & data) {
}

template<class tableKeyType, class tableDataType>
bool Table<tableKeyType, tableDataType>::lookup(const tableKeyType & key,
		tableDataType & data) {
}

template<class tableKeyType, class tableDataType>
void Table<tableKeyType, tableDataType>::deleteKey(const tableKeyType & key) {
}

// the following function is handy for debugging
template<class tableKeyType, class tableDataType>
void Table<tableKeyType, tableDataType>::dump() {
	int i;
	for (i = 0; i < MAX_TABLE; i++) {
		cout << i << '\t';
		Link p;
		for (p = T[i]; p; p = p->next)
			cout << p->key << '\t';
		cout << '\n';
	}

	cout << '\n';
}
