#include <bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

vector<vector<ld>> mul(vector<vector<ld>>& a, vector<vector<ld>>& b){
    vector<vector<ld>> c = {{0,0}, {0,0}};
    for(long long i = 0; i<2; i++){
        for(long long j = 0; j<2; j++){
            for(long long k = 0; k<2; k++){
                c[i][j] += (a[i][k] * b[k][j]);
            }
        }
    }

    return c;
}

vector<vector<ld>> binexpo(vector<vector<ld>>& a, ll b){
    if(b == 0) return {{1,0},{0,1}};
    vector<vector<ld>> res = binexpo(a,b/2);
    res = mul(res, res);
    
    if(b & 1){
        return mul(res,a);
    } else {
        return res;
    }
}

void solve(){
    ll n;
    cin>>n;
    n = min(n, (ll)1e10);
    if(n == 1){
        cout<<100<<' '<<0;
    } else if(n == 2){
        cout<<0<<' '<<100;
    } else {
        vector<vector<ld>> m = {{0.5, 0.5}, {1, 0}};
        m = binexpo(m,n-2);
        ld potato = m[0][1] * (ld)100;
        cout<< fixed << setprecision(7) << potato << ' ' << (ld) 100 - potato;
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