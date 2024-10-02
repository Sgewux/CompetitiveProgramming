#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll N = 1e5 + 1;
const ll X = 1e6 + 1;
const ll m = 1e9 + 7;
ll pow2[N];
ll CM[X];
ll lp[X];

void sieve(){
    vector<ll> pr;
    for(long long i = 0; i<=X; i++) lp[i] = 0;
    for(long long i = 2; i<=X; i++){
        if(lp[i] == 0){
            pr.push_back(i);
            lp[i] = i;
        }

        for(long long j = 0; j < pr.size() && i * pr[j] <= X; j++){
            lp[i * pr[j]] = pr[j];
            if(lp[i] == pr[j]) break;
        }
    }
}

void solve(){
    ll n; cin>>n;
    pow2[0] =1;
    for(long long i = 1; i<=N; i++) pow2[i] = (pow2[i-1] * 2) % m;
    for(long long i = 0; i<=X; i++) CM[i] = 0;
    for(long long i = 0; i<n; i++){
        ll vi; cin>>vi;
        CM[vi]++;
    }

    for(long long i = 1; i<=X; i++){
        for(long long j = i+i; j<=X; j+=i){
            CM[i] += CM[j];
        }
    }

    sieve();

    ll q; cin>>q;

    while(q--){
        ll xi; cin>>xi;
        vector<ll> pf;
        ll lastSeen = -1;
        while(lp[xi] != 0){
            if(lp[xi] != lastSeen ) pf.push_back(lp[xi]);
            lastSeen = lp[xi];
            xi /= lp[xi];
        }

        ll u = 0;

        for(long long i = 1; i<=pow2[pf.size()] - 1; i++){
            ll sets = 0;
            ll intersec = 1;
            for(long long j = 0; j<=pf.size(); j++){
                if(i & (1<<j)){
                    sets++;
                    intersec *= pf[j];
                }
            }

            if(sets & 1){
                u += CM[intersec];
            } else {
                u -= CM[intersec];
            }
        }

        cout<<pow2[n-u]<<'\n';
    }
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