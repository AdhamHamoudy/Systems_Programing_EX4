// File: include/AscendingOrder.hpp
// Email: adhamhamoudy3@gmail.com

#pragma once
#include <vector>
#include <algorithm>
#include <stdexcept>

namespace ariel {

    template<typename T>
    class AscendingOrder {
    private:
        std::vector<T> sorted; // Stores elements sorted in ascending order
        size_t index;          // Current index in the traversal

    public:
        // Constructor: sort input elements in ascending order
        AscendingOrder(const std::vector<T>& elements, size_t idx)
            : sorted(elements), index(idx) {
            std::sort(sorted.begin(), sorted.end());
        }

        // Return iterator to beginning (index 0)
        AscendingOrder begin() const {
            return AscendingOrder(sorted, 0);
        }

        // Return iterator to end (index = sorted.size())
        AscendingOrder end() const {
            return AscendingOrder(sorted, sorted.size());
        }

        // Pre-increment operator: move to next element
        AscendingOrder& operator++() {
            ++index;
            return *this;
        }

        // Dereference current element with bounds check
        const T& operator*() const {
            if (index >= sorted.size()) {
                throw std::out_of_range("Attempt to dereference end() iterator");
            }
            return sorted[index];
        }

        // Inequality check (used in for-each loops)
        bool operator!=(const AscendingOrder& other) const {
            return index != other.index;
        }
    };

}
