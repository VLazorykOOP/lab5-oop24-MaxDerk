#include <iostream>
#include <string>
using namespace std;

class Education
{
protected:
    string institution;
    int years;
public:
    Education(const string& i = "Unknown", int y = 0)
        : institution(i), years(y) {}
    Education(const Education& other)
        : institution(other.institution), years(other.years) {}
    Education& operator=(const Education& other)
    {
        if (this != &other)
        {
            institution = other.institution;
            years = other.years;
        }
        return *this;
    }
    friend ostream& operator<<(ostream& os, const Education& e)
    {
        os << "Institution: " << e.institution << "\nYears: " << e.years;
        return os;
    }
    friend istream& operator>>(istream& is, Education& e)
    {
        cout << "Enter institution: ";
        getline(is, e.institution);
        cout << "Enter years of study: ";
        is >> e.years;
        is.ignore();
        return is;
    }
};
class HigherEducation : public Education
{
private:
    string degree;
public:
    HigherEducation(const string& inst = "Unknown", int y = 0, const string& d = "Unknown")
        : Education(inst, y), degree(d) {}
    HigherEducation(const HigherEducation& other)
        : Education(other), degree(other.degree) {}
    HigherEducation& operator=(const HigherEducation& other)
    {
        if (this != &other)
        {
            Education::operator=(other);
            degree = other.degree;
        }
        return *this;
    }
    friend ostream& operator<<(ostream& os, const HigherEducation& h)
    {
        os << static_cast<const Education&>(h) << "\nDegree: " << h.degree;
        return os;
    }
    friend istream& operator>>(istream& is, HigherEducation& h)
    {
        is >> static_cast<Education&>(h);
        cout << "Enter degree: ";
        getline(is, h.degree);
        return is;
    }
};

int main()
{
    HigherEducation h1;
    cout << "Input Higher Education data:\n";
    cin >> h1;
    cout << "\nOutput Higher Education data:\n";
    cout << h1 << endl;
    cout << "\nCopy constructor:\n";
    HigherEducation h2 = h1;
    cout << h2 << endl;
    cout << "\nAssignment operator:\n";
    HigherEducation h3;
    h3 = h1;
    cout << h3 << endl;
    return 0;
}