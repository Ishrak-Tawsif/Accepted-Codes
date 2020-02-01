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
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007


int dr8[]={-1,-1,0,1,1,1,0,-1};
int dc8[]={0,1,1,1,0,-1,-1,-1};

int n,luckunum[101],luckytrace[100005],ar[203][803],frequency[203][2*100005],blocksize=800,exadd[203];

void luckynumgen()
{
    int cnt = 0;
    for(int i=1; i<100005; i++)
    {
        int temp = i,fl=1;

            while(temp != 0)
            {
                if(temp%10 != 4 && temp%10 != 7){fl=0; break;}
                temp /= 10;
            }
        if(fl == 1){luckunum[++cnt]=i; luckytrace[i]=1;}
    }//cout<<cnt<<endl;
}

int query(int u,int v)
{
    int cnt = 0,fl=0,stblock=u/blocksize,enblock=v/blocksize,ublock,vblock,till,cnt2=0,from;
//cout<<u<<" "<<v<<endl;
    ///(what we should do if start and end block same and ....)
    if(u%blocksize == 0 && v%blocksize == (blocksize-1))
    {
        stblock = u/blocksize; ///ublock will be start block
        enblock = v/blocksize; ///vblock will be end block
        //cout<<stblock<<" "<<enblock<<endl;
    }

    else if(u%blocksize == 0 && v%blocksize != (blocksize-1))
    {
        stblock = u/blocksize; ///ublock will be start block
        vblock = v/blocksize;
        enblock = vblock-1;

        ///count number in vblock

        till = v % blocksize;

        for(int i=0; i<=till; i++) if(luckytrace[ar[vblock][i]+exadd[vblock]]) cnt++;
    }

    else if(u%blocksize != 0 && v%blocksize == (blocksize-1))
    {
        enblock = v/blocksize;
        ublock = u/blocksize;
        stblock = ublock+1;

        ///count number in ublock

        from = u%blocksize;

        for(int i=from; i<=(blocksize-1); i++)if(luckytrace[ar[ublock][i]+exadd[ublock]]) cnt++;
    }

    else if(u%blocksize !=0 && v%blocksize != (blocksize-1))
    {
        ublock = u/blocksize;
        vblock = v/blocksize;
        stblock = ublock+1;
        enblock = vblock-1;

        ///count number in vblock

        till = v % blocksize;
//cout<<ublock<<" "<<vblock << endl;
        if(ublock == vblock)
        {
            from = u%blocksize;
            till = v%blocksize;
            for(int i=from; i<=till; i++)
            {
                if(luckytrace[ar[vblock][i]+exadd[vblock]]) cnt++;
            }
        }

        for(int i=0; i<=till && ublock != vblock; i++) if(luckytrace[ar[vblock][i]+exadd[vblock]]) cnt++;

         ///count number in ublock

        from = u%blocksize;

        for(int i=from; i<=(blocksize-1) && ublock != vblock; i++)if(luckytrace[ar[ublock][i]+exadd[ublock]]) cnt++;
    }

    for(int i=stblock; i<=enblock; i++)
    {
        for(int j=1; j<=30; j++)
        {
            int curnum = luckunum[j];
            curnum -= exadd[i];//cout<<i<<" "<<curnum<<" ";
            if(curnum<0) continue;
            cnt2 += frequency[i][curnum];//cout<<frequency[i][curnum]<<endl;
            //if(frequency[i][curnum] != 0)cout<<i<<" "<<curnum<<" "<<frequency[i][curnum]<<endl;
        }
    }
        return cnt+cnt2;
}

void update(int u,int v,int val)
{
    int cnt = 0,fl=0,stblock=u/blocksize,enblock=v/blocksize,ublock,vblock,till,cnt2=0,from;
//cout<<u<<" "<<v<<endl;
    ///(what we should do if start and end block same and ....)
    if(u%blocksize == 0 && v%blocksize == (blocksize-1))
    {
        stblock = u/blocksize; ///ublock will be start block
        enblock = v/blocksize; ///vblock will be end block
        //cout<<stblock<<" "<<enblock<<endl;
    }

    else if(u%blocksize == 0 && v%blocksize != (blocksize-1))
    {
        stblock = u/blocksize; ///ublock will be start block
        vblock = v/blocksize;
        enblock = vblock-1;

        ///update number in vblock

        till = v % blocksize;

        for(int i=0; i<=till; i++)
        {
            frequency[vblock][ar[vblock][i]]--;
            ar[vblock][i] += val;//cout<<ar[vblock][i]<<endl;
            frequency[vblock][ar[vblock][i]]++;
        }
    }

    else if(u%blocksize != 0 && v%blocksize == (blocksize-1))
    {
        enblock = v/blocksize;
        ublock = u/blocksize;
        stblock = ublock+1;

        ///update number in ublock

        from = u%blocksize;

        for(int i=from; i<=(blocksize-1); i++)
        {
            frequency[ublock][ar[ublock][i]]--;
            ar[ublock][i] += val;
            frequency[ublock][ar[ublock][i]]++;
        }
    }

    else if(u%blocksize !=0 && v%blocksize != (blocksize-1))
    {
        ublock = u/blocksize;
        vblock = v/blocksize;
        stblock = ublock+1;
        enblock = vblock-1;

        ///count number in vblock

//cout<<ublock<<" "<<vblock << endl;
        if(ublock == vblock)
        {
            from = u%blocksize;
            till = v%blocksize;
            for(int i=from; i<=till; i++)
            {
                frequency[ublock][ar[ublock][i]]--;
                ar[ublock][i] += val;
                frequency[ublock][ar[ublock][i]]++;
            }
        }

        till = v % blocksize;
        for(int i=0; i<=till && ublock != vblock; i++)
        {
            frequency[vblock][ar[vblock][i]]--;
            ar[vblock][i]+=val;
            frequency[vblock][ar[vblock][i]]++;
        }

         ///count number in ublock

        from = u%blocksize;
        //if(u+((blocksize-from)-1)<=n-1) till = blocksize-1;
        //else till = n-1;
        till=blocksize-1;
        for(int i=from; i<=till && ublock != vblock; i++)
        {
            frequency[ublock][ar[ublock][i]]--;
            ar[ublock][i] += val;
            frequency[ublock][ar[ublock][i]]++;
        }
    }

    for(int i=stblock; i<=enblock; i++)
    {
        exadd[i] += val;//cout<<i<<" "<<exadd[i]<<endl;
    }
}

int main()
{//out("have to change block size");
    luckynumgen();

    int m,u,v,val;
    string str;

    scanf("%d %d", &n,&m);
//cout<<"fwrf"<<endl;
        int curbl=-1,j=1;
        for(int i=0; i<n; i++)
        {
            if(i%blocksize == 0){/*cout<<i<<endl;*/curbl++;j=-1;}
            scanf("%d", &ar[curbl][++j]);//cout<<curbl << " " << j << endl;
            /*if(luckytrace[ar[curbl][j]])*/frequency[curbl][ar[curbl][j]]++;
            //cout<<frequency[curbl][ar[curbl][j]]++<<endl;
        }

        loop(i,0,m)
        {
            cin>> str;

                if(str == "count")
                {
                    scanf("%d %d", &u,&v);
                    cout<<query(--u,--v)<<endl;
                }
                else
                {
                    scanf("%d %d %d", &u,&v,&val);
                    update(--u,--v,val);
                }
        }
        
   return 0;
}