#include<iostream>
#include<cctype>

long long solve(long long * upeercaseCounts, long long * lowercaseCounts, long long k){
    long long count = 0;

    for(int i = 0; i<26; i++){
        long long greater;
        long long smaller;
        long long diff;

        if(*(upeercaseCounts+i) > *(lowercaseCounts+i)){
            greater = *(upeercaseCounts+i);
            smaller = *(lowercaseCounts+i);
        } else {
            greater = *(lowercaseCounts+i);
            smaller = *(upeercaseCounts+i);
        }
        diff = greater-smaller;

        if(diff > 1 && k != 0){
            long long cantOfMoves;
            (diff)%2 == 0 ? cantOfMoves = (diff)/2 : cantOfMoves = (diff-1)/2;
            if(k>=cantOfMoves){
                count += smaller+cantOfMoves;
                k -= cantOfMoves;
            } else if(k<cantOfMoves){
                count += smaller+k;
                k = 0; //  We ate all movements
            }
        } else {
            count+=smaller; //cant do moves
        }
    }

    return count;
}

int main(){
    long long t;
    std::cin>>t;
    long long uppercaseCounts[26];
    long long lowercaseCounts[26];

    for(long long i = 0; i<t; i++){
        for(int n = 0; n < 26; n++){
            uppercaseCounts[n] = 0;
            lowercaseCounts[n] = 0;
        }
        long long n;
        long long k;
        std::cin>>n;
        std::cin>>k;

        for(long long j = 0; j<n; j++){
            char current;
            std::cin>>current;

            if(std::islower(current)){
                lowercaseCounts[current - 'a']++;
            } else {
                uppercaseCounts[current - 'A']++;
            }
            
        }

        std::cout<<solve(uppercaseCounts, lowercaseCounts, k)<<std::endl;
    }

    return 0;
}