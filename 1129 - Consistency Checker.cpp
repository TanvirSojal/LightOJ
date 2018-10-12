#include<bits/stdc++.h>
using namespace std;
 
bool ok;
 
struct Trie{
    int cnt;
    bool endMark;
    Trie* next[10];
    Trie(){
        cnt = 0;
        endMark = false;
        for (int i=0; i<10; i++){
            next[i] = NULL;
        }
    }
};
 
void Insert(Trie* root, string s){
    Trie* cur = root;
    int sz = s.size();
    for (int i=0; i<sz; i++){
        int ch = (int)(s[i] - '0');
        if (cur->next[ch] == NULL){
            cur->next[ch] = new Trie;
        }
        cur->next[ch]->cnt++;
        if (cur->next[ch]->endMark == true &&  cur->next[ch]->cnt > 1){
            ok = false;
        }
        cur = cur->next[ch];
    }
    cur->endMark = true;
}
 
void Delete(Trie* root){
    for (int i=0; i<10; i++){
        if (root->next[i]!=NULL){
            Delete(root->next[i]);
        }
    }
    delete(root);
}
 
int main()
{
    //freopen("in.txt", "r", stdin);
    int T; scanf("%d", &T);
    for (int cs=1; cs<=T; cs++){
        ok = true;
        Trie* root = new Trie;
        int n; scanf("%d", &n);
        vector < string > v;
        for (int i=0; i<n; i++){
            string s; cin >> s;
            v.push_back(s);
        }
        sort(v.begin(), v.end());
        for (int i=0; i<n; i++){
            Insert(root, v[i]);
        }
        if (ok) printf("Case %d: YES\n", cs);
        else printf("Case %d: NO\n", cs);
        Delete(root);
    }
    return 0;
}
 
