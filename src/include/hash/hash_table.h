#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <vector>
#include <iostream>

namespace dature {

template <typename K, typename V>
class HashTable {
    public:
    HashTable() = default;
    ~HashTable() = default;

    virtual void Insert(const K &key, const V &value) = 0;
    virtual auto Find(const K &key, V &value) -> bool = 0;
    virtual auto Delete(const K &key) -> bool = 0;
};

} // namesapce dature

#endif