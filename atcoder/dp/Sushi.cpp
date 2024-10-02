#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 301;
long double memo[N][N][N];

long double f(ll ones, ll twos, ll threes, ll n){
    if((ones + twos + threes) == 0) {
        return 0;
    } else {
        long double &r = memo[ones][twos][threes];
        if(r == 0){
            r = 1;
            if(ones > 0) r += (long double)(ones/ (long double) n)*f(ones-1,twos,threes,n);
            if(twos > 0) r += (long double)(twos/ (long double) n)*f(ones+1, twos-1, threes, n);
            if(threes > 0) r += (long double)(threes/ (long double) n)*f(ones, twos+1, threes-1, n);
            
            long double xd = (long double ) 1 - (( n - (ones + twos + threes) )/ (long double) n);
            r = r/xd;
        }

        return r;
    }
}

void solve(){
    ll n;
    ll ones = 0; 
    ll twos = 0;
    ll threes = 0;
    cin>>n;

    for(long long i = 0; i<n; i++){
        ll curr; cin>>curr;
        if(curr == 1){
            ones++;
        } else if(curr == 2){
            twos++;
        } else {
            threes++;
        }
    }

    memset(memo, 0, sizeof(memo[0][0][0]) * N * N * N);

    cout<< fixed << setprecision(25) << f(ones, twos, threes, n);

}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t=1;

    while(t--){
        solve();
    }

    return 0;
}