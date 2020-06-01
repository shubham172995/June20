#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pool(i, a, b) for(int i=a;i>b;i--)
#define pooll(i, a, b) for(ll i=a;i>b;i--)
#define pb push_back
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef pair<ll, ll> llll;
typedef vector<llll> vll;
typedef vector<pair<int, ii> > EdgeList; //Edgelist representation of graphs to store an edge and weights for both directions, i.e., in an undirected graph.x

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		string s;
		cin>>s;
		int n=s.length();
		int suf1=0, suf0=0, pref1=0, pref0=0;
		int ans=INT_MAX;
		loop(i, 0, n){
			suf1+=s[i]=='1'?1:0;
			suf0+=s[i]=='0'?1:0;
		}
		ans=min(suf0, suf1);
		loop(i, 0, n){
			pref0+=s[i]=='0'?1:0;
			suf0-=s[i]=='0'?1:0;
			pref1+=s[i]=='1'?1:0;
			suf1-=s[i]=='1'?1:0;
			ans=min(ans, pref1+suf0);	//Cost of making a string of the form 000...111... , i.e., starting from this index, cost will be sum of converting all 1's prior to this index to 0 plus cost of converting all 0's after this index to 1's.
			ans=min(ans, pref0+suf1);	//Cost of making a string of the form 111...000...
		}
		cout<<ans<<endl;
	}
	return 0;
}

