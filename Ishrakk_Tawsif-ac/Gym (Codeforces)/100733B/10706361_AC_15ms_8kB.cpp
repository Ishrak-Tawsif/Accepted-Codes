#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d:\n",nn)
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


int dx[8] = {1,-1,0,0,-1,-1,1,1};
int dy[8] = {0,0,-1,1,-1,1,-1,1};

int dirr[] = {-1,-1,0,0,1,1};
int dirc[] = {0,1,-1,1,-1,0};

int dx4[] = {-1,0,0,1};
int dy4[] = {0,-1,1,0};

int cnt[101],req[101];

struct st
{
    string gn,nin;
};

st ar[105];
string mat;

int main()
{//cout<<(int)('9'-48);
    int k,max_ = -intinf;
    string nick,gang,ansnic,ansgng;

    sf(k);

    for(int i=0; i<k; i++)
    {
        cin>> ar[i].nin>> ar[i].gn;
    }

    int r,c;
    //string s;
    for(int i=0; i<k; i++)
    {

        scanf("%d %d", &r,&c);

        mem(cnt,0);
        mem(req,0);
        for(int k=0; k<r; k++)
        {
            cin>> mat;
            for(int j=0; j<mat.length(); j++)
            {
                int ind;

                if(mat[j]>='0' && mat[j]<='9') ind = (int) mat[j]-48;
                else ind = (mat[j]-'a') + 10;
//cout<<ind<<endl;
                cnt[ind] ++;
            }
        }//out("1");
        for(int j=0; j<ar[i].gn.length(); j++)
        {
            int ind;

            if(ar[i].gn[j]>='0' && ar[i].gn[j]<='9') ind = (int)ar[i].gn[j]-48;
            else ind = (ar[i].gn[j]-'a')+10;

            req[ind] ++;
        }
        for(int j=0; j<ar[i].nin.length(); j++)
        {
            int ind;
            if(ar[i].nin[j]>='0' && ar[i].nin[j]<='9') ind = (int)ar[i].nin[j]-48;
            else ind = (ar[i].nin[j]-'a')+10;
            req[ind] ++;
        }

        int fl=1,temp = intinf;
        for(int j=0; j<=35; j++)
        {
            if(req[j]<=cnt[j])
                {
                    //fl=0;
                    if(!req[j]) continue;
                    temp = min(temp,cnt[j]/req[j]);
                    //cout<<j<<" "<<req[j]<<" "<<cnt[j]<<endl;
                }
            else {temp=0; break;}
        }//cout<<fl<<" " << temp << endl;
        if(fl)
        {
            if(temp>max_)
            {
                max_ = temp;
                ansnic = ar[i].nin;
                ansgng = ar[i].gn;
            }
        }
    }
    cout<<ansnic << " " << ansgng << endl;
    return 0;
}