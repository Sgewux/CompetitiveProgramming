#include<iostream>
#include<string>

std::string solve(long long n){

    if(n == 2 || n == 3){
        return "NO SOLUTION";
    } else if(n == 1){
        return "1";
    }

    std::string even = "";
    std::string odd = "";

    for(long long i = 1; i <= n; i++){
        if(i%2 == 0){
            even += std::to_string(i);
            even += " ";
        } else {
            odd += std::to_string(i);
            odd += " ";
        }
    }

    return even + odd;
}

int main(){
    long long n;
    std::cin >> n;
    std::cout << solve(n);
    return 0;
}