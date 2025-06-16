// File: include/MiddleOutOrder.hpp
// Email: adhamhamoudy3@gmail.com

#pragma once
#include <vector>
#include <stdexcept>

namespace ariel {

    template<typename T>
    class MiddleOutOrder {
    private:
        std::vector<T> traversal; // Stores the middle-out traversal order
        size_t index;             // Current index in iteration

    public:
        // Constructor: builds middle-out traversal order
        MiddleOutOrder(const std::vector<T>& elements, size_t idx)
            : index(idx) {
            std::vector<T> original = elements;
            size_t n = original.size();
            if (n == 0) return;

            // Compute the middle index (rounded down)
            size_t mid = n / 2;
            std::vector<size_t> order;
            order.push_back(mid);

            // Alternate between left and right from the middle
            int left = static_cast<int>(mid) - 1;
            int right = static_cast<int>(mid) + 1;
            bool turnRight = false;

            while (left >= 0 || right < static_cast<int>(n)) {
                if (turnRight && right < static_cast<int>(n)) {
                    order.push_back(right++);
                } else if (!turnRight && left >= 0) {
                    order.push_back(left--);
                }
                turnRight = !turnRight; // Switch direction
            }

            // Build traversal vector using calculated indices
            traversal.reserve(n);
            for (size_t i : order) {
                traversal.push_back(original[i]);
            }
        }

        // Begin iterator
        MiddleOutOrder begin() const {
            return MiddleOutOrder(traversal, 0);
        }

        // End iterator
        MiddleOutOrder end() const {
            return MiddleOutOrder(traversal, traversal.size());
        }

        // Pre-increment
        MiddleOutOrder& operator++() {
            ++index;
            return *this;
        }

        // Dereference current element with bounds check
        const T& operator*() const {
            if (index >= traversal.size()) {
                throw std::out_of_range("Dereferencing end() iterator in MiddleOutOrder");
            }
            return traversal[index];
        }

        // Inequality comparison
        bool operator!=(const MiddleOutOrder& other) const {
            return index != other.index;
        }
    };

}
