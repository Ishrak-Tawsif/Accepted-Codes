#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case #%d: ",nn)
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


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

vector <int> mystring;
int inwhich,curlen,fl=0;
string str,ans[105];

void print1(int koyta)
{//cout<<koyta<<endl;system("pause");
    for(int i=0; i<koyta; i++) cout<<str[i];

    int taken = koyta,cur = 0;

    while(taken<str.length())
    {
        pf("+");
        for(int j=taken; j<taken+koyta && j<str.length(); j++) cout<<str[j];
        taken = taken + koyta;
    }
    pf("\n");
}

string tostring(ll res)
{
    string curstr = "";

    while(res != 0)
    {
        ll temp = (res%10);
        curstr += ((char) temp+'0');
        res /= 10;
    }
    reverse(curstr.begin(),curstr.end());

    return curstr;
}

int toint(string ss)
{
    int inss = 0;
    for(int i=0; i<ss.size(); i++)
    {
        inss = (inss * 10) + ((int)(ss[i]-'0'));
    }
    return inss;
}

int isok(int number)
{
    int sum = 0;
    while(number != 0)
    {
        sum += (number%10);
        number /= 10;
    }
    if(sum<10) return 1;
    return 0;
}

void backtrack(int pos,int num,int cur)
{
    if(fl) return;
    if(pos >= curlen)
    {
        if(isok(num))
        {
            fl = 1;
            ///printing ans
            print1(inwhich+1);
            ///printing line 2
            cout<<ans[0];
            int cnt = 1;
            for(int i=1; i<cur; i++) cout<<"+"<<ans[i];
            cout<<endl;//out(3);
            ///printing line 3
            int sum = 0;
            //for(int i=0; i<cur; i++) sum += toint(ans[i]);//out(sum);
            string strsum = tostring(num);
            cout<<strsum[0];
            for(int i=1; i<strsum.length(); i++) cout<<"+"<<strsum[i];
            pf("\n");
        }
        return;
    }

    string tempstr = tostring(mystring[inwhich]);
    for(int i=pos; i<curlen; i++)
    {
        string curstr = "";
        int temp=0;
        for(int j=pos;j<=i; j++)
        {
            curstr += tempstr[j];
            temp = (temp*10) + ((int)(tempstr[j]-'0'));
        }
        ans[cur] = curstr;
        backtrack(i+1,num+temp,cur+1);
    }
}

int main()
{
    //string str;
    int n,len;

    sf(n);
    cin>> str;
    len = str.length();

    for(int i=1; i<=10; i++)
    {
        int taken = 0,cur=0,sum = 0,totsum = 0;

        while(taken<len)
        {
            sum = 0;
            while(cur<i && taken<len)
            {
                sum = sum*10 + ((int)(str[taken]-'0'));
                cur++;
                taken++;
            }//cout<<i<<" "<<sum<<endl;
            totsum += sum;
            cur = 0;
        }
        mystring.pb(totsum);
    }

    //for(int i=0; i<mystring.size(); i++) cout<<mystring[i]<<endl;

    for(int i=0; i<mystring.size() && !fl; i++)
    {
        inwhich = i;
        curlen = tostring(mystring[i]).length();
        backtrack(0,0,0);
    }

    return 0;
}