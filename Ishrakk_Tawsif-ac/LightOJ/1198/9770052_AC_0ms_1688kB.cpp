#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d: ",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      unsigned long long int
#define mx                      5005
#define mod                     100000007
#define intinf                  2100000000
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())


int main()
{

    int tc,n,ar1[53],ar2[53],ans,ind,ind2;

        sf(tc);

        loop(tt,1,tc+1){

            sf(n);

            loop(i,0,n)
            {
                sf(ar1[i]);
            }
            loop(i,0,n)
            {
                sf(ar2[i]);
            }

                sort(ar1,ar1+n);
                sort(ar2,ar2+n);

                    ans=0;
                    for(int i=0; i<n; i++)
                    {//cout<<ar1[i]<<endl;
                        ind=-1,ind2=-1;
                        for(int j=n-1; j>=0; j--)
                        {
                            if(ar1[i]>ar2[j])
                            {
                                /*if(ind != -1)
                                {
                                    if(ar2[ind]<ar2[j]) ind = j;
                                }
                                else ind=j;*/
                                //cout<< ar1[i] << " > " << ar2[j] << endl;
                                ind = j;
                                break;
                            }
                            /*else if(ar2[j] == ar1[i])
                            {
                                ind2 = j;
                            }*/
                        }
                        //if(ind2!=-1) {ar2[ind2] = intinf; ans+=1;}
                        if(ind != -1){ar2[ind]=intinf;ar1[i]=-10; ans += 2;}
                    }

                    ind=-1,ind2=1;

                    for(int i=0; i<n; i++)
                    {
                        ind=-1;
                        for(int j=n-1; j>=0; j--)
                        {
                            if(ar1[i] == -1) continue;
                            if(ar1[i] == ar2[j]){
                                ind = j;//cout<< ar1[i] << " = " << ar2[j] << endl;
                                break;
                            }
                        }
                        if(ind != -1){ar2[ind]=intinf;ans+=1;}
                    }

                    pf("Case %d: %d\n", tt,ans);
        }
    return 0;
}