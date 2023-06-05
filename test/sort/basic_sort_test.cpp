#include "sort/basic_sort.h"
#include <cassert>
#include <stdexcept>

#define EXPEQUAL(val, ans) assert(val == ans)
#define EXPTRUE(val) assert(val == true)
#define EXPFALSE(val) assert(val == false)

// test oreder insert for basic sort
void test_order_insert() {
    dature::BinarySearch binarySearch;
    std::cout << "testing ordered insert" << std::endl;
    EXPTRUE(binarySearch.Insert(std::make_pair(1, 3)));
    EXPTRUE(binarySearch.Insert(std::make_pair(5, 1)));
    EXPTRUE(binarySearch.Insert(std::make_pair(2, 0)));
    int key = binarySearch.KeyAt(1);
    EXPEQUAL(key, 2);
    key = binarySearch.KeyAt(2);
    EXPEQUAL(key, 5);

    EXPTRUE(binarySearch.Insert(std::make_pair(6, 0)));
    key = binarySearch.KeyAt(2);
    EXPEQUAL(key, 5);
    key = binarySearch.KeyAt(3);
    EXPEQUAL(key, 6);
    std::cout << "ordered insert pass" << std::endl;
}

// test unorder insert for basic sort
void test_unorder_insert() {
    dature::BinarySearch binarySearch;
    std::cout << "testing unorder insert" << std::endl;
    EXPTRUE(binarySearch.Insert(std::make_pair(1, 3)));
    EXPTRUE(binarySearch.Insert(std::make_pair(5, 1)));
    EXPTRUE(binarySearch.Insert(std::make_pair(2, 0)));
    EXPTRUE(binarySearch.Insert(std::make_pair(7, 3)));
    EXPTRUE(binarySearch.Insert(std::make_pair(9, 1)));
    EXPTRUE(binarySearch.Insert(std::make_pair(4, 0)));
    EXPTRUE(binarySearch.Insert(std::make_pair(6, 3)));
    EXPTRUE(binarySearch.Insert(std::make_pair(8, 1)));
    EXPTRUE(binarySearch.Insert(std::make_pair(3, 0)));
    EXPTRUE(binarySearch.Insert(std::make_pair(10, 3)));
    int key = binarySearch.KeyAt(1);
    EXPEQUAL(key, 2);
    key = binarySearch.KeyAt(2);
    EXPEQUAL(key, 3);
    key = binarySearch.KeyAt(3);
    EXPEQUAL(key, 4);
    key = binarySearch.KeyAt(4);
    EXPEQUAL(key, 5);
    key = binarySearch.KeyAt(5);
    EXPEQUAL(key, 6);
    key = binarySearch.KeyAt(6);
    EXPEQUAL(key, 7);
    key = binarySearch.KeyAt(7);
    EXPEQUAL(key, 8);
    key = binarySearch.KeyAt(8);
    EXPEQUAL(key, 9);
    key = binarySearch.KeyAt(9);
    EXPEQUAL(key, 10);
    std::cout << "unorder insert pass" << std::endl;
}


void test_overflow_insert() {
    dature::BinarySearch binarySearch;
    std::cout << "testing overflow insert" << std::endl;
    EXPTRUE(binarySearch.Insert(std::make_pair(1, 3)));
    EXPTRUE(binarySearch.Insert(std::make_pair(5, 1)));
    EXPTRUE(binarySearch.Insert(std::make_pair(2, 0)));
    EXPTRUE(binarySearch.Insert(std::make_pair(7, 3)));
    EXPTRUE(binarySearch.Insert(std::make_pair(9, 1)));
    EXPTRUE(binarySearch.Insert(std::make_pair(4, 0)));
    EXPTRUE(binarySearch.Insert(std::make_pair(6, 3)));
    EXPTRUE(binarySearch.Insert(std::make_pair(8, 1)));
    EXPTRUE(binarySearch.Insert(std::make_pair(3, 0)));
    EXPTRUE(binarySearch.Insert(std::make_pair(10, 3)));
    EXPFALSE(binarySearch.Insert(std::make_pair(11, 1)));

    for (int i = 0; i < 10; i++) {
        int key = binarySearch.KeyAt(i);
        EXPEQUAL(key, i+1);
    }
    std::cout << "overflow insert pass" << std::endl;
}

void test_insert_find() {
    dature::BinarySearch binarySearch;
    std::cout << "testing insert find" << std::endl;
    EXPTRUE(binarySearch.Insert(std::make_pair(1, 2)));
    EXPTRUE(binarySearch.Insert(std::make_pair(5, 6)));
    EXPTRUE(binarySearch.Insert(std::make_pair(2, 3)));
    EXPTRUE(binarySearch.Insert(std::make_pair(7, 8)));
    EXPTRUE(binarySearch.Insert(std::make_pair(9, 10)));
    EXPTRUE(binarySearch.Insert(std::make_pair(4, 5)));
    EXPTRUE(binarySearch.Insert(std::make_pair(6, 7)));
    EXPTRUE(binarySearch.Insert(std::make_pair(8, 9)));
    EXPTRUE(binarySearch.Insert(std::make_pair(3, 4)));
    EXPTRUE(binarySearch.Insert(std::make_pair(10, 11)));
    EXPFALSE(binarySearch.Insert(std::make_pair(11, 1)));

    int val = -1;
    for (int i = 0; i < 10; i++) {
        EXPTRUE(binarySearch.Find(i+1, val));
        EXPEQUAL(val, i+2);
    }
    std::cout << "insert find pass" << std::endl;
}

void test_order_delete() {
    dature::BinarySearch binarySearch;
    std::cout << "testing ordered delete" << std::endl;
    binarySearch.Insert(std::make_pair(1, 3));
    binarySearch.Insert(std::make_pair(5, 1));
    binarySearch.Insert(std::make_pair(2, 0));
    binarySearch.Insert(std::make_pair(6, 0));

    int val;
    // Deleting in order
    EXPTRUE(binarySearch.Delete(1));
    EXPFALSE(binarySearch.Find(1, val));

    int key = binarySearch.KeyAt(0);
    EXPEQUAL(key, 2);
    key = binarySearch.KeyAt(1);
    EXPEQUAL(key, 5);
    key = binarySearch.KeyAt(2);
    EXPEQUAL(key, 6);
    
    EXPTRUE(binarySearch.Delete(2));
    EXPFALSE(binarySearch.Find(2, val));

    key = binarySearch.KeyAt(0);
    EXPEQUAL(key, 5);
    key = binarySearch.KeyAt(1);
    EXPEQUAL(key, 6);

    std::cout << "ordered delete pass" << std::endl;
}

void test_unorder_delete() {
    dature::BinarySearch binarySearch;
    std::cout << "testing unordered delete" << std::endl;
    binarySearch.Insert(std::make_pair(1, 3));
    binarySearch.Insert(std::make_pair(5, 1));
    binarySearch.Insert(std::make_pair(2, 0));
    binarySearch.Insert(std::make_pair(6, 0));

    int val;
    // Deleting out of order
    EXPTRUE(binarySearch.Delete(5));
    EXPFALSE(binarySearch.Find(5, val));

    int key = binarySearch.KeyAt(0);
    EXPEQUAL(key, 1);
    key = binarySearch.KeyAt(1);
    EXPEQUAL(key, 2);
    key = binarySearch.KeyAt(2);
    EXPEQUAL(key, 6);

    EXPTRUE(binarySearch.Delete(1));
    EXPFALSE(binarySearch.Find(1, val));

    key = binarySearch.KeyAt(0);
    EXPEQUAL(key, 2);
    key = binarySearch.KeyAt(1);
    EXPEQUAL(key, 6);

    std::cout << "unordered delete pass" << std::endl;
}



int main() {
    std::cout << "Testing ..." << std::endl;

    test_order_insert();
    test_overflow_insert();
    test_insert_find();
    test_unorder_insert();
    test_order_delete();
    test_unorder_delete();

    std::cout << "All test passed!" << std::endl;

    return 0;
}
