// Author: Ilia Munaev (ilyamunaev@gmail.com)
#pragma once

#include <string>
#include <iostream>

// legacy, need to be adapted
class Range {
  public:
    int changeRange(int GHzToAdjust, std::string& logMsg) {
      int maxBand = 7125;
      // assume we store message in log
      std::string Msg = logMsg;
      return maxBand - GHzToAdjust;
    }

    void getStatus() {
      std::cout << "Ranges: loaded" << std::endl;
    }
};
