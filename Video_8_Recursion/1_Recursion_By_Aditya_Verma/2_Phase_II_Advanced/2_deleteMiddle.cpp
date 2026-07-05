#include<bits/stdc++.h>
using namespace std;
// Delete Middle element

//Hypothesis
// delete(st,k) correctly removes kth from top of stack


// induction 
// delete(st,k) = delete(st after pop, k-1) + adding while returning

// base condition
// if k == 1
// st.pop()

void deleteMiddleStackHelper(stack<int>& st,int k){
    // base condition
    if(k==1){
        st.pop();
        return;
    }

    // induction
    int temp = st.top();
    st.pop();
    deleteMiddleStackHelper(st,k-1);
    st.push(temp);
}
// TC = O(n)
// SC = O(n)

void deleteMiddleStack(stack<int>& st){
    int n = st.size();
    if(n == 1){
        st.pop();
        return;
    }

    deleteMiddleStackHelper(st,n/2 + 1);
}

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

        deleteMiddleStack(st);
        n = st.size();
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