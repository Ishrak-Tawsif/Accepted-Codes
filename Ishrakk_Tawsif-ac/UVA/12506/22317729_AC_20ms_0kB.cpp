#include <iostream>
using namespace std;

struct node{
	int cnt;
	node *next[27];
	node(){
		cnt = 0;
		for (int i = 0; i < 26; i++) next[i] = NULL;
	}
} *root;

char ch[1000005];

void insert(){
	node *cur = root;
	for (int i = 0; ch[i] != '\0'; i++){
		int now = ch[i] - 'a'; //cout << now << endl;
		if (cur->next[now] == NULL){
			cur->next[now] = new node();
			//cur->cnt++;
		}
		cur = cur->next[now];
		cur->cnt++;
	}
}

int dfs(node *cur,int level){
	if (cur == NULL) return 0;
	if (cur->cnt == 1) return level;
	int res = 0;
	for (int i = 0; i < 26; i++){
		if (cur->next[i] != NULL){
			res += dfs(cur->next[i], level + 1);
		}
	}
	return res;
}

void del(node *cur){
	for (int i = 0; i < 26; i++){
		if (cur->next[i] != NULL) del(cur->next[i]);
	}
	delete(cur);
}

int main(){
	int tc,n;

	cin >> tc;

	for (int tt = 1; tt <= tc; tt++){
		cin >> n;
		root = new node();
		for (int i = 1; i <= n; i++){
			cin >> ch;
			insert();
		}

		int ans = dfs(root,0);
		cout<<ans<<endl;
		del(root);
	}
	//int hold;
	//cin >> hold;
	return 0;
}