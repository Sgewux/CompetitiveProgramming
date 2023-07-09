#include<iostream>


void piles(long long a, long long b){
    long long left;
    long long right;

    if(a == b){
        if (a%3 == 0){
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    
    } else {
        if (a > b){
            left = a;
            right = b; 
        } else {
            left = b;
            right = a;
        }


        long long diff = left - right;

        if((left - 2*diff) == 0 && (right - diff) == 0){
            std::cout << "YES" << std::endl;
        
        } else if ((left - 2*diff) > 0 && (right - diff) > 0){
            // both equal
            if ( (right-diff)%3 == 0){
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
    
        } else {
            std::cout << "NO" << std::endl;
        }
    }
}


int main(){
    long long lines;
    std::cin >> lines;

    for (long long i = 0; i < lines; i++){
        long long a;
        long long b;

        std::cin >> a;
        std::cin >> b;

        piles(a,b);
    }
    
    return 0;
}