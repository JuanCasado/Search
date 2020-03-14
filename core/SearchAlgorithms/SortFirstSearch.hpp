
#pragma once
#include <utility>
#include "../SearchAlgorithm.hpp"

class SortFirstSearch : public SearchAlgorithm {
public:
  SortFirstSearch(SearchAlgorithm::Mode mode);
  std::vector<const Node*> search (const Node *from, const Node *to) const;
private:
  std::vector<const Node *> search (std::vector<std::pair<const Node *, std::vector<const Node *>>> open, const Node * target) const;
  std::vector<const Node *> search (std::vector<std::pair<const Node *, std::vector<const Node *>>> open, const Node * target, std::vector<const Node*> closed) const;
  SearchAlgorithm::Mode _mode;
};