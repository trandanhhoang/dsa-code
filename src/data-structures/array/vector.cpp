#include "vector.h"

#include <vector>
using namespace std;

void testInsertRemove() {
    Vector<int> vec;
// 1 2 2 3 5 2 6
// 1 3 2 2 5 2 6
// 1 3 5 6 2 2 2
//1 3 2 4 5 6
    vec.pushBack(1);
    vec.pushBack(2);
    vec.pushBack(2);
    vec.pushBack(3);
    vec.pushBack(5);
    vec.pushBack(2);
    vec.pushBack(6);

    vec.traverse();
    cout << "Capacity: " << vec.getCapacity() << "\n";
    cout << "Search for 4: " << boolalpha << (vec.find(4) != -1) << "\n";
    cout << "Search for 8: " << boolalpha << (vec.find(8) != -1) << "\n";
    cout << "\n";

    cout << "Remove all elements\n";
    vec.remove(2);
    vec.traverse();
    vec.pushBack(5);
    vec.pushBack(2);
    vec.pushBack(6);
    vec.traverse();


    cout << "\n";
}

void testResizeReserve() {
    Vector<float> vec;
    vec.pushBack(1);
    vec.pushBack(2);
    vec.pushBack(3);
    vec.pushBack(4);
    vec.pushBack(5);
    vec.traverse();
    cout << "Capacity: " << vec.getCapacity() << "\n";
    vec.reserve(10);
    cout << "After reserve Capacity: " << vec.getCapacity() << "\n";
    vec.traverse();
    vec.resize(4, 10);
    cout << "size " << vec.getSize()<<endl;
    vec.traverse();
    vec.resize(15, 10);
    vec.traverse();
    cout << "Capacity: " << vec.getCapacity() << "\n";
    cout << "\n";
}



void testAssignmentConstructor() {
    Vector<bool> vec1(3, true);
    // Test assignment
    Vector<bool> vec2;
    vec2 = vec1;
    vec2.traverse();
    // Test copy constructor
    Vector<bool> vec3 = vec2;
    vec3.traverse();
    // Test move constructor
    auto foo = [](Vector<bool> vec) { return vec; };
    Vector<bool> vec4 = foo(Vector<bool>(5));
    vec4.traverse();
}

int main() {
    testInsertRemove();
    // testResizeReserve();
    // testAssignmentConstructor();

    return 0;
}
