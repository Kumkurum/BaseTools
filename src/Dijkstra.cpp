//
// Created by andrey on 09.04.24.
//
#include "../include/BaseTools/Dijkstra.h"
#include <queue>

namespace Algorithmic {

    Dijkstra::Dijkstra() {}

    Dijkstra::Dijkstra(std::unordered_map<std::string, Node> map):_map{map} {}

    void Dijkstra::append(const std::string &from, const std::string &to, uint32_t weight) {
        auto ptrFrom = _map.find(from);
        auto ptrTo = _map.find(to);
        if (ptrFrom == _map.end()) {
            _map.insert({from, {from}});
            ptrFrom = _map.find(from);
        }
        if (ptrTo == _map.end())
            _map.insert({to, {to}});
        ptrTo = _map.find(to);
        ptrFrom->second._ways.emplace_back(&ptrFrom->second, &ptrTo->second, weight);
    }

    std::list<Node *> Dijkstra::findPath(const std::string &from, const std::string &to) {
        std::queue<Node *> reachable;
        reachable.push(&_map[from]);
        _explored.clear();
        _explored.insert(reachable.front()->_name);

        auto currentNode = &_map[from];
        currentNode->_totalCost = 0;
        _explored.insert(currentNode->_name);

        while (!reachable.empty()) {

            currentNode = reachable.front();
            reachable.pop();

            for (auto &edge: currentNode->_ways) {
                if (_explored.contains(edge._to->_name)) {
                    //Релаксация точки
                    edge.relaxation();
                } else {
                    //Новая точка
                    reachable.push(edge._to);
                    edge._to->update(edge);
                    _explored.insert(edge._to->_name);
                }
            }
        }

        //Восстановление пути
        currentNode = &_map[to];
        std::list<Node *> result;
        result.push_back(currentNode);
        while (true) {
            currentNode = currentNode->_previous;
            result.push_back(currentNode);
            if (currentNode->_name == from)
                break;
        }
        return result;
    }

}
