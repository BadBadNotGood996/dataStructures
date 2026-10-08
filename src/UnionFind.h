//
// Created by Vladislav Secrieru on 08/10/2026.
//

#ifndef DATASTRUCTURES_UNIONFIND_H
#define DATASTRUCTURES_UNIONFIND_H

#include <vector>

class UnionFind {
public:
    UnionFind (int size);

    ~UnionFind () = default;

    int find (int x);

    void unionSet (int x, int y);

    bool connected (int x, int y);

    void print() const;

private:
    std::vector<int> m_root;

    bool valid (int x) const;
};


#endif //DATASTRUCTURES_UNIONFIND_H
