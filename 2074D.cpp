#include<bits/stdc++.h>
using namespace std;
using ll=long long;
 
int main()
{
    int t;cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,m;cin>>n>>m;
        map<ll,ll>cnt;
        auto isqrt=[&](ll x)
        {
            ll val=sqrtl(x)+5;
            while(val*val>x)val--;
            return val;
        };
        vector<ll>a(n),r(n);
        for(ll&i:a)cin>>i;
        for(ll&i:r)cin>>i;
        for(int i=0;i<n;i++)
        {
            ll aa=a[i],rr=r[i];
            for(ll x=aa-rr;x<=aa+rr;x++)
            {
                cnt[x]=max(cnt[x],2*isqrt(rr*rr-(x-aa)*(x-aa))+1);
            }
        }
        ll ans=0;
        for(auto[x,c]:cnt)ans+=c;
        cout<<ans<<"\n";
    }
}