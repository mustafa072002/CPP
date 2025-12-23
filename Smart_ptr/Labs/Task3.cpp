#include <memory>
#include <iostream>
#include <string> 
 
void observe(std::weak_ptr<int>& weak)
{
    std::cout << "weak count = " << weak.use_count() << "\n";
    if (auto p = weak.lock())
        std::cout << "\tobserve() is able to lock weak_ptr<>, value=" << *p << " with count = " << p.use_count() << " weak_count = " << weak.use_count() << '\n';
    else
        std::cout << "\tobserve() is unable to lock weak_ptr<>\n";
}

int main()
{
    std::weak_ptr<int> weak;
    std::cout << "weak_ptr<> is not yet initialized\n";
    observe(weak);

    /* would this work? why? */
    std::unique_ptr<int> p1 = std::make_unique<int>(42);
    // weak = p1;
 
    // what do the curly braces imply? what is their use in this case?
    {
        auto shared = std::make_shared<int>(42);
        weak = shared;
        std::cout << "weak_ptr<> is initialized with shared_ptr\n";
        observe(weak);
    }
 
    std::cout << "shared_ptr<> has been destructed due to scope exit\n";
    observe(weak);

    return 0;
}