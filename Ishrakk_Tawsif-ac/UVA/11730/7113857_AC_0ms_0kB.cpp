#include<bits/stdc++.h>
using namespace std;

int prime[171],in,visited[2003],des[1003];
vector <int> prime_fact[1003];
bitset <1003> isprime;


void sieve(){

    isprime[0] = isprime[1] = 1;
        for(int i=4; i<1003; i+=2) isprime[i] = 1;

            for(int i=3; i*i<1003; i+=2){
                if(!isprime[i]){
                    for(int j=i*i; j<1003; j+=i) isprime[j] = 1;
                }
            }
            in=-1;
                for(int i=0; i<1000; i++){
                    if(!isprime[i]) prime[++in]=i;
                }//cout<<in<<endl;
}

void prime_gen(){
    prime_fact[7].clear();
    for(int n=1; n<=1000; n++){
        int temp=n;
        for(int i=0; prime[i]*prime[i]<=temp && i<=in; i++){
            if(temp%prime[i] == 0){
                prime_fact[n].push_back(prime[i]);
                    while((temp%prime[i]) == 0) temp/= prime[i];
            }
        }
        if(temp!=1 && n!=temp) prime_fact[n].push_back(temp);
    }
}

int bfs(int source, int destination){

    for(int i=0; i<1003; i++){visited[i]=0; des[i]=INT_MAX;}

        queue <int> q;
        visited[source]=1;
        des[source]=0;
        q.push(source);

            while(!q.empty()){
                int temp = q.front(); q.pop();

                    if(temp == destination) return des[temp];

                    for(int i=0; i<prime_fact[temp].size(); i++){
                        int t=temp + prime_fact[temp][i];

                            if(/*!isprime[t] && */visited[t]==0 && t<=destination){
                                visited[t]=1;
                                des[t] = des[temp] + 1;
                                q.push(t);
                            }
                    }
            }
      return -1;
}

int main(){
    sieve();
    prime_gen();

        int testcase,s,d,i;
        i=0;
            //scanf("%d", &testcase);
                //for(int i=1; i<=testcase; i++){
                while(scanf("%d %d", &s, &d) == 2 && s && d){
                    printf("Case %d: %d\n", ++i, bfs(s,d));
                }
}