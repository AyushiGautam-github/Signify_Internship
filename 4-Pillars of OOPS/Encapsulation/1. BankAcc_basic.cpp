#include <iostream>
using namespace std;

class BankAcc {
private:
    int bal;
public:
    BankAcc() {
        bal= 0;
    }

    void deposit(int amt) {
        if (amt > 0) bal+= amt;
    }

    void withdraw(int amt) {
        if (amt > 0 && amt <= bal) bal -= amt;
        else cout << "Insufficient bal! \n";
    }
    int getBalance() {
        return bal;
    }
};

int main() {
    BankAcc acc;
    acc.deposit(1000); // we dont know how they are working behind the scene
    acc.withdraw(500);
    cout << "Balance: " << acc.getBalance() << endl;

    // acc.bal = 10000; // not allowed as its private
    return 0;
}
