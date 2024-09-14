//
// Created by andrey on 08.04.24.
//

#ifndef BASETOOLS_DIJKSTRA_H
#define BASETOOLS_DIJKSTRA_H
#include <cstdint>
#include <string>
#include <list>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "../../src/Node.h"

namespace Algorithmic {

    class Dijkstra {
    public:
        Dijkstra();
        explicit Dijkstra(std::unordered_map<std::string, Node> map);
        void append(const std::string &from, const std::string &to, uint32_t weight);
        std::list<Node *> findPath(const std::string &from, const std::string &to);
    private:

        std::unordered_map<std::string, Node> _map;
        std::list<Edge *> _result;
        std::unordered_set<std::string> _explored;
    };
}
#endif //BASETOOLS_DIJKSTRA_H
