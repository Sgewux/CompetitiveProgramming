#include<iostream>
#include<vector>
#include<string_view>
#include<string>

int findMiddle(int s, int t){
    int m;
    if(s==1){
        m = (t==2)?3:2;

    } else if(s==2){
        m = (t==1)?3:1;

    } else if(s==3) {
        m = (t==2)?1:2;
    }

    return m;
}

void solve(int n, int s, int t, std::vector<std::string>& moves){
    int m = findMiddle(s,t);
    if(n==1){
       moves.push_back(std::to_string(s) + " " + std::to_string(t));

    }else if(n==2){
        moves.push_back(std::to_string(s) + " " + std::to_string(m));
        moves.push_back(std::to_string(s) + " " + std::to_string(t));
        moves.push_back(std::to_string(m) + " " + std::to_string(t));
    
    } else {
        solve(n-1, s, m, moves);
        moves.push_back(std::to_string(s) + " " + std::to_string(t));
        solve(n-1, m, t, moves);
    }
}

int main(){
    int n;
    std::vector<std::string> moves;
    std::cin>>n;
    
    solve(n,1,3, moves);

    std::cout<<moves.size()<<std::endl;
    for(std::string i : moves){
        std::cout<<i<<std::endl;
    }

    return 0;
}