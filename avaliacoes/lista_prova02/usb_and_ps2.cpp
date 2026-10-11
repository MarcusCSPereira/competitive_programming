#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl;
typedef long long ll;

void solve(){
  int usb, ps2, both;cin >> usb >> ps2 >> both;
  int m; cin >> m;
  vector<ll> vu; 
  vector<ll> vp;

  for(int i=0; i<m; i++){
    ll val; cin >> val;
    string type; cin >> type;
    if(type == "USB") vu.push_back(val);
    else vp.push_back(val);
  }

  sort(vu.begin(), vu.end()); sort(vp.begin(), vp.end());

  ll cost=0;
  ll pc=0;
  int usb_used=0;
  for(int i=0; i<(int)vu.size() && usb > 0; i++){
    cost += vu[i];
    pc++;
    usb--;
    usb_used++;
  }
  vu.erase(vu.begin(), vu.begin()+usb_used);

  int ps2_used=0;
  for(int i=0; i<(int)vp.size() && ps2 > 0; i++){
    cost += vp[i];
    pc++;
    ps2--;
    ps2_used++;
  }
  vp.erase(vp.begin(), vp.begin()+ps2_used);

  vector<ll> vb = vu;
  vb.insert(vb.end(),vp.begin(),vp.end());
  sort(vb.begin(),vb.end());
    for(int i=0; i<vb.size() && both > 0; i++){
    cost += vb[i];
    pc++;
    both--;
  }

  cout << pc << " " << cost;

}

bool many_cases = false;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  ll t = 1;
  if(many_cases) cin >> t;
  while(t--) solve();
  return 0;
}