

#include "TurnoutList.h"
#include <iostream>

TurnoutList::TurnoutList() {
	size_m = 0;
}
bool TurnoutList::add(unsigned long turnout){
	if (turnout > 1800 || size_m >= DEFAULT_MAX_ITEMS) {
		return false;
	}
	if (s.insert(size_m, turnout) != -1) {
		size_m++;
		return true;
	}
	return false;
}
bool TurnoutList::remove(unsigned long turnout) {
	int pos = s.find(turnout); // Find turnout in Sequence
	if (pos != -1 && s.erase(pos)) {
		size_m--;
		return true;
	}
	return false;
}
int TurnoutList::size() const{
	return size_m;
}
unsigned long TurnoutList::minimum() const{
	if (size_m == 0) {
		return NO_TURNOUTS;
	}
	unsigned long num;
	unsigned long min;
	s.get(0, min);
	for (int i = 0; i < size_m; i++) {
		s.get(i, num);
		if (min > num) {
			min = num;
		}
	}
	return min;
}
unsigned long TurnoutList::maximum() const{
	if (size_m == 0) {
		return NO_TURNOUTS;
	}
	unsigned long num;
	unsigned long max;
	s.get(0, max);
	for (int i = 0; i < size_m; i++) {
		s.get(i, num);
		if (max < num) {
			max = num;
		}
	}
	return max;
}

