#pragma once

#include "ISortAlgorithm.hpp"

class MergeSortAlgorithm : public ISortAlgorithm {
  public:
    void sort(/* container */) const override {
      std::cout << "MergeSort: container sorted" << std::endl;
    }
};
