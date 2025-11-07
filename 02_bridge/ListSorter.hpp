#pragma once

#include <iostream>
#include "ISorter.hpp"

class ListSorter : public ISorter {
  public:
    explicit ListSorter(std::shared_ptr<ISortAlgorithm> algorithm)
        : ISorter(std::move(algorithm)) {}

    void process(/* unsorted container */) const override {
      std::cout << "ListSorter abstraction using algorithm..." << std::endl;
      algorithm_->sort(/* unsorted container */);
    }
};
