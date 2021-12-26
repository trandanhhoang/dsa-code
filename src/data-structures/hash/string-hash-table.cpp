#include "hash.h"
#include "seperate-chaining.h"

using namespace std;

template <class TValue>
class StringHashTable : public HashTable<string, TValue> {
    int hash(string key) {
        return javaStringHashCode(key);
    }
};

float randomFloat() {
    return (rand() % 10000) / 100.0;
}

int main() {
    srand(time(0));
    StringHashTable<float> hashTable;

    hashTable["Alice"] = randomFloat();
    hashTable["Bob"] = randomFloat();
    hashTable["Peter"] = randomFloat();
    hashTable["David"] = randomFloat();
    hashTable["John"] = randomFloat();
    hashTable["Chris"] = randomFloat();

    hashTable.print();

    return 0;
}
