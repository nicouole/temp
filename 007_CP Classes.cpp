//atcoder 007 (沒過)
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    long long b;
    cin >> n;
    vector<long long> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    sort(A.begin(), A.end());
    cin >> q;

    for(int i = 0; i < q; i++){
        cin >> b;
        auto lb = lower_bound(A.begin(), A.end(), b);
        if(lb == A.end()) lb = A.end()-1; //找比目標大或一樣的最小值
        auto ub = upper_bound(A.begin(), A.end(), b); //找比目標大或一樣的最小值
        if(*lb == *ub) ub--; //如果兩個找到的是一樣的(都是比目標大的最小值)，ub-變成跟目標一樣或是更小的最大值
        
        if(abs(*lb-b) > abs(*ub-b)) cout << abs(*ub-b) << endl;
        else cout << abs(*lb-b) << endl;
    }
    return 0;
}
