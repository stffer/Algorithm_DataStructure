#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>
using namespace std;

struct Node{
	int key;
	Node *left,*right,*fa;
	Node(int k=0,Node *f=NULL){
		left=right=NULL;
		fa=f;
		key=k;
	}
};
class Splay{
public:
	Node *root;
	Node *_hot;
	Splay(){
		root=_hot=NULL;
	}
	Splay(int k){
		root = new Node(k,NULL);
		_hot = root;
	}
	//right
	void zig(Node *cur){
		if(cur == NULL) return;
		Node *v  =cur->left;
		if(v == NULL) return;
		Node *g = cur->fa;
		v->fa = g;	
		if(g != NULL){
			if(cur == g->left) 
				g->left = v;
			else 
				g->right = v;
		}
		cur->left = v->right;
		if(cur->left != NULL) 
			cur->left->fa = cur;
		cur->fa = v;
		v->right = cur;
		if(cur == root) root = v;
	}
	//left
	void zag(Node *cur){
		if(cur == NULL) return;
		Node *v = cur->right;
		if(v == NULL) return;
		Node *g = cur->fa;
		v->fa = g;	
		if(g != NULL){
			if(cur == g->left) 
				g->left = v;
			else 
				g->right = v;
		}
		cur->right = v->left;
		if(cur->right != NULL) 
			cur->right->fa = cur;
		cur->fa = v;
		v->left= cur;
		if(cur == root) root = v;
			
	}
	void splay(Node *x,Node *f){
		if(x == NULL) return;
		while(x->fa != f){
			Node *p = x->fa;
			if(p == NULL) return;
			if(p->fa == f){
				if(x == p->left){
					zig(p);
				}
				else{
					zag(p);
				}
			}
			else{
				Node *g = p->fa;
				if(g == NULL) return;
				if(g->left == p){
					if(p->left == x){
						zig(g);zig(p);
					}	
					else{
						zag(p);zig(g);
					}
				} 
				else{
					if(p->left == x){
						zig(p);zag(g);
					}
					else{
						zag(g);zag(p);
					}
				}
			}
		}
	}
	Node* search(Node *cur,int k){
		if(cur == NULL) 
			return _hot;
		if(cur->key == k){
			splay(cur,NULL);
			return cur;
		}
		_hot = cur;
		if(k < cur->key)
			return search(cur->left,k);
		else 
			return search(cur->right,k);
	}
	Node* insert(Node *cur,int k){
		if(cur == NULL){
			cur = new Node(k,_hot);
			if(k < _hot->key) _hot->left=cur;
			else _hot->right=cur;
			_hot = cur;
			splay(cur,NULL);
			return cur;
		}	
		_hot = cur;
		if(k < cur->key)
			return insert(cur->left,k);
		else return insert(cur->right,k);
	}
	Node* prev(int k){
		splay(search(root,k),NULL);
		Node *cur = root->left;
		if(cur == NULL) return NULL;
		while(cur->right != NULL) cur = cur->right;
		return cur;
	}
	Node* succ(int k){
		splay(search(root,k),NULL);
		Node *cur = root->right;
		if(cur == NULL) return NULL;
		while(cur->left != NULL) cur = cur->left;
		return cur;
	}
	void deleteab(int a,int b){
		Node *pa = search(root,a);
		if(pa->key != a)
			pa = insert(pa,a);
		Node *pb = search(root,b);
		if(pb->key != b)
			pb = insert(pb,b);
		Node *p = prev(a);
		Node *s = succ(b);
		splay(p,NULL);
		splay(s,p);
		_hot = s;
		s->left = NULL;
	}
};
const int MIN_K = 0;
const int MAX_K = 1000000005;
int main()
{
	Splay *tree = new Splay(MIN_K);
	tree->insert(tree->root,MAX_K);
	int n,number;
	char op;
	cin>>n;
	while(n--){
		cin>>op>>number;
		if(op=='I'){
			tree->insert(tree->root,number);	
		}
		else if(op=='Q'){
			Node *t = tree->search(tree->root,number);
			if(number < t->key)
				t = tree->prev(number);
			printf("%d\n",t->key);
		}
		else if(op=='D'){
			int b;
			cin>>b;
			tree->deleteab(number,b);
		}
	}	
	return 0;
}
