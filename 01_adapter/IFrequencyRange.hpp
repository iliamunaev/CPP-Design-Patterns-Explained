// Author: Ilia Munaev (ilyamunaev@gmail.com)
#pragma once

#include <string>

class IFrequencyRange {
  public:
    virtual ~IFrequencyRange() = default;

    virtual int adjustRange(int diff) = 0;
    virtual void getLastStatus() = 0;
};
