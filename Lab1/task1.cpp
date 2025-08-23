#include<iostream>
using namespace std;

class BankAccount{
    private:
        float AccBalance;
    public:
        BankAccount(){
            AccBalance = 0;
            cout << "Default Constructor" << endl;
        }
        BankAccount(float a){
            AccBalance = a;
            cout << "Parameterized Constructor" << endl;
        }
        BankAccount(const BankAccount& obj){
            AccBalance = obj.AccBalance;
            cout << "Copy Constructor called" << endl;
        }
        float getBalance(){
            return AccBalance;
        }
        void setBalance(float a){
            AccBalance = a;
        }
};

int main(){
    BankAccount account1;
    cout <<"Account1 Balance: "  <<account1.getBalance() << endl << endl;
    BankAccount account2(1000);
    cout <<"Account2 Balance: "<< account2.getBalance() << endl << endl;
    BankAccount account3 = account2;
    account3.setBalance(account3.getBalance()-200);
    cout <<"Account3 Balance: "<< account3.getBalance() << endl << endl;
    cout << "Account2 Balance: " << account2.getBalance() << endl;

}
