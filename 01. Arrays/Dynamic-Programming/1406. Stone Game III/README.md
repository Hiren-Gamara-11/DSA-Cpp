# 1406. Stone Game III (POTD)

## Problem
Alice and Bob take turns picking **1, 2, or 3** stones from the beginning of the array.

Each stone has a value (can be positive or negative).

Both players play optimally.

Return:

- `"Alice"` if Alice gets a higher score.
- `"Bob"` if Bob gets a higher score.
- `"Tie"` if both scores are equal.

---

## Approach

Instead of storing the maximum score, store the **maximum score difference** the current player can achieve over the opponent.

Let:

- `dp[i]` = Maximum score difference starting from index `i`.

At every position:

1. Take 1 stone.
2. Take 2 stones.
3. Take 3 stones.

Choose the move that gives the maximum advantage.

Transition:

```
dp[i] = max(
    take1 - dp[i+1],
    take2 - dp[i+2],
    take3 - dp[i+3]
)
```

The subtraction works because after the current player takes stones, the opponent will also play optimally.

---

## Algorithm

1. Create DP array of size `n + 1`.
2. Traverse from right to left.
3. Maintain running sum for taking 1–3 stones.
4. Compute the best score difference.
5. If:
   - `dp[0] > 0` → Alice wins
   - `dp[0] < 0` → Bob wins
   - otherwise → Tie

---

## Time Complexity

- **O(n)**

Each index considers at most 3 moves.

---

## Space Complexity

- **O(n)**

---

## Concepts Used

- Dynamic Programming
- Game Theory (Minimax Idea)
- Score Difference DP
- Bottom-Up DP