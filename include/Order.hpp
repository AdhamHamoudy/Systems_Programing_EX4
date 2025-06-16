// File: include/Order.hpp
// Email: adhamhamoudy3@gmail.com

#pragma once
#include <vector>
#include <stdexcept>

namespace ariel {

    template<typename T>
    class Order {
    private:
        std::vector<T> data; // Stores elements in original insertion order
        size_t index;        // Current position in the iteration

    public:
        // Constructor: receives container elements and current index
        Order(const std::vector<T>& elements, size_t idx)
            : data(elements), index(idx) {}

        // Begin iterator (starts from index 0)
        Order begin() const {
            return Order(data, 0);
        }

        // End iterator (past-the-end position)
        Order end() const {
            return Order(data, data.size());
        }

        // Pre-increment operator: move to next element
        Order& operator++() {
            ++index;
            return *this;
        }

        // Dereference operator: return current element or throw if out of range
        const T& operator*() const {
            if (index >= data.size()) {
                throw std::out_of_range("Dereferencing past-the-end in Order");
            }
            return data[index];
        }

        // Inequality operator: check if two iterators are at different positions
        bool operator!=(const Order& other) const {
            return index != other.index;
        }
    };

}
