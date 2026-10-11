#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);

  map<ll,ll> mp;
  ll n;cin >> n;
  for (int i =0;i<n;i++){
    int t;cin>>t;

    if (t == 0){
      ll k, v; cin>> k >> v;
      mp[k] =v;
    }else{
      ll k; cin >> k;
      cout << mp[k] << endl;
    }
  };

  return 0;
}