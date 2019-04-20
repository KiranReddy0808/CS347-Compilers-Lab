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