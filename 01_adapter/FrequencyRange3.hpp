// Author: Ilia Munaev (ilyamunaev@gmail.com)
#pragma once

#include <string>
#include <iostream>

#include "IFrequencyRange.hpp"

class FrequencyRange3 : public IFrequencyRange {
  public:
    int adjustRange(int GHzToAdjust) override {
      int maxBand = 24;
      return maxBand - GHzToAdjust;
    }

    void getLastStatus() override {
      std::cout << "FR3 is loaded" << std::endl;
    }
};
