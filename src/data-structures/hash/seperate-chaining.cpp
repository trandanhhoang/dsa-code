#include "seperate-chaining.h"

#include "hash.h"

using namespace std;

template <class TValue>
class IntegerHashTable : public HashTable<int, TValue> {
    int hash(int key) {
        return key;
    }
};

int main() {
    srand(time(0));
    IntegerHashTable<int> hashTable;

    /* Insert */
    cout << "Initial hash table\n";
    hashTable.print();
    cout << "\n";

    vector<int> keys({1, 10, -20, 99, 10, -77, 24, 75, 1, 41, -33, -11});
    for (auto &&key : keys) {
        int value = rand() % 100;
        if (hashTable.exists(key)) {
            cout << "Set key " << key << " to value " << value << "\n";
        } else {
            cout << "Insert key " << key << " with value " << value << "\n";
        }
        int bucketCount = hashTable.getNumOfBuckets();
        hashTable[key] = value;
        if (bucketCount < hashTable.getNumOfBuckets()) {
            cout << "Perform rehash\n";
        }
        hashTable.print();
        cout << "\n";
    }

    /* Remove */
    for (auto &&key : {10, -20, 99, 41, -11}) {
        cout << "Remove key " << key << "\n";
        hashTable.remove(key);
    }
    cout << "\n";
    hashTable.print();

    return 0;
}
