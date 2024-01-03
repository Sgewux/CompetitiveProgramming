#include<iostream>

void solve(){
    
    long long nQueries;
    std::cin>>nQueries;
    
    char * answer = new char[nQueries+1];

    long long first;
    std::cin>>first;
    *answer = '1';
    bool pivot = false;
    long long lastAdded = first;
    long long current;


    for(long long i = 1; i < nQueries; i++){
        std::cin>>current;

        if(pivot){

            if(current>=lastAdded && current<=first){
                //std::cout<<"1";
                *(answer+i) = '1';
                lastAdded = current;
            }else {
                //std::cout<<"0";
                *(answer+i) = '0';
            }

        } else {

            if(current<lastAdded){
                if(current<=first){
                    pivot = true;
                    //std::cout<<"1";
                    *(answer+i) = '1';
                    lastAdded = current;
                } else {
                    //std::cout<<"0";
                    *(answer+i) = '0';
                }
            } else {
                //std::cout<<"1";
                *(answer+i)='1';
                lastAdded = current;
            }

        }


    }
    *(answer+nQueries) = '\0';
    std::cout<< answer << std::endl;
    delete answer;

}

int main(){
    long long nTests;
    std::cin>>nTests;
    
    for(long long i  = 0; i < nTests; i++){
        solve();
    }
    return 0;
}