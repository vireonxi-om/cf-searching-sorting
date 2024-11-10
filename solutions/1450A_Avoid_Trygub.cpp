// Problem: Avoid Trygub
// URL: https://codeforces.com/problemset/problem/1450/A
// Rating: 800
// Tags: constructive algorithms, sortings
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[210];
int n;

void solve(){
    scanf("%d", &n);
    scanf("%s", &s);
    int cnt=0;
    vector<char> b;
    for(int i=0; i<n; i++){
        if(s[i]=='t') cnt++;
        else b.push_back(s[i]);
    }
    while(cnt>0){
        b.push_back('t');
        cnt--;
    }
    for(auto x:b) printf("%c", x);
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) solve();
    return 0;
}
