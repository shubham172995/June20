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
		int n, x;
		cin>>n>>x;
		vi a(n);
		int od=0, ev=0;
		loop(i, 0, n){
			cin>>a[i];
			od=(a[i]%2)!=0?od+1:od;
			ev=(a[i]%2)==0?ev+1:ev;
		}
		if(od==0){
			cout<<"No\n";
			continue;
		}
		else if(ev==0&&x%2==0){
			cout<<"No\n";
			continue;
		}
		else{
			if(x%2==0){
				if(ev>=x){
					cout<<"Yes\n";
					continue;
				}
				else{
					ev=(ev%2)==0?ev-1:ev;
					if(od+ev>=x){
						cout<<"Yes\n";
						continue;
					}
				}
			}
			else{
				if(ev>=x){
					cout<<"Yes\n";
					continue;
				}
				else{
					ev=(ev%2)==0?ev:ev-1;
					if(od+ev>=x){
						cout<<"Yes\n";
						continue;
					}
				}
			}
		}
		cout<<"No\n";
	}
	return 0;
}
