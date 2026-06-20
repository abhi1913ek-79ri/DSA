#include <bits/stdc++.h>
using namespace std;
// Min Initial Enery
static bool cmp(vector<int>& a,vector<int>& b){
    return (a[1]-a[0]) > (b[1]-b[0]);
}

int minimumEffort(vector<vector<int>> &tasks)
{
    sort(tasks.begin(),tasks.end(),cmp);
    int energy = 0;
    int ans = 0;
    for (auto task : tasks)
    {
        int actual = task[0];
        int minimum = task[1];


        // if current energy is no sufficient to start the  task 
        // energy < minimum
        if(energy < minimum){
            ans += (minimum-energy);
            energy = minimum;
        }

        energy -= actual;
    }

    return ans;
}
int main()
{

    return 0;
}