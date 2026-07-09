#include <bits/stdc++.h>
using namespace std;
// Kth grammar LC 779

// Hypothesis
// KG(n-1,k/2) correctly gives me the digit at k/2th pos of n-1th row
// Hypothesis - GPT
// Assume kg(n-1, parentPos) correctly returns
// the symbol present at the parent position
// in the previous row.

// Induction
// KG(n,k) = if(KG(n-1,k/2) ==0 && k&1) -> 0
//           else if(KG(n-1,k/2) ==0 && !(k&1)) -> 1
//           else if(KG(n-1,k/2) == 1 && k&1) -> 1
//           else if(KG(n-1,k/2) ==1 && !(k&1)) -> 0

// Base condition
// if(n==1) return 0;

int kg(int n, int k)
{
    // base condition
    if (n == 1)
        return 0;

    // induction
    bool isOdd = k & 1;
    int kgPrev = kg(n - 1, isOdd ? k / 2 + 1 : k / 2);
    if (kgPrev)
    {
        if (isOdd)
            return 1;
        else
            return 0;
    }

    return (isOdd) ? 0 : 1;
}

// TC = O(n)
// SC = O(n)

// ADITYA'S OBSERVATION

int kg(int n, int k)
{
    // base condition
    if (n == 1)
        return 0;

    // induction
    int mid = pow(2, n - 1) / 2;
    if (k <= mid)
        return kg(n - 1, k);

    return !kg(n - 1, k - mid);
}

int main()
{

    return 0;
}