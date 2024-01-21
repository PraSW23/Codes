#include<iostream>
using namespace std;

class Promotion{//abstract class
    virtual void isPromoted()=0;//no need to worry about implementation (Pure virtual fun)
};

class Employee:Promotion{
    private: //Encapsulation
    string name;
    string company;
    int age;

    public:

    void setName(string name){
        this->name = name;
    }

    void setCompany(string company){
        this->company = company;
    }

    void setAge(int age){
        if(age >= 18)
        this->age = age;
    }

    string getName(){
        return this->name;
    }

    string getCom(){
        return this->company;
    }

    int getAge(){
        return this->age;
    }

    Employee(string name="", string company="", int age=0){
        this->name = name;
        this->company = company;
        this->age = age;
    }
    void isPromoted(){
        if(age>22){
            cout<<"Congratulations "<<name<<" you are promoted !"<<endl;
        }
        else cout<<"Sorry "<<name<<" we appreciate your hardwork but no promotions for you !"<<endl;
    }
    virtual void work(){
        cout<<"Work on Gitlab "<<endl;
    }

};

class Coder : public Employee{
    private:
    string favlan;
    public:
    Coder(string name, string company, int age, string favlan):Employee(name, company, age){
        this->favlan = favlan;
    }
    string favlang(){
        return this->favlan;
    }
    void work(){
        cout<<"Do coding in "<<favlan<<endl;
    }

};

class Teacher : Employee{
    private:
    string favsub;
    public:
    Teacher(string name, string company, int age, string favsub):Employee(name, company, age){
        this->favsub= favsub;
    }
    string favSub(){
        return this->favsub;
    }
    void work(){
        cout<<"Work on "<<favsub<<" subject to teach "<<endl;
    }
};

int main(){

    Employee e1 = Employee("Ravi", "google", 25);
    Employee e2("subhash", "MS", 20);
    cout<<e1.getName()<<endl;
    e1.setCompany("Amazon");
    cout<<e1.getCom()<<endl;
    e2.isPromoted();

    Coder c1("abinav","intel",36,"C++");
    cout<<"fav = "<<c1.getAge()<<endl;
    c1.work();

    Teacher t1("Manoj","APCL",32,"Database");
    t1.work();

    Employee * e4 = &c1;
    e4->work();

return 0;
}