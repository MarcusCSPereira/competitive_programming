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
  int n , k; cin >> n >> k;
  string s; cin >> s;
  map<char, int> freq;
  for(int i=0;i<n;i++){
    freq[s[i]]++;
  }
  int odd_freq=0;
  for(pair<char,int> p : freq){
    if(p.second % 2 !=0){
      odd_freq++;
    }
  }
  if(odd_freq > k+1){
    cout << "NO" << endl;
  }else{
    cout << "YES" << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}