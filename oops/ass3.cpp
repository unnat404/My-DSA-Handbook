#include <iostream>
#include <malloc.h>
#include <string.h>
using namespace std;
class Animal
{
    int age;     // Age of Animal
    int weight;  // Weight of Animal
    string name; // Name of Animal
    char gender; // M or F
 
public:
    Animal(int x, int y, string z, char w)
    {
        age = x;
        weight = y;
        name = z;
        gender = w;
        cout << "Base Class Parameterized constructor called\n";
    }
    void printDetail()
    {
        cout << "I am " << name << ", age : " << age << " and weight : " << weight;
    }
    virtual void look()
    {
    }
    int getAge()
    {
        return age;
    }
    int getWeight()
    {
        return weight;
    }
    string getName()
    {
        return name;
    }
    char getGender()
    {
        return gender;
    }
};
 
class Tiger : public Animal
{
 
public:
    Tiger(int x, int y, string z, char w) : Animal(x, y, z, w) {}
    void look()
    {
        cout << " looks like a big cat.\n";
    }
};
class Lion : public Animal
{
 
public:
    Lion(int x, int y, string z, char w) : Animal(x, y, z, w) {}
 
    void look()
    {
        cout << " looks like a king of jungle.\n";
    }
};
 
int main()
{
 
    int noOfObjects;
    cout << "Enter the number of objects you want to make\n";
    cin >> noOfObjects;
    Animal *p[noOfObjects];
    Animal *q;
    string classType, Name;
    int Age, Weight;
    char Gender;
    for (int i = 0; i < noOfObjects; i++)
    {
        cout << "Enter the class name i.e choose either Lion / Tiger class and the name , gender , age and weight of the animal .\n";
        cin >> classType >> Name >> Gender >> Age >> Weight;
        if (classType == "Tiger" || classType == "tiger")
        {
            p[i] = new Tiger(Age, Weight, Name, Gender);
        }
        else
        {
            p[i] = new Lion(Age, Weight, Name, Gender);
        }
    }
    int maxi = 0;
    for (int i = 0; i < noOfObjects; i++)
    {
        p[i]->printDetail();
        p[i]->look();
        if (p[i]->getAge() > maxi)
        {
            maxi = p[i]->getAge();
            q = p[i];
        }
    }
    cout << "Oldest Animal\n";
    q->printDetail();
    q->look();
 
    return 0;
}