
#include <cassert>
#include <iostream>
#include "TurnoutList.h" // Assumes TurnoutList is dependent on Sequence

void testTurnoutListWithSequence() {
    TurnoutList list;

    // Test initial state
    assert(list.size() == 0);

    // Test adding valid turnouts
    assert(list.add(300));
    assert(list.add(500));
    assert(list.add(1500));
    assert(list.size() == 3);

    // Test adding invalid turnouts
    assert(!list.add(1801)); // Exceeds valid range
    assert(!list.add(-1));   // Invalid (even though unsigned)

    // Test remove method
    assert(list.remove(500)); // Should remove 500
    assert(!list.remove(500)); // 500 is already removed
    assert(list.size() == 2);

    // Test minimum and maximum
    assert(list.minimum() == 300);
    assert(list.maximum() == 1500);

    // Test empty list minimum and maximum
    TurnoutList emptyList;
    assert(emptyList.minimum() == NO_TURNOUTS);
    assert(emptyList.maximum() == NO_TURNOUTS);

    // Test removing all elements
    assert(list.remove(300));
    assert(list.remove(1500));
    assert(list.size() == 0);
    assert(list.minimum() == NO_TURNOUTS);
    assert(list.maximum() == NO_TURNOUTS);

    // Test boundary values
    assert(list.add(0));     // Smallest valid value
    assert(list.add(1800));  // Largest valid value
    assert(list.size() == 2);
    assert(list.minimum() == 0);
    assert(list.maximum() == 1800);

    // Test adding beyond max capacity
    for (int i = 0; i < DEFAULT_MAX_ITEMS - 2; i++) {
        assert(list.add(i + 1));
    }
    assert(!list.add(999)); // Exceeds capacity
    assert(list.size() == DEFAULT_MAX_ITEMS);

    

    std::cout << "All TurnoutList tests passed!" << std::endl;
}

int main() {
    testTurnoutListWithSequence();
    return 0;
}


