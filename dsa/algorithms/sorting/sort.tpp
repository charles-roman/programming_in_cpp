#include <vector>
#include <concepts>
#include "../../utils/utils.hpp"

namespace cra {

// should T requirements be std::integral<T> || std::floating_point<T> ? what custom objects would be sorted ?
// does three_way_comparable<T> behave as expected ?

// Insertion Sort --------------------------------------------------------------------
template <typename T>
requires std::copyable<T> && std::three_way_comparable<T>
void isort(std::vector<T> &vec, const int order = utils::AscendingOrder) {
    if (order == utils::AscendingOrder) {
        for (int i{1}; i < vec.size(); ++i) {
            auto key = vec[i];
            int j = i - 1;
            while ((j >= 0) && (vec[j] > key)) {
                vec[j + 1] = vec[j];
                --j;
            }
            vec[j + 1] = key;
        }
    } else if (order == utils::DescendingOrder) {
        for (int i{1}; i < vec.size(); ++i) {
            auto key = vec[i];
            int j = i - 1;
            while ((j >= 0) && (vec[j] < key)) {
                vec[j + 1] = vec[j];
                --j;
            }
            vec[j + 1] = key;
        }
    }
}

// Selection Sort --------------------------------------------------------------------
template <typename T>
requires std::copyable<T> && std::three_way_comparable<T>
void ssort(std::vector<T> &vec, const int order = utils::AscendingOrder) {
    if (is_sorted(vec, order))
        return;

    if (order == utils::AscendingOrder) {
        for (size_t i{0}; i < (vec.size() - 1); ++i) {
            size_t key_index = i;
            for (size_t j = i + 1; j < vec.size(); ++j) {
                if (vec[j] < vec[key_index])
                    key_index = j;
            }
            std::swap(vec[i], vec[key_index]);
        }
    } else if (order == utils::DescendingOrder) {
        for (size_t i{0}; i < (vec.size() - 1); ++i) {
            size_t key_index = i;
            for (size_t j = i + 1; j < vec.size(); ++j) {
                if (vec[j] > vec[key_index])
                    key_index = j;
            }
            std::swap(vec[i], vec[key_index]);
        }
    }
}

// Merge Sort ------------------------------------------------------------------------

// Bubble Sort -----------------------------------------------------------------------

// Heap Sort -------------------------------------------------------------------------

// Quick Sort ------------------------------------------------------------------------

// Counting Sort ---------------------------------------------------------------------

// Radix Sort ------------------------------------------------------------------------

// Bucket Sort -----------------------------------------------------------------------

// external sorting?

}   // cra namespace (c. roman algorithms [library])