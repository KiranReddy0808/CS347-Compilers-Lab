#include <bits/stdc++.h>

using namespace std;

enum DataType
{
	dt_string,
	dt_num,
    dt_id,
    dt_cond,
    dt_expr,
    dt_col,
    dt_attr
};

enum ExprType
{
    et_none,
    et_num,
    et_str,
    et_col,
    et_plus,
    et_minus,
    et_times,
    et_divide,
    et_neg
};

enum CombType
{
    cb_none,
    cb_or,
    cb_and
};

enum CompType
{
    cp_none,
    cp_lt,
    cp_gt,
    cp_gte,
    cp_lte,
    cp_eq,
    cp_neq
};

struct Node
{
    DataType dataType;
    float num;
    string str;
    ExprType expr;
    CombType comb;
    CompType comp;
    Node *child1;
    Node *child2;
};

class Column{
    public:
        string columnName;
        void *table;
        DataType dataType;
        vector<string> str_entries;
        vector<float> num_entries;
        Column (void *, string);
        Column (void *, Node *);
        Column (void *);
        Column *operator + (Column const &);
        Column *operator - (Column const &);
        Column *operator - ();
        Column *operator * (Column const &);
        Column *operator / (Column const &);
        vector <bool> operator< (Column const &);
        vector <bool> operator> (Column const &);
        vector <bool> operator<= (Column const &);
        vector <bool> operator>= (Column const &);
        vector <bool> operator== (Column const &);
        vector <bool> operator!= (Column const &);
        void addData(string);
        void printData(int);
        
};

class Table{
    public:
        vector<Column*> columns;
        string tableName;
        int numRows;
        Table ();
        Table (string);
        int columnExists (string);
        void printTable();
        void printTable(vector <bool> &);
        Table* operator * (Table const &);
};

Column *computeExpression(Node *, Table *);
vector <bool> computeCondition(Node *, Table *);

vector <bool> combAnd(vector <bool> &, vector <bool> &);
vector <bool> combOr(vector <bool> &, vector <bool> &);

void tableProductResult(string, string);

void tableProjectResult(string, Node*);

void tableSelectResult(string, Node*);

void tableEquiJoinResult(string, string, Node*);

void selectRows();

void printTree(Node *);