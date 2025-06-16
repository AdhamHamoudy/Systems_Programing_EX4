// File: include/MyContainer.hpp
// Email: adhamhamoudy3@gmail.com

#pragma once
#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>

#include "AscendingOrder.hpp"
#include "DescendingOrder.hpp"
#include "SideCrossOrder.hpp"
#include "ReverseOrder.hpp"
#include "Order.hpp"
#include "MiddleOutOrder.hpp"

namespace ariel {

    template<typename T>
    class MyContainer {
    private:
        std::vector<T> elements;

    public:
        MyContainer() = default;

        void addElement(const T& element);
        void removeElement(const T& element);
        size_t size() const;

        template<typename U>
        friend std::ostream& operator<<(std::ostream& os, const MyContainer<U>& container);

        // ==== Iterator Access Methods ====

        AscendingOrder<T> begin_ascending_order() const {
            return AscendingOrder<T>(elements, 0);
        }

        AscendingOrder<T> end_ascending_order() const {
            return AscendingOrder<T>(elements, elements.size());
        }

        DescendingOrder<T> begin_descending_order() const {
            return DescendingOrder<T>(elements, 0);
        }

        DescendingOrder<T> end_descending_order() const {
            return DescendingOrder<T>(elements, elements.size());
        }

        SideCrossOrder<T> begin_side_cross_order() const {
            return SideCrossOrder<T>(elements, 0);
        }

        SideCrossOrder<T> end_side_cross_order() const {
            return SideCrossOrder<T>(elements, elements.size());
        }

        ReverseOrder<T> begin_reverse_order() const {
            return ReverseOrder<T>(elements, 0);
        }

        ReverseOrder<T> end_reverse_order() const {
            return ReverseOrder<T>(elements, elements.size());
        }

        Order<T> begin_order() const {
            return Order<T>(elements, 0);
        }

        Order<T> end_order() const {
            return Order<T>(elements, elements.size());
        }

        MiddleOutOrder<T> begin_middle_out_order() const {
            return MiddleOutOrder<T>(elements, 0);
        }

        MiddleOutOrder<T> end_middle_out_order() const {
            return MiddleOutOrder<T>(elements, elements.size());
        }

        const std::vector<T>& getElements() const {
            return elements;
        }
    };

    // === Template Method Definitions ===

    template<typename T>
    void MyContainer<T>::addElement(const T& element) {
        elements.push_back(element);
    }

    template<typename T>
    void MyContainer<T>::removeElement(const T& element) {
        size_t originalSize = elements.size();
        elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());

        if (elements.size() == originalSize) {
            throw std::runtime_error("Element not found in container");
        }
    }

    template<typename T>
    size_t MyContainer<T>::size() const {
        return elements.size();
    }

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const MyContainer<T>& container) {
        os << "[ ";
        for (const auto& el : container.elements) {
            os << el << " ";
        }
        os << "]";
        return os;
    }

}
