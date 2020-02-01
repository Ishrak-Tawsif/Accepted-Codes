#include<bits/stdc++.h>
using namespace std;

#define ll long long int

struct name{

    string first, second;

        bool operator <(const name & x) const{
            if(x.second == second) return x.first>first;
            return x.second > second;
        }
};


int main(){

    vector <name> str;
    name str_var;
    int n;
        cin>> n;

            for(int i=0; i<n; i++){
                cin>> str_var.first>> str_var.second;
                str.push_back(str_var);
            }
            sort(str.begin(),str.end());
            for(int i=0; i<n; i++) cout << str[i].first << " " << str[i].second << endl;
return 0;
}