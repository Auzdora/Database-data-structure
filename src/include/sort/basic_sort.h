#ifndef BASIC_SORT_H__
#define BASIC_SORT_H__
#include <iostream>
#include <vector>

namespace dature {

class BinarySearch {
public:
    // constructor
    BinarySearch() : size_(0), max_size_(10) {};
    ~BinarySearch() = default;

    // helpler function for insert
    bool Insert(const std::pair<int, int>& item);
    // helpler function for search, store value into output parameters
    bool Find(const int &key, int &value);

    // find the key at the specific index
    int KeyAt(int index);
    // find the key at the specific index
    int ValueAt(int index);
    // get the current size
    int GetSize() {return size_;}

    // helpler function for delete
    bool Delete(const int &key);


private:
    std::pair<int, int> data_[10];
    int size_;
    int max_size_;
    int insertAtIndex(const int &key);
    int deleteAtIndex(const int &key);
};

} // namesapce dature

#endif
