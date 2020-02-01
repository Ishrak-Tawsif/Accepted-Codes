#include <bits/stdc++.h>
using namespace std;

#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)

///1 based index

//struct myqueue
//{
///queue begin
    int myqueue[1000005],en = 0,start = 1;

    void push(int val)
    {
        myqueue[++en] = val;
    }
    void pop()
    {
        start++;
    }
    bool empty()
    {
        if(start > en) return true;
        return false;
    }
    int front()
    {
        int now = myqueue[start];
        //start ++;
        return now;
    }
///queue ends
//};


int cnt[203],ar[203][203],n,vis[203];

void init()
{
    for(int i=0; i<203; i++) cnt[i] = 0;
    for(int i=0; i<203; i++) vis[i] = 0;
    start = 1,en = 0;
}

int bfs(int sr)
{
    push(sr);
    vis[sr] = 1;

    while(!empty())
    {
        int u = front();
        pop();

        for(int i=1; i<=cnt[u]; i++)
        {
            int v = ar[u][i];
//cout<<u<<" ... "<<v<<endl;

            if(!vis[v])
            {
                if(vis[u] == 1) vis[v] = 2;
                else vis[v] = 1;
                push(v);
            }
            else if(vis[u] == vis[v]) return 0;
        }
    }

    return 1;
}

int main()
{
    //WRITE("in.txt");

    while(scanf("%d", &n) && n)
    {
        int m,u,v;
        init();

        scanf("%d", &m);
        for(int i=0; i<m; i++)
        {
            scanf("%d %d", &u,&v);
            cnt[u]++;
            cnt[v]++;
            ar[u][cnt[u]] = v;
            ar[v][cnt[v]] = u;//cout<<u<<" .. "<<cnt[u]<<endl;

//            for(int i=0; i<=2; i++)
//            {
//                for(int j=1; j<=cnt[i]; j++) cout<<i<<" "<<j<<" .. "<< ar[i][j]<<endl;
//            }
        }



        int fl = bfs(0);

        if(!fl) printf("NOT BICOLORABLE.\n");
        else printf("BICOLORABLE.\n");
    }

    return 0;
}