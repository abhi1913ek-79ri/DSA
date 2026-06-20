#include<bits/stdc++.h>
using namespace std;

// setKthBit
int setKthBit(int n,int k){
    return n | (1 << k);
}

// clearKthBit
int clearKthBit(int n,int k){
    n = n & (~(1 << k));
    return n;
}

int main(){
    int n = 13;
    int k = 0;
    cout << "n = " << bitset<32>(n).to_string()<< endl;
    cout << "After setting " <<0<< "th bit \nn = " << bitset<32>(setKthBit(n,0)).to_string()<< endl;
    cout << "After setting " <<1<< "th bit \nn = " << bitset<32>(setKthBit(n,1)).to_string()<< endl;
    cout << "After setting " <<2<< "th bit \nn = " << bitset<32>(setKthBit(n,2)).to_string()<< endl;
    cout << "After setting " <<3<< "th bit \nn = " << bitset<32>(setKthBit(n,3)).to_string()<< endl;
    cout << "After setting " <<5<< "th bit \nn = " << bitset<32>(setKthBit(n,5)).to_string()<< endl;

    // clear
    cout << "After clearing " <<0<< "th bit \nn = " << bitset<32>(clearKthBit(n,0)).to_string()<< endl;
    cout << "After clearing " <<1<< "th bit \nn = " << bitset<32>(clearKthBit(n,1)).to_string()<< endl;
    cout << "After clearing " <<2<< "th bit \nn = " << bitset<32>(clearKthBit(n,2)).to_string()<< endl;
    cout << "After clearing " <<3<< "th bit \nn = " << bitset<32>(clearKthBit(n,3)).to_string()<< endl;
    cout << "After clearing " <<5<< "th bit \nn = " << bitset<32>(clearKthBit(n,5)).to_string()<< endl;
    return 0;
}