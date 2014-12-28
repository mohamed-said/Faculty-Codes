#ifndef MVECTOR_H
#define MVECTOR_H

#include<cstdlib>
#include<stdexcept>

using namespace std;

template<class type>
class mvector {
private:
	type *vec;
	int siz;
	int cap;

	void expand(int index);

public:
	mvector();
	mvector(int SIZ);
	mvector(int SIZ, type data);
	mvector(mvector<type> &other);
	~mvector();

	int size();
	int capacity();
	bool empty();
	void resize(int SIZ);
	void shrink_to_fit();

	type* begin();
	type* end();

	void push_front(type data);
	void push_back(type data);
	void insert(type data, int index) throw (out_of_range);

	type pop_front() throw (out_of_range);
	type pop_back() throw (out_of_range);
	type erase(int index) throw (out_of_range);
	void clear();

	void swap(int index1, int index2) throw (out_of_range);
	int find(type target);

	type& operator[](int index) throw (out_of_range);
	void operator=(mvector<type> &other);
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

template<class type>
mvector<type>::mvector() {
	vec = new type[50];
	cap = 50;
	siz = 0;
}

template<class type>
mvector<type>::mvector(int SIZ) {
	cap = SIZ;
	while ((cap % 50) != 0)
		cap++;

	vec = new type[cap];
	siz = SIZ;
}

template<class type>
mvector<type>::mvector(int SIZ, type data) {
	cap = SIZ;
	while ((cap % 50) != 0)
		cap++;

	vec = new type[20];
	siz = SIZ;

	for (int i = 0; i < siz; i++)
		vec[i] = data;
}

template<class type>
mvector<type>::mvector(mvector<type> &other) {
	cap = other.cap;
	siz = other.siz;

	vec = new type[cap];

	for (int i = 0; i < siz; i++)
		vec[i] = other.vec[i];
}

template<class type>
mvector<type>::~mvector() {
	delete[] vec;
}

template<class type>
void mvector<type>::expand(int index) {
	cap *= 2;
	type *temp = vec;
	vec = new type[cap];

	for (int i = 0, j = 0; i < siz; i++, j++) {
		if (j == index)
			j++;

		vec[j] = temp[i];
	}

	delete[] temp;
}

///////////////////////////////////////////////////////////////////////////////

template<class type>
int mvector<type>::size() {
	return siz;
}

template<class type>
int mvector<type>::capacity() {
	return cap;
}

template<class type>
bool mvector<type>::empty() {
	return ((siz == 0) ? true : false);
}

template<class type>
void mvector<type>::resize(int SIZ) {
	bool need_alloc = false;
	while (cap < SIZ) {
		need_alloc = true;
		cap *= 2;
	}

	if (need_alloc) {
		type *temp = vec;
		vec = new type[cap];
		for (int i = 0; i < siz; i++)
			vec[i] = temp[i];
		delete[] temp;
	}

	siz = SIZ;
}

template <class type>
void mvector<type>::shrink_to_fit() {
	if (siz == cap)
		return;

	type *temp_ptr = vec;

	vec = new type[siz];
	for (int i = 0; i < siz; i++)
		vec[i] = temp_ptr[i];

	cap = siz;
}

///////////////////////////////////////////////////////////////////////////////

template<class type>
type* mvector<type>::begin() {
	return vec;
}

template<class type>
type* mvector<type>::end() {
	return (vec + siz);
}

///////////////////////////////////////////////////////////////////////////////

template<class type>
void mvector<type>::push_front(type data) {
	if (siz == cap)
		expand(0);
	else {
		for (int i = siz; i > 0; i--)
			vec[i] = vec[i - 1];
	}

	vec[0] = data;
	siz++;
}

template<class type>
void mvector<type>::push_back(type data) {
	if (siz == cap)
		expand(siz);

	vec[siz] = data;
	siz++;
	return;
}

template<class type>
void mvector<type>::insert(type data, int index) throw (out_of_range) {
	if ((index < 0) || (index > siz))
		throw out_of_range("mvector out_of_range");

	if (siz == cap)
		expand(index);
	else {
		for (int i = siz; i > index; i--)
			vec[i] = vec[i - 1];
	}

	vec[index] = data;
	siz++;
}

///////////////////////////////////////////////////////////////////////////////

template<class type>
type mvector<type>::pop_front() throw (out_of_range) {
	if (siz == 0)
		throw out_of_range("mvector out_of_range");

	type temp = vec[0];

	for (int i = 0; i < (siz - 1); i++)
		vec[i] = vec[i + 1];

	siz--;
	return temp;
}

template<class type>
type mvector<type>::pop_back() throw (out_of_range) {
	if (siz == 0)
		throw out_of_range("mvector out_of_range");

	type temp = vec[siz - 1];
	siz--;
	return temp;
}

template<class type>
type mvector<type>::erase(int index) throw (out_of_range) {
	if ((index < 0) || (index >= siz))
		throw out_of_range("mvector out_of_range");

	type temp = vec[index];
	siz--;
	for (int i = index; i < siz; i++)
		vec[i] = vec[i + 1];

	return temp;
}

template<class type>
void mvector<type>::clear() {
	delete[] vec;
	vec = new type[50];
	cap = 50;
	siz = 0;
}

///////////////////////////////////////////////////////////////////////////////

template<class type>
void mvector<type>::swap(int index1, int index2) throw (out_of_range) {
	if ((index1 < 0) || (index1 >= siz))
		throw out_of_range("mvector out_of_range");

	if ((index2 < 0) || (index2 >= siz))
		throw out_of_range("mvector out_of_range");

	swap(vec[index1], vec[index2]);
}

template<class type>
int mvector<type>::find(type target) {
	for (int i = 0; i < siz; i++)
		if (vec[i] == target)
			return i;

	return -1;
}

///////////////////////////////////////////////////////////////////////////////

template<class type>
type& mvector<type>::operator[](int index) throw (out_of_range) {
	if ((index < 0) || (index >= siz))
		throw out_of_range("mvector out_of_range");

	return vec[index];
}

template<class type>
void mvector<type>::operator=(mvector<type> &other) {
	delete[] vec;
	cap = other.cap;
	siz = other.siz;

	vec = new type[cap];

	for (int i = 0; i < siz; i++)
		vec[i] = other.vec[i];
}

#endif
