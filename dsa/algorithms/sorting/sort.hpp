#ifndef PROJECT_SORT_HPP
#define PROJECT_SORT_HPP

#include <vector>
#include <concepts>
#include "../../utils/utils.hpp"

namespace cra {

// Insertion Sort -------------------------------------------------------------------- [O(n^2)]
template <typename T>
requires std::copyable<T> && std::three_way_comparable<T>
void isort(std::vector<T> &vec, const int order = utils::AscendingOrder);

// Selection Sort -------------------------------------------------------------------- [O(n^2)]
template <typename T>
requires std::copyable<T> && std::three_way_comparable<T>
void ssort(std::vector<T> &vec, const int order = utils::AscendingOrder);

// Merge Sort ------------------------------------------------------------------------ [O(nlogn)]

// Bubble Sort ----------------------------------------------------------------------- [O(n^2)]

// Heap Sort ------------------------------------------------------------------------- [O()]

// Quick Sort ------------------------------------------------------------------------ [O()]

// Counting Sort --------------------------------------------------------------------- [O()]

// Radix Sort ------------------------------------------------------------------------ [O()]

// Bucket Sort ----------------------------------------------------------------------- [O()]

}   // cra namespace (c. roman algorithms [library])

#include "sort.tpp"

#endif  // PROJECT_SORT_HPP