///unsolved

#include<bits/stdc++.h>
using namespace std;

#define mx 1000005

bool isprime[mx];
int prime[mx],in,cnt_arr[1200];

void sieve(){

    isprime[0]=isprime[1]=true;
    for(int i=4; i<mx; i+=2) isprime[i]=true;

        int len = sqrt(mx);
        for(int i=3; i<len; i += 2){
            if(!isprime[i]){
                for(int j=i*i; j<mx; j += i) isprime[j]=true;
            }
        }

        in=-1;
        for(int i=0; i<mx; i++){
            if(!isprime[i]) prime[++in]=i;
        }
        //cout << in << endl;
}

int main(){
    sieve();

        int l,h,testcase,i,start,dis,fl,fll,cnt;

            scanf("%d", &testcase);

                while(testcase--){
                    scanf("%d %d", &l,&h);
                    fl=1;fll=0;cnt=0;

                    vector <int> p;
                        memset(cnt_arr,0,sizeof(cnt_arr));

                        for(int i=l; i<=h; i++){
                            if(!isprime[i]) p.push_back(i);
                        }

                            if(p.size()<2) printf("No jumping champion\n");
                            else{
                            for(int i=0; i<p.size()-1; i++){
                                dis = p[i+1] - p[i];
                                cnt_arr[dis]++;
                                //cout << dis << "       " << p[i+1] << " " << p[i]  << endl;
                            }

                            int max_=0,ans;
                            for(int i=0; i<120; i++){

                                if(cnt_arr[i] != 0) {
                                    //cout << " " << i << " " << cnt_arr[i] << endl;
                                     if(cnt_arr[max_]<cnt_arr[i]){
                                        max_=i;
                                    }
                                }

                            }
                            for(int i=0; i<120; i++){
                                 if(cnt_arr[max_] == cnt_arr[i])cnt++;
                                 if(cnt>=2){
                                    fl = 0;
                                    break;
                                    }
                            }
                            if(fl == 0) printf("No jumping champion\n");
                            else printf("The jumping champion is %d\n", max_);
                            }
                }
return 0;
}
