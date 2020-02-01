///hints

/*
http://math.stackexchange.com/questions/1403606/fi-binary-number
*/

#include<bits/stdc++.h>
using namespace std;

#define mx 1000000005
#define pb push_back

vector <long int> fibo;

void pre_gen(){

    fibo.pb(1);fibo.pb(1);

        long int temp=INT_MIN,len=(mx/2)+1;//cout<<len<<endl;
        for(int i=2; temp<=len; i++){
            temp=fibo[i-1]+fibo[i-2];
            fibo.pb(temp);
        }
}

int main(){
    pre_gen();
    //cout<<fibo[43]<<endl;
        int pos,tc;
        long int n;
            scanf("%d", &tc);

                for(int tt=1; tt<=tc; tt++){
                    scanf("%ld", &n);
                    pos=43;

                    printf("Case %d: ",tt);
                        while(n<fibo[pos]) pos--;

                            for(int i=pos; i>0; i--){
                                if(fibo[i]<=n){
                                    n-=fibo[i];
                                    printf("1");
                                }
                                else
                                {
                                    printf("0");
                                }
                            }
                            printf("\n");
                }
return 0;
}