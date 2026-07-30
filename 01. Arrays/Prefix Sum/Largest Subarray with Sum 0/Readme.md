# Longest Subarray with Sum 0 (TUF)

## Problem Statement

Given an array `arr[]`, find the **length of the longest subarray whose sum is equal to `0`**.

### Example

```text
Input:
[15, -2, 2, -8, 1, 7, 10, 23]

Output:
5
```

The longest subarray with sum `0` is:

```text
[-2, 2, -8, 1, 7]
```

Its sum is:

```text
-2 + 2 - 8 + 1 + 7 = 0
```

Length:

```text
5
```

----

## Approach 1: Brute Force

Check every possible subarray and calculate its sum.

### Idea

For every starting index:

1. Set `sum = 0`.
2. Move through the array from the current starting index.
3. Add each element to `sum`.
4. Whenever `sum == 0`, calculate the length.
5. Keep the maximum length found.

### Complexity

* **Time:** `O(n²)`
* **Space:** `O(1)`

This approach is simple but inefficient for large arrays.

---

## Approach 2: Prefix Sum + Hash Map

### Key Observation

Suppose the prefix sum at index `i` is `S`.

Later, at index `j`, the prefix sum is also `S`.

Then:

```text
prefixSum[j] - prefixSum[i] = 0
```

Therefore, the elements between `i + 1` and `j` have a sum of `0`.

So:

> **If the same prefix sum appears twice, the elements between those two indices form a zero-sum subarray.**

---

## Example

Consider:

```text
[15, -2, 2, -8, 1, 7, 10, 23]
```

### Prefix Sum Table

| Index | Element | Prefix Sum |
| ----: | ------: | ---------: |
|     0 |      15 |         15 |
|     1 |      -2 |         13 |
|     2 |       2 |         15 |
|     3 |      -8 |          7 |
|     4 |       1 |          8 |
|     5 |       7 |         15 |
|     6 |      10 |         25 |
|     7 |      23 |         48 |

The prefix sum `15` occurs at:

```text
index 0
index 2
index 5
```

We keep the **first occurrence**:

```text
15 → 0
```

When we reach index `5`:

```text
length = 5 - 0 = 5
```

The corresponding zero-sum subarray is:

```text
indices 1 to 5

[-2, 2, -8, 1, 7]
```

Check the sum:

```text
-2 + 2 - 8 + 1 + 7 = 0
```

Therefore:

```text
Maximum length = 5
```

---

## Why Store the First Index?

Suppose the same prefix sum appears at multiple indices:

```text
sum = 15

index 0
index 2
index 5
```

To get the longest possible subarray, we need the **earliest index**.

Using index `0` at index `5` gives:

```text
5 - 0 = 5
```

If we replaced index `0` with a later occurrence, the resulting subarray would be shorter.

Therefore:

> **Store only the first occurrence of each prefix sum.**

---

## Special Case: Prefix Sum = 0

If the prefix sum itself becomes `0` at index `i`, then:

```text
arr[0] + arr[1] + ... + arr[i] = 0
```

Therefore, the subarray starts from index `0`.

Its length is:

```text
i + 1
```

---

## Important Pattern

```text
Prefix Sum
    ↓
Store first occurrence in Hash Map
    ↓
Same prefix sum appears again
    ↓
Subarray between the two indices has sum 0
    ↓
Length = current index - first index
```

---

## Complexity Comparison

| Approach              | Time Complexity | Space Complexity |
| --------------------- | --------------- | ---------------- |
| Brute Force           | `O(n²)`         | `O(1)`           |
| Prefix Sum + Hash Map | `O(n)` average  | `O(n)`           |

---

## Key Takeaway

The main concept to remember is:

> **Same prefix sum at two different indices means the elements between those indices have sum `0`.**

This is a common **Prefix Sum + Hash Map** pattern used in many subarray problems.
