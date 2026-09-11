#include<bits/stdc++.h>
using namespace std;
// 3483. Unique 3-Digit Even Numbers
int solve(vector<int>& digits){
    vector<int> freq(10,0);
    for(auto& d : digits){
        freq[d]++;
    }
    int cnt = 0;
    for(int i = 100;i<=999;i++){
        if(i&1) continue;

        int n = i;
        int a = n%10;
        n /= 10;
        int b = n%10;
        n /= 10;
        int c = n%10;

        vector<int> need(10,0);
        need[a]++;
        need[b]++;
        need[c]++;

        bool possible = true;
        for(int d=0;d<=9;d++){
            if(need[d]>freq[d]){
                possible = false;
                break;
            }
        }

        if(possible){
            cnt++;
        }
    }
    return cnt;
    // TC = O(1000)
    // sc = O(1)
}
int main(){
    int n;
    cin >> n;
    vector<int> digits(n);
    for(auto& d : digits){
        cin >> d;
    }

    cout << solve(digits);
    return 0;
}