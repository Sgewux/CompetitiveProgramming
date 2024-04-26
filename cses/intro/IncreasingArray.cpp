#include<iostream>

int main(){
    long long n;
    long long count = 0;
    std::cin >> n;
    long long previous;
    std::cin >> previous;

    for(int i = 0; i < n-1; i++){
        long long current;
        std::cin >> current;
        long long difference = previous - current;

        if( difference > 0){ // Current number smaller than prvious one
            count += difference;
            current += difference;
        }

        previous = current;

    }

    std::cout << count;
    return 0;
}