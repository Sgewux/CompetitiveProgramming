#include<numeric>
#include<iostream>
#include<iterator>
#include<vector>
#include<unordered_set>

void division(long long n){
    if( ((n*(n+1))/2 ) % 2 == 0){
        std::cout << "YES" << std::endl;
        
        std::unordered_set<long long> a;
        std::unordered_set<long long> b;

        if(n%2 == 0){
            long long i = 1;
            long long l = 0;

            while (i<n){

                if(l%2 != 0){
                    a.insert(i);
                    b.insert(i+1);
                } else {
                    a.insert(i+1);
                    b.insert(i);
                }
                l++;
                i = i +2;
            }

            std::cout << n/2 << std::endl;
            for(auto e:a){
                std::cout << e << " " ;
            }
            std::cout << std::endl;

            std::cout << n/2 << std::endl;
            for(auto e:b){
                std::cout << e << " " ;
            }

        } else {


            a.insert(1);
            a.insert(2);
            b.insert(3);

            long long i = 4;
            long long l = 0;

            while (i<n){

                if(l%2 != 0){
                    a.insert(i);
                    b.insert(i+1);
                } else {
                    a.insert(i+1);
                    b.insert(i);
                }
                l++;
                i = i +2;
            }

            std::cout << (n-1)/2 + 1 << std::endl;
            for(auto e:a){
                std::cout << e << " " ;
            }
            std::cout << std::endl;

            std::cout << (n-1)/2 << std::endl;
            for(auto e:b){
                std::cout << e << " " ;
            }
        }

  
    } else {
        std::cout << "NO";
    }
}

int main(){
    long long n;

    std::cin>>n;
    division(n);
    return 0;
}