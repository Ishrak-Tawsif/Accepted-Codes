#include<bits/stdc++.h>
using namespace std;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

/*#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
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
#define inf                     2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      5000005
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

string add(string num1,string num2)
{
    if(num1.length()<num2.length())
    {
        ///swap
        string temp = num1;
        num1 = num2;
        num2 = temp;
    }

    int i=num1.length()-1,j = num2.length()-1,carry=0,temp;
    string ans = "";
    while(i>=0 && j>=0)
    {
        temp = (num1[i]-'0' + num2[j]-'0') + carry;//cout<<num1[i]<<endl;
        if(temp>=10)
        {
            ans += (temp%10 + '0');
            temp /= 10;
            carry = temp%10;
        }
        else
        {
            ans += (temp + '0');
            carry = 0;
        }
        i--;
        j--;
    }//cout<<i<<" "<<j<<endl;
    if(i>=0)
    {
        while(i>=0)
        {
            temp = num1[i]-'0';
            temp += carry;//cout<<temp<<" "<<carry<<endl;;
            //while(temp!=0) ans += (temp%10)+'0',temp/=10;
            if(temp>=10)
            {
                ans += (temp%10)+'0';
                temp /= 10;
                carry = temp%10;
            }
            else
            {
                ans += (temp+'0');
                carry = 0;
            }
            i--;
        }
        //while(i>=0) ans += num1[i],i--;
        if(carry) ans += (carry + '0');
    }
    else
    {//out(carry);
        if(carry) ans += (carry + '0');
    }
    reverse(ans.begin(),ans.end());
    return ans;
}


int main()
{//WRITE("in.txt");

    string n,temp;

    cin>> n;

    temp = '1';

    if(temp == n) {pf("1\n"); return 0;}

    for(int i=2; ; i++)
    {
        int koybar = i;
        string cur = "0";

        while(koybar--)
        {
            cur = add(cur,temp);
            //if(i == 15) out(cur);
        }
        temp = cur;
        //out(temp);
        if(temp == n) {pf("%d\n",i); break;}//system("pause");
    }//out(temp);out(temp.size());

    return 0;
}