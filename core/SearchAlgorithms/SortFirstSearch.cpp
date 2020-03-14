
#include <iostream>
#include "SortFirstSearch.hpp"

SortFirstSearch::SortFirstSearch (SearchAlgorithm::Mode mode){
  this->_mode = mode;
}

std::vector<const Node*> SortFirstSearch::search (const Node *from, const Node *to) const {
  std::vector<const Node*> path;
  std::vector<std::pair<const Node*, std::vector<const Node*>>> first = {{from, path}};
  switch (this->_mode){
    case SortFirstSearch::Mode::OPEN:{
      return search (first, to);
    }
    case SortFirstSearch::Mode::CLOSE:{
      std::vector<const Node*> closed;
      return search (first, to, closed);
    }
  }
}

std::vector<const Node*> SortFirstSearch::search (std::vector<std::pair<const Node*, std::vector<const Node*>>> open, const Node *target)const  {
  if (open.size()<1)
    return std::vector<const Node*>{};
  int bestDistance = Node::Distance(open[0].first, target);
  int best = 0;
  for (int i = 0; i < open.size(); ++i) {
    const int newDistance = Node::Distance(open[i].first, target);
    if (newDistance < bestDistance){
      bestDistance = newDistance;
      best = i;
    }
  }
  const Node *currentNode = open[best].first;
  std::vector<const Node*> currentPath = open[best].second;
  open.erase(open.begin()+best);
  currentPath.push_back(currentNode);
  if (!Node::Distance(currentNode, target))
    return currentPath;
  std::vector<const Node*> childs = currentNode->nextState();
  for (std::vector<const Node*>::iterator child = childs.begin(); child != childs.end(); ++child)
    open.push_back({*child, currentPath});
  return search(open, target);
}

std::vector<const Node*> SortFirstSearch::search (std::vector<std::pair<const Node*, std::vector<const Node*>>> open, const Node *target, std::vector<const Node*> closed) const {
  if (open.size()<1)
    return std::vector<const Node*>{};
  int bestDistance = Node::Distance(open[0].first, target);
  int best = 0;
  for (int i = 0; i < open.size(); ++i) {
    const int newDistance = Node::Distance(open[i].first, target);
    if (newDistance < bestDistance){
      bestDistance = newDistance;
      best = i;
    }
  }
  const Node *currentNode = open[best].first;
  std::vector<const Node*> currentPath = open[best].second;
  open.erase(open.begin()+best);
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
  return search(open, target, closed);
}
