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
  int n; cin >> n;
  vector<ll> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  ll count_seq=0;
  bool in_seq = false;
  
  for(int i=0;i<n;i++){
    if(a[i] == 0){
      in_seq = false;
    }else{
      if(a[i] !=0 ){
        if(!in_seq){
          in_seq = true;
          count_seq++;
        }
      }
    }
  }

  if(count_seq == 0){
    COUT(0);
  }else if(count_seq == 1){
    COUT(1);
  }else{
    COUT(2);
  }
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}