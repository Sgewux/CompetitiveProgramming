#include<iostream>
#include<algorithm>

bool solve(long long * unsortedNums, long long * sortedNums, long long n){
    for(long long i = 0; i < n; i++){
        if(*(sortedNums+i) % 2 == 0 && *(unsortedNums+i) % 2 != 0){
            return false;
        } else if(*(sortedNums+i) % 2 != 0 && *(unsortedNums+i) % 2 == 0){
            return false;
        }
    }

    return true;
}

int main(){
    long long t;
    long long n;
    long long num;

    std::cin>>t;

    for(long long j = 0; j < t; j++){
        std::cin>>n;
        long long unsortedNums[n];
        long long sortedNums[n];
        for(long long i = 0; i < n; i++){
            std::cin>>num;
            unsortedNums[i] = num;
            sortedNums[i] = num;
        }

        std::sort(sortedNums, sortedNums+n);

        solve(unsortedNums, sortedNums, n) == true ? std::cout<<"YES" : std::cout<<"NO";
        std::cout<<std::endl;
    }

    return 0;
}