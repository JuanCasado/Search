
#include "Node8.hpp"

Node8::Node8 (std::vector<std::string> state) {
  this->_state = state;
  for (std::vector<std::string>::iterator i = this->_state.begin(); i != this->_state.end(); ++i)
    if (*i == Node8::blank)
      this->blankIndex = i - this->_state.begin();
}

int Node8::getBlank () {
  return this->blankIndex;
}

std::vector<std::string> Node8::state() const {
  return this->_state;
}

std::vector<std::string> swap(const std::vector<std::string> &state, int from, int to) {
  std::vector<std::string> newState;
  for (int i = 0; i < state.size(); ++i)
    newState.push_back(state[i]);
  newState[to] = newState[from];
  newState[from] = Node8::blank;
  return newState;
}

std::vector<const Node*> Node8::nextState() const {
  const int blankX = this->blankIndex%3;
  const int blankY = this->blankIndex/3;
  std::vector<const Node*> nextStates;
  if (blankX > 0)
    nextStates.push_back(new Node8{swap(this->_state, this->blankIndex-1, this->blankIndex)});
  if (blankX < Node8::maxX-1)
    nextStates.push_back(new Node8{swap(this->_state, this->blankIndex+1, this->blankIndex)});
  if (blankY > 0)
    nextStates.push_back(new Node8{swap(this->_state, this->blankIndex-Node8::maxX, this->blankIndex)});
  if (blankY < Node8::maxY-1)
    nextStates.push_back(new Node8{swap(this->_state, this->blankIndex+Node8::maxX, this->blankIndex)});
  return nextStates;
}

int Node8::distance(const Node *other) const {
  int acc = 0;
  for (int i = 0; i < Node8::length; ++i)
    if (this->state()[i] != other->state()[i])
      ++acc;
  return acc;
}

std::stringstream Node8::str() const {
  std::stringstream ss;
  for (int i = 0; i < Node8::length; ++i) {
    if (this->state()[i] == Node8::blank)
      ss << "_" << ",";
    else
      ss << this->state()[i] << ",";
    if (!((i+1)%Node8::maxX))
      ss << "\n";
  }
  return ss;
}

