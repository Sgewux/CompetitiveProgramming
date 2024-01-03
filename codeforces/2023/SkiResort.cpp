#include<iostream>
 
long long solve(int * arr, long long n, long long k){
    
    long long count = 0;
    long long currentCant = 0;
    for(long long j = 0; j < n; j++){
        if(*(arr+j) == 0){
            if(currentCant>=k){
                count += (currentCant+1-k)*((currentCant+1-k)+1)/2;
            }
            currentCant = 0;
        } else {
            currentCant += *(arr+j);
        }
    }

    if(currentCant>=k){
        count += (currentCant+1-k)*((currentCant+1-k)+1)/2;
    }

    return count;
}
 
int main(){
    long long t;
    std::cin>>t;
    for(long long j = 0; j < t; j++){
        long long n;
        long long k;
        long long q;
        std::cin>>n;
        std::cin>>k;
        std::cin>>q;
 
        int arr[n];
 
        for(long long i = 0; i < n; i++){
            long long current;
            std::cin>>current;
            current <= q ? arr[i] = 1 : arr[i] = 0;
        }
 
        std::cout<<solve(arr, n, k)<<std::endl;
 
 
    }
    return 0; 
}