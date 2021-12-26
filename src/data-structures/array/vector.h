#if !defined(VECTOR_H)
#define VECTOR_H

#include <cstring>
#include <iostream>

using namespace std;

template <class T>
class Vector {
   protected:
    T *arr = nullptr;
    int size = 0;
    int capacity = 0;

   public:
    Vector() = default;
    Vector(int initSize, T defaultValue = T());
    Vector(const Vector &that);
    Vector(Vector &&that);
    ~Vector();

    Vector &operator=(const Vector &that);
    T &operator[](int index);
    const T &operator[](int index) const;

    int getSize() {return size;}
    int getCapacity() { return capacity; }
    bool empty() { return size == 0; }

    void resize(int size, T defaultValue = T());
    void reserve(int newCapacity);
    int find(int value);
    void insertAt(int index, T value);
    void pushBack(T value);
    void remove(T value);
    void removeAt(int index);
    void popBack();
    void clear();
    void traverse();
};

/* Constructor and assignment */

template <class T>
Vector<T>::Vector(int initSize, T defaultValue) : size(initSize),
                                                  capacity(2 * initSize) {
    arr = new T[capacity];
    for (int i = 0; i < size; i++) {
        arr[i] = defaultValue;
    }
}

template <class T>
Vector<T>::Vector(const Vector<T> &that) : size(that.size),
                                           capacity(that.capacity) {
    std::cout << "Copy constructor called\n";
    arr = new T[capacity];
    for (int i = 0; i < size; i++) {
        arr[i] = that[i];
    }
}

template <class T>
Vector<T>::Vector(Vector<T> &&that) : size(that.size),
                                      capacity(that.capacity),
                                      arr(that.arr) {
    std::cout << "Move constructor called\n";
    that.arr = nullptr;
}

template <class T>
Vector<T> &Vector<T>::operator=(const Vector<T> &that) {
    std::cout << "Assignment called\n";
    capacity = that.capacity;
    size = that.size;
    arr = new T[capacity];
    for (int i = 0; i < size; i++) {
        arr[i] = that.arr[i];
    }
    return *this;
}

/* Allocation */

template <class T>
void Vector<T>::resize(int newSize, T defaultValue) {
    if (newSize < 0) {
        throw "Invalid size!";
    }
    //check old and new
    if(this->capacity < newSize){
        this->reserve(newSize);
    }
    T *new_arr = new T[newSize];
    if(size > newSize){
        for(int i =0;i<newSize;i++){
            new_arr[i] = this->arr[i];
        }
    }
    else{
        for(int i = 0;i<size;i++){
            new_arr[i] = this->arr[i];
        }
        for(int i = size;i<newSize;i++){
            new_arr[i] = defaultValue;
        }
    }
    // assign 2 variable and delete old pointer array.
    delete[] arr;
    this->size = newSize;
    this->arr = new_arr;
}

template <class T>
void Vector<T>::reserve(int newCapacity) {
    // TODO
    //check old and new
    if(newCapacity<size){
        throw "newCap < size";
    }
    T *new_arr = new T[newCapacity];
    for(int i =0;i<size;i++){
        new_arr[i] = this->arr[i];
    }
    // assign 2 variable and delete old pointer array.
    this->capacity = newCapacity;
    delete[] arr;
    this->arr = new_arr;
}

/* Basic operations */

template <class T>
T &Vector<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        throw "Out of index!";
    }
    return arr[index];
}

template <class T>
const T &Vector<T>::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw "Out of index!";
    }
    return arr[index];
}

template <class T>
int Vector<T>::find(int value) {
    // TODO
    for(int i=0;i<this->size;i++){
        if (this->arr[i]==value)
            return i;
    }
    return -1;
}

template <class T>
void Vector<T>::insertAt(int index, T value) {
    if (index < 0 || index > size) {
        throw "Out of index!";
    }
    // TODO
    size++;
    if(size>capacity){
        this->reserve(this->capacity*2);
    }
    if(capacity==0){
        this->reserve(this->capacity+1);
    }
    for(int i=size;i>index;i--){
        this->arr[i]=this->arr[i-1];
    }
    this->arr[index] = value;
}

template <class T>
void Vector<T>::pushBack(T value) {
    // TODO
    this->reserve(this->capacity+1);
    this->arr[size] = value;
    size++;
}

template <class T>
void Vector<T>::remove(T value) {
    // TODO
    // int index = this->find(value);
    // if(index != -1){
    //     for(int i=index;i<size-1;i++){
    //         this->arr[i] = this->arr[i+1];
    //     }
    //     this->size--;
    // }
    T a;
    int index;
    int check=0;
    for(index = 0;index<size;index++){
        if(check==size){
            break;
        }
        while(arr[check]==value){
            check++;
        }
        arr[index]=arr[check];
        check++;
    }
    size = index;
}

template <class T>
void Vector<T>::removeAt(int index) {
    if (index < 0 || index >= size) {
        throw "Out of index!";
    }
    for(int i=index;i<size-1;i++){
        this->arr[i] = this->arr[i+1];
    }

    this->size--;
    // TODO
}

template <class T>
void Vector<T>::popBack() {
    //check size
    size--;
}

template <class T>
void Vector<T>::clear() {
    size = 0;
}

/* Traversal */

template <class T>
void Vector<T>::traverse() {
    std::cout << "Traverse: ";
    // TODO
    for(int i =0;i<this->size;i++){
        cout<< this->arr[i] <<" ";
    }
    std::cout << "\n";
}

/* Destructor */

template <class T>
Vector<T>::~Vector() {
    // TODO
    delete[] arr;
}

#endif  // VECTOR_H
