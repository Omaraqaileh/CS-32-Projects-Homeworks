
#include <cassert>
#include <iostream>
#include "Sequence.h" // Assume the Sequence class is implemented

void testSequence() {
    Sequence seq;
     // Test 1: Test initial state of Sequence
    assert(seq.size() == 0); // Sequence should be empty initially
    assert(seq.empty() == true); // Sequence should be empty initially

    // Test 2: Insert items at specific positions
    assert(seq.insert(0, 10) == 0); // Insert 10 at position 0
    assert(seq.insert(1, 20) == 1); // Insert 20 at position 1
    assert(seq.size() == 2); // Size should be 2 after insertion

    // Test 3: Insert an item at the start of the sequence
    assert(seq.insert(0, 5) == 0); // Insert 5 at position 0
    assert(seq.size() == 3); // Size should now be 3

    // Test 4: Insert an item at the end of the sequence
    assert(seq.insert(seq.size(), 30) == 3); // Insert 30 at the end
    assert(seq.size() == 4); // Size should now be 4

    // Test 5: Test getting the value at specific positions
    unsigned long value;
    assert(seq.get(0, value) == true && value == 5); // 5 is at position 0
    assert(seq.get(1, value) == true && value == 10); // 10 is at position 1
    assert(seq.get(2, value) == true && value == 20); // 20 is at position 2
    assert(seq.get(3, value) == true && value == 30); // 30 is at position 3

    // Test 6: Test set method
    assert(seq.set(1, 15) == true); // Set position 1 to 15
    assert(seq.get(1, value) == true && value == 15);
}
void test(const Sequence& uls)
{
    assert(uls.size() == 2);
    ItemType x = 999;
    assert(uls.get(0, x) && x == 20);
    assert(uls.get(1, x) && x == 10);
}


int main() {
    Sequence s1;
    s1.insert(0, 10);
    s1.insert(0, 20);
    test(s1);
    Sequence s;
    assert(s.empty());
    ItemType x = 97;
    assert(!s.get(68, x) && x == 97); // x unchanged by get failure
    assert(s.find(42) == -1);
    assert(s.insert(42) == 0);
    assert(s.size() == 1 && s.find(42) == 0);
    assert(s.get(0, x) && x == 42);
    cout << "Passed all tests" << endl;
    testSequence(); // Run all the tests
    cout << "All test cases passed";
    return 0;
}
