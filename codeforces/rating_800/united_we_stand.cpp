#include <bits/stdc++.h>
#include <iterator>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;
//typedef __int128 i128;
const int tam_limit = 1e5 + 1;

bool many_cases = true;

void solve(){
  READVEC(n, a, ll, ll);
  vector<ll> b,c;
  sort(a.begin(), a.end());
  ll b_num = a[0];
  for(int i=0;i<n;i++){
    if(b_num % a[i] == 0){ // É divisivel
      b.push_back(a[i]);
      b_num = a[i];
    }else{
      c.push_back(a[i]);
    }
  }
  if(b.size() == 0 || c.size() == 0){
    cout <<  -1 << endl;
  }else{
    cout << b.size() <<  " " << c.size() << endl;
    for(int i=0;i<b.size();i++){
      if(i == b.size()-1){
        cout << b[i] << endl;
      }else{
        cout << b[i] << " ";
      }
    }
    for(int i=0;i<c.size();i++){
      if(i == c.size()-1){
        cout << c[i] << endl;
      }else{
        cout << c[i] << " ";
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}