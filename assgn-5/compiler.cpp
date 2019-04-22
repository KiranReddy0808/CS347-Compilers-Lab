#include <bits/stdc++.h>
#include "compiler.h"

using namespace std;

void printTree(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    Node *curr;
    q.push(root);
    q.push(NULL);
    while (q.size() > 1)
    {
        curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            q.push(NULL);
            cout << "\n\n";
        }
        else
        {
            for (int i=0; i<curr->childs.size(); i++)
            {
                q.push(curr->childs[i]);
            }
            cout << curr->dataType << ", " << curr->valueType << " ## ";
        }
    }
}

bool SemanticAnalysis(Node *root){
    return true;
}