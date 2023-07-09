#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_set>
#include<utility>


std::string printPalindrome(const std::string &line){
    std::unordered_set<char> counts;
    char* oddCharRepPtr = nullptr;
    std::string left = "";
    std::string right = "";
    std::string middle = "";

    
    if(line.length() % 2 == 0){ //Even length
        for(char c : line){

            if(counts.count(c) == 0){
                size_t cCount = std::count(line.begin(), line.end(), c);

                if(cCount % 2 != 0){
                    return "NO SOLUTION";
                } else {
                    counts.insert(c);
                    left.insert(left.end(), cCount /2, c);
                    right.insert(right.begin(), cCount /2, c);
                }
            
            } 
        }
    
    } else { //odd lenght

        // Odd lenght must have one and only one odd character

        for(char c : line){

            if(counts.count(c) == 0 && !(oddCharRepPtr && c == *oddCharRepPtr) ){
                size_t cCount = std::count(line.begin(), line.end(), c);

                if( (cCount % 2 != 0)){

                    if(!oddCharRepPtr){
                        char n;
                        n = c;
                        oddCharRepPtr = &n;
                        middle.insert(middle.end(), cCount, c);                       
                    
                    } else {
                        return "NO SOLUTION";
                    } 
                
                } else if (cCount % 2 == 0){
                    counts.insert(c);
                    left.insert(left.end(), cCount /2, c);
                    right.insert(right.begin(), cCount /2, c);
                }
            
            }
        }     

    }

    return left + middle + right;
}

int main(){
    std::string line;
    std::getline(std::cin, line);

    std::cout << printPalindrome(line);
    return 0;
}