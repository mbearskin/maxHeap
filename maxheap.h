//Martha Winger- Bearskin
//Homework # 8
//maxHeap.h


#ifndef MAXHEAP_H
#define MAXHEAP_H

#include "AbstractHeap.h"
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class maxHeap: public AbstractHeap<T>
{
private:
    T *m_data;
    int m_max;
    int m_size;
    
public:
    
    // default constructor
    maxHeap(): m_max(4), m_size(0)
    {
        m_data = new T[4];
    }
    // destructor
    ~maxHeap()
    {
        delete [] m_data;
    }
    //copy constructor
    maxHeap(const maxHeap<T> &rhs) : m_max(4), m_size(0)
    {
        // do the same as the default constructor
        m_data = new T[4];
        *this = rhs;
    }
    //operator =
    const maxHeap & operator= (const maxHeap & rhs);
    
    bool isEmpty() const;
    int size() const;
    const T& top() const;
    void print() const;
    void insert(const T& x);
    void clear();
    void remove();
    void prettyPrint (int ix, int pad)const;


};

#include "maxheap.hpp"
#endif
