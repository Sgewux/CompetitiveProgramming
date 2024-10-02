#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
   string s;
   getline(cin, s);

   if(s.length() < 3){
        cout<<"NO"<<'\n';
   } else {
        string s2 = s.substr(2,s.length()-2);
        string s3 = s.substr(0,2);
        if(s2[0] == '0' || (s2[0] == '1' && s2.length() == 1) || s3 != "10"){
            cout<<"NO"<<'\n';
        } else {
            cout<<"YES"<<'\n';
        }
   }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    std::cin>>t;
    cin.ignore();

    while(t--){
        solve();
    }

    return 0;
}