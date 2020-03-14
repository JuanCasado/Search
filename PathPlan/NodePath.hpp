
#include "../core/Node.hpp"
#include "Map.hpp"

class NodePath : public Node{
public:
  NodePath(int x, int y, const Map *map);
  std::vector<std::string> state() const;
  std::vector<const Node*> nextState() const;
protected:
  int distance(const Node *node) const;
  std::stringstream str() const;
private:
  const Map *_map;
  int _x;
  int _y;
};