#if !defined(TOWER_OF_HANOI_H)
#define TOWER_OF_HANOI_H

#include <iostream>
#include <unordered_map>
#include <vector>

class TowerOfHanoi {
    std::unordered_map<char, std::vector<int>> disks;
    std::vector<char> rods;

   public:
    TowerOfHanoi(int numOfDisks, std::vector<char> rods, char src);
    int move(char src, char dst);
    void print();
};

TowerOfHanoi::TowerOfHanoi(int numOfDisks, std::vector<char> rods, char src) : rods(rods) {
    for (int i = numOfDisks; i >= 1; i--) {
        disks[src].emplace_back(i);
    }
}

int TowerOfHanoi::move(char src, char dst) {
    int disk = disks[src].back();
    disks[src].pop_back();
    disks[dst].emplace_back(disk);
    return disk;
}

void TowerOfHanoi::print() {
    for (auto &&rod : rods) {
        std::cout << rod << ": ";
        for (auto &&ele : disks[rod]) {
            std::cout << ele << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

#endif  // TOWER_OF_HANOI_H
