
#pragma once
#include "SearchAlgorithm.hpp"
#include "SearchAlgorithms/BreadFirstSearch.hpp"
#include "SearchAlgorithms/DepthFirstSearch.hpp"
#include "SearchAlgorithms/SortFirstSearch.hpp"

SearchAlgorithm *creteSearch (SearchAlgorithm::Type type, SearchAlgorithm::Mode mode);