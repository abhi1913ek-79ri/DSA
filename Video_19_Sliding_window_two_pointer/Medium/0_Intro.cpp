#include<bits/stdc++.h>
using namespace std;
// Types of Pattern

// 1. Constant Window Problem - can be done by Two Pointers/sliding window  as we have thinek about all the elements in window 
// Example : max sum of subarray - two pointers
// max sum of pints on card
// brute generate all subarray of length k and get answer - O(n*n)
// Optimal : two pinters


// 2. longest subarray / subtring 
// brute : O(n*n) - generate all subarray
// better : O(n+n) - sliding window variable size 
// 1. left shrink
// 2. right expand
// optimal : O(n) - if only max length is asked shrinks one always

// 3. Numbers of subarrays : 2nd ka utilise optimal
// two parts me divide karke let say sum exactly k : sum <=k ans sum <=k-1 then find difference

// 4. minimum shortest window :
// find a valid window then shrink as smalll as it is possible 

#include<bits/stdc++.h>
using namespace std;

/*
==============================
TWO POINTER + SLIDING WINDOW
==============================

👉 4 CORE PATTERNS
*/

/////////////////////////////////////////////////////////
// 1. FIXED SIZE WINDOW (Constant Window)
/////////////////////////////////////////////////////////

/*
👉 Condition: Window size = K (fixed)

Problems:
- Max sum subarray of size K
- First negative in every window
- Count anagrams

Brute:
- Generate all subarrays of size k → O(n*k)

Optimal:
- Sliding window → O(n)

Logic:
- Add next element
- Remove previous element
*/

/////////////////////////////////////////////////////////
// 2. VARIABLE SIZE WINDOW (Longest / Largest)
/////////////////////////////////////////////////////////

/*
👉 Condition: Window size changes

Problems:
- Longest substring without repeating characters
- Longest subarray with sum ≤ K
- Fruits into baskets

Brute:
- Generate all subarrays → O(n^2)

Better:
- Sliding window → O(n)

🔥 KEY IDEA:
- Expand right
- If invalid → shrink left

Optimal Trick:
- If ONLY max length asked → shrink one step at a time
*/

/////////////////////////////////////////////////////////
// 3. NUMBER OF SUBARRAYS (Exactly K)
/////////////////////////////////////////////////////////

/*
👉 Most important trick 🔥

Formula:
Exactly(K) = AtMost(K) - AtMost(K-1)

Problems:
- Subarrays with K distinct
- Binary subarrays with sum = K

Brute:
- O(n^2)

Optimal:
- Sliding window + hashmap → O(n)
*/

/////////////////////////////////////////////////////////
// 4. MINIMUM WINDOW (Shortest Valid Window)
/////////////////////////////////////////////////////////

/*
👉 Goal: smallest valid window

Problems:
- Minimum window substring
- Smallest subarray with sum ≥ K

Brute:
- O(n^3)

Better:
- O(n^2)

Optimal:
- Expand till valid
- Then shrink as much as possible

🔥 KEY IDEA:
- VALID → shrink
- INVALID → expand
*/


// | Question Type      | Approach        |
// | ------------------ | --------------- |
// | Size K fix hai     | Fixed Window    |
// | Longest / Maximum  | Variable Window |
// | Count exact K      | AtMost trick    |
// | Minimum / Shortest | Min Window      |


int main(){
    return 0;
}


int main(){
    
    return 0;
}