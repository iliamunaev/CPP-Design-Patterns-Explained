#pragma once

#include <memory>
#include "ISortAlgorithm.hpp"

class ISorter {
  protected:
    std::shared_ptr<ISortAlgorithm> algorithm_;

  public:
    explicit ISorter(std::shared_ptr<ISortAlgorithm> algorithm)
        : algorithm_(std::move(algorithm)) {}

    virtual ~ISorter() = default;
    virtual void process(/* container */) const = 0;
};
