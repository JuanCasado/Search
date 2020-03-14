
#include <iostream>
#include "NodePath.hpp"
#include "../core/SearchFactory.hpp"

int main (int argc, char **argv) {
  const Map *map = new Map{{
    {"","","","","",""},
    {"","x","x","x","x",""},
    {"","x","x","x","x",""},
    {"","x","x","x","x",""},
    {"","x","x","x","x","x"},
    {"","","","","",""},
  }};
  const NodePath *initNode = new NodePath{0, 0, map};
  const NodePath *finalNode = new NodePath{5, 5, map};
  
  std::cout << "From: " << Node::print(initNode) << std::endl;
  std::cout << "To: " << Node::print(finalNode) << std::endl;
  std::cout << "Distance: " << Node::Distance(initNode, finalNode) << std::endl;

  SearchAlgorithm *searcher = creteSearch(SearchAlgorithm::Type::SortFirstSearch, SearchAlgorithm::Mode::CLOSE);
  const std::vector<const Node*> result = searcher->search(initNode, finalNode);
  std::cout << "Path: " << Node::print(result) << std::endl;
  std::cout << "Steps: " << result.size()-1 << std::endl;
}

