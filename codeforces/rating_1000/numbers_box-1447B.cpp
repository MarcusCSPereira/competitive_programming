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
  int n, m; cin >> n >> m;
  int negative_count = 0;
  int min_abs_value = INT_MAX;
  int all_sum = 0;
  for(int r=0;r<n;r++){
    for(int c=0; c<m; c++){
      int value; cin >> value;
      all_sum += abs(value);
      min_abs_value = min(min_abs_value, abs(value));
      if(value < 0){
        negative_count++;
      }
    }
  }

  if (negative_count % 2 ==0){
    COUT(all_sum);
  }else{
    COUT(all_sum - 2*min_abs_value);
  }
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}