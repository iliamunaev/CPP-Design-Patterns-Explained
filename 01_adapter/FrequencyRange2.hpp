// Author: Ilia Munaev (ilyamunaev@gmail.com)
#pragma once

#include <string>
#include <iostream>

#include "IFrequencyRange.hpp"

class FrequencyRange2 : public IFrequencyRange {
  public:
    int adjustRange(int GHzToAdjust) override {
      int maxBand = 71;
      return maxBand - GHzToAdjust;
    }

    void getLastStatus() override {
      std::cout << "FR2 is loaded" << std::endl;
    }
};
