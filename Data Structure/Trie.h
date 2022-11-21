#include <bits/stdc++.h>
using namespace std;
const int ALPHABET_SIZE = 26;
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool endmark;
};
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;
 
    pNode->endmark = false;
 
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
 
    return pNode;
}
TrieNode *root=getNode();
void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
 
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
 
        pCrawl = pCrawl->children[index];
    }
    pCrawl->endmark = true;
}
bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
 
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;
 
        pCrawl = pCrawl->children[index];
    }
 
    return (pCrawl->endmark);
}
bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}
 

TrieNode* remove(TrieNode* root, string key, int depth = 0)
{
    if (!root)
    if (depth == key.size()) {
        if (root->endmark)
            root->endmark = false;
 
        if (isEmpty(root)) {
            delete (root);
            root = NULL;
        }
 
        return root;
    }
    int index = key[depth] - 'a';
    root->children[index] =remove(root->children[index], key, depth + 1);

    if (isEmpty(root) && root->endmark == false) {
        delete (root);
        root = NULL;
    }
 
    return root;
}
 
void display(struct TrieNode* root, char str[], int level)
{
    if (root->endmark==true) 
    {
        str[level] = '\0';
        cout << str << endl;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) 
    {      
        if (root->children[i]) 
        {
            str[level] = i + 'a';
            display(root->children[i], str, level + 1);
        }
    }
}

 