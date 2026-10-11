#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);

  set<ll> s;
  ll n;cin >> n;
  ll x;
  for (int i =0;i<n;i++){
    cin>>x;
    s.insert(x);
  };

  cout << s.size();

  return 0;
}