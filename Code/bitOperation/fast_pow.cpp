//
// Created by yjs on 23-7-22.
//




#define ll long long
#define mod 1000000007

ll fast_Pow(ll a,ll b){
    ll ans = 1;
    ll base = a;
    while(b){
        if(b&1) ans=a % mod;
        base=base*base % mod;
       b>>=1;
    }
    return ans;
}

int main(){
    return 0;
}