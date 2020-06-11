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

vi st, a;
int n;

int left(int p){
	return p<<1;
}

int right(int p){
	return (p<<1)+1;
}

void buildmin(int p, int l, int r){
	if(l==r)
		st[p]=l;
	else{
		buildmin(left(p), l, (l+r)/2);
		buildmin(right(p), ((l+r)/2)+1, r);
		int p1=st[left(p)], p2=st[right(p)];
		st[p]=a[p1]<a[p2]?p1:p2;
	}
}

int rmq(int p, int l, int r, int i, int j){
	if(i>r||j<l)
		return -1;
	if(l>=i&&r<=j)
		return st[p];
	int p1=rmq(left(p), l, (l+r)/2, i, j);
	int p2=rmq(right(p), ((l+r)/2)+1, r, i, j);
	if(p1==-1)return p2;
	if(p2==-1)return p1;
	return a[p1]<a[p2]?p1:p2;
}

void updateminimum(int v, int tl, int tr, int pos, int new_val) {
    if (tl != tr) {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            updateminimum(v*2, tl, tm, pos, new_val);
        else
            updateminimum(v*2+1, tm+1, tr, pos, new_val);
		st[v]=st[left(v)]<st[right(v)]?st[left(v)]:st[right(v)];
    } else {
        st[v] = new_val;
    }
}


void updatemin(int p){
	int p1, p2;
	if(left(p)<n)
		p1=st[left(p)];
	else p1=-1;
	if(right(p1)<n)
		p2=st[right(p)];
	else p2=-1;
	if(p1==-1)st[p]=p2;
	if(p2==-1)st[p]=p1;
	if(p1!=-1&&p2!=-1)st[p]=a[p1]<a[p2]?p1:p2;
	if(p!=1)
		updatemin(p/2);
}

void buildsum(int p, int l, int r){
	if(l==r)
		st[p]=a[l];
	else{
		buildsum(left(p), l, (l+r)/2);
		buildsum(right(p), ((l+r)/2)+1, r);
		int p1, p2;
		p1=st[left(p)];
		p2=st[right(p)];
		st[p]=p1+p2;
	}
}

int rsq(int p, int l, int r, int i, int j){
	if(i>r||j<l)
		return -1;
	if(l>=i&&r<=j)
		return st[p];
	int p1=rsq(left(p), l, (l+r)/2, i, j);
	int p2=rsq(right(p), ((l+r)/2)+1, r, i, j);
	if(p1==-1)return p2;
	if(p2==-1)return p1;
	return p1+p2;
}

void updatesum(int p){
	int p1, p2;
	if(left(p)<n)
		p1=st[left(p)];
	else p1=-1;
	if(right(p1)<n)
		p2=st[right(p)];
	else p2=-1;
	if(p1==-1)st[p]=p2;
	if(p2==-1)st[p]=p1;
	if(p1!=-1&&p2!=-1)
	if(p!=-1&&p2!=-1)st[p]=p1+p2;
	if(p>1)
		updatesum(p/2);
}

//Updates with deletions and Insertions.

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl != tr) {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
		st[v]=st[left(v)]+st[right(v)];
    } else {
        st[v] = new_val;
    }
}


//Searching for the first element greater than a given amount

int get_first(int v, int lv, int rv, int l, int r, int x) {
    if(lv > r || rv < l) return -1;
    if(l <= lv && rv <= r) {
        if(st[v] <= x) return -1;
        while(lv != rv) {
            int mid = lv + (rv-lv)/2;
            if(st[2*v] > x) {
                v = 2*v;
                rv = mid;
            }else {
                v = 2*v+1;
                lv = mid+1;
            }
        }
        return lv;
    }

    int mid = lv + (rv-lv)/2;
    int rs = get_first(2*v, lv, mid, l, r, x);
    if(rs != -1) return rs;
    return get_first(2*v+1, mid+1, rv, l ,r, x);
}




int main(){
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);*/
	int cas=1;
	while(1){
		cin>>n;
		if(n==0)
			break;
		a.resize(n+1);
		st.resize(4*n);
		loop(i, 1, n+1){
			scanf("%d", &a[i]);
		}
		buildsum(1, 1, n);
		if(cas!=1)
			printf("\n");
		printf("Case %d:\n", cas);
		while(1){
			getchar();
			char s[10];
			scanf("%s", s);
			if(s[0]=='E')
				break;
			else if(s[0]=='M'){
				int i, j;
				scanf("%d %d", &i, &j);
				printf("%d\n",rsq(1, 1, n, i, j));
			}
			else{
				int i, j;
				scanf("%d %d", &i, &j);
				update(1, 1, n, i, j);
			}
		}
		++cas;
	}
	return 0;
}