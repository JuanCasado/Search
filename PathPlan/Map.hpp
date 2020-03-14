
#include <vector>
#include <string>

class Map {
public:
  Map (std::vector<std::vector<std::string>> map);
  bool isEmpty (int x, int y) const;
  static inline const std::string empty = "";
  int maxX () const;
  int maxY () const;
private:
  std::vector<std::vector<std::string>> _map;
};