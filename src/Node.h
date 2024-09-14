//
// Created by andrey on 16.04.24.
//

#ifndef BASETOOLS_NODE_H
#define BASETOOLS_NODE_H

#include <string>
#include <cstdint>
#include <vector>
#if __cplusplus == 202002L
//Так можно писать код под новые и старые стандарты! класс
// типо через дерективу using
#endif
namespace Algorithmic {
struct Edge;
struct Node;
    struct Node {
        std::string _name;
        std::vector<Edge> _ways;
        Node *_previous{nullptr};
        uint32_t _totalCost{1'000'000};
        uint32_t _cost{};

        void update(const Edge &other);
    };

    struct Edge {
        Edge(Node *from, Node *to, uint32_t weight) : _from{from}, _to{to}, _weight{weight} {};
        Node *_from;
        Node *_to;
        uint32_t _weight;

        void relaxation();
    };
}

#endif //BASETOOLS_NODE_H
