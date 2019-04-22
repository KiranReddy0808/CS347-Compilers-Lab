#include <bits/stdc++.h>

using namespace std;

struct Node
{
    string dataType;
    string valueType;
    vector <Node *> childs;
    Node(string dataType, string valueType){
        this->dataType = dataType;
        this->valueType = valueType;
    }
};

void printTree(Node *root);