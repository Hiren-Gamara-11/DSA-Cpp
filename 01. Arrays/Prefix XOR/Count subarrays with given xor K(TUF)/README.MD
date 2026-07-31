# Count Subarrays With Given XOR K (TUF)

## Problem

Given an array `nums` and an integer `k`, find the number of subarrays whose XOR is equal to `k`.

### Example

```text
nums = [4, 2, 2, 6, 4]
k = 6

Answer = 4
```

---

## Approach: Prefix XOR + Hashmap

Let:

```text
prefixXor = XOR of elements from the start up to the current index
previousXor = XOR before the required subarray
```

For the subarray XOR to be `k`:

```text
prefixXor ^ previousXor = k
```

Therefore:

```text
previousXor = prefixXor ^ k
```

At every index:

1. Update `prefixXor`.
2. Calculate:

```text
required = prefixXor ^ k
```

3. Add the frequency of `required` from the hashmap.
4. Store the current `prefixXor` in the hashmap.

---

## Important Initialization

```text
mp[0] = 1
```

This represents the prefix XOR before the array starts.

It is necessary for counting subarrays that begin at index `0`.

---

## Why the Hashmap Stores Frequencies

The hashmap stores:

```text
Prefix XOR → Frequency
```

For example:

```text
mp[4] = 2
```

means prefix XOR `4` has appeared twice so far.

When:

```text
required = prefixXor ^ k
```

we add the number of times `required` has already appeared.

---

## Important XOR Properties

```text
a ^ a = 0
a ^ 0 = a
a ^ b = c  →  a = b ^ c
```

These properties allow us to transform:

```text
prefixXor ^ previousXor = k
```

into:

```text
previousXor = prefixXor ^ k
```

---

## Complexity

```text
Time:  O(n) average
Space: O(n)
```

## Key Takeaway

### Pattern: Prefix XOR + Frequency Hashmap

When a problem asks you to **count subarrays with a given XOR**, think:

```text
Prefix XOR
     ↓
required = prefixXor ^ k
     ↓
Frequency Hashmap
```
