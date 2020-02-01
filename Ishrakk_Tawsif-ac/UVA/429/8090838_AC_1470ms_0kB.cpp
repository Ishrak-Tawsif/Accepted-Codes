#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int dir_r[]={0,-1,1,0};
int dir_c[]={-1,0,0,1};
//int n,vis[101][101];

unordered_map <string,int> dictionary;
unordered_map <string,int> vis,dis;

string word_change(string str,int pos,char alpha)
{
    str[pos]=alpha;
    return str;
}

bool isindictionary(string str)
{
    if(dictionary[str]==1) return true;
    return false;
}

string grid[101];
/*
int dfs(int i,int j)
{
    vis[i][j]=1;//cout<< i <<" "<< j <<endl;
    //system("pause");
        for(int k=0; k<4; k++)
        {
            int temp_r=i+dir_r[k];
            int temp_c=j+dir_c[k];
                if(temp_r>=0 && temp_r<n && temp_c>=0 && temp_c<n && !vis[temp_r][temp_c] && grid[temp_r][temp_c]!='.')
                    dfs(temp_r,temp_c);
        }
}
*/
int bfs(string s,string d)
{
    queue <string> q;
    q.push(s);
    vis[s]=1;
    dis[s]=0;

        while(!q.empty())
        {
            string temp=q.front();
            q.pop();
//cout<<temp<<endl;
            if(temp==d) return dis[temp];
            if(d.length()!=temp.length()) continue;

                for(int j=0; j<temp.length(); j++){

                    for(int i=97; i<=122; i++)
                    {
                        char c=(char)i;

                            string ss=word_change(temp,j,c);
                            //cout<<ss<<" "<<isindictionary(ss)<<endl;
                            if(isindictionary(ss) && !vis[ss]){
                                vis[ss]=1;
                                //cout<<temp<<endl;
                                dis[ss]=dis[temp]+1;
                                q.push(ss);
                            }
                    }
                }
                //system("pause");
        }
}

int main()
{
    int tc;
    //cout<<word_change("nerob",4,'n')<<endl;
    /*dictionary["nirob"]=1;
    cout<<dictionary["nirob"] <<" " <<dictionary["tawsif"]<<endl;
    dictionary.clear();
    cout<<dictionary["nirob"] <<" " <<dictionary["tawsif"]<<endl;
    for(int i=97; i<=122; i++) cout<<(char)i<<endl;*/
    //bfs("nerob","ssdf");

        scanf("%d", &tc);
        for(int tt=1; tt<=tc; tt++)
        {
            string str,str_des,line;
            dictionary.clear();
                //cin.ignore();
                while(cin>> str)
                {
                    if(str[0]=='*') break;
                    dictionary[str]=1;//cout<<tc<<endl;
                }
           cin.ignore();

           while (getline(cin, line) && line != "")
            {
                stringstream ss(line);
                string str, str_des;
                ss >> str >> str_des;//cout<<str<<" "<<str_des<<endl;
                vis.clear(); dis.clear();
                cout << str <<" "<<str_des <<" "<< bfs(str,str_des) <<endl;
           }

           if(tt!=tc) cout<<endl;
        }
   return 0;
}

/*
dip
lip
mad
map
maple
may
pad
pip
pod
pop
sap
sip
slice
slick
spice
stick
stock
*
spice stock
may pod

*/