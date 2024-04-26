#include<iostream>
#include<set>

int main(){
    std::set<long long> alreadySeen;
    long long count = 0;
    long long n;
    std::cin >> n;

    for(long long i = 0; i < n; i++){
        long long a;
        std::cin>>a;

        if(alreadySeen.count(a) == 0){
            count++;
            alreadySeen.insert(a);
        }
    }

    std::cout << count;
    return 0;
}