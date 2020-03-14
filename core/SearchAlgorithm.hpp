
#pragma once
#include "Node.hpp"

class SearchAlgorithm {
public:
  enum Mode {
    CLOSE,
    OPEN,
  };
  enum Type {
    BreadFirstSearch,
    DepthFirstSearch,
    SortFirstSearch
  };
  virtual std::vector<const Node*> search (const Node *from, const Node *to) const = 0;
};