#include <iostream>
#include "LinkedList.hpp"

int main(){
    DSLib::LinkedList<int> mylist;

    mylist.insert(10);
    mylist.insert(2);
    mylist.insert(9);
    mylist.insert(7);
    mylist.insert(0);

    mylist.remove(9);

    std::cout << "Size: " << mylist.size() << std::endl;
    std::cout << "Values: ";
    mylist.print();
    std::cout << std::endl;
}
