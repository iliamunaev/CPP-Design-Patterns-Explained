#pragma once

#include <iostream>
#include "ISorter.hpp"

class ListSort : public ISorter {
  public:
    explicit ListSort(std::shared_ptr<ISortAlgorithm> algorithm)
        : ISorter(std::move(algorithm)) {}

    void process(/* unsorted container */) const override {
      std::cout << "ListSort abstraction using algorithm..." << std::endl;
      algorithm_->sort(/* unsorted container */);
    }
};
