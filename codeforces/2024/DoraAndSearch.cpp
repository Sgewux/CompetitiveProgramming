#include <bits/stdc++.h>

void solve(long long n, std::vector<long long>& a){
    long long l = 0;
    long long r = n-1;
    long long min = 1;
    long long max = n;

    while(l<r){
        if(!(a[l] != min && a[l] != max)){
            if(a[l] == min){
                min++;
            } else {
                max--;
            }

            l++;

        } else if(!(a[r] != min && a[r] != max)){
            if(a[r] == min){
                min++;
            } else {
                max--;
            }

            r--;

        } else {
            std::cout<< l+1 <<' '<< r+1 <<'\n';
            return;
        }
    }

    std::cout<<-1<<'\n';
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long n;
    long long curr;
    std::cin>>t;

    while(t--){
        std::vector<long long>a;
        std::cin>>n;

        for(long long i = 0; i<n; i++){
            std::cin>>curr;
            a.push_back(curr);
        }

        solve(n, a);
    }

    return 0;
}