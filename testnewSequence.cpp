
#include "newSequence.h"
#include <iostream>
#include <cassert>
using namespace std;

void test(const Sequence& uls)
{
    assert(uls.size() == 2);
    ItemType x = 999;
    assert(uls.get(0, x) && x == 20);
    assert(uls.get(1, x) && x == 10);
}

int main()
{
    Sequence seq;

    // Test 1: Test initial state of Sequence
    cout << "hello";
    assert(seq.size() == 0); // Sequence should be empty initially
    cout << "hello";
    assert(seq.empty() == true); // Sequence should be empty initially

    // Test 2: Insert items at specific positions
    assert(seq.insert(0, 10) == 0); // Insert 10 at position 0
    cout << "hello";
    assert(seq.insert(1, 20) == 1); // Insert 20 at position 1
    cout << "hello";
    assert(seq.size() == 2); // Size should be 2 after insertion
    cout << "hello";

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
    Sequence s;
    s.insert(0, 10);
    s.insert(0, 20);
    test(s);
    cout << "yo";

    Sequence seq1;
    Sequence seq2(10);

    // Test 1: Test the size and empty method
    assert(seq1.size() == 0); // seq1 should be empty initially
    assert(seq1.empty() == true); // seq1 should be empty initially

    // Test 2: Insert elements and check size
    unsigned long x = 10;
    unsigned long y = 20;
    assert(seq1.insert(0, x) == 0); // Insert 10 at position 0
    assert(seq1.insert(1, 20) == 1); // Insert 20 at position 1
    assert(seq1.size() == 2); // Size should now be 2
    assert(seq1.get(0, x) == true && x == 10);  // First element should be 10
    assert(seq1.get(1, y) == true && y == 20);  // Second element should be 20

    // Test 3: Insert at a specific position
    unsigned long f = 15;
    assert(seq1.insert(1, f) == 1); // Insert 15 at position 1
    assert(seq1.size() == 3); // Size should now be 3
    assert(seq1.get(1, f) == true && f == 15);  // 15 should now be at position 1

    // Test 4: Test remove elements by value
    assert(seq1.remove(10) == 1); // Remove 10 from the sequence, should return 1
    assert(seq1.size() == 2); // Size should now be 2 after removal

    
    assert(seq1.erase(1) == true); // Erase element at position 1 (which is 15 now)
    assert(seq1.size() == 1); // Size should now be 1 after the erase

    // Test 6: Test edge cases of inserting into full sequence
    Sequence full_seq(3);
    full_seq.insert(0, 10);
    full_seq.insert(1, 20);
    full_seq.insert(2, 30);
    assert(full_seq.insert(3, 40) == -1); // Sequence is full, should return -1

    // Test 7: Test set method
    full_seq.set(1, 25); // Set position 1 to 25
    value = 0;
    assert(full_seq.get(1, value) == true && value == 25); // Verify value at position 1 is 25

    // Test 8: Test the find method
    assert(full_seq.find(25) == 1); // 25 should be found at index 1
    assert(full_seq.find(40) == -1); // 40 is not in the sequence

    // Test 9: Test copy constructor
    Sequence seq3 = full_seq;
    assert(seq3.size() == full_seq.size()); // Same size after copy
    assert(seq3.get(1, value) == true && value == 25); // Same value at the copied position

    // Test 10: Test assignment operator
    Sequence seq4;
    seq4 = full_seq;
    assert(seq4.size() == full_seq.size()); // Same size after assignment
    assert(seq4.get(1, value) == true && value == 25); // Same value at the assigned position
    // Test 11: Test swapping sequences
    Sequence seq5;
    seq5.insert(0, 1);
    seq5.insert(1, 2);
    seq5.insert(2, 3);
    full_seq.swap(seq5); // Swap seq5 and full_seq
    assert(full_seq.size() == 3); // After swap, full_seq should have 3 elements
    assert(seq5.size() == 3); // seq5 should have 3 elements after swap

    assert(full_seq.get(0, value) == true && value == 1); // First element of full_seq after swap should be 1
    assert(seq5.get(0, value) == true && value == 10); // First element of seq5 after swap should be 10

    cout << "All tests passed";
}
