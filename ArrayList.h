#pragma once

#include "List.h"
#include <iostream>

using namespace std;

template <typename T> class ArrayList : public List<T>
{
  public:
    ArrayList() : size_(0) {}

    // void add(T item) // adds to the front of the array
    // {
    //     if (size >= CAPACITY)
    //     {
    //         cout << "Array is full" << endl;
    //         return;
    //     }

    //     for (int i = size; i > 0; i--)
    //     {
    //         data[i] = data[i - 1];
    //     }
    //     data[0] = item;
    //     size++;
    // }
    // void deletefront()
    // {
    //     if (size == 0)
    //     {
    //         cout << "Array is empty" << endl;
    //         return;
    //     }
    //     for (int i = 0; i < size; i++)
    //     {
    //         data[i] = data[i + 1];
    //     }
    //     size--;
    // }

    // bool search(T item)
    // {
    //     if (size == 0)
    //     {
    //         cout << "Array is empty" << endl;
    //         return false;
    //     }
    //     for (int i = 0; i < size; i++)
    //     {
    //         if (data[i] == item)
    //             return true;
    //     }
    //     return false;
    // }

    // void printArray()
    // {
    //     for (int i = 0; i < size; i++)
    //     {
    //         cout << data[i] << ",";
    //     }
    //     cont::endl;
    // }

    // void adbaback(T item) // adds back to the back of array
    // {
    //     if (size >= CAPACITY)
    //     {
    //         cout << "Array is full" << endl;
    //         return;
    //     }

    //     data[size] = item;
    //     size++;
    // }

    // void deleteback()
    // {
    //     if (size == 0)
    //     {
    //         cout << "Array is empty" << endl;
    //         return;
    //     }
    //     size--;
    // }

    void addFront(T *value) override
    {
        if (size_ >= CAPACITY)
        {
            cout << "Array is full" << endl;
            return;
        }

        for (int i = size_; i > 0; i--)
        {
            data_[i] = data_[i - 1];
        }
        data_[0] = value;
        ++size_;
    }

    void deleteFront() override
    {
        if (size_ == 0)
        {
            cout << "Array is empty" << endl;
            return;
        }
        delete data_[0];
        for (int i = 0; i < size_ - 1; i++)
        {
            data_[i] = data_[i + 1];
        }
        --size_;
    }

    bool search(T *value) const override
    {
        for (int i = 0; i < size_; ++i)
        {
            if (*data_[i] == *value)
            {
                return true;
            }
        }
        return false;
    }

    void print() const override
    {
        for (int i = 0; i < size_; ++i)
        {
            cout << *data_[i] << ",";
        }
        cout << endl;
    }

    ~ArrayList() override
    {
        for (int i = 0; i < size_; ++i)
        {
            delete data_[i];
        }
    }

  private:
    static const int CAPACITY = 20;
    T *data_[CAPACITY];
    int size_;
};