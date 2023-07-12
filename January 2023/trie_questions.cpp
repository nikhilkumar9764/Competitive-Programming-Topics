/*Design an Autocorrect system in which you can add words and get a correct 
word for a given query word. 
  
For a given query word, the Autocorrect system handles two categories of 
spelling mistakes: 
  
Capitalization: If the query matches a word in the wordlist (case-insensitive), 
then the query word is returned with the same case as the case in the wordlist. 
Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow" 
Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow" 
Example: wordlist = ["yellow"], query = "yellow": correct = "yellow" 
  
   
Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the query word 
with any vowel individually, it matches a word in the wordlist (case-insensitive), 
then the query word is returned with the same case as the match in the wordlist. 
Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw" 
Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match) 
Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match) 
  
  
In addition, the auto correct system operates under the following precedence 
rules: 
● When the query exactly matches a word in the wordlist (case-sensitive), 
you should return the same word back. 
● When the query matches a word up to capitalization, you should return the 
first such match in the wordlist. 
● When the query matches a word up to vowel errors, you should return the 
first such match in the wordlist. 
● If the query has no matches in the wordlist, you should return the empty 
string. 

Example 1: 
 
Input: 
add("KiTe");
add("kite");
add("hare");
add("Hare");
 
query("kite") -> "kite"
query("Kite") -> "KiTe"
query("KiTe") -> "KiTe"
query("Hare") -> "Hare"
query("HARE") -> "hare"
query("Hear") -> ""
query("hear") -> ""
query("keti") -> "KiTe"
query("keet") -> ""
query("keto") -> "KiTe

*/


#include<bits/stdc++.h>
using namespace std;
#define MAX (1e6+7)

struct Node{
   char data;
   struct Node* children;
};


Node* insert(string x,int idx)
{
    if(idx == x.size())
    {
        return;
    }
    Node* x1 = new Node();
    x1->data = x[idx];
    x1->children = insert(x,idx+1);
}


string query(Node* root , string qu , int idx,  string &res)
{
    if(qu[idx]->data == root->data)
    {
        res+=qu[idx];
        
    }
    else if()
}



/* Given a long string phone number and a sequence of strings with each character representing the digits of a keypad .
2 --> abc , 3 --> def , 4--> ghi , 5--> jkl , 6--> mno , 7--> pqrs , 8-->tuv , 9 --> wxyz
  */