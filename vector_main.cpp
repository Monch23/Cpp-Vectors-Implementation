#include <iostream>
#include "vector.h"

int main() {
    // Test 1: Create a vector
    Vector vec;
    std::cout << "Initial size: " << vec.get_size() << std::endl;
    std::cout << "Initial capacity: " << vec.get_capacity() << std::endl;

    // Test 2: Push back elements
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    std::cout << "After push_back(10), push_back(20), push_back(30):" << std::endl;
    std::cout << "Size: " << vec.get_size() << std::endl;
    std::cout << "Capacity: " << vec.get_capacity() << std::endl;
    vec.list_vector();

    // Test 3: Push front
    vec.push_front(5);
    std::cout << "After push_front(5):" << std::endl;
    vec.list_vector();

    // Test 4: Access elements using at()
    std::cout << "Element at index 0: " << vec.at(0) << std::endl;
    std::cout << "Element at index 2: " << vec.at(2) << std::endl;

    // Test 5: Insert element at specific index
    vec.insert(2, 15); // Insert 15 at index 2
    std::cout << "After insert(2, 15):" << std::endl;
    vec.list_vector();

    // Test 6: Erase element at index
    vec.erase(1); // Erase element at index 1
    std::cout << "After erase(1):" << std::endl;
    vec.list_vector();

    // Test 7: Front and back elements
    std::cout << "Front element: " << vec.front() << std::endl;
    std::cout << "Back element: " << vec.back() << std::endl;

    // Test 8: Clear the vector
    vec.clear();
    std::cout << "After clear():" << std::endl;
    std::cout << "Size: " << vec.get_size() << std::endl;
    std::cout << "Capacity: " << vec.get_capacity() << std::endl;
    vec.list_vector();

    // Test 9: Shrink to fit
    vec.push_back(100);
    vec.push_back(200);
    vec.shrink_to_fit();
    std::cout << "After push_back(100), push_back(200), and shrink_to_fit():" << std::endl;
    std::cout << "Size: " << vec.get_size() << std::endl;
    std::cout << "Capacity: " << vec.get_capacity() << std::endl;
    vec.list_vector();

    return 0;
}
