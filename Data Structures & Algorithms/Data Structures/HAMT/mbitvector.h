#ifndef MBITVECTOR_H
#define MBITVECTOR_H

#include<stdexcept>

using namespace std;

#include"mpair.h"

class mbitvector {
private:
	unsigned char *vec1; // represent the state: has a parent or not ( it is the other end of "isconnected" )
	unsigned char *vec2; // represent the state: end_of word
	int max_bytes; 		 // the allocated space in bytes;
	int max_siz; 		 // the allocated space in bits
	int bytes; 			 // number of bytes (unsigned char) in use
	int siz; 			 // number of bits in use

	void expand(int target_siz);
	void map_index(int &index, int &in_array_index, int &in_char_index);
	void set_char(int &in_array_index, int &in_char_index, bool state1,
			bool state2);
	mpair<bool, bool> get_char(int &in_array_index, int &in_char_index);
public:
	mbitvector();
	mbitvector(int _siz);
	mbitvector(mbitvector &other);
	~mbitvector();

	int size();
	int capacity();
	int bytes_num();
	int bytes_capacity();
	void shrink_to_fit();
	void clear();

	void set_state(int index, bool bit1, bool bit2) throw (out_of_range);
	mpair<bool, bool> get_state(int index) throw (out_of_range);
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void mbitvector::expand(int target_siz) {
	// function to manage the capacity of the two corresponding arrays.
	// used to expand the arrays when inserting out of their bound
	// so that the arrays occupy the target_index

	int target_byte_size;
	int target_index = target_siz - 1;
	int temp;
	map_index(target_index, target_byte_size, temp);

	int cur_max_bytes = max_bytes;
	while (max_bytes < target_byte_size)
		max_bytes *= 2;

	unsigned char *temp_ptr1 = vec1;
	unsigned char *temp_ptr2 = vec2;

	vec1 = new unsigned char[max_bytes];
	vec2 = new unsigned char[max_bytes];

	for (int i = 0; i < cur_max_bytes; i++) {
		vec1[i] = temp_ptr1[i];
		vec2[i] = temp_ptr2[i];
	}

	delete[] temp_ptr1;
	delete[] temp_ptr2;

	max_siz = max_bytes * 8;
	bytes = target_byte_size;
}

void mbitvector::map_index(int &index, int &in_array_index,
		int &in_char_index) {
	// function to map the node index to:
	// 1. the character index in the array...in_array_index.
	// 2. the bit index in that character...in_char_index.

	in_array_index = ((int) (index / 8));
	in_char_index = index % 8;
}

void mbitvector::set_char(int &in_array_index, int &in_char_index, bool state1,
		bool state2) {
	// function responsible for the bitwise operations to:
	// set a certain bit...in_char_index
	// in a certain character in the array...in_array_index
	// with a certain value...state
	// the two indexes are calculated with the function map_index

	unsigned char temp_state1 = vec1[in_array_index]; // getting the current char from the two vectors
	unsigned char temp_state2 = vec2[in_array_index];
	unsigned char temp_char1;
	unsigned char temp_char2;

	bool *state1_bits = new bool[8];
	bool *state2_bits = new bool[8];

	for (int i = 0; i < 8; i++) // resolving the two unsigned char into two bool arrays
			{
		temp_char1 = temp_state1;
		temp_char2 = temp_state2;
		temp_char1 <<= i;
		temp_char1 >>= 7;
		state1_bits[i] = ((bool) (temp_char1));
		temp_char2 <<= i;
		temp_char2 >>= 7;
		state2_bits[i] = ((bool) (temp_char2));
	}

	state1_bits[in_char_index] = state1; // putting my values without affecting other bits
	state2_bits[in_char_index] = state2; // putting my values without affecting other bits
	temp_char1 = 0;
	temp_char2 = 0;

	for (int i = 0; i < 7; i++) // re-constructing the char after setting my values in the targeted position
			{
		temp_char1 += state1_bits[i];
		temp_char1 <<= 1;
		temp_char2 += state2_bits[i];
		temp_char2 <<= 1;
	}

	temp_char1 += state1_bits[7];
	temp_char2 += state2_bits[7];

	vec1[in_array_index] = temp_char1; // setting the character in the vector with the re-formated characters
	vec2[in_array_index] = temp_char2;
}

mpair<bool, bool> mbitvector::get_char(int &in_array_index,
		int &in_char_index) {
	// function responsible for the bitwise operations to:
	// get a certain bit...in_char_index
	// in a certain character in the array...in_array_index
	// the two indexes are calculated with the function map_index

	unsigned char temp_state1 = vec1[in_array_index];
	unsigned char temp_state2 = vec2[in_array_index];
	temp_state1 <<= in_char_index;
	temp_state1 >>= 7;
	bool state1 = ((bool) (temp_state1));

	temp_state2 <<= in_char_index;
	temp_state2 >>= 7;
	bool state2 = ((bool) (temp_state2));

	mpair<bool, bool> temp_pair(state1, state2);
	return temp_pair;

}

///////////////////////////////////////////////////////////////////////////////

mbitvector::mbitvector() // default constructor
{
	vec1 = new unsigned char[1000];
	vec2 = new unsigned char[1000];
	max_bytes = 1000;
	max_siz = 8000;
	siz = 0;
	bytes = 1;
}

mbitvector::mbitvector(int _siz) // constructor 2
		{
	max_siz = _siz;
	while (((max_siz % 8) != 0) && (max_siz < 8000))
		max_siz++;

	max_bytes = max_siz / 8;
	siz = _siz;
	bytes = 0;
	while ((bytes * 8) < siz)
		bytes++;

	vec1 = new unsigned char[max_bytes];
	vec2 = new unsigned char[max_bytes];
}

mbitvector::mbitvector(mbitvector &other) // copy constructor
		{
	max_siz = other.max_siz;
	max_bytes = other.max_bytes;
	siz = other.siz;
	bytes = other.bytes;

	vec1 = new unsigned char[max_bytes];
	vec2 = new unsigned char[max_bytes];

	for (int i = 0; i < max_bytes; i++) {
		vec1[i] = other.vec1[i];
		vec2[i] = other.vec2[i];
	}
}

mbitvector::~mbitvector() {
	delete[] vec1;
	delete[] vec2;
}

///////////////////////////////////////////////////////////////////////////////

int mbitvector::size() {
	// return the number of bits in use ( number of nodes )
	return siz;
}

int mbitvector::capacity() {
	// return the allocated space in bits
	return max_siz;
}

int mbitvector::bytes_num() {
	// return the number of bytes in use
	return bytes;
}

int mbitvector::bytes_capacity() {
	// return the allocated space in bytes
	return max_bytes;
}

void mbitvector::shrink_to_fit() {
	// re-allocate the two arrays to exactly contain the bits in use
	// to eliminate any TRAILING wasted space
	// can be used after constructing the table to eliminate this wasted space

	unsigned char *temp_ptr1 = vec1;
	unsigned char *temp_ptr2 = vec2;

	vec1 = new unsigned char[bytes];
	vec2 = new unsigned char[bytes];

	for (int i = 0; i < bytes; i++) {
		vec1[i] = temp_ptr1[i];
		vec2[i] = temp_ptr2[i];
	}

	delete[] temp_ptr1;
	delete[] temp_ptr2;

	max_siz = bytes * 8;
	max_bytes = bytes;
}

void mbitvector::clear() {
	// reset the container to the default constructor

	delete[] vec1;
	delete[] vec2;

	vec1 = new unsigned char[1000];
	vec2 = new unsigned char[1000];
	max_bytes = 1000;
	max_siz = 8000;
	siz = 0;
	bytes = 1;
}

///////////////////////////////////////////////////////////////////////////////

void mbitvector::set_state(int index, bool bit1, bool bit2) throw (out_of_range) {
	// set the state of the node in index with a certain value
	// node state represented with two boolean variable

	if (index < 0)
		throw out_of_range(
				"ERROR: setting element with invalid index in mbitvector::set_state()");

	siz = max(siz, index + 1);
	if (siz >= max_siz)
		expand(siz);

	int super_index;
	int sub_index;
	map_index(index, super_index, sub_index);
	set_char(super_index, sub_index, bit1, bit2);
}

mpair<bool, bool> mbitvector::get_state(int index) throw (out_of_range) {
	// get the state of the node in index with a certain value
	// node state represented with two boolean variable

	if ((index < 0) || (index >= siz))
		throw out_of_range(
				"ERROR: accessing element out_of_range in mbitvector::get_state()");

	int super_index;
	int sub_index;
	map_index(index, super_index, sub_index);
	return get_char(super_index, sub_index);
}

#endif // MBITVECTOR_H
