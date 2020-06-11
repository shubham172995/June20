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


//								STARTS HERE	

vi p, ranks;

void CreateSet(int n){
	ranks.resize(n);
	p.resize(n);
	loop(i, 0, n){
		p[i]=i;
	}
}

int FindSet(int i){
	return p[i]==i?i:(p[i]=FindSet(p[i]));
}

bool isSameSet(int x, int y){
	return FindSet(x)==FindSet(y);
}

void unionSet(int x, int y){
	if(!isSameSet(x, y)){
		int px=FindSet(x), py=FindSet(y);	//Path Compression.
		if(ranks[px]>ranks[py])
			p[py]=px;
		else{
			p[px]=py;
			ranks[py]=ranks[px]==ranks[py]?ranks[py]+1:ranks[py];
		}
	}
}

/*
Path compression in Find_set.
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
*/

int numDisjointSets(){
	int num=0;
	loop(i, 0, p.size()){
		if(p[i]==i)
			++num;
	}
	return num;
}

int sizeOfSet(int i){
	int siz=0;
	int par=FindSet(i);
	loop(j, 0, p.size()){
		if(par==FindSet(j))
			++siz;
	}
	return siz;
}

int main(){
    int n, m;
    CreateSet(101);
    scanf("%d %d", &n, &m);
    int k;
    int count=0;
    vi visited(101);
    vector<vi> a(n);
    loop(i, 0, n){
        cin>>k;
        if(k==0)
            ++count;
        a[i].resize(k);
        loop(j, 0, k){
            int temp;
            cin>>temp;
            a[i][j]=temp;
            visited[a[i][j]]=1;
        }
        loop(j, 0, k){
            loop(idx, j+1, k){
                unionSet(a[i][j], a[i][idx]);
            }
        }
    }
    /*loop(i, 0, n)
    loop(j, 0, k){
        loop(idx, j+1, k){
            unionSet(a[i][j], a[i][idx]);
        }
    }
    loop(i, 1, m+1){
        cout<<i<<" HEY "<<ranks[i]<<" "<<p[i]<<endl;
    }*/
    bool flag=false;
    vector<bool> check(101);
    loop(i, 0, 101){
        if(visited[FindSet(i)]&&!check[FindSet(i)]){
            ++count;
            check[FindSet(i)]=1;
            flag=1;
        }
    }
    if(!flag){
        cout<<count<<endl;
    }
    else cout<<count-1<<endl;
    return 0;
}