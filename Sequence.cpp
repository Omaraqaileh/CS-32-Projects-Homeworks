
#include <iostream>
#include "Sequence.h"


Sequence::Sequence() {
	m_size = 0;
}
const bool Sequence::empty() {
	return m_size == 0;


}
 int Sequence::size() const{
	return m_size;

}
int Sequence::insert(int pos, const ItemType& value) {
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
	for (int i = pos; i < m_size - 1; i++) {
		container[i] = container[i + 1];
	}
	m_size--;
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
const bool Sequence::get(int pos, ItemType& value) const {
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
	for (int i = 0; i < DEFAULT_MAX_ITEMS; ++i) {
		std::swap(container[i], other.container[i]);
	}
	std::swap(m_size, other.m_size);
}


