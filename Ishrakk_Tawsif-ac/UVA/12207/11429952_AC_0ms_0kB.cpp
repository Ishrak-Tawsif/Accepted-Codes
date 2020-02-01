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
#define inf                     1e9
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      1000+5
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

unordered_map <int,int >mpp;
queue <int> q;
stack <int> extra;

void process(int temp)
{
    stack <int> cur = extra;
    queue <int> qqq;
    int ar[10005],in=-1;

    while(!cur.empty())
    {
        int now =  cur.top();//out(now);
        if(now != temp) ar[++in] = now;
        cur.pop();
    }
    //ar[++in] = temp;

    while(!extra.empty()) extra.pop();

    /*while(!qqq.empty())
    {
        int now = qqq.front();
        extra.push(now);out(now);
        qqq.pop();
    }//cout<<extra.size()<<endl;*/
    for(int i=in; i>=0; i--) extra.push(ar[i]);
    extra.push(temp);
}

int main()
{//WRITE("in.txt");
    int tt=0,n,qu;
    char ch;

    //sf(tc);

    //for(int tt=1; tt<=tc; tt++)
    //{
        while(~scanf("%d %d", &n,&qu))
        {
            if(!n && ! qu) break;
            mpp.clear();

            while(!q.empty())q.pop();
            while(!extra.empty())extra.pop();

            for(int i=1; i<=(min(n,1100)); i++) q.push(i),mpp[i] = 1;
            cin.ignore();

            printf("Case %d:\n", ++tt);
            while(qu--)
            {//out(qu);
                cin>> ch;

                if(ch == 'N')
                {//out(extra.size())<<endl;
                    if(!extra.empty()) pf("%d\n", extra.top()),mpp[extra.top()]++,q.push(extra.top()),extra.pop();
                    else
                    {//cout<<q.front()<<" "<<mpp[q.front()]<<endl;
                        while(mpp[q.front()]>1)
                        {
                            mpp[q.front()]--;
                            q.pop();
                        }
                        pf("%d\n", q.front());
                        int temp = q.front();
                        q.push(temp);
                        //mpp[temp]++
                        q.pop();
                    }
                }
                else
                {
                    int temp;
                    scanf("%d", &temp);
                    //mpp[temp]++;
                    //q.push(temp);
                    if(!extra.empty()) process(temp);
                    else extra.push(temp);
                }
            }
    }
}


/*
5 20
E 2
N
N
N
N
N
N
N
N
N
E 1
E 3
N
N
N
N
N
N
N
N
0 0

*/