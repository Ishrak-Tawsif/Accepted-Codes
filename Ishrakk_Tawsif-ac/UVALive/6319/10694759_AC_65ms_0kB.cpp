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

string str,str2;

void append(string ss,int ind)
{
    if(str.size() == ind) str += ss;

    string temp="";

    for(int i=0; i<ind; i++) temp += str2[i];
    temp += ss;
    for(int i=ind; i<str2.size(); i++) temp += str2[i];

    str2 = temp;
}

void substring(int f,int t)
{
    int ind = 0;//cout<<f<<" " << t <<endl;
    for(int i=f; i<=t; i++)
    {
        //if(str[ind] == str2[i]) cout<<str[ind],ind++;
        //if(ind>=str.size()) break;
        cout<<str2[i];//cout<<i;
    }
    pf("\n");
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");

    int tc;
    string s;

    sf(tc);

    loop(tt,0,tc)
    {
        cin>> str;
        str2 = str;

        while(cin>> s)
        {

            if(s == "I")
            {
                string cur;
                int ind;
                cin>> cur>> ind;

                append(cur,ind);
            }
            else if(s == "P")
            {
                int f,t;//out("ok");
                scanf("%d %d", &f,&t);//cout<<f<<" " << t <<endl;
                substring(f,t);
            }
            else
            {
                break;
            }
        }
    }

    return 0;
}