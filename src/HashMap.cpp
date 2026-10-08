//
// Created by Vladislav Secrieru on 08/10/2026.
//

#include "HashMap.h"

HashMap::HashMap() {
    for (int i = 0; i < getSize(); ++i ) {
        std::pair<int, std::string> el = {0, ""};
        m_list.push_back(el);
    }
}

void HashMap::insert(int key, std::string value) {
    int idx = hashFunc(key);
    if (idx != -1) {
        std::pair<int, std::string> el = {key, value};
        m_list[idx] = el;
        m_currSize++;
    } else {
        std::cout << "map full" << std::endl;
    }
}

void HashMap::print() const {
    for (int i = 0; i < getSize(); ++i ) {
        std::cout << m_list[i].first << ", " << m_list[i].second << std::endl;
    }
}

bool HashMap::empty(int idx) const {
    if (m_list[idx].first == 0) return true;
    return false;
}

int HashMap::hashFunc(int key) {
    int idx = key % getSize();
    if (empty(idx)) {
        return idx;
    } else {
        for (int i = 1; i < m_size; ++i) {
            if (empty(idx + i)) return idx + i;
        }

        return -1;
    }
}

int HashMap::getSize() const {
    return m_size;
}
