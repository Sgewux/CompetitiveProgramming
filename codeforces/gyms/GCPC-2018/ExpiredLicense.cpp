#include <bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

const ll N = 1e7;

vector<bool> prime(N+1, true);
void sieve(){
    prime[0] = false;
    prime[1] = false;
    for(long long i = 2; i<=N; i++){
        if(prime[i]){
            for(long long j = i*i; j<=N; j+=i){
                prime[j] = false;
            }
        }
    }
}

ll toWhole(string n){
    string s = "";
    ll afterP = 5;
    bool p = false;
    for(auto& c : n){
        if(c != '.'){
            if(s.length() > 0){
                s+=c;
            } else if(c != '0'){
                s+=c;
            }


            if(p) afterP--;
        } else {
            p=true;
        }

    }

    while(afterP--) s.push_back('0');

    return stoi(s);
}

void solve(){
    string a; string b;
    cin>>a>>b;
    ll d;

    pair<ll,ll>fracC = {toWhole(a), toWhole(b)};

    while((d = gcd(fracC.first, fracC.second)) != 1){
        fracC.first /= d;
        fracC.second /= d;
    }

    assert(fracC.first <= 1e7 && fracC.second <= 1e7);

    if(fracC.first == 1 && fracC.second == 1){
        cout<<2<<' '<<2<<'\n';
    }else if(prime[fracC.first] && prime[fracC.second]){
        cout<<fracC.first<<' '<<fracC.second<<'\n';
    } else {
        cout<<"impossible"<<'\n';
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    std::cin>>t;
    sieve();

    while(t--){
        solve();
    }

    return 0;
}