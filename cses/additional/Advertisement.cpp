#include <bits/stdc++.h>

template<typename T>
class StaticStack{
    private:
        long long size;
        long long top = 0;
        T* arr = nullptr;

    public:
        StaticStack(long long size){
            this->size = size;
            this->arr = new T[this->size];
        }

        ~StaticStack(){
            delete[] this->arr;
        }

        bool empty(){
            return top == 0;
        }

        bool push(T element){
            if(top < size) {
                *(arr + top) = element;
                top++;
                return true;
            } else {
                return false;
            }
        }

        T getTop(){
            if(top > 0){
                T toReturn = *(arr + top - 1);
                return toReturn;
            } else {
                throw std::length_error("The Stack is empty");
            }
        }

        void pop(){
            if(top > 0){
                top--;
            } else {
                throw std::length_error("The Stack is empty");
            }
        }
};

void solve(){
    long long n;
    long long curr;
    std::cin>>n;
    StaticStack<std::pair<long long, long long>> s(n);
    long long ans = -1;

    for(long long i = 0; i<n; i++){

        std::cin>>curr;

        long long startsFrom = i;
        while(!s.empty() && s.getTop().first >= curr){
            std::pair<long long, long long> former = s.getTop();
            s.pop();

            ans = std::max(ans, former.first * (i - former.second));
            startsFrom = former.second;
        }

        s.push({curr, startsFrom});
    }

    while(!s.empty()){
        ans = std::max(ans, s.getTop().first * (n - s.getTop().second));
        s.pop();
    }

    std::cout<<ans;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t = 1;
    

    while(t--){
        solve();
    }

    return 0;
}