// Problem: Guess the K-th Zero (Easy version)
// URL: https://codeforces.com/problemset/problem/1520/F1
// Rating: 1600
// Tags: binary search, interactive
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, t, k;


int main(){
    scanf("%d%d%d", &n, &t, &k);
    int l=1, r=n, ans, num;
    while(l<=r){
        int mid=(l+r)/2;
        printf("? %d %d\n", 1, mid);
        fflush(stdout);
        scanf("%d", &num);
        if(mid-num==k) ans=mid;
        if(mid-num>=k) r=mid-1;
        else l=mid+1;
    }
    printf("! %d\n", ans);
    return 0;
}


