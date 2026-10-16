#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;
//typedef __int128 i128;

bool many_cases = true;

void solve(){
  ll a, b; cin >> a >> b;
  if(b > a){
    swap(a,b);
  }
  if(a == b){
    cout << "0" << " " << "0" << endl;
  }else{
    ll gcd = a-b;
    ll moves = min(b%gcd, gcd - b % gcd);
    cout << gcd << " " << moves << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}