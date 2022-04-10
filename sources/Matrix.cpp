#include <iostream>
#include <bits/stdc++.h>
#include "Matrix.hpp"
#include <string>
using namespace std;


namespace zich{

    Matrix::Matrix(vector<double> const & vec , int row , int col){
        if (vec.empty() || row<1 || col<1 || vec.size()!=row*col){
            throw std::domain_error("invalid input");
        }
        this->rows=row;
        this->columns=col;
        vector<double> mat;
        //mat.reserve(vec.size());
        this->mat=vec;
    }
    Matrix::Matrix(zich::Matrix const & other){
        if (other.mat.empty() || other.rows<1 || other.columns<1 || other.mat.size()!=other.rows*other.columns){
            throw std::domain_error("invalid input");
        }
        this->rows=other.rows;
        this->columns=other.columns;
        vector<double> vec;
        //vec.reserve(other.mat.size());
        for (int i=0 ; i<other.mat.size() ; i++){
            double temp = other.mat[(unsigned int)i];
            vec.push_back(temp);
        }
        this->mat=vec;
    }

    int Matrix::get_rows() const{
        return this->rows;
    }

    int Matrix::get_columns()const{
        return this->columns;
    }

    vector<double> Matrix::get_mat(){
        return this->mat;
    }

    Matrix Matrix::operator + (Matrix & other){
        if (this->rows!=other.rows || this->columns!=other.columns){
            throw std::domain_error( "matrices are not the same size");
        }
        vector<double> vec;
        // vec.reserve(this->mat.size());
        for (int i=0 ; i<this->mat.size() ; i++){
            double temp = this->mat[(unsigned int)i]+other.mat[(unsigned int)i];
            vec.push_back(temp);
        }
        Matrix ans{vec,this->rows,this->columns};
        return ans;
    }

    Matrix Matrix::operator - (Matrix & other){
        if (this->rows!=other.rows || this->columns!=other.columns){
            throw std::domain_error( "matrices are not the same size");
        }
        vector<double> vec;
        // vec.reserve(this->mat.size());
        for (int i=0 ; i<this->mat.size() ; i++){
            double temp = this->mat[(unsigned int)i]-other.mat[(unsigned int)i];
            vec.push_back(temp);
        }
        Matrix ans{vec,this->rows,this->columns};
        return ans;
    }
    Matrix operator * (double const & num , Matrix other){
        vector<double> vec;
        // vec.reserve(other.mat.size());
        for (int i=0 ; i<other.mat.size() ; i++){
            double temp = other.mat[(unsigned int)i]*num;
            vec.push_back(temp);
        }
        Matrix ans{vec,other.rows,other.columns};
        return ans;
    } //  סקלר לפני הכפל
    Matrix Matrix::operator * (double num){
        vector<double> vec;
        // vec.reserve(this->mat.size());
        for (int i=0 ; i<this->mat.size() ; i++){
            double temp = this->mat[(unsigned int)i]*num;
            vec.push_back(temp);
        }
        Matrix ans{vec,this->rows,this->columns};
        return ans;
    } // סקלר אארחי הכפל
    Matrix Matrix::operator * (Matrix & other){
        if (this->columns!=other.rows){
            throw std::domain_error( "undefined matrices multiplication");
        }
        int size = this->rows*other.columns;
        vector<double> vec((unsigned long)size , 0);
        // vec.reserve((unsigned long)size);
        for (int i=0 ; i<this->mat.size() ; i++){
            int for_row = i/this->columns;
            for (int j=0 ; j<other.columns ; j++){
                int for_ind = (other.columns*for_row) + j;
                int for_col = ((i%this->columns)*other.columns) + j;
                double first = this->mat[(unsigned long)i];
                double second = other.mat[(unsigned long)for_col];
                double mul = first*second;
                vec.at((unsigned long)for_ind) += mul;
            }
        }
        Matrix ans{vec,this->rows,other.columns};
        return ans;
    } // כפל מטריצות
    Matrix& Matrix::operator *= (Matrix & other){
        if (this->columns!=other.rows){
            throw std::domain_error( "undefined matrices multiplication");
        }
        int size = this->rows*other.columns;
        vector<double> vec((unsigned long)size , 0);
        for (int i=0 ; i<this->mat.size() ; i++){
            int for_row = i/this->columns;
            for (int j=0 ; j<other.columns ; j++){
                int for_ind = (other.columns*for_row) + j;
                int for_col = ((i%this->columns)*other.columns) + j;
                double first = this->mat[(unsigned long)i];
                double second = other.mat[(unsigned long)for_col];
                double mul = first*second;
                vec.at((unsigned long)for_ind) += mul;
            }
        }
        mat.resize((unsigned int)size);
        for (int i=0 ; i<this->mat.size() ; i++){
            this->mat.at((unsigned long)i) = vec.at((unsigned long)i);
        }
        this->columns = other.columns;
        return *this;
    }
    Matrix& Matrix::operator *= (double num){
        vector<double> vec;
        // vec.reserve(this->mat.size());
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
        // vec.reserve(this->mat.size());
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
        // vec.reserve(this->mat.size());
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
    Matrix operator + (Matrix & other){
        vector<double> vec;
        // vec.reserve(other.mat.size());
        for (int i=0 ; i<other.mat.size() ; i++){
            double temp = other.mat[(unsigned int)i];
            vec.push_back(temp);
        }
        Matrix ans{vec,other.rows,other.columns};
        return ans;
    } // unari
    Matrix operator - (Matrix & other){
        vector<double> vec;
        // vec.reserve(other.mat.size());
        for (int i=0 ; i<other.mat.size() ; i++){
            double temp = -1 * other.mat[(unsigned int)i];
            vec.push_back(temp);
        }
        Matrix ans{vec,other.rows,other.columns};
        return ans;
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
    vector<string> splitString(string str, char spl){
        string temp;
        vector<string> splitted;
        bool in_out = false;
        for (int i=0; i<str.length(); i++){
            if (str[(unsigned int)i] == spl && !temp.empty()){
                splitted.push_back(temp);
                temp = "";
                if (spl == ','){
                    if (str[(unsigned int)i+1] != ' '){
                        throw std::domain_error("invalid input");
                    }
                    i += 1;
                }
            }
            else{
                if (str[(unsigned int)i] == '[' || str[(unsigned int)i] == ']'){
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
        while (c != '\n'){
            c = is.get();
            input += c;
        }
        input.pop_back();
        std::vector<std::string> rows;
        std::vector<std::string> num_in_row;
        std::vector<double> vec;
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

// int main(){
//    std::vector<double> vec7 = {1,2,3,1,2,3};
//    std::vector<double> vec8 = {2,3,2,3,2,3};
//    zich::Matrix a{vec7, 3, 2};
//    zich::Matrix b{vec8, 2, 3};
//    cout << a.get_columns() << endl;
//    cout << a.get_rows() << endl;
//    cout << a << endl;
// //    a*=b;
// //    cout << a << endl;
//     // cout << (4*a).get_mat().at(3) << endl;
//     cout << (a*b).get_mat().at(3) << endl;
//    cout << a << endl;
// //    cout << (a*b) << endl;
//    return 1;
// }