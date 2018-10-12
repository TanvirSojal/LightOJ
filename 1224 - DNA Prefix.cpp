#include<bits/stdc++.h>
using namespace std;
 
int res;
 
struct node{
    int cnt;
    int depth;
    node* next[4];
 
    node(){
        cnt = 0;
        depth = 0;
        for (int i=0; i<4; i++){
            next[i] = NULL;
        }
    }
 
 
};
 
void Insert(node* root, char *s){
    int ch, sz = strlen(s);
    node* cur = root;
 
    for (int i=0; i<sz; i++){
        if (s[i]=='A') ch = 0;
        else if (s[i]=='C') ch = 1;
        else if (s[i]=='G') ch = 2;
        else ch = 3;
        if (cur->next[ch] == NULL){
            cur->next[ch] = new node;
        }
 
        cur = cur->next[ch];
        cur->cnt++;
        cur->depth = i + 1;
        res = max(res, (cur->depth * cur->cnt));
    }
}
 
void Delete(node* root){
    for (int i=0; i<4; i++){
        if (root->next[i]!=NULL){
            Delete(root->next[i]);
        }
    }
    delete(root);
}
 
 
int main()
{
    //freopen("input.txt", "r", stdin);
    int T; scanf("%d", &T);
    for (int cs=1; cs<=T; cs++){
        node* root = new node;
        int n; scanf("%d", &n);
        while(n--){
            char s[52];
            scanf("%s", s);
            Insert(root, s);
        }
        printf("Case %d: %d\n", cs, res);
        Delete(root);
        res = 0;
 
    }
    return 0;
}
