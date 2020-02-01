#include<bits/stdc++.h>
using namespace std;

#define mx 1005

bitset <mx> isprime;
int prime[mx];

void sieve(){

    isprime[0]=isprime[1]=1;
        for(int i=4; i<mx; i+=2) isprime[i]=1;
            for(int i=3; i<mx; i+=2){
                if(!isprime[i]){
                    for(int j=i*i; j<mx; j+=i) isprime[j]=1;
                }
            }
            int in=-1;
            for(int i=0; i<mx; i++){
                if(!isprime[i]) prime[++in]=i;
            }//cout << in << endl;
}

vector <int> v[mx];
void prime_gen(){
    for(int i=2; i<mx; i++){
        int temp=i;

            for(int j=0; prime[j]*prime[j]<=temp; j++){
                if(temp%prime[j] == 0){
                    v[i].push_back(prime[j]);
                    while(temp%prime[j] == 0) temp/=prime[j];
                }
            }
            if(temp!=1 && temp!=i) v[i].push_back(temp);
    }
}

int bfs(int sr, int des){
//cout << sr << " " << des << endl;
    int dis[mx],vis[mx];
    for(int i=0; i<mx; i++){
        dis[i]=0; vis[i]=0;
    }

        queue<int>q;
        q.push(sr);
        vis[sr]=1;
        dis[sr]=0;

            while(!q.empty()){
                int frnt = q.front(); q.pop();//cout << frnt << endl;
                    if(frnt == des) return dis[frnt];

                    for(int i=0; i<v[frnt].size(); i++){
                        int tt = frnt+v[frnt][i];//cout << tt << endl;

                            if(tt<=des && vis[tt]==0){
                                dis[tt]=dis[frnt]+1;
                                vis[tt]=1;
                                q.push(tt);
                            }
                    }
            }
 return -1;
}

int main(){
    sieve();
    prime_gen();//for(int i=0; i<v[9].size(); i++) cout << v[9][i] << endl;

        int src,des,testcase;
        scanf("%d", &testcase);
            for(int tt=1; tt<=testcase; tt++){
                scanf("%d %d", &src, &des);
                cout << "Case " << tt << ": " << bfs(src,des) << endl;
            }
return 0;
}