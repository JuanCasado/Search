
#include "Map.hpp"

Map::Map(std::vector<std::vector<std::string>> map) {
  this->_map = map;
}

bool Map::isEmpty (int x, int y) const{
  return this->_map[x][y]==Map::empty;
}

int Map::maxX() const{
  return this->_map.size();
}

int Map::maxY() const{
  return this->_map[0].size();
}
