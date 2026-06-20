#include<bits/stdc++.h>
using namespace std;
// wrong
// NGE-III : Queue - Method
int countDigits(int n){
    if(n == 0) return 1;
    return log10(abs(n)) + 1;
}
int ngeIII(int n){
    if(countDigits(n)<2) return -1;
    queue<int> q;
    int m = n;
    int lastDigit = -1;
    while (m>0)
    {
        int ld = m%10;
        m/=10;
        if(q.empty()) q.push(ld);
        else{
            if(q.back()<ld) q.push(ld);
            else{

                lastDigit = ld;
                m = m*10+q.back();
                while (!q.empty())
                {
                    m = m*10 + q.front();
                    q.pop();
                }
                m/=10; // to remove back of q
                break;
            }
        }
    }

    return m*10+lastDigit;
}

int main(){
    int n = 12;
    cout << "n = "<<n<<endl;
    cout << "nge =  " << ngeIII(n) <<endl;

    return 0;
}