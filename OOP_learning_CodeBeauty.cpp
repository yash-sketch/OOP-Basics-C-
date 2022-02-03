#include<iostream>
using namespace std;

//Abstraction (complex system is hidden and is represented as a very simple system)

class abstractEmployee{
    virtual void AskforPromotion() = 0; //makes this function(method) obligatory ie any class that signs this contract or is
                                        //derived from this abstract class will have to provide an implimentation for this method
                                        //here the AskforPromotion is the simplified version as if someone comes and sees that Employee 
                                        //class has signed this contract then they must have have provided an implimentation for this too
                                        //and that user does not have to worry about how it's done they can just use this functionality 
                                        //without any worry. That is how Abstraction works!!! :D
};

class Employee: abstractEmployee{
private:
    string Name;
    string Company;
    int Age;
public:
    
    //Encapsulation (getter setter)
    void setName(string name){
        Name = name;    
    }
    string getName(){
        return Name;
    }
    void setCompany(string company){
        Company = company;    
    }
    string getCompany(){
        return Company;
    }
    void setAge(int age){
        if(age>18)Age= age;    
    }
    int getAge(){
        return Age;
    }  

    

    void Introduce(){
        cout<<"Name : "<<Name<<"\n";
        cout<<"Company : "<<Company<<"\n";
        cout<<"Age : "<<Age<<"\n";
    }
    Employee(string name , string company, int age){   //constructor 

        Name = name ;               // 3 rules : 1. No return type
        Company = company;          // 2. same name as the class
        Age = age;                  // 3. is public (not necessarilly always)
    }

    void AskforPromotion(){
        if(Age>30) {
            cout<<Name<<" congrats you got promoted!"<<"\n";
        }else{
            cout<<Name<<" sorry NO promotion for you:("<<"\n";
        }
    }
    virtual void work(){
        cout<<Name<<" is reading mail,replying to them , fixing bugs ...."<<"\n";
    }
};

// Inheritance :
//         Parent class -> Child class(has all the attributes of the parent and some of it's own)
//      
class Developer:public Employee{
public:
    string FavProglang;
    Developer(string name , string company, int age , string favProglang)
    :Employee(name ,company, age)
    {
        FavProglang= favProglang;
    }
    void Fixbug(){
        cout<<getName()<<" is fixing bug using "<<FavProglang<<"\n";
    }
    void work(){
        cout<<getName()<<" is writing "<<FavProglang<<" code"<<"\n";
    }
};

class Teacher:public Employee{
public:
    string Subject;
    
    Teacher(string name , string company, int age, string subject)
    :Employee(name,company,age)
    {
        Subject = subject;
    }
    void PrepareLesson(){
        cout<<getName()<<" is teaching "<<Subject<<"\n";
    }

    void work(){
        cout<<getName()<<" Teaching "<<Subject<<" to kids"<<"\n";
    }
};

signed main(){
    Developer d= Developer("Saldina", "You Tube", 25, "C++");
    Teacher t= Teacher("John", "Abc School", 35, "History");
    //POLYMORPHISM:
    // THE MOST COMMON USE OF POLYMORPHISM IS WHEN A PARENT CLASS REFERENCE IS USED TO 
    // REFER TO A CHILD CLASS OBJECT
    Employee *e1= &d;
    Employee *e2= &t;

    e1->work();  // to make it work be sure that "work()" method in Employee class is virtual
    e2->work();

}