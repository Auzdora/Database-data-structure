#include "hash/hash_table.h"
#include <list>
#include <memory>
#include <mutex>  // NOLINT
#include <utility>
#include <vector>

namespace dature {

template <typename K, typename V>
class ExtendibleHashTable : public HashTable <K, V> {
    public:
    // constructor
    explicit ExtendibleHashTable(size_t size);

    /**
     * @brief Insert the KV pair to extendible hash table. If the KV pair has been inserted, 
     *  update its value.
     *  Note: 
     *    1. First check if it can directly insert into the IndexOf(key) bucket. If it 
     *      can, return. Otherwise execute step 2.
     *    2. Check if corresponding bucket is full.
     *    3. Then you need to check if global depth is equal to local depth, if it does,
     *      you need to expand the directory size and connect all new directory to corre-
     *      sponding buckets. And increase global depth atomically.
     *    4. Split bucket, redistribute KV pairs and directory pointers.
     *    5. Update the index, goto step 2.
     *    6. Insert the KV pairs that user specified.
     *   
     * @param key The key to be inserted.
     * @param value The value associated with the key.
     * @return None.
     */
    void Insert(const K &key, const V &value) override;

    /**
     * @brief Find the KV pair based on keys.
     *
     * @param key The key to be searched.
     * @param[out] value The value associated with the key.
     * @return If find the KV pair, return True, if not find, return False.
     */
    auto Find(const K &key, V &value) -> bool override;

    /**
     * @brief Delete the KV pair.
     *
     * @param key The key to be deleted.
     * @return If delete the KV pair, return True, if not find, return False.
     */
    auto Delete(const K &key) -> bool override;

    class Bucket {
        public:
        // constructor
        explicit Bucket(size_t size, int local_depth);

        inline int GetLocalDepth();

        inline bool IsFull();

        /**
         * @brief Insert the KV pair. First check if it has the key, if it has,
         *  update the value. Then check if bucket is full, return False if full.
         *
         * @param key The key to be inserted.
         * @param value The value associated with the key.
         * @return If insert the KV pair, return True, if failed, return False.
         */
        auto Insert(const K &key, const V &value) -> bool;

        /**
         * @brief Find the KV pair based on keys in the bucket.
         *
         * @param key The key to be searched.
         * @param[out] value The value associated with the key.
         * @return If find the KV pair, return True, if not find, return False.
         */
        auto Find(const K &key, V &value) -> bool;

        /**
         * @brief Delete the KV pair in the bucket.
         *
         * @param key The key to be deleted.
         * @return If delete the KV pair, return True, if not find, return False.
         */
        auto Delete(const K &key) -> bool;

        private:
        size_t size_;
        int local_depth_;
        std::list<std::pair<K, V>> bucket_;
    };

    private:
    int global_depth_;                         // global depth for extendible hash table
    int bucket_num_;                           // the total number of buckets
    size_t bucket_size_;                       // each bucket size
    std::vector<std::shared_ptr<Bucket>> dir_; // directory of the extendible hash table

    auto IndexOf(const K &key) -> size_t;
    auto GetGlobalDepth();
};

} // namespace dature