#include "Element.h"
#include <string>
using namespace std;

Element::Element(){
    data = '\0';
}

Element::Element(string data){
    this->data = data;
}

string Element::getData() const{
    return data;
}

void Element::setData(string value){
    this->data = value;
}