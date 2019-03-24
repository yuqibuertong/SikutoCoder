#include <bits/stdc++.h>
using namespace std;

int n;
long long dp[31][1<<3];
bool ins[1<<3];

void read_and_parse(){
	memset(ins,0,sizeof(ins));
	for(int i=0;i<1<<3;i++){
		bool has_odd=0,cnt=0;
		for(int j=0;j<3;j++){
			if((i>>j&1)==1)has_odd|=cnt,cnt=0;
			else cnt^=1;
		}
		if(!has_odd&&!cnt)ins[i]=1;
	}
}

void solve(){
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<1<<3;j++){
			dp[i][j]=0;
			for(int k=0;k<1<<3;k++)if(!(k&j)&&ins[k|j])
				dp[i][j]+=dp[i-1][k];
		}
	printf("%lld\n",dp[n][0]);
}

int main(){
	while(scanf("%d",&n)&&~n){
		read_and_parse();
		solve();
	}
	return 0;	
}
