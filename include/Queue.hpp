#pragma once
#include "Node.hpp"
#include <stdexcept>

namespace DSLib {

    class EmptyQueueException : public std::exception{
        const char * what() const throw(){
            return "Cannot return value from empty queue.";
        }
    };
    
    template <typename T>
    class Queue{
        private:
            Node<T>* m_front;
            Node<T>* m_back;
        public:
            Queue();
            void enqueue(T data);
            bool dequeue(T &data);
            T front();
            bool isEmpty();
    };

    template <typename T>
    Queue<T>::Queue(){
        this->m_front = nullptr;
        this->m_back = nullptr;
    }

    template <typename T>
    void Queue<T>::enqueue(T data){
        if(this->m_front == nullptr && this->m_back == nullptr){
            this->m_front = new Node<T>(data);
            this->m_back = this->m_front;
        }
        else{
            this->m_back->setNext(new Node<T>(data));
            this->m_back = this->m_back->getNext();
        }
    }

    template <typename T>
    bool Queue<T>::dequeue(T &value){
        if(this->isEmpty()) 
            return false;
        value = this->m_front->getData();
        Node<T>* toDelete = this->m_front;
        this->m_front = this->m_front->getNext();
        delete toDelete;
        return true;
    }

    template <typename T>
    T Queue<T>::front(){
        if(this->isEmpty())
            throw EmptyQueueException();
        return this->m_front->getData();
    }

    template <typename T>
    bool Queue<T>::isEmpty(){
        return this->m_front == nullptr;
    }

} // namespace DSLib
