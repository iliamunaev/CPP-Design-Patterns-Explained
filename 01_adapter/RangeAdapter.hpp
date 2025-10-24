// Author: Ilia Munaev (ilyamunaev@gmail.com)
#pragma once

#include "IFrequencyRange.hpp"
#include "Range.hpp"

#include <string>

class RangeAdapter : public IFrequencyRange, private Range {
  public:
    int adjustRange(int GHzToAdjust) override {
      std::string logMsg = "Some msg";
      return changeRange(GHzToAdjust, logMsg);
  }

  void getLastStatus() override {
    getStatus();
  }
};

