//
// Created by Vladislav Secrieru on 08/10/2026.
//

#include "UnionFind.h"

UnionFind::UnionFind(int size) {
    m_root.resize(size);

    for (int i {}; i < size; ++i) {
        m_root[i] = -1;
    }
}

int UnionFind::find(int x) {
    if (!valid(x)) {
        std::cout << "invalid input " << x << std::endl;
        return -1;
    } else {
        if (m_root[x] < 0) {
            return x;
        }

        return m_root[x] = find(m_root[x]);
    }
}

void UnionFind::unionSet(int x, int y) {
    if (! valid(x) || ! valid(y)) {
        std::cout << "invalid input " << x << " " << y << std::endl;
    } else {
        int rootX = find(x);
        int rootY = find(y);

        int rankX = std::abs(m_root[rootX]);
        int rankY = std::abs(m_root[rootY]);

        if (rootX != rootY) {
            if (rankX > rankY) {
                m_root[rootY] = rootX;
                m_root[rootX] -= rankY;
            } else if (rankX < rankY) {
                m_root[rootX] = rootY;
                m_root[rootY] -= rankX;
            } else {
                m_root[rootY] = rootX;
                m_root[rootX] -= 1;
            }
        }
    }
}

bool UnionFind::connected(int x, int y) {
    if (! valid(x) || ! valid(y)) {
        std::cout << "invalid input " << x << " " << y << std::endl;
    } else {
        return find(x) == find(y);
    }
}

void UnionFind::print() const {
    for (int i {}; i < m_root.size(); ++i) {
        std::cout << m_root[i] << " ";
    }
    std::cout << std::endl;
}

bool UnionFind::valid(int x) const  {
    return x >= 0 && x < m_root.size();
}