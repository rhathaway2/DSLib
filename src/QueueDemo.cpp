#include <iostream>
#include "Queue.hpp"


int main(){

    DSLib::Queue<char> q;

    q.enqueue('A');
    q.enqueue('B');
    q.enqueue('C');
    q.enqueue('D');
    q.enqueue('E');
    q.enqueue('F');

    std::cout << "Is the queue empty? " << q.isEmpty() << std::endl;
    std::cout << "The first value in the queue is: " << q.front() << std::endl;

    char output;
    std::cout << "Printing all values in the queue: " << std::endl;
    while(q.dequeue(output))
        std::cout << " " << output << std::endl;

    return 0;
}
