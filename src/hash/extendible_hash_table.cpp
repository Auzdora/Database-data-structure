#include "hash/extendible_hash_table.h"

namespace dature {

//==================================================//
//                  Bucket Define
//==================================================//
template <typename K, typename V>
ExtendibleHashTable<K, V>::Bucket::Bucket(size_t size, int local_depth)
: size_(size), local_depth_(local_depth) {}

template <typename K, typename V>
int ExtendibleHashTable<K, V>::Bucket::GetLocalDepth() {
    return local_depth_;
}

template <typename K, typename V>
bool ExtendibleHashTable<K, V>::Bucket::IsFull() {
    return bucket_.size() == size_;
}

template <typename K, typename V>
auto ExtendibleHashTable<K, V>::Bucket::Insert(const K &key, const V &value) -> bool {
    for (auto &[k, v] : bucket_) {
        if (k == key) {
            v = value;
            return true;
        }
    }

    if (IsFull()) {
        return false;
    }

    bucket_.emplace_back(key, value);
    return true;
}

template <typename K, typename V>
auto ExtendibleHashTable<K, V>::Bucket::Find(const K &key, V &value) -> bool {
    for (auto &[k, v] : bucket_) {
        if (k == key) {
            value = v;
            return true;
        }
    }
    return false;
}

template <typename K, typename V>
auto ExtendibleHashTable<K, V>::Bucket::Delete(const K &key) -> bool {
    for (auto &[k, v] : bucket_) {
        if (k == key) {
            bucket_.erase(k);
            return true;
        }
    }
    return false;
}

//==================================================//
//             ExtendibleHashTable Define
//==================================================//
// template <typename K, typename V>


template <typename K, typename V>
auto ExtendibleHashTable<K, V>::IndexOf(const K &key) -> size_t {
    int mask = (1 << global_depth_) - 1;
    return std::hash<K>()(key) & mask;
}

} // namespace dature

