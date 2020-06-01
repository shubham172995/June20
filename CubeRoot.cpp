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

#include<bits/stdc++.h>
using namespace std;

float abso(float num){
    return num>0?num:-num;
}

int main(){
    int n;
    bool flag=false; //In case the number is negative, flag will be set to indicate that.
    printf("Enter the number you want to find the cube root of.\n");
    scanf("%d", &n); //Assuming the number fits the int range.
    if(n<0){
        n*=-1;
        flag=true;
    }
    //I will try to run a simulation to bring the answer close to cube root within 3 places of decimal accuracy
    //And, for that, I am trying the Binary Search for answer technique. We can opt for ternary or quaternary
    //search also but no big difference in complexity since only constant because of base change will be changed.
    float diff=0.001, low=0.000, up=n+0.000, mid=0.000;
    while(1){
        mid=(low+up)/2.000;
        float temp=mid*mid*mid+0.000;
        if(abso(temp-n)<=diff)
            break;
        if(temp>n)
            up=mid;
        else if(temp<n)
            low=mid;
    }
    if(flag){
        printf("-%.3f\n", mid);
    }
    else printf("%.3f\n", mid);
    return 0;
}
