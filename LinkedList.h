#pragma once

#include "List.h"
#include "Node.h"
#include <iostream>
using namespace std;

// template <typename T> class LinkedList
// {
//   public:
// Node<T> *head;
// Node<T> *tail;
// int size;

// LinkedList(T *value)
// {
//     Node<T> *temp = new Node<T>(value);
//     head = temp;
//     tail = temp;
//     size = 1;
// }

// LinkedList() // overloading constructor
// {
//     head = nullptr;
//     tail = nullptr;
//     size = 0;
// }

// void print()
// {
//     Node<T> *temp1 = head;   // create a new pointer to traverse the list
//     while (temp1 != nullptr) // never move head pointer use temp1
//     {
//         temp1->print();      // passing the value of head to print function in node class
//         temp1 = temp1->next; // moving to the next node
//     }
// }

// void append(T *value)
// {
//     Node<T> *newNode = new Node<T>(value); // create a new node with the given value
//     if (head == nullptr)
//     { // if the list is empty, set the new node as the head
//         head = newNode;
//         tail = newNode;
//         size++;
//         return;
//     }
//     tail->next = newNode;
//     tail = newNode;
//     size++;
// }

template <typename T> class LinkedList : public List<T>
{
  public:
    LinkedList() : head_(nullptr) {}
    void addFront(T *value) override
    {
        Node<T> *fresh = new Node<T>(value);
        fresh->next = head_;
        head_ = fresh;
    }
    void deleteFront() override
    {
        if (head_ == nullptr)
        {
            std::cout << "LinkedList is empty." << std::endl;
            return;
        }
        Node<T> *doomed = head_;
        head_ = head_->next;
        delete doomed->data;
        delete doomed;
    }
    bool search(T *value) const override
    {
        Node<T> *current = head_;
        while (current != nullptr)
        {
            if (*current->data == *value)
                return true;
            current = current->next;
        }
        return false;
    }
    void print() const override
    {
        Node<T> *current = head_;
        while (current != nullptr)
        {
            std::cout << *current->data << ",";
            current = current->next;
        }
        std::cout << std::endl;
    }
    ~LinkedList() override
    {
        while (head_ != nullptr)
        {
            Node<T> *doomed = head_;
            head_ = head_->next;
            delete doomed->data;
            delete doomed;
        }
    }

  private:
    Node<T> *head_;
};