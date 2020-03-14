
#include <iostream>
#include "Node8.hpp"
#include "../core/SearchFactory.hpp"

int main (int argc, char **argv) {
  const Node8 *initNode = new Node8{{"7","2","4","5",Node8::blank,"6","8","3","1"}};
  const Node8 *finalNode = new Node8{{Node8::blank,"1","2","3","4","7","5","6","8"}};
  
  std::cout << "From: " << Node::print(initNode) << std::endl;
  std::cout << "To: " << Node::print(finalNode) << std::endl;
  std::cout << "Distance: " << Node::Distance(initNode, finalNode) << std::endl;

  SearchAlgorithm *searcher = creteSearch(SearchAlgorithm::Type::SortFirstSearch, SearchAlgorithm::Mode::CLOSE);
  const std::vector<const Node*> result = searcher->search(initNode, finalNode);
  std::cout << "Path: " << Node::print(result) << std::endl;
  std::cout << "Steps: " << result.size()-1 << std::endl << std::endl;
}

