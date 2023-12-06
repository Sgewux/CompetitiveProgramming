#include <bits/stdc++.h>


long long solve(int* arr, long long minIdx, long long n){
    arr[minIdx]++;
    long long ans = 1;
    for(long long i = 0; i<n; i++){
        ans = ans*arr[i];
    }

    return ans;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long n;
    long long curr;
    long long min;
    long long minIdx;
    std::cin>>t;

    while(t--){
        std::cin>>n;
        min = 10e9;
        int arr[n];

        for(long long i = 0; i < n; i++){
            std::cin>>curr;
            arr[i] = curr;
            if(curr < min){
                min = curr;
                minIdx = i;
            }
        }

        std::cout<< solve(arr, minIdx, n) << '\n';

        
    }
    
    return 0;
}