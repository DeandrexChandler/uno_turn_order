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
    LinkedList() : head_(nullptr), size_(0) {}
    void addFront(T *value) override
    {
        Node<T> *fresh = new Node<T>(value);
        fresh->next = head_;
        head_ = fresh;
        ++size_;
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
        --size_;
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

    void addAnywhere(int position, T *value) override
    {
        if (position < 0 || position > size_)
        {
            cout << "Outside of range" << endl;
            return;
        }

        if (position == 0)
        {
            addFront(value);
            return;
        }

        Node<T> *prev_ = head_;
        for (int i = 0; i < position - 1; i++)
            prev_ = prev_->next;

        Node<T> *fresh = new Node<T>(value);
        fresh->next = prev_->next;
        prev_->next = fresh;
        ++size_;
    }

    void deleteAnywhere(int position) override
    {
        if (position < 0 || position >= size_)
        {
            cout << "Outside of range" << endl;
            return;
        }

        if (size_ == 0)
        {
            cout << "Array is empty" << endl;
            return;
        }

        if (position == 0)
        {
            deleteFront();
            return;
        }

        Node<T> *prev = head_;
        for (int i = 0; i < position - 1; i++)
            prev = prev->next;

        Node<T> *doomed = prev->next;
        prev->next = doomed->next;
        delete doomed->data;
        delete doomed;
        --size_;
    }

    void reverse() override {}
    void concat(List<T> *other) override {}

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
    int size_;
};