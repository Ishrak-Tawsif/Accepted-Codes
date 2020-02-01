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
#define inf                     1e9
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      1000005
#define mod                     1000000007

string str;

int ipow(int base,int exp)
{
    int res = 1;

    if(!exp) return res;

    while(exp --) res *= base;

    return res;
}

int convert(string str)
{
    int len = str.length(),mul=10,num=0;
        for(int i=0; i<len; i++)
        {
            int temp = (int)str[i]-'0';
            num *= mul;
            num += temp;
        }
    return num;
}

int main()
{//WRITE("in.txt");
    int pre,cur,n,tc=0;

    while(cin>> str>> n)
    {//out(str);
        if(str[0] == '0' && str.length() == 1 && !n) break;
        tc++;
        int num=0,res=0;
        ///octal
        if(str[0] == '0' && str[1] != 'x')
        {//out("ok,,,,,,,,");
            int p = 0;
            int len = str.length()-1;

            while(len>=1)
            {
                int temp = (int)str[len]-'0';
                num += (temp * ipow(8,p));
                p++;
                len--;
            }//cout<<num<<endl;
        }
        ///hexadecimal
        else if(str[0] == '0' && str[1] == 'x')
        {//out("ok");
            int p = 0,len = str.length()-1;
            while(len>=2)
            {
                int temp;
                if(str[len]>='0' && str[len]<='9') temp = (int) str[len]-'0';
                else temp = ( (int) str[len]-'A') + 10;
//out(temp);
                num += (temp * ipow(16,p));
                len--;
                p++;
            }//cout<<num<<".."<<endl;
        }
        else
        {//out("ok//////");
            int len = str.length(),mul=10;
            for(int i=0; i<len; i++)
            {
                int temp = (int)str[i]-'0';
                num *= mul;
                num += temp;
            }//cout<<num<<endl;
        }
        int pre1 = -inf,fl=0,res2=-1;
        pre = num;
        string inp,ans;

        while(n--)
        {
            cin>> inp>> ans;//cout<<pre<<" "<<convert(ans)<<endl;
            int given = convert(ans);

            if(inp == "++i")
            {
                pre ++;
                if(pre == given) res++;
                else pre = given;
            }
            else if(inp == "--i")
            {
                pre--;
                if(pre == given) res++;
                else pre = given;
            }
            else if(inp == "i++")
            {
                if(pre == given) res++,pre++;
                else pre = given+1;
            }
            else if(inp == "i--")
            {
                if(pre == given) res++,pre--;
                else pre = given-1;
            }
            else
            {
                if(pre == given) res++;
                else pre = given;
            }
        }
        pf("%d\n", max(res,res2));//if(tc == 152) system("pause");
    }

    return 0;
}