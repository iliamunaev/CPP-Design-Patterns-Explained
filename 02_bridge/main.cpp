#include <memory>

#include "MergeSortAlgorithm.hpp"
#include "InsertSortAlgorithm.hpp"
#include "VectorSort.hpp"
#include "ListSort.hpp"

int main() {
  auto mergeAlgo = std::make_shared<MergeSortAlgorithm>();
  auto insertAlgo = std::make_shared<InsertSortAlgorithm>();

  {
    VectorSort vectorSorter(mergeAlgo);
    ListSort listSorter(insertAlgo);

    vectorSorter.process();
    listSorter.process();
  }
  std::cout << std::endl;
  {
    VectorSort vectorSorter(insertAlgo);
    ListSort listSorter(mergeAlgo);

    vectorSorter.process();
    listSorter.process();
  }

  return 0;
}
