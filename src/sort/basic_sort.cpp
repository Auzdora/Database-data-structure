#include "sort/basic_sort.h"

namespace dature {

bool BinarySearch::Insert(const std::pair<int, int>& item) {
    if (size_ + 1 > max_size_) {
        return false;
    }
    int idx = insertAtIndex(item.first);

    if (item.first == data_[idx].first) {
        idx = idx + 1;
    }
    
    // move the items after idx
    for (int i = size_ - 1; i >= idx; i--) {
        data_[i + 1].first = data_[i].first;
        data_[i + 1].second = data_[i].second;
    }
    // insert the item
    data_[idx].first = item.first;
    data_[idx].second = item.second;
    size_ ++;
    return true;
}

bool BinarySearch::Find(const int &key, int &value) {
    // use binary search to find the key
    int start = 0, end = GetSize() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (key < data_[mid].first) {
            end = mid - 1;
        } else if (key > data_[mid].first) {
            start = mid + 1;
        } else {
            value = data_[mid].second;
            return true;
        }
    }
    return false;
}

int BinarySearch::KeyAt(int index) {
    return data_[index].first;
}

bool BinarySearch::Delete(const int &key) {
    int index = deleteAtIndex(key);
    if (index == -1) {
        return false;
    }

    for (int i = index; i < size_ - 1; i ++) {
        data_[i].first = data_[i + 1].first;
        data_[i].second = data_[i + 1].second;
    }
    size_ += -1;
    return true;
}

int BinarySearch::deleteAtIndex(const int &key) {
    int start = 0, end = size_ - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (key < data_[mid].first) {
            end = mid - 1;
        } else if (key > data_[mid].first) {
            start = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int BinarySearch::insertAtIndex(const int &key) {
    // use binary search to find where to insert
    int start = 0, end = size_ - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (key <= data_[mid].first) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return start;
}

} // namespace dature