
#include "NodePath.hpp"

NodePath::NodePath(int x, int y, const Map *map){
  this->_map = map;
  this->_x = x;
  this->_y = y;
}

std::vector<std::string> NodePath::state() const{
  return {std::to_string(this->_x), std::to_string(this->_y)};
}

std::vector<const Node*> NodePath::nextState() const{
  std::vector<const Node*> newState;
  if (this->_x > 0){
    newState.push_back(new NodePath(this->_x-1, this->_y, this->_map));
  }
  if (this->_y > 0){
    newState.push_back(new NodePath(this->_x, this->_y-1, this->_map));
  }
  if (this->_x < this->_map->maxX()-1){
    newState.push_back(new NodePath(this->_x+1, this->_y, this->_map));
  }
  if (this->_y < this->_map->maxY()-1){
    newState.push_back(new NodePath(this->_x, this->_y+1, this->_map));
  }
  return newState;
}

int NodePath::distance(const Node *node) const{
  const std::vector<std::string> otherState = node->state();
  const int otherX = std::stoi(otherState[0]);
  const int otherY = std::stoi(otherState[1]);
  return abs(this->_x-otherX) + abs(this->_y-otherY);
}

std::stringstream NodePath::str() const{
  std::stringstream ss;
  ss << "x: " << this->state()[0] << "\n";
  ss << "y: " << this->state()[1] << "\n";
  return ss;
}
