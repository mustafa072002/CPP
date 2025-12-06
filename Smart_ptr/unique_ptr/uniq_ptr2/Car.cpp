#include <memory>
#include <iostream>

class Car
{
private:
    std::string name;

public:
    Car(std::string name)
    {
        this->name = name;
    }
    std::string getName()
    {
        return name;
    }
};

class Employee
{
private:
    // Car * obj; Wrong mmkn employee tany yst5dm el 3arbya
    std::unique_ptr<Car> obj;

public:
    Employee(std::unique_ptr<Car> &car)
    {
        this->obj =std::move(car);
    }

    std::string getCarName()
    {
        return obj->getName();
    }
};

int main()
{
    std::unique_ptr<Car> bmw{new Car{"bmw"}};
    std::cout << bmw->getName() << std::endl;
    
    Employee emp{bmw}; // Bmw b3d Keda htb2a b Null
    std::cout << bmw->getName() << std::endl;

    
    
    std::cout << emp.getCarName() << std::endl;

}