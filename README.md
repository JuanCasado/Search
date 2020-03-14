---
title: Search
author: Juan Casado Ballesteros
date: March 3, 2020
---

Small cpp library to solve basic search problems.

## New Problem definition

To define a new problem just public inherit from core/Node.
The requirements for a node are:

* To express its content in the form of an std::vector<std::string>
* To be able to know the children that will be hanging from it in the search tree.
* Tho be able to know the distance from itself to any other node of its kind.

## Core

Few and simple search algorithms have been implemented.

* SearchAlgorithm::Type::BreadFirstSearch
* SearchAlgorithm::Type::DepthFirstSearch
* SearchAlgorithm::Type::SortFirstSearch
  
Each algorithms has been implemented with and without an OPEN list.
If the OPEN list is used nodes will be explored just once.

## Usage example

CustomNode refers to a class that public inherit from core/Node.

```cpp

#include "CustomNode.hpp"
#include "../core/SearchFactory.hpp"
...

int main (int argc, char **argv) {
  
  ...

  const CustomNode *initNode = new CustomNode{...};
  const CustomNode *finalNode = new CustomNode{...};
  
  std::cout << "From: " << Node::print(initNode);
  std::cout << "To: " << Node::print(finalNode);
  std::cout << "Distance: " << Node::Distance(initNode, finalNode) << std::endl;

  SearchAlgorithm *searcher = creteSearch(SearchAlgorithm::Type::SortFirstSearch, SearchAlgorithm::Mode::CLOSE);
  const std::vector<Node*> result = searcher->search(initNode, finalNode);
  std::cout << "Path: " << Node::print(result);
  std::cout << "Steps: " << result.size()-1 << std::endl;
}

```

## Compile examples

Tho examples are proved with the library:

### Game8

[Puzzle8](https://blog.goodaudience.com/solving-8-puzzle-using-a-algorithm-7b509c331288) game.

```bash
make Game8
./Game8.app
```

### PathPlan

Path finder over a discrete map.

```bash
make PathPlan
./Game8.app
```
