
#include <iostream>
#include "DepthFirstSearch.hpp"

DepthFirstSearch::DepthFirstSearch (SearchAlgorithm::Mode mode){
  this->_mode = mode;
}

std::vector<const Node*> DepthFirstSearch::search (const Node *from, const Node *to) const {
  std::vector<const Node*> path;
  std::vector<std::pair<const Node*, std::vector<const Node*>>> first = {{from, path}};
  switch (this->_mode){
    case DepthFirstSearch::Mode::OPEN:{
      return search (first, to);
    }
    case DepthFirstSearch::Mode::CLOSE:{
      std::vector<const Node*> closed;
      return search (first, to, closed);
    }
  }
}

std::vector<const Node*> DepthFirstSearch::search (std::vector<std::pair<const Node*, std::vector<const Node*>>> open, const Node *target) const {
  if (open.size()<1){
    return std::vector<const Node*>{};
  }
  const Node *currentNode = open[0].first;
  std::vector<const Node*> currentPath = open[0].second;
  open.erase(open.begin());
  currentPath.push_back(currentNode);
  if (!Node::Distance(currentNode, target))
    return currentPath;
  std::vector<const Node*> childs = currentNode->nextState();
  for (std::vector<const Node*>::iterator child = childs.begin(); child != childs.end(); ++child)
    open.insert(open.begin(),{*child, currentPath});
  return search(open, target);
}

std::vector<const Node*> DepthFirstSearch::search (std::vector<std::pair<const Node*, std::vector<const Node*>>> open, const Node *target, std::vector<const Node*> closed) const {
  if (open.size()<1)
    return std::vector<const Node*>{};
  const Node *currentNode = open[0].first;
  std::vector<const Node*> currentPath = open[0].second;
  open.erase(open.begin());
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
      open.insert(open.begin(),{*child, currentPath});
  }
  return search(open, target, closed);
}
