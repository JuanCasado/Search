
#include "SearchFactory.hpp"

SearchAlgorithm *creteSearch (SearchAlgorithm::Type type, SearchAlgorithm::Mode mode){
  switch (type){
    case SearchAlgorithm::Type::BreadFirstSearch:
      return new BreadFirstSearch(mode);
    case SearchAlgorithm::Type::DepthFirstSearch:
      return new DepthFirstSearch(mode);
    case SearchAlgorithm::Type::SortFirstSearch:
      return new SortFirstSearch(mode);
  }
}