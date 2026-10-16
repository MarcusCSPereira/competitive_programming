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
  ll start, jumps;
	cin >> start >> jumps;

	ll final_pos;

  if (jumps % 4 == 1)
    final_pos = -jumps; // If jumps % 4 == 1, move left by 'jumps'
  else if (jumps % 4 == 2)
    final_pos = 1; // If jumps % 4 == 2, move right by 1
  else if (jumps % 4 == 3)
    final_pos = jumps + 1; // If jumps % 4 == 3, move right by 'jumps + 1'
  else if (jumps % 4 == 0)
    final_pos = 0; // If jumps % 4 == 0, no net movement

  // Adjust the final position based on the parity of the starting position
  if (start % 2 == 0)
    final_pos = start + final_pos; // If starting position is even, add the calculated position
  else
    final_pos = start - final_pos; // If starting position is odd, subtract the calculated position

  cout << final_pos << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}