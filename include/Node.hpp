#pragma once

namespace DSLib {

    // Generic Node class
    template <typename T>
    class Node{
        private:
            T data;
            Node* next;
        public:
            Node(T data);
            Node(T data, Node<T>* next);
            T getData();
            void setData(T data);
            Node<T>* getNext();
            void setNext(Node<T>* next);
    };
    
    template <typename T>
    Node<T>::Node(T data){
        this->data = data;
        this->next = nullptr;
    }
    
    template <typename T>
    Node<T>::Node(T data, Node<T>* next){
        this->data = data;
        this->next = next;
    }
    
    template <typename T>
    T Node<T>::getData(){
        return this->data;
    }
    
    template <typename T>
    void Node<T>::setData(T data){
        this->data = data;
    }
    
    template <typename T>
    Node<T>* Node<T>::getNext(){
        return this->next;
    }
    
    template <typename T>
    void Node<T>::setNext(Node<T>* next){
        this->next = next;
    }

} // namespace DSLib
