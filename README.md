# Assignment 4 – Custom Container with Iterators

**Author:** Adham Hamoudy  
**Email:** adhamhamoudy3@gmail.com  

---

## 📌 Project Description

This project implements a generic, templated container class `MyContainer<T>` that supports dynamic addition and removal of comparable elements (e.g., `int`, `double`, `std::string`). The container is equipped with six different custom iterators that traverse the data in various logical orders.

The assignment demonstrates understanding of topics such as templates, functors, containers, and iterators, as taught in lectures 7–10.

---

## 🧩 Implemented Components

### ✅ `MyContainer<T>`
- Generic container that stores any comparable type.
- Supports:
  - `addElement(const T&)`
  - `removeElement(const T&)` – removes all occurrences or throws if not found
  - `size()` – returns number of elements
  - Output stream (`<<`) for pretty-printing

### ✅ Iterators

All iterators implement `begin()`, `end()`, `++`, `*`, and `!=`.

| Iterator Type       | Description |
|---------------------|-------------|
| `AscendingOrder`    | Sorts elements in ascending order |
| `DescendingOrder`   | Sorts elements in descending order |
| `SideCrossOrder`    | Alternates smallest → largest → next-smallest → next-largest... |
| `ReverseOrder`      | Reverses the insertion order |
| `Order`             | Traverses in original insertion order |
| `MiddleOutOrder`    | Starts at middle, alternates left/right |

---

## 📂 File Structure

| File | Description |
|------|-------------|
| `include/MyContainer.hpp` | Declaration and implementation of the container class |
| `include/*.hpp` | All six iterator implementations |
| `Demo.cpp` | Provided test/demo file showing required usage |
| `test.cpp` | Doctest unit tests for all functionalities |
| `Makefile` | Build automation as required by the assignment |

---

## 🛠️ Build Instructions

### Compile and run demo:
```bash
make Main
./main_exec
