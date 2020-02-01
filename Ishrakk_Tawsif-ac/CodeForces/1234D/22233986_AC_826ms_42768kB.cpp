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
#define mod                     100000007


int dr8[]={-1,-1,0,1,1,1,0,-1};
int dc8[]={0,1,1,1,0,-1,-1,-1};

int tree[27][4*mx],ar[mx];

void update(int node,int bg,int en,int pos,int ch,int val)
{
    if(bg>pos || en<pos) return;
    if(bg == en && bg == pos)
    {
        tree[ch][node] += val;
        return;
    }

    int lf = node * 2;
    int rt = (node * 2) + 1;
    int mid = (bg + en) / 2;

    update(lf,bg,mid,pos,ch,val);
    update(rt,mid+1,en,pos,ch,val);

    tree[ch][node] = tree[ch][lf] + tree[ch][rt];
}

int query(int node,int bg,int en,int i,int j,int ch)
{
    if(bg>j || en<i) return 0;
    if(i<=bg && en<=j) {return tree[ch][node];}

    int lf = (node * 2);
    int rt = (node * 2) + 1;
    int mid = (bg + en) / 2;

    int lfval = query(lf,bg,mid,i,j,ch);
    int rtval = query(rt,mid+1,en,i,j,ch);

    return (lfval + rtval);
}

char str[mx];

int main()
{

    scanf("%s", &str);
    int sz = 0;
    for(int i=0; str[i] != '\0'; i++)
    {
        int now = (str[i] - 'a') + 1;
        ar[i+1] = now;
        sz ++;
    }

    for(int i=1; i<=sz; i++)
    {
        update(1,1,sz,i,ar[i],1);
    }

//    for(int i=1; i<=sz; i++)
//    {
//        printf("%d %d\n", ar[i],query(1,1,sz,i,i,ar[i]));//printf("%d %d\n",ar[i],now);
//    }

    int q,tp,pos;
    char ch;
    scanf("%d", &q);

    for(int qq=1; qq<=q; qq++)
    {
        scanf("%d", &tp);

        if(tp == 1)
        {
            scanf("%d %c", &pos,&ch);
            int now = (ch - 'a') + 1;
            int pre = ar[pos];
            update(1,1,sz,pos,pre,-1);
            update(1,1,sz,pos,now,1);
            ar[pos] = now;
        }
        else
        {
            int l,r;

            scanf("%d %d",&l,&r);
            int res = 0;
            for(int i=1; i<=26; i++)
            {
                int kkk = query(1,1,sz,l,r,i);
                res += (kkk>0);
            }
            printf("%d\n",res);
        }
    }

    return 0;
}