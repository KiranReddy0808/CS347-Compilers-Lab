#include <bits/stdc++.h>

using namespace std;

enum DataType
{
    dt_int,
    dt_flt,
    dt_void,
    dt_err
};

struct Node
{
    string dataType;
    string valueType;
    vector <Node *> childs;

    DataType elemType;
    string code;
    float nodeVal;
    vector<int> dimList;
    vector<Node *> paramList;
    Node(string dataType, string valueType){
        this->dataType = dataType;
        this->valueType = valueType;
    }
};

struct SymbolNode
{
    string name;
    bool array;
    int level;
    vector<int> dimList;
    DataType type;
    SymbolNode(string name, bool array, int level, DataType type){
        this->name = name;
        this->array = array;
        this->level = level;
        this->type = type; 
    }
};

struct FuncNode
{
    string name;
    DataType retType;
    vector<SymbolNode*> paramList;
    vector<SymbolNode*> localVar;
    FuncNode (string name, DataType retType){
        this->name=name;
        this->retType=retType;
    }
};

void printTree(Node *root);