#include<iostream>
#include<string>
#include<limits>

void solve(const char * pattern, long long size){
    char answer[size+1];
    answer[size] = '\0';
    *(pattern) == '?' ? answer[0] = '0' : answer[0] = *pattern;
    *(pattern+(size-1)) == '?' ? answer[size-1] = '1' : answer[size-1] = *(pattern+(size-1));

    char lastSeen = answer[size-1];

    for(long long i = size-2; i >= 1; i--){
        if(*(pattern+i) == '?'){
            answer[i] = lastSeen;
        } else {
            answer[i] = *(pattern+i);
            lastSeen = *(pattern+i);
        }
    }

    std::cout<<answer<<std::endl;
}

int main(){
    long long t;
    std::string pattern;
    std::cin>>t;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for(long long i = 0; i < t; i++){
        std::getline(std::cin, pattern);
        solve(pattern.c_str(), pattern.size());
    }
    return 0;
}