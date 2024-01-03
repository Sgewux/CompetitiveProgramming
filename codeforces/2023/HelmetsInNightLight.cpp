#include <bits/stdc++.h>

struct sort_pred{
    bool operator()(const std::pair<long long, long long>& left, const std::pair<long long, long long>& right){
        return left.second < right.second; //If left one less than, true. if right one less than, false.
    }
};

long long findBreakp(std::vector<std::pair<long long, long long>>& x, long long n, long long p){
    long long s = 0;
    long long e = n-1;
    long long m;

    while (s < e){
        m = (s+e)/2;
        if(x[m].second == p){
            return m;
        } else if (x[m].second < p){
            s = m+1;
        } else if(x[m].second > p){
            e = m-1;
        }
    }

    m = (s+e)/2;

    if(x[m].second > p){
        return m-1;
    } else {
        return m;
    }
}


long long solve(std::vector<std::pair<long long, long long>>& x, long long n, long long p){
    std::sort(x.begin(), x.end(), sort_pred());
    long long t = p;
    if(n == 1){
        return t;
    }

    long long m = findBreakp(x, n, p);
    long long c = 1; //Num of elements already choosen
    long long i = 0;

    while (c<n && i<=m){
        if(c + x[i].first > n){ //Dont take all
            t += x[i].second * (n-c);
            return t;
        } else {
            c+=x[i].first;
            t += x[i].first * x[i].second;
        }
        i++;
    }

    t += p*(n-c);

    return t;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long n;
    long long p;
    long long curr;
    std::vector<std::pair<long long, long long>> x;
    std::cin>>t;

    while(t--){
        std::cin>>n;
        std::cin>>p;
        x.clear();

        for(long long i = 0; i<n; i++){
            std::cin>>curr;
            std::pair<long long, long long>p;
            p.first = curr;
            x.push_back(p);
        }

        for(long long i = 0; i<n; i++){
            std::cin>>curr;
            x[i].second = curr;
        }

        std::cout<<solve(x,n,p)<<'\n';

    }//
    
    return 0;
}