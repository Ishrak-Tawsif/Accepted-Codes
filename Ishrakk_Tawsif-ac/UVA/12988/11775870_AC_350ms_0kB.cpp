#include<bits/stdc++.h>
using namespace std;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case #%d:\n",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007

vector <int> vv[27];
int cnt = 0,ar[19],vis[19];
int isok[5];

void backtrack(int ind)
{
    if(ind == 5)
    {
        cnt++;//out(cnt);
        for(int i=1; i<ind; i++) vv[cnt].pb(ar[i]);
        return;
    }

    for(int i=1; i<=4; i++)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            ar[ind] = i;
            backtrack(ind+1);
            vis[i] = 0;
        }
    }
}

string str[5];

int checkraw(int i,int j,int k,int l)
{
    int fl = 1,inwhich,click[5];

    for(int a=0; a<4; a++)
    {
        int sum = 0;
        mem(click,0);
        for(int b=0; b<4; b++)
        {
            ///[j][i]

            if(b==0) inwhich = i;
            else if(b==1) inwhich = j;
            else if(b==2) inwhich = k;
            else inwhich = l;

            if(isok[b])
            {
                sum += (str[b][a]-'0');
                click[str[b][a]-'0'] = 1;
            }
            else
            {
                sum += vv[inwhich][a];
                click[vv[inwhich][a]] = 1;
            }
        }
        for(int ii=1; ii<=4; ii++) fl &= (click[ii])? 1 : 0;
    }
    return fl;
}

int checkcol(int i,int j,int k,int l)
{
    int sum = 0,inwhich,fl=1,click[5];

    for(int a=0; a<4; a++)
    {
        sum = 0;
        if(isok[a])
        {
            for(int b=0; b<4; b++)
            {
                sum += (str[a][b]-'0');
            }
            if(sum != 10) fl = 0;
            continue;
        }
        mem(click,0);
        if(a==0) inwhich = i;
        else if(a==1) inwhich = j;
        else if(a==2) inwhich = k;
        else inwhich = l;

        for(int b=0; b<4; b++)
        {
            sum += vv[inwhich][b];
            click[vv[inwhich][b]] = 1;
        }
        for(int ii=1; ii<=4; ii++) fl &= click[ii];
    }
    return fl;
}

int checksqr(int i,int j,int k,int l)
{
    int fl = 1,inwhich,click[5];
    vector <int> temp[5];
    for(int a=0; a<4; a++)
    {
        if(isok[a])
        {
            for(int b=0; b<4; b++)temp[a].pb(str[a][b]-'0');
            continue;
        }
        if(a==0) inwhich = i;
        else if(a==1) inwhich = j;
        else if(a==2) inwhich = k;
        else inwhich = l;
        for(int b=0; b<4; b++)
        {
            for(int b=0; b<4; b++) temp[a].pb(vv[inwhich][b]);
        }
    }

    mem(click,0);
    for(int a=0; a<2; a++)
    {
        for(int b=0; b<2; b++) click[temp[a][b]]=1;
    }

    for(int ii=1; ii<=4; ii++) fl &= click[ii];

    mem(click,0);
    for(int a=0; a<2; a++)
    {
        for(int b=2; b<4; b++) click[temp[a][b]]=1;
    }

    for(int ii=1; ii<=4; ii++) fl &= click[ii];

    mem(click,0);
    for(int a=2; a<4; a++)
    {
        for(int b=0; b<2; b++) click[temp[a][b]]=1;
    }

    for(int ii=1; ii<=4; ii++) fl &= click[ii];

    mem(click,0);
    for(int a=2; a<4; a++)
    {
        for(int b=2; b<4; b++) click[temp[a][b]]=1;
    }

    for(int ii=1; ii<=4; ii++) fl &= click[ii];

    return fl;
}

int main()
{//WRITE("in.txt");
    backtrack(1);

    string curr;

    int tc,taken;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        for(int i=0; i<4; i++) cin>> str[i];

        mem(isok,0);

        casepf(tt);

        for(int i=0; i<4; i++)
        {
            int fl = 1;
            for(int j=0; j<4; j++)
            {
                if(str[i][j] == '*') fl=0;
            }
            isok[i] = fl;
        }

        taken = 0;
        int track[25];
        for(int i=1; i<=24; i++)
        {
            mem(track,0);
            track[i] = 1;
            int thikase;

            for(int j=1; j<=24; j++)
            {
                if(i == j) continue;
                for(int k=1; k<=24; k++)
                {
                    if(i == k || j == k) continue;
                    for(int l=1; l<=24; l++)
                    {
                        if(i == l || j == l || k == l) continue;

                        ///checking
                        thikase = 1;
                        int inwhich;
                        for(int konta=0; konta<4; konta++)
                        {
                            if(isok[konta]) continue;
                            for(int a=0; a<4; a++)
                            {
                                if(konta==0) inwhich = i;
                                else if(konta==1) inwhich = j;
                                else if(konta==2) inwhich = k;
                                else inwhich = l;
                                if(str[konta][a] != '*')
                                {
                                    if((str[konta][a]-'0') != vv[inwhich][a]) {thikase = 0;break;}
                                }
                            }
                        }
                            if(thikase)thikase = checkraw(i,j,k,l);
                            if(thikase)thikase = checkcol(i,j,k,l);
                            if(thikase) thikase = checksqr(i,j,k,l);
                            if(thikase)
                            {
                                for(int a=0; a<4; a++)
                                {
                                        if(isok[a])
                                        {
                                            for(int b=0; b<4; b++) cout<<str[a][b];
                                            cout<<endl;
                                        }
                                        else
                                        {
                                            if(a==0) inwhich = i;
                                            else if(a==1) inwhich = j;
                                            else if(a==2) inwhich = k;
                                            else inwhich = l;
                                            for(int b=0; b<4; b++) cout<<vv[inwhich][b];
                                            cout<<endl;
                                        }

                                }
                            }
                            if(thikase) break;
                    }
                    if(thikase) break;
                }
                if(thikase) break;
            }
            if(thikase) break;
        }
    }
    return 0;
}