#include <iostream>
#include <bits/stdc++.h>
#include "Matrix.hpp"
#include <string>
using namespace std;


namespace zich{

    Matrix::Matrix(vector<double> const & vec , int row , int col){ // constructor
        if (vec.empty() || row<1 || col<1 || vec.size()!=row*col){
            throw std::domain_error("invalid input");
        }
        this->rows=row;
        this->columns=col;
        vector<double> mat;
        this->mat=vec;
    }
    Matrix::Matrix(zich::Matrix const & other){ // copy constructor
        if (other.mat.empty() || other.rows<1 || other.columns<1 || other.mat.size()!=other.rows*other.columns){
            throw std::domain_error("invalid input");
        }
        this->rows=other.rows;
        this->columns=other.columns;
        vector<double> vec;
        for (int i=0 ; i<other.mat.size() ; i++){
            double temp = other.mat[(unsigned int)i];
            vec.push_back(temp);
        }
        this->mat=vec;
    }

    int Matrix::get_rows() const{ // getter
        return this->rows;
    }
    int Matrix::get_columns()const{ // getter
        return this->columns;
    }
    vector<double> Matrix::get_mat(){ // getter
        return this->mat;
    }
    Matrix Matrix::operator + (Matrix & other){
        if (this->rows!=other.rows || this->columns!=other.columns){
            throw std::domain_error( "matrices are not the same size");
        }
        vector<double> vec;
        for (int i=0 ; i<this->mat.size() ; i++){
            double temp = this->mat[(unsigned int)i]+other.mat[(unsigned int)i];
            vec.push_back(temp);
        }
        Matrix ans{vec,this->rows,this->columns}; // new matrix with sumed values
        return ans;
    }
    Matrix Matrix::operator - (Matrix & other){
        if (this->rows!=other.rows || this->columns!=other.columns){
            throw std::domain_error( "matrices are not the same size");
        }
        vector<double> vec;
        for (int i=0 ; i<this->mat.size() ; i++){
            double temp = this->mat[(unsigned int)i]-other.mat[(unsigned int)i];
            vec.push_back(temp);
        }
        Matrix ans{vec,this->rows,this->columns}; // new matrix with sumed values
        return ans;
    }
    Matrix operator * (double const & num , Matrix other){ // scalar before *
        vector<double> vec;
        for (int i=0 ; i<other.mat.size() ; i++){
            double temp = other.mat[(unsigned int)i]*num;
            vec.push_back(temp);
        }
        Matrix ans{vec,other.rows,other.columns}; // new matrix with nuled values
        return ans;
    }
    Matrix Matrix::operator * (double num){ // scalar after *
        vector<double> vec;
        for (int i=0 ; i<this->mat.size() ; i++){
            double temp = this->mat[(unsigned int)i]*num;
            vec.push_back(temp);
        }
        Matrix ans{vec,this->rows,this->columns}; // new matrix with nuled values
        return ans;
    }
    Matrix Matrix::operator * (Matrix & other){ // matrices multiplication
        if (this->columns!=other.rows){
            throw std::domain_error( "undefined matrices multiplication");
        }
        int size = this->rows*other.columns;
        vector<double> vec((unsigned long)size , 0); // initialize with zeros
        for (int i=0 ; i<this->mat.size() ; i++){
            int for_row = i/this->columns;
            for (int j=0 ; j<other.columns ; j++){
                int for_ind = (other.columns*for_row) + j; // the right index in the new matrix
                int for_col = ((i%this->columns)*other.columns) + j; // the right index in the second matrix
                double first = this->mat[(unsigned long)i];
                double second = other.mat[(unsigned long)for_col];
                double mul = first*second;
                vec.at((unsigned long)for_ind) += mul;
            }
        }
        Matrix ans{vec,this->rows,other.columns}; // return a new matrix with results
        return ans;
    }
    Matrix& Matrix::operator *= (Matrix & other){ // matrices multiplication
        if (this->columns!=other.rows){
            throw std::domain_error( "undefined matrices multiplication");
        }
        int size = this->rows*other.columns;
        vector<double> vec((unsigned long)size , 0); // initialize with zeros
        for (int i=0 ; i<this->mat.size() ; i++){
            int for_row = i/this->columns;
            for (int j=0 ; j<other.columns ; j++){
                int for_ind = (other.columns*for_row) + j; // the right index in the new matrix
                int for_col = ((i%this->columns)*other.columns) + j; // the right index in the second matrix
                double first = this->mat[(unsigned long)i];
                double second = other.mat[(unsigned long)for_col];
                double mul = first*second;
                vec.at((unsigned long)for_ind) += mul;
            }
        }
        mat.resize((unsigned int)size);
        for (int i=0 ; i<this->mat.size() ; i++){ // copy fron new vector to this vector
            this->mat.at((unsigned long)i) = vec.at((unsigned long)i);
        }
        this->columns = other.columns; // update columns
        return *this;
    }
    Matrix& Matrix::operator *= (double num){
        vector<double> vec;
        for (int i=0 ; i<this->mat.size() ; i++){
            this->mat[(unsigned int)i] *= num;
        }
        return *this;
    }
    Matrix& Matrix::operator += (Matrix & other){
        if (this->rows!=other.rows || this->columns!=other.columns){
            throw std::domain_error( "matrices are not the same size");
        }
        vector<double> vec;
        for (int i=0 ; i<this->mat.size() ; i++){
            this->mat[(unsigned int)i] += other.mat[(unsigned int)i];
        }
        return *this;
    }
    Matrix& Matrix::operator -= (Matrix & other){
        if (this->rows!=other.rows || this->columns!=other.columns){
            throw std::domain_error( "matrices are not the same size");
        }
        vector<double> vec;
        for (int i=0 ; i<this->mat.size() ; i++){
            this->mat[(unsigned int)i] -= other.mat[(unsigned int)i];
        }
        return *this;
    }
    bool Matrix::operator == (Matrix const & other) const{
        if (this->rows!=other.rows || this->columns!=other.columns){
            throw std::domain_error( "matrices are not the same size");
        }
        for (int i=0 ; i<this->mat.size() ; i++){
            if (this->mat[(unsigned int)i] != other.mat[(unsigned int)i]){
                return false;
            }
        }
        return true;
    }
    bool Matrix::operator != (Matrix const & other) const{
        if (this->rows!=other.rows || this->columns!=other.columns){
            throw std::domain_error( "matrices are not the same size");
        }
        for (int i=0 ; i<this->mat.size() ; i++){
            if (this->mat[(unsigned int)i] != other.mat[(unsigned int)i]){
                return true;
            }
        }
        return false;
    }
    bool Matrix::operator <= (Matrix const & other) const{
        if (this->rows!=other.rows || this->columns!=other.columns){
            throw std::domain_error( "matrices are not the same size");
        }
        double sumThis = 0;
        double sumOther = 0;
        bool flag = false;
        for (int i=0 ; i<this->mat.size() ; i++){
            sumThis += this->mat[(unsigned long)i];
            sumOther += other.mat[(unsigned long)i];
        }
        if (sumThis <= sumOther){
            flag = true;;
        }
        return flag;
    }
    bool Matrix::operator >= (Matrix const & other) const{
        if (this->rows!=other.rows || this->columns!=other.columns){
            throw std::domain_error( "matrices are not the same size");
        }
        double sumThis = 0;
        double sumOther = 0;
        bool flag = false;
        for (int i=0 ; i<this->mat.size() ; i++){
            sumThis += this->mat[(unsigned long)i];
            sumOther += other.mat[(unsigned long)i];
        }
        if (sumThis >= sumOther){
            flag = true;;
        }
        return flag;
    }
    bool Matrix::operator < (Matrix const & other) const{
        if (this->rows!=other.rows || this->columns!=other.columns){
            throw std::domain_error( "matrices are not the same size");
        }
        double sumThis = 0;
        double sumOther = 0;
        bool flag = false;
        for (int i=0 ; i<this->mat.size() ; i++){
            sumThis += this->mat[(unsigned long)i];
            sumOther += other.mat[(unsigned long)i];
        }
        if (sumThis < sumOther){
            flag = true;
        }
        return flag;
    }
    bool Matrix::operator > (Matrix const & other) const{
        if (this->rows!=other.rows || this->columns!=other.columns){
            throw std::domain_error( "matrices are not the same size");
        }
        double sumThis = 0;
        double sumOther = 0;
        bool flag = false;
        for (int i=0 ; i<this->mat.size() ; i++){
            sumThis += this->mat[(unsigned long)i];
            sumOther += other.mat[(unsigned long)i];
        }
        if (sumThis > sumOther){
            flag = true;
        }
        return flag;
    }
    Matrix operator + (Matrix & other){ // unari plus
        vector<double> vec;
        for (int i=0 ; i<other.mat.size() ; i++){
            double temp = other.mat[(unsigned int)i];
            vec.push_back(temp);
        }
        Matrix ans{vec,other.rows,other.columns}; // return a new matrix with same values
        return ans;
    }
    Matrix operator - (Matrix & other){ // unari minus
        vector<double> vec;
        for (int i=0 ; i<other.mat.size() ; i++){
            double temp = -1 * other.mat[(unsigned int)i];
            vec.push_back(temp);
        }
        Matrix ans{vec,other.rows,other.columns};
        return ans; // return a new matrix with minus the same values
    }
    std::ostream& operator << (std::ostream& os , Matrix & matrix){
        for (int row=0 ; row<matrix.get_rows() ; row++){
            for (int col=0 ; col<matrix.get_columns() ; col++){
                if (col == 0){
                    os << '[';
                }
                int index = (row*matrix.get_columns())+col;
                os << matrix.mat[(unsigned long)index];
                if (col != matrix.get_columns()-1){
                    os << ' ';
                }
            }
            os << ']';
            if (row != matrix.get_rows()-1){
                os << '\n';
            }
        }
        return os;
    }
    vector<string> splitString(string str, char spl){ // split string by char
        string temp;
        vector<string> splitted;
        bool in_out = false;
        for (int i=0; i<str.length(); i++){
            if (str[(unsigned int)i] == spl && !temp.empty()){
                splitted.push_back(temp);
                temp = "";
                if (spl == ','){ // check if after every ',' there is a ' ' and jump by another char
                    if (str[(unsigned int)i+1] != ' '){
                        throw std::domain_error("invalid input");
                    }
                    i += 1;
                }
            }
            else{
                if (str[(unsigned int)i] == '[' || str[(unsigned int)i] == ']'){
                    // check if after every '[' there is a ']'
                    if (str[(unsigned int)i] == '['){
                        if (!in_out){
                            in_out=true;
                        }else{
                            throw std::domain_error("invalid input");
                        }
                    }
                    if (str[(unsigned int)i] == ']'){
                        if (in_out){
                            in_out=false;
                        }else{
                            throw std::domain_error("invalid input");
                        }
                    }
                    continue;
                }
                temp += str[(unsigned int)i];
            }
        }
        splitted.push_back(temp);
        return splitted;
    }
    std::istream& operator >> (std::istream& is , Matrix & matrix){
        int row = 0;
        int col = 0;
        std::string input;
        char c = 0;
        // get all input
        while (c != '\n'){
            c = is.get();
            input += c;
        }
        input.pop_back();
        std::vector<std::string> rows;
        std::vector<std::string> num_in_row;
        std::vector<double> vec;
        // use split funcion for splitting by ',' ans then by ' ' for each row
        rows = splitString(input , ',');
        for (int i=0 ; i<rows.size() ; i++){
            row++;
            num_in_row = splitString(rows[(unsigned long)i] , ' ');
            if (col!=0 && col!=num_in_row.size()){
                throw std::domain_error("invalid input");
            }
            col = num_in_row.size();
            for (int j=0 ; j<num_in_row.size() ; j++){
                double num_double = std::stod(num_in_row[(unsigned long)j]);
                vec.push_back(num_double);
            }
        }
        matrix.mat = vec;
        matrix.rows=row;
        matrix.columns=col;
        return is;
    }
    Matrix& Matrix::operator ++(){
        for (int i=0 ; i<this->mat.size() ; i++){
            this->mat[(unsigned long)i]++;
        }
        return *this;
    }
    Matrix Matrix::operator ++(int num){
        Matrix copy = *this;
        for (int i=0 ; i<this->mat.size() ; i++){
            this->mat[(unsigned long)i]++;
        }
        return copy;
    }
    Matrix Matrix::operator --(int num){
        Matrix copy = *this;
        for (int i=0 ; i<this->mat.size() ; i++){
            this->mat[(unsigned long)i]--;
        }
        return copy;
    }
    Matrix& Matrix::operator --(){
        for (int i=0 ; i<this->mat.size() ; i++){
            this->mat[(unsigned long)i]--;
        }
        return *this;
    }
    Matrix::~Matrix(){
    }

}