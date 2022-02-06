#include <iostream>
#include <string>
#include "Stack.hpp"


int main(){

    DSLib::Stack<std::string> strStack;
    int stackSize;

    strStack.push("apple");
    strStack.push("banana");
    strStack.push("orange");
    strStack.push("peach");
    strStack.push("grape");
    strStack.push("mango");


    std::cout << "is strStack empty? " << strStack.isEmpty() << std::endl;
    stackSize = strStack.size();
    std::cout << "strStack size: " << stackSize << std::endl;
    std::cout << "top of stack: " << strStack.top() << std::endl;

    std::cout << std::endl << "Popping all values off the stack:" << std::endl;
    std::string output;
    while(!strStack.isEmpty()){
        strStack.pop(output);
        std::cout << output << std::endl;
    }

    std::cout << std::endl;
    std::cout << "is strStack empty? " << strStack.isEmpty() << std::endl;
    stackSize = strStack.size();
    std::cout << "strStack size: " << stackSize << std::endl;

    return 0;
}
