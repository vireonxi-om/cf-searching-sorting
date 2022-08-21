// Problem: Guessing the Greatest (easy version)
// URL: https://codeforces.com/problemset/problem/1486/C1
// Rating: 1600
// Tags: binary search, interactive
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n;


int main(){
    scanf("%d", &n);
    printf("? %d %d\n", 1, n);
    fflush(stdout);
    int pos;
    scanf("%d", &pos);
    int l=1, r=n, mid=(l+r)/2;
    while(l+1<r){
        mid=(l+r)/2;
        int a, b;
        printf("? %d %d\n", l, mid);
        fflush(stdout);
        scanf("%d", &a);
        printf("? %d %d\n", mid, r);
        fflush(stdout);
        scanf("%d", &b);
        if(a==pos){
            r=mid;
            continue;
        }
        else if(pos<=mid){
            l=mid;
            pos=b;
            continue;
        }
        if(b==pos){
            l=mid;
            continue;
        }
        else if(pos>mid){
            r=mid;
            pos=a;
            continue;
        }
    }
    if(l==pos) printf("! %d\n", r);
    else printf("! %d\n", l);
    fflush(stdout);
    return 0;
}



