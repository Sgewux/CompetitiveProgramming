#include<iostream>
#include<unordered_set>
#include<cmath>
#include<string>

std::string solve(long long n, long long m){
    std::unordered_set<long long> posiblities;
    int i = 1;
    long long powOf3;
    while ( n % (powOf3 = std::pow(3, i)) == 0)
    {
        for(int j = 0; j <= i; j++){
            posiblities.insert( (std::pow(2,j))*(n/powOf3) );
        }

        i++;
    }

    if(posiblities.count(m) == 1){
        return "YES";
    } else {
        return "NO";
    }
}

int main(){
    long long lines;
    long long n;
    long long m;

    std::cin>>lines;

    for (long long i = 0; i < lines; i++){
        std::cin>>n;
        std::cin>>m;

        m == n ? std::cout<<"YES" : m < n ? std::cout<<solve(n,m) : std::cout<<"NO";
        std::cout<<std::endl;
    }
    
    return 0;
}