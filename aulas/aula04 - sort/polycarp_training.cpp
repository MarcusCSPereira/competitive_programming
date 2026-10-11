#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);

  ll n; cin >> n;
  vector<ll> v(n);
  for(auto &i : v) cin >> i;

  sort(v.begin(), v.end()); // O(n log n)
  ll sum = 1;
  for(ll i =0; i<n; i++){
    if(v[i] >= sum){
      sum++;
    }
  }

  cout << sum - 1;

  return 0;
}