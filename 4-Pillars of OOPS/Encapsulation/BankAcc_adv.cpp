#include<iostream>
#include<string>
using namespace std;

//using frnd class= gives selective access to pvt members (to reset pin)
//using static members= single shared copy for all instances (bankcode)
//const= protects fucntion from changing the object
//pvt helper methods- verifypin()

class BankSecurity;

class BankAcc{
    private:
    string accholder;
    string accno;
    double bal;
    string pin;
    static string bankcode; //this is shared across all objects

    bool verifypin(const string& pin) {
        return (this->pin==pin);
    }
    friend class BankSecurity;

    public:
    BankAcc(): accholder("Unknown"), accno("000000"),bal(0.0), pin("0000"){}
    BankAcc(string accholder, string accno, double bal, string pin){
        this->accholder=accholder;
        this->accno=accno;
        setbal(bal);
        setpin(pin);
    }

    void setpin(string pin){
        if(pin.length()==4) this->pin=pin;
        else cout<<"enter 4 digit pin"<<endl;
    }
    void setbal(double amt){
        if(amt>0) bal=amt;
    }

    void deposit(double amt, const string &pin){
        if(verifypin(pin)){
        if(amt>0) bal+=amt;
        else cout<<"invalid amt!"<<endl;
        }
        else cout<<"invalid pin!"<<endl;
    }
    void withdraw(double amt, const string& pin){
        if(verifypin(pin)){
        if(amt>0 && amt<=bal) bal-=amt;
        else cout<<"Invalid amt or insufficient bal!";
    }
    else cout<<"invalid pin!"<<endl;
    }
    void display() const{
        cout<<"ACCOUNT SUMMARY--"<<endl;
        cout<<"Account Holder: "<<accholder<<endl;
        cout<<"Account Number: "<<accno<<endl;
        cout<<"Bal: "<<bal;
    }

    static void setbankcode(const string& bcode){
        bankcode=bcode;
    }
    static string getbankcode(){
        return bankcode;
    }
};

string BankAcc::bankcode="SBIN0001234";

class BankSecurity {
    public: 
    void resetpin(BankAcc& acc, const string& oldpin, const string& newpin){
        if(acc.verifypin(oldpin)){
            if(newpin.length()==4){
                acc.pin=newpin; cout<<"Pin reset!"<<endl;
            }
            else cout<<"enter valid 4 digit pin!"<<endl;
        }
        else cout<<"old pin is incorrect!"<<endl;
    }
    double getbal(BankAcc& acc, const string& pin){
        if(acc.verifypin(pin)) return acc.bal;
        else{cout<<"inavalid pin!"<<endl; return -1;}
    }
};

int main(){
    BankAcc a1("Ayushi Gautam", "123456", 5000.0,"4321");
    a1.display();
    string pin;

    cout<<endl<<"enter pin to deposit 5000-";
    cin>>pin;
    a1.deposit(3000, pin);
    cout<<endl<<"enter pin to withdraw 1000-";
    cin>>pin;
    a1.withdraw(1000,pin);

    BankSecurity sc;
    cout<<"Reset pin"<<endl;
    string oldpin, newpin;
    cout<<"enter old pin-"<<endl;
    cin>>oldpin;
    cout<<"enter new pin-"<<endl;
    cin>>newpin;

    sc.resetpin(a1, oldpin, newpin);

    cout<<"checking balance-"<<endl;
    cout<<"enter recently changed pin-"<<endl;
    cin>>pin;
    double bal=sc.getbal(a1,pin);
    cout<<"current balance="<<bal;
}