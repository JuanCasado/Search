
#pragma once
#include "../core/Node.hpp"

class Node8 : public Node {
public:
  Node8(std::vector<std::string> state);
  ~Node8(){};
  std::vector<std::string> state() const;
  std::vector<const Node*> nextState() const;
  int getBlank ();
  static const int length = 9;
  static const int maxX = 3;
  static const int maxY = 3;
  inline static const std::string blank = "";
protected:
  int distance(const Node *node) const;
  std::stringstream str() const;
private:
  std::vector<std::string> _state;
  int blankIndex;
};

