#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);

  ll n; cin >> n;
  vector<ll> v(n);
  for(ll &i : v) cin >> i;

  sort(v.rbegin(),v.rend());

  ll sum = 0;
  for(int i = 0; i<n;i++){
    if(i%3 == 2){
      sum+= v[i];
    }
  }

  cout << sum;

  return 0;
}