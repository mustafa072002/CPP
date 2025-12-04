#include <iostream>

class Buffer
{
private:
    int size;
    int *ptr;

public:
    /* Default Constructor */
    Buffer()
    {
        std::cout << "Default Constructor Called\n";
        size = 5;
        ptr = new int[size];
        for (int i = 0; i < size; i++)
        {
            ptr[i] = i;
        }
    }

    /* Parametrized  Constructor*/
    Buffer(int size)
    {
        std::cout << "Parametrized Constructor Called\n";
        this->size = size;
        ptr = new int[this ->size];
        for (int i = 0; i < this->size; i++)
        {
            ptr[i] = i;
        }
    }

    /* Copy Constructor */
    Buffer(const Buffer &obj)
    {
        std::cout << "Copy Constructor Called\n";
        size = obj.size;
        ptr = new int[size];
        for (int i = 0; i < size; i++)
        {
            ptr[i] = obj.ptr[i];
        }
    }
    /* Move Constructor */
    // Buffer(Buffer &&obj)
    // {
    //     std::cout << "Mover Constructor Called\n";
    //     size = obj.size;
    //     ptr = obj.ptr;
    //     obj.ptr = nullptr;
    // }

    /* Copy Assignment Operator */
    Buffer &operator=(Buffer &obj)
    {
        std::cout << "Copy Assignment Operator\n";
        size = obj.size;
        if (this != &obj)
        {
            delete[] ptr;
            ptr = new int[size];
            for (int i = 0; i < size; i++)
            {
                ptr[i] = obj.ptr[i];
            }
        }
        return *this;
    }
    /* Move Assignment Operator */
    Buffer operator=(Buffer &&obj)
    {
        std::cout << "Move Assignment Operator\n";
        if (this != &obj)
        {
            size = obj.size;
            delete[] ptr;
            ptr = obj.ptr;
            obj.ptr = nullptr;
        }
        return *this;
    }
    // ~Buffer()
    // {
    //     delete[] ptr;
    // }

    void PrintBuffer()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << ptr[i] << " ";
        }
        std::cout << "\n";
    }
};


class LogMessage
{

};
int main()
{
    /* code */
    Buffer b1;
    b1.PrintBuffer();
    Buffer b2 = Buffer(10);
    b2.PrintBuffer();
    Buffer b3(15);
    b3 = b2;
    b2 = std::move(b1);
    return 0;
}
