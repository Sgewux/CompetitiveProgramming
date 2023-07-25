#include<iostream>


bool solve(long long k,  long long * colors, long long n){
    long long head =  *(colors);
    long long tail = *(colors + (n-1));

    long long headCount = 0;
    long long tailCount = 0;

    long long lastHeadIdx;
    long long lastTailIdx;

    if(head == tail){
        for(long long i = 0; i < n; i++){
            if (*(colors + i) == head){
                headCount++;
            }
        }

        if(headCount>= k){
            return true;
        }
    }

    headCount = 0;

    for(long long i = 0; i < n; i++){
        if(headCount == k){
            break;
        } else if (*(colors + i) == head){
            headCount++;
            lastHeadIdx = i;
        }
    }

    for(long long i = n-1; i > lastHeadIdx; i--){
        if(tailCount == k){
            break;
        } else if (*(colors + i) == tail){
            tailCount++;
            lastTailIdx = i;
        }
    }

    if((tailCount == k && headCount == k)){
        return true;
    } else { 
        return false;
    }

}

int main(){
    long long t;
    long long n;
    long long k;
    std::cin>>t;

    for(long long j = 0; j < t; j++){
        std::cin>>n;
        std::cin>>k;
        long long colors[n];

        for(long long i = 0; i < n; i++){
            std::cin>>colors[i];
        }

        solve(k, colors, n) == true ? std::cout<<"YES" : std::cout<< "NO";
        std::cout<<std::endl;
        
    }
    return 0;
}