#if !defined(SEPERATE_CHAINING_H)
#define SEPERATE_CHAINING_H

#include <iostream>
#include <vector>

/* Single node of hash table */

template <class TKey, class TValue>
struct Node {
    TKey key;
    int hashCode;
    TValue value;
    Node<TKey, TValue> *next;
    Node(TKey key, int hashCode, Node *next) : key(key),
                                               hashCode(hashCode),
                                               next(next) {}
};

/* Hash table using seperate chaining */

template <class TKey, class TValue>
class HashTable {
    typedef Node<TKey, TValue> NodeType;

   protected:
    std::vector<NodeType *> buckets;
    int numOfElements = 0;
    const float maxLoadFactor = 1.0;

    /* Default hash function */

    virtual int hash(TKey key) = 0;

    /* Bucket utils */

    int getBucketIndex(int hashCode) {
        // TODO: Get bucket index from hash code
    }

    // Get next number of buckets
    int nextPrimeNumOfBuckets(int minNumberOfBuckets) {
        // Double number of buckets
        int newNumOfBuckets = minNumberOfBuckets;
        bool isPrime = false;
        // Check if current number of buckets is prime
        while (!isPrime) {
            isPrime = true;
            for (int i = 3; i * i <= newNumOfBuckets; i += 2) {
                if (newNumOfBuckets % i == 0) {
                    isPrime = false;
                    break;
                }
            }
            // Try next one if current number of buckets fail
            if (!isPrime) newNumOfBuckets += 2;
        };
        return newNumOfBuckets;
    }

    void rehash(int numOfBuckets) {
        // TODO: Rehash all nodes by new number of buckets
    }

   public:
    HashTable() {
        buckets = std::vector<NodeType *>(1);
    }

    ~HashTable() {
        // TODO
    }

    int getNumOfElements() {
        return numOfElements;
    }

    int getNumOfBuckets() {
        return buckets.size();
    }

    /* Basic operations */

    TValue &operator[](TKey key) {
        // TODO:
        // - Set if key exists
        // - Insert if key does not exist (like unordered_map of STL)
        // - Rehash if load factor >= max load factor
    }

    bool exists(TKey key) {
        // TODO: Check if node of key exists
    }

    void remove(TKey key) {
        // TODO: Remove node of key
    }

    /* IO utils */

    void print() {
        std::cout << "Number of elemenets: " << numOfElements << "\n";
        std::cout << "Number of buckets: " << buckets.size() << "\n";
        std::cout << "Buckets:\n";
        for (int i = 0; i < buckets.size(); i++) {
            std::cout << i << ": ";
            NodeType *node = buckets[i];
            while (node) {
                if (node != buckets[i]) {
                    std::cout << " -> ";
                }
                std::cout << "(" << node->key << "," << node->value << ")";
                node = node->next;
            }
            std::cout << "\n";
        }
    }
};
#endif  // SEPERATE_CHAINING_H
