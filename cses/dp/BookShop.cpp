#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
const int N = 1000 + 1;
const int W = 1e5 + 1;
 
int memo[N][W];
 
void solve(){
    int n; int w;
    cin>>n>>w;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; i++) cin>>v[i].first;
    for(int i = 0; i < n; i++) cin>>v[i].second;
    
    memset(memo, 0, sizeof(memo[0][0]) * N * W);
    
    for(int i = 1; i <= n; i++){
        int wi; int vi;
        wi = v[i-1].first;
        vi = v[i-1].second;
        
        for(int j = 1; j<=w; j++){
            if(j >= wi){
                memo[i][j] = max(memo[i-1][j], memo[i-1][j-wi] + vi);
            } else {
                memo[i][j] = memo[i-1][j];
            }
        }
    }
    
    cout<<memo[n][w];
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