#ifndef ELEMENT
#define ELEMENT
#include <string>

using namespace std;

class Element {

public:
    Element();
    Element(string data);
    string getData() const;
    void setData(string value);
   
private:
    string data;
};

#endif