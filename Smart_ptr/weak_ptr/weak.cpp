#include <iostream>
#include <memory>

/** Bst5dmo Lw 3ayz yb2a 3ndy Owner For Shared Pointer bas fe nafs el wa2t mommkn a5ly 7d Tany
 *  Yshawer 3leh bas lw ana k owner 3mlt delete yb2a 5las malhosh access
 *  (Hena Mesh Hynf3 Unique Pointer l2n keda hya5od meny el ownership)
 *  w mesh hynf3 ykon raw pointer 3lshan hy access null lw ana ms7to
 *  a7yegy hena dor el weak
 */

class pointer
{
private:
    int *ptr = nullptr;

public:
    void print()
    {
        // *ptr = 10;
        std::cout << *ptr << std::endl;
    }

    void setValue(std::shared_ptr<int> obj)
    {
        ptr = obj.get();
    }
};

int main()
{

    std::shared_ptr<int> sptr = std::make_shared<int>(42);
    std::weak_ptr<int> wptr = sptr;
    wptr.
    // while(1);
}