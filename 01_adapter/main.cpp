// Author: Ilia Munaev (ilyamunaev@gmail.com)
#include <memory>
#include <string>
#include <iostream>
#include <format>

#include "IFrequencyRange.hpp"
#include "FrequencyRange2.hpp"
#include "FrequencyRange3.hpp"
#include "RangeAdapter.hpp"

int main() {
  const std::unique_ptr<IFrequencyRange> frequencyRanges[] {
    std::make_unique<FrequencyRange2>(),
    std::make_unique<FrequencyRange3>(),
    std::make_unique<RangeAdapter>()
  };

  for (const auto &range : frequencyRanges) {
      std::cout << std::format("Adjusted to -> {}\n", range->adjustRange(15));
      range->getLastStatus();
  }
}


