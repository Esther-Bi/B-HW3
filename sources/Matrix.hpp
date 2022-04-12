#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

#ifndef MY_HEADER
#define MY_HEADER

namespace zich{

    class Matrix{
        private:
            int rows;
            int columns;
            std::vector<double> mat;
        public:
            Matrix(vector<double> const & , int , int); // constructor
            Matrix(zich::Matrix const & other); // copy constructor

            int get_rows()const;
            int get_columns()const;
            vector<double> get_mat();
            Matrix operator + (Matrix &);
            Matrix operator - (Matrix &);
            friend Matrix operator * (double const & , Matrix); // scalar before *
            Matrix operator * (double); // scalar after *
            Matrix operator * (Matrix &); // matrices multiplication
            Matrix& operator *= (Matrix &);
            Matrix& operator *= (double);
            Matrix& operator += (Matrix &);
            Matrix& operator -= (Matrix &);
            bool operator == (Matrix const &)const;
            bool operator != (Matrix const &)const;
            bool operator <= (Matrix const &)const;
            bool operator >= (Matrix const &)const;
            bool operator < (Matrix const &)const;
            bool operator > (Matrix const &)const;
            friend Matrix operator + (Matrix &); // unari
            friend Matrix operator - (Matrix &); // unari
            friend std::ostream& operator << (std::ostream& os , Matrix &);
            friend std::istream& operator >> (std::istream& is , Matrix &);
            Matrix& operator ++();
            Matrix operator ++(int);
            Matrix operator --(int);
            Matrix& operator --();
            ~Matrix();

    };

}

#endif