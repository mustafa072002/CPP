#include <iostream>

class Account
{
private:
    float Balance;
    int ID;

protected:
    void AccountFees()
    {
    }

public:
    virtual void Withdraw(float Amount) = 0;
    virtual void Deposit(float Amount) = 0;

    Account() = delete;
    Account(int ID, float Balance)
    {
        this->ID = ID;
        this-> Balance = Balance;
    }
    ~Account() = default;
};

class SavingAccount : public Account
{
private:
    float interestRate;

public:


    void Withdraw(float Amount)
    {
        std::cout << "Withdrawing Amount Saving" << std::endl;
    }
    void Deposit(float Amount)
    {
        std::cout << "Depositing Amount Saving" << std::endl;
    }

    SavingAccount();
    SavingAccount(int ID , float Balance , float interestRate) : Account({ID} ,{Balance})
    {
        this->interestRate = interestRate;
    }
};

class CurentAccount : public Account
{
    public:


    void Withdraw(float Amount)
    {
        std::cout << "Withdrawing Amount Current" << std::endl;
    }
    void Deposit(float Amount)
    {
        std::cout << "Depositing Amount Current" << std::endl;
    }

    CurentAccount();
    CurentAccount(int ID , float Balance ) : Account({ID} ,{Balance})
    {
    }
};

void ATM(Account &ref)
{
    ref.Withdraw(1500);
}

int main()
{   
    SavingAccount obj(150 ,125.5 , 10);
    CurentAccount CurrObj(150 , 120);
    Account* obj2 = &CurrObj;
    obj2 ->Withdraw(150);
    ATM(obj);
}