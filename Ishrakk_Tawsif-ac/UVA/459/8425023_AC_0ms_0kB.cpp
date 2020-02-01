#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 2503
#define ll long long int
#define mp make_pair
#define mod 100000007

int par[101],arr[101];

int find_(int p)
{
    if(par[p] == p) return p;
    return find_(par[p]);
}

int main()
{
    string str;
    char c;
    int tc;

        sf(tc);
            loop1(tt,tc)
            {
                cin>> c;
                    int len=c-'A';getchar();
                    for(int i=0; i<=len; i++) par[i]=i;
                    while(getline(cin,str) && str[0])
                    {
                        int cc=str[0]-'A';
                        int ccc=str[1]-'A';

                        int a=find_(cc);
                        int b=find_(ccc);

                            if(a!=b) par[b]=a;
                    }

                memset(arr,0,sizeof(arr));
                int cnt=0;

                for(int i=0; i<=len; i++)
                {
                    //for(int i=0; i<=len; i++) cout<<arr[i] << " "; cout<<endl;
                    if(arr[i] == 0) {int k=find_(i);if(arr[k]==0){arr[k]=1;cnt++;}}
                }
                pf("%d\n",cnt);
                if(tt!=tc)pf("\n");
            }
    return 0;
}