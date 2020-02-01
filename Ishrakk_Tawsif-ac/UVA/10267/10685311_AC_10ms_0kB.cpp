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

char com,colr,ar[253][253];
int row,col,x,y;
string name;

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    //cout<<calc(150)<<".."<<endl; system("pause");

    while(cin>> com)
    {//cout<<com<<endl;
        if(com == 'I')
        {
            scanf("%d %d", &col,&row);
            mem(ar,'O');
        }
        else if(com == 'C') mem(ar,'O');
        else if(com == 'L')
        {
            cin>> x>> y>> colr;
            ar[y][x] = colr;
        }
        else if(com == 'V')
        {//cout<<"VVVVVVV\n";
            int y1,y2;
            cin>> x>> y1>> y2>> colr;
            if(y1>y2) swap(y1,y2);
            for(int i=y1; i<=y2; i++) ar[i][x] = colr;
        }
        else if(com == 'H')
        {
            int y1,y2;
            cin>> y1>> y2>> x>> colr;
            if(y1>y2) swap(y1,y2);
            for(int i=y1; i<=y2; i++)
            {
                ar[x][i] = colr;
            }
        }
        else if(com == 'K')
        {//cout<<"grgwrgwrg\n";
            int x1,y1,x2,y2;
            cin>> x1>> y1>> x2>> y2>> colr;
            if(y1>y2) swap(y1,y2);
            if(x1>x2) swap(x1,x2);
            for(int i=y1; i<=y2; i++)
            {
                for(int j=x1; j<=x2; j++) ar[i][j] = colr;
            }
        }
        else if(com == 'F')
        {
            cin>>x >>y>> colr;
            char cur = ar[y][x];
            ar[y][x] = colr;
            if(cur == colr) continue;
            queue <int> q;
            q.push(y);
            q.push(x);

                int vis[253][253];
                mem(vis,0);
                while(!q.empty())
                {
                    int rr = q.front(); q.pop();
                    int cc = q.front(); q.pop();

                        for(int i=0; i<4; i++)
                        {
                            int tr = rr + dx4[i];
                            int tc = cc + dy4[i];
                            if(tr>=1 && tr<=row && tc>=1 && tc<=col)
                            {
                                if(!vis[tr][tc] && ar[tr][tc] == cur)
                                {
                                    vis[tr][tc] = 1;
                                    ar[tr][tc] = colr;
                                    q.push(tr);
                                    q.push(tc);
                                }
                            }
                        }
                }
        }
        else if(com == 'S')
        {//cout<<"grwg\n";
            cin>> name;
            cout << name << endl;
            for(int i=1; i<=row; i++)
            {
                for(int j=1; j<=col; j++) cout << ar[i][j];
                 cout <<endl;
            }
        }
        else if(com == 'X')
        {
            break;
        }
        else continue;
    }
//system("pause");
    return 0;
}