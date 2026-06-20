#include<bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids){
    stack<int> st;

    for(auto asteroid : asteroids){
        bool destroyed = false; // flag for asteroid 

        // collison condition --  and then only comaparison
        while (!st.empty() && (st.top()>0 && asteroid<0))
        {
            if(abs(asteroid) > st.top()){  // may be more than one time
                st.pop(); // top destroyed
                continue;
            }else if(abs(asteroid) == st.top()){
                destroyed = true; // both destroyed
                st.pop(); 
            }

            destroyed = true;
            break;
        }

        if(!destroyed){
            st.push(asteroid);
        }
    }

    vector<int> ans;

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(),ans.end());

    return ans;
}

void printArray(vector<int>& nums){
    cout <<"[";
    for(auto num : nums) cout << num << " ";
    cout << "]\n";
}

int main(){
    vector<int> asteroids = {8,-8};
    vector<int> ans = asteroidCollision(asteroids);
    cout << "Asteroids : ";
    printArray(asteroids);
    cout << "Afetr Collison asteroids : ";
    printArray(ans);
    return 0;
}

// Asteroid Collision  -- logic wrong
// vector<int> asteroidCollision(vector<int>& asteroids) {
//     stack<int> st;

//     for(auto asteroid :asteroids){
//         if(st.empty()){
//             st.push(asteroid);
//             continue;
//         }
//         // collison condition
//         if(st.top() > 0 && asteroid < 0){
//             int top = st.top();
//             while ((!st.empty())&&(st.top() > 0 && asteroid < 0))
//             {
//                 if(-1*asteroid >= st.top()){
//                     top = st.top();
//                     st.pop();
//                 }else {
//                     break;
//                 }
//             }
//             if(st.empty()&& top != (-1*asteroid)) st.push(asteroid);
//         }else{
//             st.push(asteroid);
//         }
//     }

//     vector<int> ans;
//     while (!st.empty())
//     {
//         ans.push_back(st.top());
//         st.pop();
//     }
    
//     reverse(ans.begin(),ans.end());

//     return ans;
// }
