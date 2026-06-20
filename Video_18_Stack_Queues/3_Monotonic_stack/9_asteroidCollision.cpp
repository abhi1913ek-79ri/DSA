#include <bits/stdc++.h>
using namespace std;
// asteroid collision
// collision condition : collison only happen if
// st.top() is positive and asteroid is negative
vector<int> asteroidCollision(vector<int> &asteroids)
{
    stack<int> st;

    for (auto asteroid : asteroids)
    {
        bool destroyed = false;

        while (!st.empty() && (st.top() > 0 && asteroid < 0)) // collision condition
        {
            if (abs(asteroid) > st.top())
            {
                // top destroyed and continue till it get euqal or greater
                st.pop();
                continue;
            }
            else if (abs(asteroid) == st.top())
            {
                // both destroyed
                destroyed = true;
                st.pop();
                break;
            }
            else
            {
                // asteroid destroyed
                destroyed = true;
                break;
            }
        }
        if (!destroyed)
            st.push(asteroid);
    }

    vector<int> ans;

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
    // TC = O(N)
    // SC = O(N)
}

// printArray
void printArray(vector<int>& nums){
    cout << "[";
    for(auto num:nums) cout << num << " ";
    cout << "]\n";
}

int main(){
    vector<int> asteroids = {10,2,-5};
    vector<int> asteroidAfterCollison = asteroidCollision(asteroids);
    cout << "Asteroid Before collison : ";
    printArray(asteroids);
    cout << "Asteroid After collison : ";
    printArray(asteroidAfterCollison);
    return 0;
}