#include <iostream>

class string
{
private:
    char *name = nullptr;

public:

    /* =========Default Constructor===== */
    string()
    {
        std::cout << "Default Construcor \n";
        name = new char[8]{"Mustafa"};
    }
    
    /* =========Copy Constructor===== */
    string(string& obj){
        std::cout << "Copy Construcor \n";
    }


    /* ==========de-construcotr ======= */
    ~string()
    {
        std::cout << "Default deConstrucor \n";
        delete[] name;
        name = nullptr;
    }
    
};


void func(string str){
    return;
}

int main(){
    string mystring;

    func(mystring);
}