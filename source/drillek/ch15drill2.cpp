/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
*/

#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

struct Person{
private:
    string first_name;
    string last_name;
    int age;
public:
    Person(){};
    Person(string first_n, string last_n, int a){

        const string bad_chars = ";:\"`[]*&^*%$#@!";
        for(int i=0; i<first_n.size(); i++)
            for (int j=0; j<bad_chars.size(); ++j)
                if (first_n[i]==bad_chars[j]) error("Illegal character");
        for(int i=0; i<last_n.size(); i++)
            for (int j=0; j<bad_chars.size(); ++j)
                if (first_n[i]==bad_chars[j]) error("Illegal character");



        if (a<0 || a>=150) error("age must be between 0 and 150");
        if (first_n == "" || last_n == "") error("Name can't be empty!");


        constructor(first_n, last_n, a);
    }

    void constructor(string first_n, string last_n, int a){
        first_name = first_n;
        last_name = last_n;
        age = a;
    }

    string first() const {return first_name;}
    string last() const {return last_name;}
    int age1() const {return age;}
};




ostream& operator<<  (ostream& os, const Person& p){
    return os << p.first() << " "<<p.last() << " " << p.age1();
};

istream& operator>> (istream& is, Person& p)
{
    string first_name;
    string last_name;
    int age;

    cout << "Enter name: ";
    is >> first_name;

    cout << "Enter last name: ";
    is >> last_name;

    cout << "Enter age: ";
    is >> age;

    p=Person(first_name, last_name, age);

    return is;
};


int main(){

    Person Goofy{"Goofy", "Goofy", 63};
    cout << Goofy << "\n";

    Person random1;
    cin >> random1;
    cout << random1;


    cout << "Enter names and ages: " << "\n";

    vector<Person> persons;

    for(Person p; cin>>p;){
        if (p.first()=="stop") break;
        persons.push_back(p);
    }

    for(Person p : persons){

        cout << p << "\n";
    }
};