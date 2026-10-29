//
// Created by Vladislav Secrieru on 08/10/2026.
//

#ifndef DATASTRUCTURES_CIRCULARQUEUE_H
#define DATASTRUCTURES_CIRCULARQUEUE_H

#include <iostream>
#include <vector>

class CircularQueue {
public:
    CircularQueue(int k) {
        m_size = k + 1;
        m_queue.resize(m_size);
        m_hPtr = 1;
        m_tPtr = 0;
    }

    bool enQueue(int value) {
        if (!isFull()) {
            m_tPtr = (m_tPtr + 1) % m_size;
            m_queue[m_tPtr] = value;

            return true;
        } else {
            return false;
        }
    }

    bool deQueue() {
        if (!isEmpty()) {
            m_hPtr = (m_hPtr + 1) % m_size;

            return true;
        } else {
            return false;
        }
    }

    int Front() {
        if (!isEmpty()) return m_queue[m_hPtr];
        else return -1;
    }

    int Rear() {
        if (!isEmpty()) {
            return m_queue[m_tPtr];
        }
        else return -1;
    }

    bool isEmpty() {
        return length() == 0;
    }

    bool isFull() {
        return !(((m_tPtr + 2) % m_size )!= m_hPtr);
    }

    void print() const {
        for (const int& el : m_queue) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }

private:
    std::vector<int> m_queue;
    int m_size;
    int m_hPtr;
    int m_tPtr;

    int length() const {
        return ((m_tPtr + m_size) - m_hPtr + 1) % m_size;
    }

    void clear() {
        m_hPtr = 0;
        m_tPtr = 1;
    }
};


#endif //DATASTRUCTURES_CIRCULARQUEUE_H
