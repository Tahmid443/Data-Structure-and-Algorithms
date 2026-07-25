# 📚 Sorting Algorithms in C++

This repository contains implementations of the most common sorting algorithms in **C++** using arrays and manual swap operations (where applicable). These algorithms are fundamental in Data Structures and Algorithms (DSA) and Competitive Programming.

---

## 📑 Algorithms Included

| Algorithm | Best Time | Average Time | Worst Time | Space | Stable |
|-----------|-----------|--------------|------------|--------|--------|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) | ✅ Yes |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) | ❌ No |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | ✅ Yes |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) | ❌ No |
| Radix Sort | O(nk) | O(nk) | O(nk) | O(n+k) | ✅ Yes |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) | ❌ No |

---

# 🔵 Bubble Sort

### Description
Bubble Sort repeatedly compares adjacent elements and swaps them if they are in the wrong order. After each pass, the largest element "bubbles" to its correct position.

### Characteristics
- Simple to understand
- Good for learning
- Inefficient for large datasets

### Complexity
- Best: **O(n)**
- Average: **O(n²)**
- Worst: **O(n²)**

---

# 🟢 Selection Sort

### Description
Selection Sort repeatedly finds the minimum element from the unsorted portion and places it at the beginning.

### Characteristics
- Performs fewer swaps
- Easy implementation
- Not stable

### Complexity
- Best: **O(n²)**
- Average: **O(n²)**
- Worst: **O(n²)**

---

# 🟣 Merge Sort

### Description
Merge Sort uses the Divide and Conquer technique. It divides the array into halves, sorts each half recursively, and merges them back together.

### Characteristics
- Stable
- Efficient
- Requires extra memory

### Complexity
- Best: **O(n log n)**
- Average: **O(n log n)**
- Worst: **O(n log n)**

---

# 🟠 Heap Sort

### Description
Heap Sort builds a Max Heap and repeatedly extracts the largest element to produce a sorted array.

### Characteristics
- In-place sorting
- No additional memory required
- Not stable

### Complexity
- Best: **O(n log n)**
- Average: **O(n log n)**
- Worst: **O(n log n)**

---

# 🔴 Radix Sort

### Description
Radix Sort sorts numbers digit by digit using a stable sorting algorithm (usually Counting Sort).

### Characteristics
- Non-comparison based
- Very fast for integers
- Works only for specific data types

### Complexity
- Best: **O(nk)**
- Average: **O(nk)**
- Worst: **O(nk)**

> **k = Number of digits in the largest number**

---

# 🟡 Quick Sort

### Description
Quick Sort selects a pivot element and partitions the array into two halves. The process is recursively repeated.

### Characteristics
- Divide and Conquer
- Very fast in practice
- Widely used

### Complexity
- Best: **O(n log n)**
- Average: **O(n log n)**
- Worst: **O(n²)**

---

# 📂 Repository Structure

```
Sorting-Algorithms/
│
├── bubble_sort.cpp
├── selection_sort.cpp
├── merge_sort.cpp
├── heap_sort.cpp
├── radix_sort.cpp
├── quick_sort.cpp
└── README.md
```

---

# 🚀 How to Run

Compile any file using **g++**

```bash
g++ BubbleSort.cpp -o BubbleSort
./BubbleSort
```

Example:

```bash
g++ QuickSort.cpp -o QuickSort
./QuickSort
```

---

# 🎯 Learning Order

1. Bubble Sort
2. Selection Sort
3. Merge Sort
4. Quick Sort
5. Heap Sort
6. Radix Sort

---

## 💡 Concepts Covered

- Arrays
- Dynamic Memory Allocation
- Recursion
- Divide and Conquer
- Heap Data Structure
- Stable vs Unstable Sorting
- In-place Sorting
- Time & Space Complexity Analysis

---

## ⭐ If you found this repository helpful, don't forget to star it!
