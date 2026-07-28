/*
    Problem: Smallest Palindromic Rearrangement I
    Category: Strings

    Approaches:
    1. Brute Force:
       - Generate all permutations of the string.
       - Check which permutations are palindromes.
       - Return the lexicographically smallest palindrome.
       - Time Complexity: O(n! * n)
       - Space Complexity: O(n)

    2. Backtracking:
       - Count character frequencies.
       - Generate only valid palindromic arrangements.
       - Keep track of the lexicographically smallest palindrome.
       - Time Complexity: Exponential in the worst case.
       - Space Complexity: O(n)

    3. Optimal - Frequency Counting:
       - Count the frequency of each character.
       - Build the left half using half of each character's frequency.
       - Add the odd-frequency character in the middle if the length is odd.
       - Reverse the left half to create the right half.
       - Iterating from 'a' to 'z' ensures the smallest lexicographical order.

    Time Complexity: O(n + 26) -> O(n)
    Space Complexity: O(n + 26) -> O(n)
*/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        // Count frequency of each character
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string half = "";

        // Build the left half in lexicographical order
        for (int i = 0; i < 26; i++) {
            half += string(freq[i] / 2, 'a' + i);
        }

        // Create the right half by reversing the left half
        string revHalf = half;
        reverse(revHalf.begin(), revHalf.end());

        // Add middle character if length is odd
        string middle = "";
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                middle = char('a' + i);
                break;
            }
        }

        return half + middle + revHalf;
    }
};