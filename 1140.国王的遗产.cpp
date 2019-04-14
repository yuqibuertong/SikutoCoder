#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define cls(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int maxn=3e4+10;
const double eps=1e-6;
inline ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
inline ll sqr(ll x){return x*x;}
inline ll fpow(ll a,ll b,ll c){ll ret=1%c;for(;b;b>>=1,a=a*a%c)if(b&1)ret=ret*a%c;return ret;}
inline ll read(){
	ll x=0,f=1;char ch;
	do{ch=getchar();if(ch=='-')f=-1;}while(!isdigit(ch));
	do{x=x*10+ch-'0';ch=getchar();}while(isdigit(ch));
	return f*x;
}

vector<int> G[maxn];
int n,m,root,sz[maxn],id[maxn],f[maxn],ans[101];
bool del[maxn];

void read_and_parse(){
	n=read(),m=read();
	for(int i=1,x,y;i<n;i++){
		x=read(),y=read();
		G[x].pb(y),G[y].pb(x);
	}
}

void get(int u,int fa){
	sz[u]=1,id[u]=u,f[u]=fa;
	for(auto v:G[u]){
		if(v==fa||del[v])continue;
		get(v,u);
		sz[u]+=sz[v];
		id[u]=min(id[u],id[v]);
	}
}
void dfs(int u,int fa,int res){
	del[u]=1;
	for(auto v:G[u]){
		if(v==fa||del[v]||v==res)continue;
		dfs(v,u,res);
	}
}

void solve(){
	ans[m]=n;
	for(int idx=1;idx<m;idx++){
		root=1;
		while(del[root])++root;
		get(root,0);
		int res,mx=0,mi=inf;
		for(int i=1;i<=n;i++){
			if(i==root||del[i])continue;
			int t1=sz[root]-sz[i];
			int t2=sz[i];
			if(t1==t2){
				mx=t1,mi=root,res=i;
				break;
			}
			if(t1>mx&&t1*2<=sz[root]){
				mx=t1,mi=root,res=i;
			}
			if(t2>=mx&&t2*2<=sz[root]){
				if(t2==mx&&id[i]<mi)mi=id[i],res=i;
				else if(t2>mx)res=i,mx=t2,mi=id[i];
			}
		}
		if(sz[res]>=sz[root]-sz[res]){
			ans[idx]=sz[root]-sz[res];
			dfs(root,0,res);
		}else{
			ans[idx]=sz[res];
			dfs(res,f[res],f[res]);
		}
		ans[m]-=ans[idx];
	}
	for(int i=1;i<=m;i++)printf("%d%c",ans[i],i==m?'\n':' ');
}
int main(){
	read_and_parse();
	solve();
	return 0;
}
Download as text 
