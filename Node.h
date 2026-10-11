#pragma once
#include <iostream>
using namespace std;

// template <typename T> class Node
// {
//   public:
//     T data;
//     Node<T> *next;

//     Node(T *value)
//     {
//         this->value = value;
//         next = nullptr;
//     }

//     void print() { cout << value << endl; }
// };

template <typename T> class Node
{
  public:
    T *data;
    Node<T> *next;

    explicit Node(T *value) : data(value), next(nullptr) {}
};