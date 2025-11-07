#pragma once

#include <iostream>

class ISortAlgorithm {
  public:
    virtual ~ISortAlgorithm() = default;
    virtual void sort(/* container */) const = 0;
};
