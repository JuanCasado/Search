
#pragma once

#include <vector>
#include <string>
#include <sstream>

class Node {
public:
  virtual ~Node(){};
  virtual std::vector<std::string> state() const = 0;
  virtual std::vector<const Node*> nextState() const = 0;
  static int Distance(const Node *node1, const Node *node2) {
    return node1->distance(node2);
  }
  static std::string print(const Node *node, const std::string separator = "") {
    std::stringstream ss;
    ss << separator << "{\n";
    std::stringstream ssNode = node->str();
    std::string line;
    while (std::getline(ssNode, line, '\n')) {
      ss << separator << "\t" << line << "\n";
    }
    ss << separator << "}\n";
    return ss.str();
  } 
  static std::string print(std::vector<const Node*> nodes) {
    std::stringstream ss;
    ss << "[\n";
    for (std::vector<const Node*>::iterator i = nodes.begin(); i != nodes.end(); ++i)
      ss << Node::print(*i, "\t");
    ss << "]" << std::endl;
    return ss.str();
  }
protected:
  virtual int distance(const Node *node) const = 0;
  virtual std::stringstream str() const = 0;
};
