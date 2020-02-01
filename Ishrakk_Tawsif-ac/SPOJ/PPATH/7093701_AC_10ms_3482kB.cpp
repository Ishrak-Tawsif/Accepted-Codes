#include<bits/stdc++.h>
using namespace std;

#define mx 10000

bitset <mx> isprime;
int arr[] = {0,1,2,3,4,5,6,7,8,9};

void sieve(){

    isprime[0] = isprime[1] = 1;

        for(int i=4; i<mx; i+=2) isprime[i]=1;
            for(int i=3; i*i<mx; i+=2){
                if(!isprime[i]){
                    for(int j=i*i; j<mx; j+=i) isprime[j]=1;
                }
            }
}

int num_convert(int num, int pos, int val){

    int d=num%10; num/=10;
    int c=num%10; num/=10;
    int b=num%10; num/=10;
    int a=num%10; num/=10;

        if(pos == 1) return val*1000 + b*100 + c*10 + d;
        else if(pos == 2) return a*1000 + val*100 + c*10 + d;
        else if(pos == 3) return a*1000 + b*100 + val*10 + d;
        else if(pos == 4) return a*1000 + b*100 + c*10 + val;
}

int bfs(int sr, int des){

    bool visited[10000];
    int dis[10000];

        for(int i=1000; i<10000; i++){
            visited[i]=0; dis[i]=INT_MAX;
        }

        queue <int> q;
        visited[sr]=1; dis[sr]=0;
        q.push(sr);

            while(!q.empty()){
                int temp = q.front(); q.pop();
                int diff=0,t=temp,t1;

                    for(int i=0; i<10; i++){
                        for(int j=1; j<=4; j++){
                                int t1 = num_convert(temp,j,i);
                                    if(t1>=1000 && t1<=9999 && !isprime[t1] && visited[t1] == 0){
                                        dis[t1] = dis[temp]+1;
                                        visited[t1]=1;
                                        q.push(t1);
                                    }
                        }
                    }
            }

    return dis[des];
}

int main(){
    sieve();
        int s,d,testcase;

            scanf("%d", &testcase);

                while(testcase--){
                    scanf("%d %d", &s, &d);
                    cout << bfs(s,d) << endl;
                }
return 0;
}