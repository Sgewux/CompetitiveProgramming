#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>

long long solve(std::unordered_map<long long, long long>& a, std::unordered_map<long long, long long>& b, std::unordered_set<long long>& seenVals){
    long long answer = 0;
    for(long long val : seenVals){
        answer = std::max(answer, a[val] + b[val]);
    }

    return answer;
}


int main(){
    long long t;
    long long n;
    std::cin>>t;

    for(long long i = 0; i < t; i++){
        std::cin>>n;
        std::unordered_set<long long> seenVals;
        std::unordered_map<long long, long long> a;
        std::unordered_map<long long, long long> b;
        long long elem;
        

        long long lastSeen;
        long long count;
        std::cin>>lastSeen;
        seenVals.insert(lastSeen);
        count = 1;
        for(long long j = 0; j < n-1; j++){
            std::cin>>elem;
            seenVals.insert(elem);
            if(elem == lastSeen){
                count += 1;
            } else {
                a[lastSeen] = std::max(a[lastSeen], count);
                count = 1;
                lastSeen = elem;

            }
        }
        a[lastSeen] = std::max(a[lastSeen], count);

        std::cin>>lastSeen;
        seenVals.insert(lastSeen);
        count = 1;
        for(long long j = 0; j < n-1; j++){
            std::cin>>elem;
            seenVals.insert(elem);
            if(elem == lastSeen){
                count += 1;
            } else {
                b[lastSeen] = std::max(b[lastSeen], count);
                count = 1;
                lastSeen = elem;

            }
        }
        b[lastSeen] = std::max(b[lastSeen], count);

        std::cout<<solve(a, b, seenVals)<<std::endl;
    }

    return 0;
}