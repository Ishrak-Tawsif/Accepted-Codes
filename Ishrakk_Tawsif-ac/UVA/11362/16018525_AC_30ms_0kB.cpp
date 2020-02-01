#include <iostream>
#include <stdio.h>

using namespace std;

char ch[100005][13];
int node[100005][13];
int root,curnode;
int isword[100005];

int fl;

void init()
{
    root = 0;
    curnode = 0;
    for(int i=0; i<13; i++) node[root][i] = -1;
}

void insert(int id)
{
    int len = 0;

    for(int i=0; i<11; i++)
    {
        if(ch[id][i] == '\0') break;
        len++;
    }


    int now = root;
    int isok = 1,curfl=1;

    for(int i=0; i<len; i++)
    {
        int cur = ch[id][i] - '0';//cout<<cur<<endl;

        if(node[now][cur] == -1)
        {//if(id == 4) cout<<i<<" "<<now<<" "<<node[0][1]<<endl;
            node[now][cur] = ++curnode;//if(id == 4) {cout<<"nzeroone || "<<now<<" "<<cur<<" "<<node[0][1]<<endl;cout<< "cn "<<curnode<<endl;}
            for(int j=0; j<12; j++)
            {
                node[curnode][j] = -1;
            }
        }//if(i == 0) cout<<now<<" "<<cur<<" "<<node[now][cur]<<endl;
        //if(now == 3) cout<<" cur \\\\\\\ " << cur<<endl;
        now = node[now][cur];
        //cout<<id<<" "<<i<<" "<<"node0/1 "<<node[0][1]<<endl;

    }//cout<<now<<" ... kkkkk \n";
    isword[now] = 1;
}

void dfs(int root,int cur,int tot,int len,int id)
{
    if(cur>=len)
    {
        //cout<<id<<" ... "<<root<<endl;
        for(int i=0; i<12; i++)
        {
            if(node[root][i] != -1) {fl = 0; /*cout<<id<<" "<<root<<" "<<i<<" "<<node[root][i]<<".....\n";*/}
        }
        //if(root != -1)fl = 0;
        return;
    }

    if(root == -1) return;

    //if(isword[root]) {cout<<id<<" "<<root<<". here .."<<endl;fl = 0;}

    char c = ch[id][cur];//cout<<id<<" "<<c<<endl;
    int now = c - '0';//cout<<c<<endl;


    int nxt = node[root][now];
    if(nxt == -1) {/*cout<<id<<" "<<cur<<endl;*/return;}
    dfs(nxt,cur+1,tot+1,len,id);
}

int main()
{//freopen("o.txt","w",stdout);
    int tc,n;

    scanf("%d", &tc);

    for(int tt=1; tt<=tc; tt++)
    {
        scanf("%d", &n);

        fl = 1;

        init();

        for(int i=0; i<n; i++)
        {
            scanf("%s", &ch[i]);
            insert(i);
        }

        int len = 0;
        fl = 1;
        for(int i=0; i<n; i++)
        {
            len = 0;
            for(int j=0; j<13; j++)
            {
                if(ch[i][j] == '\0') break;
                len ++;
            }
            int cc = ch[i][0] - '0';
            int cur = node[0][cc];//cout<<cur<<endl;
            dfs(0,0,0,len,i);
            if(!fl) {/*cout<<i<<endl;*/break;}
        }
        (!fl)? printf("NO\n") : printf("YES\n");
    }
//getchar();
    return 0;
}