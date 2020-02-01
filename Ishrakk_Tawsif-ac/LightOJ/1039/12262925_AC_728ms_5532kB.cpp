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
    #define casepf(nn)              printf ("Case %d: ",nn)
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
    #define all(a)                  (a.begin(),a.end())
    #define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
    #define mx                      10005
    #define mod                     1000000007
     
    template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
    template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
     
    string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
    ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}
     
    /* ...........................................................................................................*/
     
    map <string,int> isforbidden,vis;
     
    char convert(char ch,int k)
    {
        int now = (ch-'a');
        now += k;
        now = now%26;
        now += 26;
        now %= 26;
        now += (int) 'a';
        ch = (char)(now);//out(now);
        return ch;
    }
     
    int bfs(string st,string en)
    {
        queue <pair<string,int > > q;
        vis.clear();
        q.push(mp(st,0));
     
        while(!q.empty())
        {
            string cur = q.front().first;
            int dis = q.front().second;
            q.pop();
     
            if(cur == en) return dis;
     
            string temp;
            for(int i=0; i<cur.length(); i++)
            {
                temp = cur;
                temp[i] = convert(cur[i],1);
                if(!isforbidden[temp] && !vis[temp])
                {
                    vis[temp] = 1;
                    q.push(mp(temp,dis+1));
                }
                temp = cur;
                temp[i] = convert(cur[i],-1);
                if(!isforbidden[temp] && !vis[temp])
                {
                    vis[temp] = 1;
                    q.push(mp(temp,dis+1));
                }
            }
        }
    }
     
    void clearall()
    {
        vis.clear();
        isforbidden.clear();
    }
     
    int main()
    {//WRITE("in.txt");
        int tc,n;
     
        sf(tc);
        //char ch;int k;while(cin>> ch>> k)out(convert(ch,k));
        for(int tt=1; tt<=tc; tt++)
        {
            string st,en;
     
            cin>> st>> en;
     
            sf(n);
     
            clearall();
     
            string f,s,t;
            for(int i=0; i<n; i++)
            {
                cin>> f>> s>> t;
                int len1 = f.length();
                int len2 = s.length();
                int len3 = t.length();
     
                for(int j=0; j<len1; j++)
                {
                    for(int k=0; k<len2; k++)
                    {
                        for(int l=0; l<len3; l++)
                        {
                            string temp = "";
                            temp += f[j]; temp += s[k]; temp += t[l];//out(temp);
                            isforbidden[temp] = 1;
                        }
                    }
                }
            }
     
            casepf(tt);
     
            if(isforbidden[st] || isforbidden[en]){pf("-1\n");continue;}
     
            int res = bfs(st,en);
            pf("%d\n", res);
     
        }
        return 0;
    }