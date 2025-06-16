// File: include/DescendingOrder.hpp
// Email: adhamhamoudy3@gmail.com

#pragma once
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <functional>

namespace ariel {

    template<typename T>
    class DescendingOrder {
    private:
        std::vector<T> sorted; // Stores elements sorted in descending order
        size_t index;          // Current position in the traversal

    public:
        // Constructor: sort elements in descending order using std::greater
        DescendingOrder(const std::vector<T>& elements, size_t idx)
            : sorted(elements), index(idx) {
            std::sort(sorted.begin(), sorted.end(), std::greater<T>());
        }

        // Begin iterator (starts at index 0)
        DescendingOrder begin() const {
            return DescendingOrder(sorted, 0);
        }

        // End iterator (points to sorted.size())
        DescendingOrder end() const {
            return DescendingOrder(sorted, sorted.size());
        }

        // Pre-increment operator: advance to next element
        DescendingOrder& operator++() {
            ++index;
            return *this;
        }

        // Dereference operator: access current element or throw if invalid
        const T& operator*() const {
            if (index >= sorted.size()) {
                throw std::out_of_range("Attempt to dereference end() iterator");
            }
            return sorted[index];
        }

        // Inequality operator: compare iterator positions
        bool operator!=(const DescendingOrder& other) const {
            return index != other.index;
        }
    };

}
