#ifndef __MB_CX10_5__
#define __MB_CX10_5__

#include <iostream>
const int MAX_TABLE = 11;

template<class tableKeyType, class tableDataType>
class Table {
private:
	struct Slot;
	typedef Slot * Link;
	struct Slot {
		tableKeyType key;
		tableDataType data;
		Link next;
	};
	Link T[MAX_TABLE]; // table is an array of pointers to slots
	int hash(const tableKeyType & key);
	bool search(Link & slotPointer, const tableKeyType & target);

public:
	Table(); // Table constructor

	void insert(const tableKeyType & key, const tableDataType & data);
	bool lookup(const tableKeyType & key, tableDataType & data);
	void deleteKey(const tableKeyType & key);
	void dump();
};

#endif
