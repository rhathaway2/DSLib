#pragma one
#include <iostream>
#include "Node.hpp"

namespace DSLib {

    // LinkedList Class
    template <typename T>
    class LinkedList{
        private:
            Node<T>* head;
        public:
            LinkedList();
            void insert(T);
            bool remove(T);
            int size();
            void print();
    };
    
    
    template <typename T>
    LinkedList<T>::LinkedList(){
        this->head = nullptr;
    }
    
    template <typename T>
    void LinkedList<T>::insert(T newItem){
        if(this->head == nullptr || newItem < this->head->getData()){
            this->head = new Node<T>(newItem, this->head);
        }
        else{
            Node<T>* cur = this->head->getNext();
            Node<T>* trail = this->head;
    
            while(cur != nullptr && newItem >= cur->getData()){
                cur = cur->getNext();
                trail = trail->getNext();
            }
    
            Node<T>* newNode = new Node<T>(newItem, cur);
            trail->setNext(newNode);
        }
    }
    
    template <typename T>
    bool LinkedList<T>::remove(T target){
        if(this->head == nullptr)
            return false;
        else if(this->head->getData() == target){
            Node<T>* deletedNode = this->head;
            this->head = this->head->getNext();
            delete deletedNode;
            return true;
        }
        else{
            Node<T>* cur = this->head->getNext();
            Node<T>* trail = this->head;
    
            while(cur != nullptr && cur->getData() != target){
                cur = cur->getNext();
                trail = trail->getNext();
            }
    
            if(cur != nullptr){
                trail->setNext(cur->getNext());
                delete cur;
                return true;
            }
            return false;
        }
    }
    
    template <typename T>
    int LinkedList<T>::size(){
        int size = 0;
        Node<T>* cur = this->head;
        while(cur != nullptr){
            cur = cur->getNext();
            size += 1;
        }
        return size;
    }
    
    template <typename T>
    void LinkedList<T>::print(){
        Node<T>* cur = this->head;
        while(cur != nullptr){
            std::cout << cur->getData() << " ";
            cur = cur->getNext();
        }
        std::cout << std::endl;
    }

} // namespace DSLib
