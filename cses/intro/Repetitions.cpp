#include<iostream>
#include<algorithm>
#include<string>

long long solve(const char * str, long long n, long long i){
    long long count = 0;
    char current = *(str+i);

    if(i==n){
        return 0;
    }

    while(i < n){
        if(*(str+i) == current){
            count++;
            i++;
        } else {
            break;
        }
    }

    return std::max(count, solve(str, n, i));
}

int main(){
    std::string str;
    std::getline(std::cin, str);
    std::cout<<solve(str.c_str(), str.size(), 0);
    return 0;
}