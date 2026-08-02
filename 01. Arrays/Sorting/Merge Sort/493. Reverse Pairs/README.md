# 493. Reverse Pairs (TUF)

## 📌 Problem Statement

Given an integer array `nums`, return the number of **reverse pairs** in the array.

A reverse pair is defined as:

```
i < j
nums[i] > 2 × nums[j]
```

---

## 🧠 Key Idea

A brute force approach checks every possible pair, resulting in **O(n²)** time.

The optimal solution uses **Merge Sort** because, during the merge step, both halves are already sorted. This allows reverse pairs to be counted efficiently using a two-pointer technique before merging.

---

## 🚀 Approach

1. Divide the array into two halves using Merge Sort.
2. Recursively sort both halves.
3. Before merging, count all reverse pairs between the two sorted halves.
4. Merge the two halves into a single sorted array.
5. Sum the counts from all recursive calls.

---

## 💡 Why Merge Sort?

Since both halves are sorted:

- A pointer in the right half only moves forward.
- Each element is processed once during counting.
- Counting becomes **linear** for each merge.

This reduces the overall complexity from **O(n²)** to **O(n log n)**.

---

## ⚠️ Important Observation

While counting reverse pairs, use **`2LL`** instead of `2` to avoid integer overflow.

Example:

```cpp
nums[i] > 2LL * nums[j]
```

Without `2LL`, multiplication may overflow for large integer values.

---

## 📊 Complexity Analysis

| Operation | Complexity |
|----------|------------|
| Time | **O(n log n)** |
| Space | **O(n)** |

---

## 🏷️ Topics

- Array
- Sorting
- Merge Sort
- Divide and Conquer
- Two Pointers

---

## 📚 What I Learned

- How Merge Sort can solve counting problems efficiently.
- Counting reverse pairs before merging sorted halves.
- Using two pointers on sorted subarrays.
- Preventing integer overflow using `long long`.
- Applying Divide and Conquer to optimize pair-counting problems.

---

## 🔗 Related Problems

- 912. Sort an Array
- Count Inversions
- 315. Count of Smaller Numbers After Self