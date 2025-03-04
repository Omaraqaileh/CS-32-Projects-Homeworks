
#include <iostream>
#include "newSequence.h"



Sequence::Sequence() {
	container = new ItemType[DEFAULT_MAX_ITEMS];
	m_size = 0;
	m_capacity = DEFAULT_MAX_ITEMS;
}
Sequence::Sequence(int size) {
	container = new ItemType[size];
	m_capacity = size;
	m_size = 0;
}
Sequence::~Sequence() {
	delete[] container;
}
Sequence::Sequence(const Sequence& other) {
	m_capacity = other.m_capacity;
	m_size = other.m_size;
	container = new ItemType[m_size];
	for (int i = 0; i < m_size; i++) {
		container[i] = other.container[i];
	}
}

Sequence& Sequence::operator=(const Sequence &seq) {
	if (&seq == this) {
		return *this;  // Check for self-assignment
	}
	delete[] container;  // Free old memory
	m_capacity = seq.m_capacity;
	m_size = seq.m_size;
	container = new ItemType[m_capacity];  // Allocate new array

	// Only copy elements up to the new size
	for (int i = 0; i < m_size; i++) {
		container[i] = seq.container[i];
	}

	return *this;
} 
const bool Sequence::empty() {
	return m_size == 0;
}
const int Sequence::size() const{
	return m_size;

}
int Sequence::insert(int pos, const ItemType& value) {
	if (m_size >= m_capacity) {
		return -1;
	}

	if (pos < 0 || pos > m_size || m_size == DEFAULT_MAX_ITEMS) {
		return -1;
	}
	for (int i = m_size - 1; i >= pos; --i) {
		container[i + 1] = container[i];
	}
	container[pos] = value;
	m_size++;
	return pos;


}

int Sequence::insert(const ItemType& value) {
	if (m_size >= m_capacity) {
		return -1;
	}
	int p = 5000;
	for (int i = 0; i < m_size; i++) {
		if (container[i] >= value) {
			p = i;
			break;
		}
	}
	if (p == 5000) {
		p = m_size;
	}
	if (p == DEFAULT_MAX_ITEMS) {
		return -1;
	}
	ItemType hello = value;
	for (int i = p; i < m_size + 1; i++) {
		ItemType mate = container[i];
		container[i] = hello;
		hello = mate;
	}
	m_size++;
	return p;


}
bool Sequence::erase(int pos) {
	if (pos < 0 || pos >= m_size) {
		return false;
	}

	for (int i = 0; i < m_size; i++) {

		// If key is found in array
		if (pos == i) {

			// Reduce size of array and move all
			// elements one space towards left
			m_size = m_size - 1;
			for (int j = i; j < m_size; j++) {
				container[j] = container[j + 1];
			}
			break;
		}

	}

	return true;
}
int Sequence::remove(const ItemType& value) {
	int j = 0;
	for (int i = 0; i < m_size; i++) {
		while (container[i] == value) {
			erase(i);
			j++;
		}
	}
	return j;


}
bool Sequence::get(int pos, ItemType& value) const {
	if (pos < 0 || pos >= m_size) {
		return false;
	}
	value = container[pos];
	return true;
}

bool Sequence::set(int pos, const ItemType& value) {
	if (pos < 0 || pos >= m_size) {
		return false;
	}
	container[pos] = value;
	return true;
}
const int Sequence::find(const ItemType& value) {
	int index = -1;
	for (int i = 0; i < m_size; i++) {
		if (container[i] == value) {
			index = i;
			break;
		}
	}
	return index;
}
void Sequence::swap(Sequence& other) {
	for (int i = 0; i < std::min(m_size, other.m_size); ++i) {
		std::swap(container[i], other.container[i]);
	}
	std::swap(m_capacity, other.m_capacity);
	std::swap(m_size, other.m_size);
}
