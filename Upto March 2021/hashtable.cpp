#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
class Node 
{
public:
    string key;
    T value; // value to be generic
    Node<T>* next;
    Node(string key,T value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
    
};

template<typename T>
class Hashtable
{
public : 
   int ts;
   int cs;
   Node<T> **arr;
   Hashtable(int ts = 2)
   {
       this->ts = ts;
       this->cs = 0;
       arr = new Node<T>*[this->ts];
       for(int i=0;i<this->ts;i++)
       {
           this->arr[i] = NULL;
       }
   }

   void display()
   {
      for(int i=0;i<this->ts;i++)
      {
       Node<T>* temp = this->arr[i];
       if(temp == NULL)
       {
           cout<<"Empty\n";
           continue;
       }
       while(temp!=NULL)
       {
           cout<<"("<<temp->key<<","<<temp->value<<")"<<"\n";
           temp = temp->next;
       }
      }
   }

   int hashfunc(string key)
   {
       int su = 0;
       int factor = 1;
       for(int i=0;i<key.size();i++)
       {
           su = (su%this->ts) + ((int)key[i]*factor)%this->ts;
           su = su%this->ts;
           factor = ((factor%this->ts) * (37%this->ts))%this->ts;
       }
       return (int)(su);
   }

   void rehash()
   {
       int old_size = this->ts;
       this->ts = 2*old_size;
       Node<T>** old_table = this->arr;
       this->arr = new Node<T>*[this->ts];
       for(int i=0;i<this->ts;i++)
       {
           this->arr[i] = NULL;
       }
       for(int i=0;i<old_size;i++)
       {
           Node<T>  *temp = old_table[i];
           while(temp!=NULL)
           {
               insert(temp->key,temp->value);
               temp = temp->next;
           }
       }
   }

   void insert(string key,T value)
   {
       int bi = hashfunc(key); 
       T res = search(key);
       if(res!=NULL)
       {
           Node<T> *temp = this->arr[bi];
           while(temp!=NULL)
           {
               if(temp->key == key)
               {
                   temp->value = value;
               }
               temp = temp->next;
           }
           return;
       }
       Node<T>* new_node = new Node<T>(key,value);
       if(this->arr[bi] == NULL)
       {
           this->arr[bi] = new_node;
       }
       else{
           //collision occurrs
           new_node->next = this->arr[bi];
           this->arr[bi] = new_node;
       }
       this->cs++;
       double lf = (double) (cs)/ts;
       if(lf>0.5)
       {
           rehash();
       }
   }

   T search(string key)
   {
       int idx = hashfunc(key);
       Node<T> *temp = this->arr[idx];
       while(temp!=NULL)
       {
           if(temp->key == key)
           {
               return temp->value;
           }
           temp = temp->next;
       }
       return NULL;
   }
};

int main()
{
    int n;
    cin>>n;
    Hashtable<int>* hash = new Hashtable<int>();
    while(n--)
    {
        string key;
        int value;
        cin>>key>>value;
        hash->insert(key,value);
    }
    hash->display();
}