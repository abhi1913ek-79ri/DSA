#include<bits/stdc++.h>
using namespace std;
// reverse stack

// Hypthesis
// reverse(st after pop)  = correctly reverse n- 1 elements of stack

// induction
// reverse(st) = reververse(st,n-1) + insert at bottom  nth ele

// base condition
// if(n == 1) return 


// insert
// hypothesis
// insert(st,n-1,ele) corrctly insert at it's suitable position

// induction
// insert(st,n,ele) = insert(st,n-1,ele) + push back temp while returning

void insert(stack<int>& st,int ele){
    // base condition
    if(st.empty()) {
        st.push(ele);
        return;
    }

    // induction
    int temp = st.top();
    st.pop();
    insert(st,ele);
    st.push(temp);
}

void revStackHelper(stack<int>& st){
    // Base condition
    if(st.size() <= 1) return;

    // induction
    int temp = st.top();
    st.pop();
    revStackHelper(st);
    insert(st,temp);
}

// TC = O(n^2)
// SC = O(n)

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        stack<int> st;
        for(int i = 0;i<n;i++){
            int curr;
            cin >> curr;
            st.push(curr);
        }

        revStackHelper(st);
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        for(int i = ans.size()-1;i>=0;i--){
            cout << ans[i];
            if(i) cout << " ";
        }
        cout << "\n";
        
    }
    
    return 0;
}