#include <memory>

#include "MergeSortAlgorithm.hpp"
#include "InsertSortAlgorithm.hpp"
#include "VectorSorter.hpp"
#include "ListSorter.hpp"

int main() {
  auto mergeAlgo = std::make_shared<MergeSortAlgorithm>();
  auto insertAlgo = std::make_shared<InsertSortAlgorithm>();

  {
    VectorSorter VectorSorterer(mergeAlgo);
    ListSorter listSorter(insertAlgo);

    VectorSorterer.process();
    listSorter.process();
  }
  std::cout << std::endl;
  {
    VectorSorter VectorSorterer(insertAlgo);
    ListSorter listSorter(mergeAlgo);

    VectorSorterer.process();
    listSorter.process();
  }

  return 0;
}
