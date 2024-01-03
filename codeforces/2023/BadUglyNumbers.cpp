#include<iostream>
#include<cmath>

const char * solve(long long n){

    char * answer = new char[n+1];
    if((n-1)%3 == 0){
        *(answer) = '4'; 

        for(long long i = 1; i<=n-2; i++){
            *(answer+i) = '2';
        }

    } else {
        for(long long i = 0; i<n-1; i++){
            *(answer+i) = '2';
        }
    }


    *(answer+(n-1)) = '3';
    *(answer+n) = '\0';

    return answer;
}

int main(){
    long long t;
    long long n;
    const char * answer = nullptr;
    std::cin>>t;

    for(long long i = 0; i < t; i++){
        std::cin>>n;
        if(n==1){
            std::cout<<-1<<std::endl;
        } else {
            answer = solve(n);
            std::cout<<answer<<std::endl;
            delete answer;
        }
    }
    return 0;
}