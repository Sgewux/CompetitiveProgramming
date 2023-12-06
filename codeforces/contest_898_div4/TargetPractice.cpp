#include <bits/stdc++.h>

int solve(){
    long long count=0;
    std::string row;
    for(long long i =0; i<10; i++){
        std::getline(std::cin, row);
        for(long long j =0; j<10; j++){
            if(row.at(j) == 'X'){
                if(i==0 || i == 9){
                    count+=1;
                }
            
             else if(i==1 || i==8){
                if(j != 0 && j != 9){
                    count+=2;
                } else {
                    count +=1;
                }
            } else if(i==2 || i==7){
                if(j==0||j==9){
                    count+=1;
                } else if(j==1 || j==8){
                    count+=2;
                } else {
                    count+=3;
                }
            } else if(i==3 || i==6){
                if(j==0||j==9){
                    count+=1;
                } else if(j==1 || j==8){
                    count+=2;
                } else if(j==2 || j==7) {
                    count+=3;
                }else {
                    count+=4;
                }           
            } else if(i==4 || i==5){
                if(j==0||j==9){
                    count+=1;
                } else if(j==1 || j==8){
                    count+=2;
                } else if(j==2 || j==7) {
                    count+=3;
                }else if(j==3 || j==6) {
                    count+=4;
                } else {
                    count+=5;
                }
            }

        }
            
        
    }
    }

    return count;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    std::cin>>t;
    std::string a;
    std::getline(std::cin, a);
    while(t--){
        std::cout<<solve()<<'\n';
    }
    
    return 0;
}