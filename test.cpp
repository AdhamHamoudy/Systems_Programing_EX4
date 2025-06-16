// File: test.cpp
// Email: adhamhamoudy3@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MyContainer.hpp"
#include <sstream>

using namespace ariel;

// === Core Functionality Tests ===

TEST_CASE("Add and Size") {
    MyContainer<int> c;
    CHECK(c.size() == 0);
    c.addElement(5);
    c.addElement(3);
    CHECK(c.size() == 2);
}

TEST_CASE("Remove Element") {
    MyContainer<int> c;
    c.addElement(1);
    c.addElement(1);
    c.removeElement(1);
    CHECK(c.size() == 0);
    CHECK_THROWS(c.removeElement(1));
}

TEST_CASE("Output Stream") {
    MyContainer<int> c;
    c.addElement(1);
    c.addElement(2);
    std::stringstream ss;
    ss << c;
    CHECK(ss.str() == "[ 1 2 ]");
}

// === Iterator Tests ===

TEST_CASE("Ascending Order") {
    MyContainer<int> c;
    c.addElement(5);
    c.addElement(1);
    c.addElement(3);
    std::vector<int> result;
    for (auto it = c.begin_ascending_order(); it != c.end_ascending_order(); ++it)
        result.push_back(*it);
    CHECK(result == std::vector<int>({1, 3, 5}));
}

TEST_CASE("Descending Order") {
    MyContainer<int> c;
    c.addElement(5);
    c.addElement(1);
    c.addElement(3);
    std::vector<int> result;
    for (auto it = c.begin_descending_order(); it != c.end_descending_order(); ++it)
        result.push_back(*it);
    CHECK(result == std::vector<int>({5, 3, 1}));
}

TEST_CASE("SideCross Order") {
    MyContainer<int> c;
    c.addElement(7);
    c.addElement(15);
    c.addElement(6);
    c.addElement(1);
    c.addElement(2);
    std::vector<int> result;
    for (auto it = c.begin_side_cross_order(); it != c.end_side_cross_order(); ++it)
        result.push_back(*it);
    CHECK(result == std::vector<int>({1, 15, 2, 7, 6}));
}

TEST_CASE("Reverse Order") {
    MyContainer<int> c;
    c.addElement(7);
    c.addElement(15);
    c.addElement(6);
    c.addElement(1);
    c.addElement(2);
    std::vector<int> result;
    for (auto it = c.begin_reverse_order(); it != c.end_reverse_order(); ++it)
        result.push_back(*it);
    CHECK(result == std::vector<int>({2, 1, 6, 15, 7}));
}

TEST_CASE("Order (insertion order)") {
    MyContainer<int> c;
    c.addElement(7);
    c.addElement(15);
    c.addElement(6);
    c.addElement(1);
    c.addElement(2);
    std::vector<int> result;
    for (auto it = c.begin_order(); it != c.end_order(); ++it)
        result.push_back(*it);
    CHECK(result == std::vector<int>({7, 15, 6, 1, 2}));
}

TEST_CASE("MiddleOut Order") {
    MyContainer<int> c;
    c.addElement(7);
    c.addElement(15);
    c.addElement(6);
    c.addElement(1);
    c.addElement(2);
    std::vector<int> result;
    for (auto it = c.begin_middle_out_order(); it != c.end_middle_out_order(); ++it)
        result.push_back(*it);

    CHECK(result == std::vector<int>({6, 15, 1, 7, 2}));
}

