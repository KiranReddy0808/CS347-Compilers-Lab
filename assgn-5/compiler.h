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

enum DataType
{
    dt_int,
    dt_flt,
    dt_void,
    dt_err
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


bool SemanticAnalysis(Node *root);

void printTree(Node *root);