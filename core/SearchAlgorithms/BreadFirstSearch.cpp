
#include <iostream>
#include "BreadFirstSearch.hpp"

BreadFirstSearch::BreadFirstSearch (SearchAlgorithm::Mode mode){
  this->_mode = mode;
}

std::vector<const Node*> BreadFirstSearch::search (const Node *from, const Node *to) const {
  std::vector<const Node*> path;
  std::vector<std::pair<const Node *, std::vector<const Node *>>> first = {{from, path}};
  switch (this->_mode){
    case BreadFirstSearch::Mode::OPEN:{
      return search (first, to);
    }
    case BreadFirstSearch::Mode::CLOSE:{
      std::vector<const Node *> closed;
      return search (first, to, closed);
    }
  }
}

std::vector<const Node*> BreadFirstSearch::search (std::vector<std::pair<const Node*, std::vector<const Node*>>> open, const Node *target) const {
  int size = open.size();
  if (size<1)
    return std::vector<const Node*>{};
  for (int i = 0; i < size; ++i){
    const Node *currentNode = open[i].first;
    std::vector<const Node*> currentPath = open[i].second;    
    currentPath.push_back(currentNode);
    if (!Node::Distance(currentNode, target))
      return currentPath;
    std::vector<const Node*> childs = currentNode->nextState();
    for (std::vector<const Node*>::iterator child = childs.begin(); child != childs.end(); ++child)
      open.push_back({*child, currentPath});
  }
  open.erase(open.begin(), open.begin()+size);
  return search(open, target);
}

std::vector<const Node*> BreadFirstSearch::search (std::vector<std::pair<const Node*, std::vector<const Node*>>> open, const Node *target, std::vector<const Node*> closed) const {
  int size = open.size();
  if (size<1)
    return std::vector<const Node*>{};
  for (int i = 0; i < size; ++i){
    const Node *currentNode = open[i].first;
    std::vector<const Node*> currentPath = open[i].second;
    currentPath.push_back(currentNode);
    closed.push_back(currentNode);
    if (!Node::Distance(currentNode, target))
      return currentPath;
    std::vector<const Node*> childs = currentNode->nextState();
    for (std::vector<const Node*>::iterator child = childs.begin(); child != childs.end(); ++child) {
      bool newState = true;
      for (std::vector<const Node*>::iterator visited = closed.begin(); (visited != closed.end())&&newState; ++visited)
        if ((*visited)->state() == (*child)->state())
          newState = false;
      if (newState)
        open.push_back({*child, currentPath});
    }
  }
  open.erase(open.begin(), open.begin()+size);  
  return search(open, target, closed);
}
