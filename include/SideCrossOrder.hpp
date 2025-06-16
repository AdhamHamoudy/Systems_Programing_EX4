// File: include/SideCrossOrder.hpp
// Email: adhamhamoudy3@gmail.com

#pragma once
#include <vector>
#include <algorithm>
#include <stdexcept>

namespace ariel {

    template<typename T>
    class SideCrossOrder {
    private:
        std::vector<T> traversal; // Stores the side-cross traversal order
        size_t index;             // Current position in the traversal

    public:
        // Constructor: builds the side-cross order from sorted elements
        SideCrossOrder(const std::vector<T>& elements, size_t idx)
            : index(idx) {
            std::vector<T> sorted = elements;
            std::sort(sorted.begin(), sorted.end());

            size_t left = 0, right = sorted.size() - 1;

            // Interleave from smallest and largest toward the center
            while (left <= right) {
                if (left == right) {
                    traversal.push_back(sorted[left]); // Add middle element once
                } else {
                    traversal.push_back(sorted[left]);  // Add smallest remaining
                    traversal.push_back(sorted[right]); // Add largest remaining
                }
                ++left;
                if (right > 0) --right;
            }
        }

        // Return iterator to the beginning of the traversal
        SideCrossOrder begin() const {
            return SideCrossOrder(traversal, 0);
        }

        // Return iterator to the end (past-the-end position)
        SideCrossOrder end() const {
            return SideCrossOrder(traversal, traversal.size());
        }

        // Pre-increment: move to next element
        SideCrossOrder& operator++() {
            ++index;
            return *this;
        }

        // Dereference: return current element
        const T& operator*() const {
            if (index >= traversal.size()) {
                throw std::out_of_range("Dereferencing past-the-end in SideCrossOrder");
            }
            return traversal[index];
        }

        // Compare inequality (used in iteration loops)
        bool operator!=(const SideCrossOrder& other) const {
            return index != other.index;
        }
    };

}
