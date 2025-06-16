// File: include/ReverseOrder.hpp
// Email: adhamhamoudy3@gmail.com

#pragma once
#include <vector>
#include <algorithm>
#include <stdexcept>

namespace ariel {

    template<typename T>
    class ReverseOrder {
    private:
        std::vector<T> reversed; // Stores the reversed version of input
        size_t index;            // Current position in iteration

    public:
        // Constructor: reverses the given elements
        ReverseOrder(const std::vector<T>& elements, size_t idx)
            : reversed(elements), index(idx) {
            std::reverse(reversed.begin(), reversed.end());
        }

        // Begin iterator (start at index 0)
        ReverseOrder begin() const {
            return ReverseOrder(reversed, 0);
        }

        // End iterator (past-the-end index)
        ReverseOrder end() const {
            return ReverseOrder(reversed, reversed.size());
        }

        // Pre-increment: move to next element
        ReverseOrder& operator++() {
            ++index;
            return *this;
        }

        // Dereference: return current element, throw if out of range
        const T& operator*() const {
            if (index >= reversed.size()) {
                throw std::out_of_range("Dereferencing past-the-end in ReverseOrder");
            }
            return reversed[index];
        }

        // Inequality check (used in iteration)
        bool operator!=(const ReverseOrder& other) const {
            return index != other.index;
        }
    };

}
