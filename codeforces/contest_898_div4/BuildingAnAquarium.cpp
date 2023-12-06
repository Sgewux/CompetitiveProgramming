#include <bits/stdc++.h>

long double solve(long long x, std::vector<long long>& h, std::unordered_map<long long, std::pair<long long, long long>>& q, long long n){
    long long s = 0;
    long long e = h.size() - 1;
    long long m;
    long long w;

    if(h.size() == 1){ //All same length
        return h[0] + (x/n);
    }

    while (s < e){
        m = (s+e)/2;
        w = h[m] * q[h[m]].first - q[h[m]].second;
        if(w == x){
            return h[m];
        } else if(w < x){
            s = m+1;
        } else if(w > m){
            e = m-1;
        }
    }

    m = (s+e)/2;
    w = h[m]*q[h[m]].first - q[h[m]].second;

    if(w>x){ //If binary search found UpperBound
        m--;
        w = h[m]*q[h[m]].first - q[h[m]].second;
    }

    if(m != 0){
        if(m == h.size()-1){
            return h[m] + ( (x-w)/(n) );
        } else {
            return h[m] + ((x-w) / q[h[m+1]].first);
        }
    } else {
        return h[0] + x/q[h[1]].first;
    }
    
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    std::cin>>t;

    while(t--){
        long long n;
        long long x;
        std::cin>>n;
        std::cin>>x;
        long long curr;
        long long lastSeen;
        long long k = 0;
        long long j = 0;
        std::vector<long long> a; //Raw
        std::vector<long long>h; //Sorted and wihtout reps
        std::unordered_map<long long, std::pair<long long, long long>> q; //h: k,j

        for(long long i = 0; i<n; i++){
            std::cin>>curr;
            a.push_back(curr);
        }
        std::sort(a.begin(), a.end());

        lastSeen = -1;
        for(long long i : a){
            if(i != lastSeen){
                h.push_back(i);
                std::pair<long long, long long>p;
                p.first = k;
                p.second = j;
                q[i] = p;
                lastSeen = i;
            }
            k++;
            j+=i;
        }

        std::cout<<std::fixed<<std::setprecision(0)<< std::floor(solve(x, h, q, n)) <<'\n';

    }
    
    return 0;
}