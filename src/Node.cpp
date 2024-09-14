//
// Created by andrey on 16.04.24.
//

#include "Node.h"
namespace Algorithmic {

    void Node::update(const Edge &other) {
        _totalCost = other._from->_totalCost + other._weight;
        _previous = other._from;
        _cost = other._weight;
    }

    void Edge::relaxation() {
        if (_from->_totalCost + _weight < _to->_totalCost)
            _to->update(*this);
    }
}