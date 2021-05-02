#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD (ll) (1e9+7)
/* Trie data structure to find occurrences of all possible combinations
starting with something just like how a search engine works*/
class Node
{
public:
    char ch;
    bool terminal;
    unordered_map<char,Node*> children;
    Node(char x)
    {
        this->ch = x;
        this->terminal = false;
    }
};

class Trie
{
public:
    Node* root;
    Trie()
    {
        this->root = new Node('\0');
    }
    void insert(string str)
    {
        ll len = str.size();
        Node* temp = this->root;
        for(int i=0;i<len;i++)
        {
            char ch = str[i];
            if(temp->children.count(ch))
            {
                temp = temp->children[ch];
            }
            else{
                Node* np = new Node(ch);
                temp->children[ch] = np;
                temp = temp->children[ch];
            }
        }
        temp->terminal = true;
    }

    void dfs(Node* temp,string str,string res)
    {
        if(temp == NULL)
        {
            return;
        }
        if(temp->terminal == true)
        {
           cout<<str+res<<"\n";
        }
        for(auto it:temp->children)
        {
            dfs(it.second,str,res+it.first);
        }
    }

    void autocomplete(string str)
    {
        ll len = str.size();
        Node* temp = this->root;
        for(int i=0;i<len;i++)
        {
            char ch = str[i];
            if(temp->children.count(ch))
            {
                temp = temp->children[ch];
            }
            else{
               return;
            }
        }
        dfs(temp,str,"");
    }
};
int main()
{
    Trie t;
    ll n; // The no of strings
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        t.insert(s);
    }
    string pat;// the string which is to be auto completed;
    cin>>pat;
    t.autocomplete(pat);
}