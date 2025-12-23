#include <memory>
#include <iostream>

int main()
{
    std::unique_ptr<int> uP1 = std::make_unique<int>(5);
    std::unique_ptr<int> uP2 {uP1.get()};
}