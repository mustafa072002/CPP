#include <iostream>
#include <initializer_list>
class String
{
private:
    int var;
    int *ptr = nullptr;
    int  arr[5] = {1,2,3,4,5};


public:
    String()
    {
        std::cout << "Default Constructor Called" << std::endl;
        var = 5;
        ptr = new int(5);
    }

    String(int x)
    {
        var = x;
        ptr = new int(5);
    }
    // String (const String& obj) = delete; // prevent Copying
    // String (const String& obj) = default; //Use Compiler Default Copy Constructor

    ~String()
    {
        delete[] ptr;
    }
    String(String &obj)
    {
        var = obj.var;
        ptr = new int(5);
        // delete obj.ptr;
        std::cout << "myCopy Constructor Called" << std::endl;
    }

    // String(String &&obj)
    // {
    //     std::cout << "Move Constructor Called" << std::endl;
    // }

    float add(std::initializer_list<float> a, std::initializer_list<float> b)
    {
        return *a.begin() + *b.begin();
    }
    int add(std::initializer_list<int> a, std::initializer_list<int> b)
    {
        return *a.begin() + *b.begin();
    }

    String& operator=(const String& ref)
    {
        var =ref.var;
        bar = ref.bar;
        *ptr = *ref.ptr;

        return *this;
    }

    String operator+(String ref)
    {   
        ref.var += var;
        ref.bar += bar;
        return ref;
    }

    bool operator>=(String& ref)
    {
        if (var >= ref.var)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int operator[](int x)
    {
        return arr[x];
    }

    /* Pre Increment */
    String& operator++()
    {
        bar++;
        return *this;
    }

    /* Post Increment */
    String operator++(int)
    {
        String Temp = *this;
        this->bar++;
        return Temp;
    }

    int getVar()
    {
        return var;
    }

    int bar = 500;
};

String &func(String &obj)
{
    return obj;
}

String operator+(int x , String &ref)
{
    String Temp;
    Temp.bar = x + ref.bar;
    return Temp;
}

int main()
{
    
    String C(100);
    String B;
    String A;
    A.operator=(B.operator+(C));

    String D ;
    D = 5+C ;
    int xarray[5] = {6,7,8,9,10};
    xarray[0] = D[0];
    
    std::cout << xarray[0] << std::endl;
    std::cout << D.getVar() << std::endl;
    std::cout << C.operator>=(A) << std::endl;
}
