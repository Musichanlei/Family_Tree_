#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <sstream>

class Person {
public:
    Person() {}

    Person(std::string first, std::string last, std::string bYear, std::string dYear) {
        setFirst(first);
        setLast(last);
        setBYear(bYear);
        setDYear(dYear);
    }

    Person(std::string first, std::string last, std::string bYear, std::string dYear, std::string spouse) {
        setFirst(first);
        setLast(last);
        setBYear(bYear);
        setDYear(dYear);
        setSpouse(spouse);
    }

    void setFirst(std::string theFirst) {
        fName = theFirst;
    }

    void setLast(std::string theLast) {
        Lname = theLast;
    }

    void setBYear(std::string theBYear) {
        BY = theBYear;
    }

    void setDYear(std::string theDYear) {
        DY = theDYear;
    }

    void setSpouse(std::string theSpouse) {
        SP = theSpouse;
    }

    std::string getFirst() {
        return fName;
    }

    std::string getLast() {
        return Lname;
    }

    std::string getBYear() {
        return BY;
    }

    std::string getDYear() {
        return DY;
    }

    std::string getSpouse() {
        return SP;
    }

    std::string toString() {
        std::ostringstream output;
        output << getFirst() << " " << getLast() << std::endl 
               << getBYear() << "-" << getDYear() << std::endl << std::endl;
        if (!getSpouse().empty()) {
            output << "Married to: " << std::endl << getSpouse();
        }
        return output.str();
    }

private:
    std::string fName;
    std::string Lname;
    std::string BY;
    std::string DY;
    std::string SP;
};

#endif
