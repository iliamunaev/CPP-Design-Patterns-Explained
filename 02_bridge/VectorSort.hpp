
#pragma once

#include <iostream>
#include "ISorter.hpp"

class VectorSort : public ISorter {
  public:
    explicit VectorSort(std::shared_ptr<ISortAlgorithm> algorithm)
        : ISorter(std::move(algorithm)) {}

    void process(/* unsorted container */) const override {
      std::cout << "VectorSort abstraction using algorithm..." << std::endl;
      algorithm_->sort(/* unsorted container */);
    }
};
