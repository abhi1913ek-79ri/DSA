#include<bits/stdc++.h>
using namespace std;
//Minimum Bit Flips to Convert Number brute -- compare and count no. of different bits 
// in bInary representation of start and goal
int minBitFlips1(int start, int goal) {
    string binStart = bitset<32>(start).to_string();
    string binGoal = bitset<32>(goal).to_string();
    int cnt = 0;
    for(int i = 31;i>=0;i--){
        if(binStart[i]!=binGoal[i]){
            cnt++;
        }
    }
    return cnt;
    // TC = O(32)
    // SC = O(32)
}

// Using Bit Manipualtion --  Brute 
int minBitFlips2(int start,int goal){
    // XOR operation gives 1 for different bits ;
    int ans = start^goal;
    int cnt = 0;
    while (ans)
    {
        cnt+=ans&1;
        ans >>=1;
    }
    return cnt;
    // TC = O(32)
    // SC = O(1)
}

// Bit Manipulation -- Optimal
int minBitFlips3(int start,int goal){
    // Brian Kanighan Algorithm
    int ans = start^goal;
    int cnt = 0;
    while (ans)
    {
        ans&=ans-1;
        cnt++;
    }
    return cnt;
    // TC = O(no of different bits)
    // SC = O(1)
}


// Using Builtin popCount function
int minBitFlips4(int start,int goal){
    return __builtin_popcount(start^goal);
    // TC = O(1) -- due to hardwere instructions
}

int main(){
    int start = 3;
    int goal  = 4;
    cout << "Start = " << start << "\nGoal = "<< goal<<"\nMin. no. of bit flips = " << minBitFlips4(start,goal) <<endl;
    return 0;
}