#include<iostream>
#include<string>
using namespace std;

//using getters and setters
//adding pin for extra security
class BankAcc{
    private:
    string accholder;
    string accno;
    double bal;
    string pin;

    bool verifypin(const string& pin) const{
        return this->pin==pin;
    }

    public:
    BankAcc(): accholder("Unknown"), accno("000000"),bal(0.0), pin("0000"){}
    BankAcc(string accholder, string accno, double bal, string pin){
        this->accholder=accholder;
        this->accno=accno;
        setbal(bal);
        setpin(pin);
    }

    //setters (write only)
    void setpin(string pin){
        if(pin.length()==4) this->pin=pin;
        else cout<<"enter 4 digit pin"<<endl;
    }
    void setbal(double amt){
        if(amt>0) bal=amt;
    }
    void setaccno(string accno){
        if(accno.length()==6) this->accno=accno;
    }
    void setaccholder(string accholder){
        if(!accholder.empty()) this->accholder=accholder;
    }

    //getters (read only)
    double getbal(const string& pin) const{
        if(verifypin(pin)) return bal;
        else{
            cout<<"invalid pin!"<<endl;
            return -1;
        }
    }
    string getaccno() const{
        return accno;
    }
    string getaccholder() const{
        return accholder;
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

    cout<<endl<<endl<<"After Transaction:"<<endl;
    a1.display();

}