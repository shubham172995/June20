#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)
#define pool(i, a, b) for(int i=a;i>b;i--)
#define pooll(i, a, b) for(ll i=a;i>b;i--)

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		vector<int> a(n);
		loop(i, 0, n){
			cin>>a[i];
		}
		int len=0;
		loop(i, 0, n){
			stack<int> s;
			int temp=1;
			bool flag=false;
			int j=i+1;
			s.push(a[i]);
			while(s.size()&&j!=n){
				if(flag && s.top()==a[j]){
					++temp;
					s.pop();
					++j;
				}
				else if(flag && s.top()!=a[j])
					++j;
				else if(!flag && s.top()==a[j]){
					s.push(a[j]);
					++temp;
					++j;
				}
				else if(!flag && s.top()!=a[j]){
					map<int, int> m;
					int max=0;
					while(j<n){
						if(a[j]==s.top()){
							flag=true;
							break;
						}
						++m[a[j]];
						max=max>m[a[j]]?max:m[a[j]];
						++j;
					}
					if(flag)
						temp+=max;
				}
			}
			if(flag)
				temp-=s.size();
			len=len>temp?len:temp;
		}
		cout<<len<<endl;
	}
	return 0;
}