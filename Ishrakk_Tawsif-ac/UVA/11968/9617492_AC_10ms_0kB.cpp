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
#define ll                      long long int
#define mx                      5005
#define mod                     100000007
#define intinf                  2100000000
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())

ll cake[1003],drink[1003];

int main()
{//WRITE("in.txt");
    int tc,item,dr,cak;
    ll temp;
    ll sum=0;

        sf(tc);

            loop(tt,1,tc+1)
            {
                scanf("%d %d %d", &item,&cak,&dr);
                    //ll cake[cak+3],drink[dr+3];
                    sum=0.0;
                    for(int i=0; i<cak; i++)
                    {
                        cin>> temp;

                            cake[i] = temp;
                            sum += (temp);
                    }
                    for(int i=0; i<dr; i++)
                    {
                        cin>> temp;

                            drink[i] = temp;
                            sum += (temp);
                    }
                    for(int i=0; i<(item-(cak+dr)); i++)
                    {
                        cin>> temp;

                        sum += (temp);
                    }

                    //sum = (sum/(item));

                    double avg = (sum*1.0)/(item*1.0);

                    sort(cake,cake+cak);
                    sort(drink,drink+dr);

                    double mindif = llinf*(1.0),diff;
                    ll ans=llinf;
                    for(int i=0; i<cak; i++)
                    {
                        if(cake[i]>avg)
                        {
                            diff = cake[i]-avg;
                        }
                        else diff = avg-cake[i];
                        if(diff<mindif)
                        {
                            mindif = diff;
                            ans = cake[i];
                        }
                    }

                    mindif = llinf*(1.0),diff;
                    ll ans2;

                    for(int i=0; i<dr; i++)
                    {
                        if(drink[i]>avg)
                        {
                            diff = drink[i]-avg;
                        }
                        else diff = avg - drink[i];

                        if(diff<mindif)
                        {
                            mindif = diff;
                            ans2 = drink[i];
                        }
                    }

                    pf("Case #%d: %lld %lld\n", tt,ans,ans2);//system("pause");
            }

    return 0;
}