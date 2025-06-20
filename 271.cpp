#include <bits/stdc++.h>
using namespace std;
 
#define all(v) v.begin(), v.end()
 
typedef long long ll;
 
const int INF = 1e9 + 7;

uint64_t modexp(uint64_t b, uint64_t e, uint64_t m){
    uint64_t r = 1;
    b %= m;
    while(e){
        if(e & 1) r = (__uint128_t)r * b % m;
        b = (__uint128_t)b * b % m;
        e >>= 1;
    }
    return r;
}

class Solution {
    uint64_t n, e, d;
public:
    Solution(){
        uint64_t p = 61, q = 53;
        n = p * q;
        uint64_t phi = (p - 1) * (q - 1);
        e = 17;
        for(uint64_t x = 1; x < phi; ++x)
            if((e * x) % phi == 1){
                d = x;
                break;
            }
    }

    string encode(vector<string>& strs){
        ostringstream out;
        out << strs.size() << '|';
        for(size_t i = 0; i < strs.size(); ++i){
            const auto& s = strs[i];
            for(size_t j = 0; j < s.size(); ++j){
                uint64_t m = static_cast<unsigned char>(s[j]);
                uint64_t c = modexp(m, e, n);
                out << c;
                if(j + 1 < s.size()) out << ' ';
            }
            if(i + 1 < strs.size()) out << '|';
        }
        return out.str();
    }

    vector<string> decode(const string& s){
        vector<string> res;
        istringstream in(s);
        size_t count; char sep;
        in >> count >> sep;
        for(size_t i = 0; i < count; ++i){
            string block; 
            if(!getline(in, block, '|')) block.clear();
            istringstream bs(block);
            string num, decoded;
            while(bs >> num){
                uint64_t c = stoull(num);
                uint64_t m = modexp(c, d, n);
                decoded += char(m);
            }
            res.push_back(decoded);
        }
        return res;
    }
};

signed main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef LOCAL
        freopen("a.in", "r", stdin);
    #endif
    Solution object;
    exit(EXIT_SUCCESS);
}