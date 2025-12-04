#include <iostream>
#include <memory>


int main()
{
    std::unique_ptr<int> int_ptr({new int(5)});
    std::unique_ptr<int> bar({new int(5)});

    // bar = ptr; Error

    // (Working)Raw Pointers Not Recommended and take care you are the one who requested Add
    // int *bar = int_ptr.get();

    // Moving OwnerShip of int_ptr to bar
    // Accessing int ptr after this will segmentation fault (free the heap)
    bar = std::move(int_ptr);

    
    std::cout << *bar << std::endl;
    std::cout << *int_ptr << std::endl;
}