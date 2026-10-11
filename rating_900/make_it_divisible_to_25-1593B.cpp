#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define READVEC(n, v, TN, TV) TN n; cin >> n; vector<TV> v(n); for (TN i = 0; i < n; i++) cin >> v[i];
#define COUT(x) ({ cout << x << endl; return; })
typedef long long ll;
//typedef __int128 i128;

bool many_cases = true;

int min_operations(string n, string possible_value)
{
	int operations = 0;
	int checker_index = possible_value.size() - 1; 

	for (int i = n.size() - 1; i >= 0; i--)
	{
		if (n[i] == possible_value[checker_index])
		{
			checker_index--;
			if (checker_index < 0)
				break;
		}
		else
			operations++;
	}
	if (checker_index >= 0)
		operations = INT_MAX;

	return operations;
}

void solve(){
  string n;
  cin >> n;

  vector<string> possible_values = {"00", "25", "50", "75"};
  int ans = INT_MAX;

  for (auto possible_value : possible_values)
    ans = min(ans, min_operations(n, possible_value));

  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t; while(t--) solve();
  return 0;
}