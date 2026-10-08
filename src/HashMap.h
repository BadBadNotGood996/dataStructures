//
// Created by Vladislav Secrieru on 08/10/2026.
//


#ifndef DATASTRUCTURES_HASHMAP_H
#define DATASTRUCTURES_HASHMAP_H

#include <iostream>
#include <vector>
#include <utility>
#include <string>

class HashMap {
public:
    HashMap();

    ~HashMap() = default;

    void insert(int key, std::string value);

    void print() const;

private:
    std::vector<std::pair<int, std::string>> m_list;
    int m_size { 4 };
    int m_currSize { 0 };

    bool empty(int idx) const;

    int hashFunc(int key);

    int getSize() const;
};


#endif //DATASTRUCTURES_HASHMAP_H
