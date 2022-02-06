#pragma once
#include "Node.hpp"

namespace DSLib {

    template <typename T>
    class Stack{
        private:
            Node<T> *m_top;
        public:
            Stack();
            void push(T value);
            bool pop(T &val);
            T top();
            int size();
            bool isEmpty();
    };

    template <typename T>
    Stack<T>::Stack(){
        this->m_top = nullptr;
    }

    template <typename T>
    void Stack<T>::push(T value){
        if(this->isEmpty())
            this->m_top = new Node<T>(value);
        else
            this->m_top = new Node<T>(value, this->m_top);
    }

    template <typename T>
    bool Stack<T>::pop(T &value){
        if(this->isEmpty())
            return false;
        Node<T>* curr_top = this->m_top;
        value = curr_top->getData();
        this->m_top = this->m_top->getNext();
        delete curr_top;
        return true;
    }

    template <typename T>
    T Stack<T>::top(){
        if(this->isEmpty())
            return nullptr;
        return this->m_top->getData();
    }

    template <typename T>
    int Stack<T>::size(){
        int size = 0;
        Node<T>* curr = this->m_top;
        while(curr != nullptr){
            curr = curr->getNext();
            size++;
        }
        return size;
    }

    template <typename T>
    bool Stack<T>::isEmpty(){
        return this->m_top == nullptr;
    }

} // namespace DSLib
