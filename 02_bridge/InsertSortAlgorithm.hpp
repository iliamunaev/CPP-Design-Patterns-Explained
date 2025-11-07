
#pragma once

#include "ISortAlgorithm.hpp"

class InsertSortAlgorithm : public ISortAlgorithm {
  public:
    void sort(/* container */) const override {
      std::cout << "InsertSort: container sorted" << std::endl;
    }
};


