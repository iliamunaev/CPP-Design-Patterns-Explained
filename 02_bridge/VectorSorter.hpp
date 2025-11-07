
#pragma once

#include <iostream>
#include "ISorter.hpp"

class VectorSorter : public ISorter {
  public:
    explicit VectorSorter(std::shared_ptr<ISortAlgorithm> algorithm)
        : ISorter(std::move(algorithm)) {}

    void process(/* unsorted container */) const override {
      std::cout << "VectorSorter abstraction using algorithm..." << std::endl;
      algorithm_->sort(/* unsorted container */);
    }
};
