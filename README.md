# C Pointer Review 🖥️

A hands-on project that thoroughly explores the concept of pointers in C programming. This repository contains practical examples and implementations demonstrating pointer arithmetic, function pointers, generic sorting algorithms, and common use cases.

## 📚 Topics Covered

### 1. **Basic Pointer Concepts**
- Pointer declaration and initialization
- Size of different pointer types
- `const` qualifiers with pointers (`const int*` vs `int* const`)
- Pointer arithmetic and subtraction

### 2. **String Operations**
- Custom `my_strlen()` implementation using pointer arithmetic
- String literals and `const char*`

### 3. **Sorting Algorithms**
- **Bubble Sort** - Optimized with early termination flag
- **Bubble Qsort** - Generic bubble sort using `void*` and function pointers
- **Standard Library `qsort()`** - Sorting structures by age

### 4. **Function Pointers**
- Calculator program with function pointer array
- Dynamic function dispatching
- Comparison functions for sorting

### 5. **Generic Programming**
- `Swap()` function using byte-by-byte copying
- Type-agnostic bubble sort implementation
- Callback functions for custom comparison logic

### 6. **Memory & Pointer Operations**
- Pointer comparison (address comparison)
- Array traversal using pointers
- Relationship between arrays and pointers

## 🚀 Code Examples

### Custom String Length
```c
size_t my_strlen(const char* str) {
    assert(str);
    const char* end = str;
    while (*end) end++;
    return end - str;
}
