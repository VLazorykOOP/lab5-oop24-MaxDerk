#include <iostream>
#include <string>
using namespace std;

class Tail
{
private:
    double length;
public:
    Tail(double l = 0.0) : length(l) {}
    double getLength() const
    {
        return length;
    }
    void setLength(double l)
    {
        length = l;
    }
};
class Dog
{
protected:
    Tail tail;
    string color;
    int age;
public:
    Dog(const string& col = "Unknown", int ag = 0, double tailLen = 0.0)
        : tail(tailLen), color(col), age(ag) {
    }
    ~Dog()
    {
        cout << "Destroying Dog\n";
    }
    const string& getColor() const
    {
        return color;
    }
    int getAge() const
    {
        return age;
    }
    double getTailLength() const
    {
        return tail.getLength();
    }
};
class NamedDog : public Dog
{
private:
    string name;
public:
    NamedDog(const string& col = "Unknown", int ag = 0, double tailLen = 0.0, const string& nm = "Unknown")
        : Dog(col, ag, tailLen), name(nm) {
    }
    ~NamedDog()
    {
        cout << "Destroying NamedDog\n";
    }
    void print() const
    {
        cout << "Color: " << color << "\nAge: " << age << "\nTail length: " << tail.getLength() << " cm" << "\nName: " << name << endl;
    }
};
int main()
{
    string tempColor, tempName;
    int age;
    double tailLen;
    cout << "Input dog data:\n";
    cout << "Input dog color: ";
    getline(cin, tempColor);
    cout << "Input dog age: ";
    cin >> age;
    cout << "Input tail length (cm): ";
    cin >> tailLen;
    cin.ignore();
    cout << "Input dog name: ";
    getline(cin, tempName);
    NamedDog dog(tempColor, age, tailLen, tempName);
    cout << "Output dog data:\n";
    dog.print();
    return 0;
}