#include<bits/stdc++.h>
using namespace std;
// Three sum 

// brute




int main(){
    
    return 0;
}

/*2. Three Sum
Problem
a+b+c=0
Brute Force
Intuition

Har possible triplet check karo.

Algorithm
for i
   for j
      for k

          if sum==0

Duplicate remove using set.

Complexity

Time

O(n³)

Space

O(set)

Better (Hashing)
Intuition

Fix one element.

Baaki 2 Sum bana do.

for every i

    target = -nums[i]

    HashMap use karo
Algorithm
for i

    map clear

    for j=i+1

         need=target-nums[j]

         if found

             insert triplet into set

         store nums[j]

Duplicate remove using set.

Complexity

Time

O(n² log n)

Space

O(n)

Optimal (Sorting + Two Pointers)
Intuition

Sabse important.

Sort kar do.

Fix first number.

Baaki do numbers two pointers se search karo.

i

l=i+1

r=n-1
sum=nums[i]+nums[l]+nums[r]

If

sum<0

Left increase.

If

sum>0

Right decrease.

Else

Answer.

Move both pointers.

Skip duplicates.

Algorithm
sort

for i

   skip duplicates

   l=i+1
   r=n-1

   while(l<r)

        sum

        if sum<0
             l++

        else if sum>0
             r--

        else

             store

             l++
             r--

             skip duplicates
Complexity

Time

O(n²)

Space

O(1)*/