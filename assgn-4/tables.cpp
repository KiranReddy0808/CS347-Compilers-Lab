#include <bits/stdc++.h>
#include "tables.h"

using namespace std;

bool isFloat( const string &in) {
    std::stringstream sstr(in);
    float f;
    return bool(sstr >> f);
}

Table::Table(string tableName)
{
    ifstream tableFile(tableName+".csv");
    if (tableFile.good()){
        this->tableName = tableName;
        string row;
        string entry;
        getline(tableFile, row);
        stringstream s(row);
        while (getline(s, entry, ',')) {
            this->columns.push_back(new Column((void *)this, entry));
        }
        this->numRows = 0;
        if (getline(tableFile, row)){
            stringstream s(row);
            int col = 0;
            while (getline(s, entry, ',')) {
                if (isFloat(entry)){
                    this->columns[col]->dataType = dt_num;
                    this->columns[col]->addData(entry);
                }
                else{
                    this->columns[col]->dataType = dt_string;
                    this->columns[col]->addData(entry);
                }
                col++;
            }
            this->numRows++;
            while(getline(tableFile, row)){
                stringstream s(row);
                int col = 0;
                while (getline(s, entry, ',')) {
                    this->columns[col]->addData(entry);
                    col++;
                }
                this->numRows++;
            }
        }
        else{
            throw std::runtime_error(tableName+" table has no data");
        }
        tableFile.close();

    }
    else{
        throw std::runtime_error(tableName+" table not found");
    }
}

Table::Table(){
}

Table* Table::operator * (Table const &table){
    Table *product = new Table();
    product->tableName = "product table";
    int firstColumns = this->columns.size();
    for (int i=0; i<this->columns.size(); i++){
        product->columns.push_back(new Column((void *)product, this->tableName+"."+this->columns[i]->columnName));
        product->columns[i]->dataType = this->columns[i]->dataType;
        // cout << this->tableName+"."+this->columns[i]->columnName << " ";
    }
    for (int i=0; i<table.columns.size(); i++){
        product->columns.push_back(new Column((void *)product, table.tableName+"."+table.columns[i]->columnName));
        product->columns[firstColumns+i]->dataType = table.columns[i]->dataType;
        // cout << table.tableName+"."+table.columns[i]->columnName << " ";
    }
    // cout << endl;
    product->numRows = 0;
    for (int i=0; i<this->numRows; i++){
        for (int j=0; j<table.numRows; j++){
            for (int k=0; k<this->columns.size(); k++){
                if (product->columns[k]->dataType == dt_num){
                    product->columns[k]->num_entries.push_back(this->columns[k]->num_entries[i]);
                    // cout << product->columns[k]->num_entries[product->numRows] << " ";
                }
                else if (product->columns[k]->dataType == dt_string){
                    product->columns[k]->str_entries.push_back(this->columns[k]->str_entries[i]);
                    // cout << product->columns[k]->str_entries[product->numRows] << " ";
                }
            }
            for (int k=0; k<this->columns.size(); k++){
                if (product->columns[firstColumns+k]->dataType == dt_num){
                    product->columns[firstColumns+k]->num_entries.push_back(table.columns[k]->num_entries[j]);
                    // cout << product->columns[firstColumns+k]->num_entries[product->numRows] << " ";
                }
                else if (product->columns[firstColumns+k]->dataType == dt_string){
                    product->columns[firstColumns+k]->str_entries.push_back(table.columns[k]->str_entries[j]);
                    // cout << product->columns[firstColumns+k]->str_entries[product->numRows] << " ";
                }
            }
            // cout << endl;
            product->numRows++;
        }
    }
    // cout << product->numRows << endl;
    return product;
}

int Table::columnExists(string colName){
    for (int i=0; i<this->columns.size(); i++){
        if (this->columns[i]->columnName == colName){
            return i;
        }
    }
    return -1;
}

void Table::printTable(){
    for (int j=0; j<this->columns.size(); j++){
        cout << this->columns[j]->columnName << " ";
    }
    cout<<endl;
    for(int i=0; i<this->numRows; i++){
        for (int j=0; j<this->columns.size(); j++){
            this->columns[j]->printData(i);
            cout << " ";
        }
        cout<<endl;
    }
}

void Table::printTable(vector <bool> &filter){
    for (int j=0; j<this->columns.size(); j++){
        cout << this->columns[j]->columnName << " ";
    }
    cout<<endl;
    for(int i=0; i<this->numRows; i++){
        if (filter[i]){
            for (int j=0; j<this->columns.size(); j++){
                this->columns[j]->printData(i);
                cout << " ";
            }
            cout<<endl;
        }
    }
}

Column::Column(void *table, string columnName){
    if (table != NULL){
        this->table = table;
        this->columnName = columnName;
    }
    else{
        throw std::runtime_error("There is no table for "+columnName);
    }
}

Column::Column(void *table, Node *data){
    if (table != NULL){
        Table *table1 = (Table *)table;
        this->table = table;
        if (data->dataType == dt_num){
            this->dataType = data->dataType;
            this->columnName = to_string(data->num);
            this->num_entries.assign(table1->numRows, data->num);
        }
        else if (data->dataType == dt_string){
            this->dataType = data->dataType;
            this->columnName = data->str;
            this->str_entries.assign(table1->numRows, data->str);
        }
        else{
            throw std::runtime_error("Invalid datatype to make a column");
        }
    }
    else{
        throw std::runtime_error("Table doesn't exist");
    }
}

Column::Column(void *table){
    if (table != NULL){
        Table *table1 = (Table *)table;
        this->table = table;
    }
    else{
        throw std::runtime_error("Table doesn't exist");
    }

}

void Column::addData(string data){
    if (this->dataType == dt_num){
        this->num_entries.push_back(stof(data));
    }
    else if (this->dataType == dt_string){
        this->str_entries.push_back(data);
    }
}

void Column::printData(int row){
    if (this->dataType == dt_num){
        cout<<this->num_entries[row];
    }
    else if(this->dataType == dt_string){
        cout<<this->str_entries[row];
    }
}



Column *Column::operator+ (Column const &col){
    if (this->table == col.table){
        Table *table = (Table *)(this->table);
        Column *result = new Column(col.table);
        int numRows = table->numRows;
        result->columnName = this->columnName+" + "+col.columnName;
        if (this->dataType == col.dataType){
            if (this->dataType == dt_num){
                result->dataType = dt_num;
                for (int i=0; i<numRows; i++){
                    result->num_entries.push_back(this->num_entries[i]+col.num_entries[i]);
                }
                return result;
            }
            else if(this->dataType == dt_string){
                result->dataType = dt_string;
                for (int i=0; i<numRows; i++){
                    result->str_entries.push_back(this->str_entries[i]+col.str_entries[i]);
                }
                return result;
            }
            else{
                cout << "Incompatible column datatypes for + operation : "<< this->columnName+" '+' "+col.columnName << endl;
                delete(result);
                return NULL;
            }
        }
        else{
            cout << "Incompatible column datatypes for + operation : " << this->columnName+" '+' "+col.columnName << endl;
        }
    }
    else{
        return NULL;
    }
}

Column *Column::operator- (Column const &col){
    if (this->table == col.table){
        Table *table = (Table *)(this->table);
        Column *result = new Column(col.table);
        int numRows = table->numRows;
        result->columnName = this->columnName+" - "+col.columnName;
        if (this->dataType == col.dataType){
            if (this->dataType == dt_num){
                result->dataType = dt_num;
                for (int i=0; i<numRows; i++){
                    result->num_entries.push_back(this->num_entries[i]-col.num_entries[i]);
                }
                return result;
            }
            else{
                cout << "Incompatible column datatypes for - operation : "<< this->columnName+" '-' "+col.columnName << endl;
                delete(result);
                return NULL;
            }
        }
        else{
            cout << "Incompatible column datatypes for - operation : " << this->columnName+" '-' "+col.columnName << endl;
        }
    }
    else{
        return NULL;
    }
}

Column *Column::operator* (Column const &col){
    if (this->table == col.table){
        Table *table = (Table *)(this->table);
        Column *result = new Column(col.table);
        int numRows = table->numRows;
        result->columnName = this->columnName+" * "+col.columnName;
        if (this->dataType == col.dataType){
            if (this->dataType == dt_num){
                result->dataType = dt_num;
                for (int i=0; i<numRows; i++){
                    result->num_entries.push_back(this->num_entries[i]*col.num_entries[i]);
                }
                return result;
            }
            else{
                cout << "Incompatible column datatypes for * operation : "<< this->columnName+" '*' "+col.columnName << endl;
                delete(result);
                return NULL;
            }
        }
        else{
            cout << "Incompatible column datatypes for * operation : " << this->columnName+" '*' "+col.columnName << endl;
        }
    }
    else{
        return NULL;
    }
}

Column *Column::operator/ (Column const &col){
    if (this->table == col.table){
        Table *table = (Table *)(this->table);
        Column *result = new Column(col.table);
        int numRows = table->numRows;
        result->columnName = this->columnName+" / "+col.columnName;
        if (this->dataType == col.dataType){
            if (this->dataType == dt_num){
                result->dataType = dt_num;
                for (int i=0; i<numRows; i++){
                    result->num_entries.push_back(this->num_entries[i]/col.num_entries[i]);
                }
                return result;
            }
            else{
                cout << "Incompatible column datatypes for / operation : "<< this->columnName+" '/' "+col.columnName << endl;
                delete(result);
                return NULL;
            }
        }
        else{
            cout << "Incompatible column datatypes for / operation : " << this->columnName+" '/' "+col.columnName << endl;
        }
    }
    else{
        return NULL;
    }
}

Column *Column::operator- (){
    Table *table = (Table *)(this->table);
    Column *result = new Column(table);
    int numRows = table->numRows;
    result->columnName = " - "+this->columnName;
    if (this->dataType == dt_num){
        result->dataType = dt_num;
        for (int i=0; i<numRows; i++){
            result->num_entries.push_back(-1 * this->num_entries[i]);
        }
        return result;
    }
    else{
        cout << "Incompatible column datatypes for - operation : "<< " '-' "+this->columnName << endl;
        delete(result);
        return NULL;
    }
}

vector <bool> Column::operator< (Column const &col){
    vector <bool> result;
    if (this->table == col.table){
        Table *table = (Table *)(this->table);
        int numRows = table->numRows;
        if (this->dataType == col.dataType){
            if (this->dataType == dt_num){
                for (int i=0; i<numRows; i++){
                    result.push_back(this->num_entries[i]<col.num_entries[i]);
                }
                return result;
            }
            else{
                cout << "Incompatible column datatypes for < operation : "<< this->columnName+" '<' "+col.columnName << endl;
                return result;
            }
        }
        else{
            cout << "Incompatible column datatypes for < operation : " << this->columnName+" '<' "+col.columnName << endl;
        }
    }
    else{
        return result;
    }
}

vector <bool> Column::operator> (Column const &col){
    vector <bool> result;
    if (this->table == col.table){
        Table *table = (Table *)(this->table);
        int numRows = table->numRows;
        if (this->dataType == col.dataType){
            if (this->dataType == dt_num){
                for (int i=0; i<numRows; i++){
                    result.push_back(this->num_entries[i]>col.num_entries[i]);
                }
                return result;
            }
            else{
                cout << "Incompatible column datatypes for > operation : "<< this->columnName+" '>' "+col.columnName << endl;
                return result;
            }
        }
        else{
            cout << "Incompatible column datatypes for > operation : " << this->columnName+" '>' "+col.columnName << endl;
        }
    }
    else{
        return result;
    }
}

vector <bool> Column::operator<= (Column const &col){
    vector <bool> result;
    if (this->table == col.table){
        Table *table = (Table *)(this->table);
        int numRows = table->numRows;
        if (this->dataType == col.dataType){
            if (this->dataType == dt_num){
                for (int i=0; i<numRows; i++){
                    result.push_back(this->num_entries[i]<=col.num_entries[i]);
                }
                return result;
            }
            else{
                cout << "Incompatible column datatypes for <= operation : "<< this->columnName+" '<=' "+col.columnName << endl;
                return result;
            }
        }
        else{
            cout << "Incompatible column datatypes for <= operation : " << this->columnName+" '<=' "+col.columnName << endl;
        }
    }
    else{
        return result;
    }
}

vector <bool> Column::operator>= (Column const &col){
    vector <bool> result;
    if (this->table == col.table){
        Table *table = (Table *)(this->table);
        int numRows = table->numRows;
        if (this->dataType == col.dataType){
            if (this->dataType == dt_num){
                for (int i=0; i<numRows; i++){
                    result.push_back(this->num_entries[i]>=col.num_entries[i]);
                }
                return result;
            }
            else{
                cout << "Incompatible column datatypes for >= operation : "<< this->columnName+" '>=' "+col.columnName << endl;
                return result;
            }
        }
        else{
            cout << "Incompatible column datatypes for >= operation : " << this->columnName+" '>=' "+col.columnName << endl;
        }
    }
    else{
        return result;
    }
}

vector <bool> Column::operator== (Column const &col){
    vector <bool> result;
    if (this->table == col.table){
        Table *table = (Table *)(this->table);
        int numRows = table->numRows;
        if (this->dataType == col.dataType){
            if (this->dataType == dt_num){
                for (int i=0; i<numRows; i++){
                    result.push_back(this->num_entries[i]==col.num_entries[i]);
                }
                return result;
            }
            else if (this->dataType == dt_string){
                for (int i=0; i<numRows; i++){
                    result.push_back(this->str_entries[i]==col.str_entries[i]);
                }
                return result;
            }
            else{
                cout << "Incompatible column datatypes for = operation : "<< this->columnName+" '=' "+col.columnName << endl;
                return result;
            }
        }
        else{
            cout << "Incompatible column datatypes for = operation : " << this->columnName+" '=' "+col.columnName << endl;
        }
    }
    else{
        return result;
    }
}

vector <bool> Column::operator!= (Column const &col){
    vector <bool> result;
    if (this->table == col.table){
        Table *table = (Table *)(this->table);
        int numRows = table->numRows;
        if (this->dataType == col.dataType){
            if (this->dataType == dt_num){
                for (int i=0; i<numRows; i++){
                    result.push_back(this->num_entries[i]!=col.num_entries[i]);
                }
                return result;
            }
            else if (this->dataType == dt_string){
                for (int i=0; i<numRows; i++){
                    result.push_back(this->str_entries[i]!=col.str_entries[i]);
                }
                return result;
            }
            else{
                cout << "Incompatible column datatypes for != operation : "<< this->columnName+" '!=' "+col.columnName << endl;
                return result;
            }
        }
        else{
            cout << "Incompatible column datatypes for != operation : " << this->columnName+" '!=' "+col.columnName << endl;
        }
    }
    else{
        return result;
    }
}

vector <bool> combAnd(vector <bool> &condition1, vector <bool> &condition2){
    vector <bool> result;
    if (condition1.size() == condition2.size()){
        for (int i=0; i<condition1.size(); i++){
            result.push_back(condition1[i] && condition2[i]);
        }
    }
    return result;
}

vector <bool> combOr(vector <bool> &condition1, vector <bool> &condition2){
    vector <bool> result;
    if (condition1.size() == condition2.size()){
        for (int i=0; i<condition1.size(); i++){
            result.push_back(condition1[i] || condition2[i]);
        }
    }
    return result;
}

void printTree(Node *root){
    // Base Case 
    if (root == NULL)  return; 
  
    // Create an empty queue for level order tarversal 
    queue<Node *> q; 
  
    // Enqueue Root and initialize height 
    q.push(root); 
  
    while (q.empty() == false) 
    { 
        // Print front of queue and remove it from queue 
        Node *node = q.front(); 
        cout << node->dataType << " " << node->expr << " " << node->comp << " " << node->comb << " "<< node->str << " " << node->num << endl; 
        q.pop(); 
  
        /* Enqueue left child */
        if (node->child1 != NULL) 
            q.push(node->child1); 
  
        /*Enqueue right child */
        if (node->child2 != NULL) 
            q.push(node->child2); 
    }
}

Column *computeExpression(Node *node, Table *table){
    if (node->expr == et_num){
        return new Column(table, node->child1);
    }
    if (node->expr == et_str){
        return new Column(table, node->child1);
    }
    if (node->expr == et_col){
        Node *col = node->child1;
        if (col->child2 == NULL){
            string colName = col->child1->str;
            int colIndex = table->columnExists(colName);
            if (colIndex == -1){
                cout << colName << " doesn't exist in " << table->tableName << endl;
                return NULL;
            }
            else{
                return table->columns[colIndex];
            }
        }
        else{
            if (table->tableName == col->child1->str){
                string colName = col->child2->str;
                int colIndex = table->columnExists(colName);
                if (colIndex == -1){
                    cout << colName << " doesn't exist in " << table->tableName << endl;
                    return NULL;
                }
                else{
                    return table->columns[colIndex];
                }
            }
            else if (table->tableName == "product table"){
                string colName = col->child1->str+"."+col->child2->str;
                int colIndex = table->columnExists(colName);
                if (colIndex == -1){
                    cout << colName << " doesn't exist in " << table->tableName << endl;
                    return NULL;
                }
                else{
                    return table->columns[colIndex];
                }
            }
            else{
                cout << col->child1->str+"."+col->child2->str << " doesn't exist in " << table->tableName << endl;
                return NULL;
            }
        }
    }
    if (node->expr == et_none){
        return computeExpression(node->child1, table);
    }
    if (node->expr == et_plus){
        Column *operand1 = computeExpression(node->child1, table);
        Column *operand2 = computeExpression(node->child2, table);
        if (operand1 != NULL && operand2 != NULL){
            return (*operand1)+(*operand2);
        }
        else{
            return NULL;
        }
    }
    if (node->expr == et_minus){
        Column *operand1 = computeExpression(node->child1, table);
        Column *operand2 = computeExpression(node->child2, table);
        if (operand1 != NULL && operand2 != NULL){
            return (*operand1)-(*operand2);
        }
        else{
            return NULL;
        }
    }
    if (node->expr == et_times){
        Column *operand1 = computeExpression(node->child1, table);
        Column *operand2 = computeExpression(node->child2, table);
        if (operand1 != NULL && operand2 != NULL){
            return (*operand1)*(*operand2);
        }
        else{
            return NULL;
        }
    }
    if (node->expr == et_divide){
        Column *operand1 = computeExpression(node->child1, table);
        Column *operand2 = computeExpression(node->child2, table);
        if (operand1 != NULL && operand2 != NULL){
            return (*operand1)/(*operand2);
        }
        else{
            return NULL;
        }
    }
    if (node->expr == et_neg){
        Column *operand = computeExpression(node->child1, table);
        if (operand != NULL){
            return -(*operand);
        }
        else{
            return NULL;
        }
    }
}

vector <bool> computeCondition(Node *node, Table *table){
    vector <bool> failed;
    if (node->comp == cp_none){
        if (node->comb == cb_none){
            return computeCondition(node->child1, table);
        }
        if (node->comb == cb_and){
            vector <bool> condition1 = computeCondition(node->child1, table);
            vector <bool> condition2 = computeCondition(node->child2, table);
            return combAnd(condition1, condition2);
        }
        if (node->comb == cb_or){
            vector <bool> condition1 = computeCondition(node->child1, table);
            vector <bool> condition2 = computeCondition(node->child2, table);
            return combOr(condition1, condition2);
        }
    }
    if(node->comp == cp_lt){
        Column *operand1 = computeExpression(node->child1, table);
        Column *operand2 = computeExpression(node->child2, table);
        if (operand1 != NULL && operand2 != NULL){
            return (*operand1)<(*operand2);
        }
        else{
            return failed;
        }
    }
    if(node->comp == cp_gt){
        Column *operand1 = computeExpression(node->child1, table);
        Column *operand2 = computeExpression(node->child2, table);
        if (operand1 != NULL && operand2 != NULL){
            return (*operand1)>(*operand2);
        }
        else{
            return failed;
        }
    }
    if(node->comp == cp_lte){
        Column *operand1 = computeExpression(node->child1, table);
        Column *operand2 = computeExpression(node->child2, table);
        if (operand1 != NULL && operand2 != NULL){
            return (*operand1)<=(*operand2);
        }
        else{
            return failed;
        }
    }
    if(node->comp == cp_gte){
        Column *operand1 = computeExpression(node->child1, table);
        Column *operand2 = computeExpression(node->child2, table);
        if (operand1 != NULL && operand2 != NULL){
            return (*operand1)>=(*operand2);
        }
        else{
            return failed;
        }
    }
    if(node->comp == cp_eq){
        Column *operand1 = computeExpression(node->child1, table);
        Column *operand2 = computeExpression(node->child2, table);
        if (operand1 != NULL && operand2 != NULL){
            return (*operand1)==(*operand2);
        }
        else{
            return failed;
        }
    }
    if(node->comp == cp_neq){
        Column *operand1 = computeExpression(node->child1, table);
        Column *operand2 = computeExpression(node->child2, table);
        if (operand1 != NULL && operand2 != NULL){
            return (*operand1)!=(*operand2);
        }
        else{
            return failed;
        }
    }
}

void tableProductResult(string tableName1, string tableName2){
    Table *table1, *table2;
    try {
        table1 = new Table(tableName1);
    }
    catch (const std::exception& e) {
        cout << e.what() << endl;
        table1 = NULL;
    }
    try {
        table2 = new Table(tableName2);
    }
    catch (const std::exception& e) {
        cout << e.what() << endl;
        table2 = NULL;
    }
    if (table1==NULL || table2==NULL){
        return;
    }
    Table *product = (*table1)*(*table2);
    cout<<"CARTESIAN_PRODUCT Query Result"<<endl;
    product->printTable();
    cout<<endl;
}

void tableProjectResult(string tableName, Node *attributes){
    Table *table;
    try {
        table = new Table(tableName);
    }
    catch (const std::exception& e) {
        cout << e.what() << endl;
        return;
    }
    vector <int> colIndices;
    Node *temp = attributes;
    int colIndex;
    bool err = false;
    while (temp!=NULL){
        Node *attr = temp->child2;
        string colName;
        if (attr->child2 == NULL){
            colName = attr->child1->str;
            colIndex = table->columnExists(colName);
            if (colIndex == -1){
                err = true;
                cout << colName << " doesn't exist in " << table->tableName << endl;
            }
            else{
                colIndices.push_back(colIndex);
            }
        }
        else{
            if (tableName == attr->child1->str){
                colName = attr->child2->str;
                colIndex = table->columnExists(colName);
                if (colIndex == -1){
                    err = true;
                    cout << colName << " doesn't exist in " << table->tableName << endl;
                }
                else{
                    colIndices.push_back(colIndex);
                }
            }
            else{
                err = true;
                cout << attr->child1->str+"."+attr->child2->str << " doesn't exist in " << table->tableName << endl;
            }
        }
        temp = temp->child1;
    }
    if (!err){
        cout<<"PROJECT Query Result"<<endl;
        for (int j=0; j<colIndices.size(); j++){
            cout << table->columns[colIndices[j]]->columnName << " ";
        }
        cout<<endl;
        for(int i=0; i<table->numRows; i++){
            for (int j=0; j<colIndices.size(); j++){
                table->columns[colIndices[j]]->printData(i);
                cout << " ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}

void tableSelectResult(string tableName, Node *node){
    Table *table;
    try {
        table = new Table(tableName);
    }
    catch (const std::exception& e) {
        cout << e.what() << endl;
        return;
    }
    vector <bool> filter = computeCondition(node, table);
    if (filter.size()==table->numRows){
        cout<<"SELECT Query Result"<<endl;
        table->printTable(filter);
        cout<<endl;
    }
    else{
        cout<<endl;
        return;
    }
}

void tableEquiJoinResult(string tableName1, string tableName2, Node *node){
    Table *table1, *table2;
    try {
        table1 = new Table(tableName1);
    }
    catch (const std::exception& e) {
        cout << e.what() << endl;
        table1 = NULL;
    }
    try {
        table2 = new Table(tableName2);
    }
    catch (const std::exception& e) {
        cout << e.what() << endl;
        table2 = NULL;
    }
    if (table1==NULL || table2==NULL){
        return;
    }
    Table *product = (*table1)*(*table2);
    vector <bool> filter = computeCondition(node, product);
    if (filter.size()==product->numRows){
        cout<<"EQUI_JOIN Query Result"<<endl;
        product->printTable(filter);
        cout<<endl;
    }
    else{
        cout<<endl;
        return;
    }
}

