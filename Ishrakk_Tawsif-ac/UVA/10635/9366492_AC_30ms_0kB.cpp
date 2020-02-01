#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 100005
#define ll long long int
#define mp make_pair
#define mod 1000000


int p,q=0,prn[65000],prncs[65000];


int main()
{
    int tc,temp,n;
//cin.ignore();
    sf(tc);
    
        loop1(tt,tc)
        {//cout<<tt<<endl;
        
        int ans[65001];
        for(int i=0; i<=65000; i++) {ans[i]=INT_MAX; prn[i]=0;}
            
            scanf("%d %d %d",&n,&p,&q);
           /* sf(n);
            sf(p);
            sf(q);*/
            p++,q++;

//cout<<q<<endl;
                

                loop1(i,p) {sf(temp); prn[temp]=i;}
                //loop1(i,q) {sf(temp); prncs[temp]=prn[temp];}
                //cout<<" q "<<" "<<q << " " <<p<<endl;

                    int l,r,mid;
                    //cout<<3<<endl;
                    for(int i=0; i<q; i++)
                    {//cout<<i<<endl;
                        sf(temp);

                            if(prn[temp])
                            {
                                temp = prn[temp];

                                    l=0,r=n*n,mid;

                                        while(l+1<r)
                                        {//cout<<l<<" " << r << " " << mid <<endl;
                                            mid = (l+r)/2;

                                            if(ans[mid]>=temp) r=mid;
                                            else l=mid;
                                        }
                                ans[l+1]=temp;//cout<<l+1 << " " <<temp<<endl;
                            }//cout<<1<<endl;
                    }//cout<<4<<endl;
                    int aaannss=-1;int ss=(n*n);
                    for(int ii=ss; ii>=1; ii--)
                    {//cout<<ii<<"..."<<endl;cout<<ans[ii]<<" " <<aaannss<<" ....\n";
                        if(ans[ii]<=ss)
                        {
                            aaannss=ii;//cout<<ans[ii]<<" " <<aaannss<<" ....\n";
                            break;
                        }
                    }
                    pf("Case %d: %d\n",tt,aaannss);
        }
    return 0;
}