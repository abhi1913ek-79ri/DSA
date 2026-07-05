#include<bits/stdc++.h>
using namespace std;
// Sort stack 

// Hypothesis
// sort(st, n-1)  correct sort the stack with size n-1

// induction 
// sort(st,n) = sort(st,n-1) and insert nth ele in stack

// Base Condition
// if(st.size() <= 1) return

// insert function
// Hypothesis
// insert(st,n-1,ele) correctly insert ele in sorted st size n-1

// induction
// st.push_back(nth ele)
void insert(stack<int>& st,int ele){
    // base condition
    if(st.empty() || ele >= st.top()){
        st.push(ele);
        return;
    }

    int temp = st.top();
    st.pop();
    insert(st,ele);
    st.push(temp);
}
void sortStackHelper(stack<int>& st){
    // base condition
    if(st.size()<=1) return;
    int temp = st.top();
    st.pop();
    sortStackHelper(st);
    insert(st,temp);
}

void sortStack(stack<int>& st){
    if(st.empty() || st.size() == 1) return;
    sortStackHelper(st);
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
        sortStack(st);
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