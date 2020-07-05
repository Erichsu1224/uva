#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PB push_back
#define PII pair<int, int>
#define MP make_pair
#define all(x) x.begin(), x.end()
#define REP(x, y, z) for(int x = (y); x <= (z); x++)
#define REPP(x, y, z) for(int x = (y); x >= (z); x--)
#define F first
#define S second
#define MSET(x, y) memset(x, y, sizeof(x)) 
#define EB emplace_back
#define maxn
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure
struct Node
{
	int num;
	Node* left;
	Node* right;

	Node(int n){
		num = n;
		left = NULL;
		right = NULL;
	}
};

//declaration
Node* tree;
int n;
char str[300];
vector<int> v;
bool flag_hasvalue;
//functions
void init(){
	v.clear();
	Node *p = new Node(-1);
	tree = p;
	flag_hasvalue = false;
}

void addNode(int n, char* tra){
	Node* ptr = tree;

	for(int i = 0; i < strlen(tra); i++){
		if(i == strlen(tra)-1){
			if(ptr->num != -1)
				flag_hasvalue = true;
			ptr->num = n;
		}
			

		if(tra[i] == 'L'){
			if(ptr->left == NULL){
				Node *p = new Node(-1);
				ptr->left = p;
			}
			
			ptr = ptr->left;
		}
		if(tra[i] == 'R'){
			if(ptr->right == NULL){
				Node *p = new Node(-1);
				ptr->right = p;
			}
			ptr = ptr->right;
		}
	}
}

bool input(){
	init();
	while(true){
		if(scanf("%s", str) == EOF){
			return false;
		}

		if(!strcmp(str, "()")){
			break;
		}

		sscanf(str+1, "%d", &n);

		addNode(n, strchr(str, ',')+1);
	}
	return true;
}

bool dfs(Node *ptr){
	if(ptr->num == -1)
		return false;

	if(ptr->left != NULL){
		if(!dfs(ptr->left))
			return false;
	}
	if(ptr->right != NULL)
		if(!dfs(ptr->right))
			return false;

	return true;
}

void bfs(Node *ptr){
	
	queue<Node*> q;

	q.push(ptr);

	while(!q.empty()){
		auto now = q.front();	q.pop();
		v.EB(now->num);

		if(now->left != NULL){
			q.push(now->left);
		}
			
		if(now->right != NULL){
			q.push(now->right);
		}
	}
}

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	while(input()){
		if(flag_hasvalue || !dfs(tree))
			printf("not complete\n");
		else{
			bfs(tree);
			for(int i = 0; i < v.size(); i++){
				if(i == 0)
					printf("%d", v[i]);
				else
					printf(" %d", v[i]);
			}
			puts("");
		}
	}
	
	return 0;
}