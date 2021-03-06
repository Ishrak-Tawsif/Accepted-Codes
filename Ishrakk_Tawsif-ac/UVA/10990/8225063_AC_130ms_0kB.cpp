#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(till) for(int i=0; i<till; i++)
#define pb push_back
#define mx 2000005
#define ll long long int
#define mp make_pair
#define mod 1000005

bitset <mx> ismark;
int euler_phi[mx];

void sieve()
{
    for(int i=1; i<mx; i++) euler_phi[i]=i;

        ismark[1]=1;

            for(int i=2; i<mx; i++)
            {
                if(!ismark[i]){
                    for(int j=i; j<mx; j+=i)
                    {
                        ismark[j]=1;
                        euler_phi[j]= (euler_phi[j]/i)*(i-1);
                    }
                }
            }
}

int depth[2000003];

void pre_gen()
{
    depth[1]=0;
    for(int i=2; i<=2000000; i++)
    {
        int temp=i,cnt=0;

            //if(euler_phi[temp]==1) cnt++;

            while(euler_phi[temp]!=1)
            {   //cout<<temp<<endl;
                cnt++;
                temp=euler_phi[temp];
            }//cout<<cnt<<endl;
            depth[i]=(cnt+1)+depth[i-1];
    }
}

int main()
{
    sieve();
    pre_gen();

        int tc,up,lo;

                sf(tc);
                while(tc--)
                {
                    scanf("%d %d",&lo,&up);
                    //cout<<depth[up]<<" "<<depth[lo]<<endl;
                    pf("%d\n", depth[up]-depth[lo-1]);
                }
    return 0;
}