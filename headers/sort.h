#if !defined(SORT_H)
#define SORT_H

#include <iostream>

struct SortData {
    int key;
    std::string value;
    SortData() = default;
    SortData(int key, std::string value) : key(key), value(value) {}
    bool operator>(const SortData &that) { return key > that.key; }
    bool operator<(const SortData &that) { return key < that.key; }
    bool operator>=(const SortData &that) { return key >= that.key; }
    bool operator<=(const SortData &that) { return key <= that.key; }
    bool operator==(const SortData &that) { return key == that.key; }
    bool operator!=(const SortData &that) { return key != that.key; }
};

std::vector<SortData> getUnsortedStableData() {
    return std::vector<SortData>{
        SortData(4, "A"),
        SortData(4, "B"),
        SortData(2, "A"),
        SortData(1, "A"),
        SortData(2, "B"),
        SortData(3, "A"),
        SortData(1, "B"),
        SortData(3, "B"),
        SortData(1, "C"),
        SortData(2, "C"),
        SortData(3, "C"),
        SortData(4, "C"),
    };
}

void printSortData(std::vector<SortData> &data) {
    for (int i = 0; i < data.size(); i++) {
        std::cout << "(" << data[i].key << "," << data[i].value << ")";
        if (i == data.size() - 1 || data[i].key != data[i + 1].key) {
            std::cout << "\n";
        } else {
            std::cout << " ";
        }
    }
};

#endif  // SORT_H
