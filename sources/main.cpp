// #include <iostream>
// #include <string>
// #include "Matrix.hpp"
// #include "Matrix.cpp"
// using namespace std;

// int main(){
//     std::vector<double> vec = {0,0,0};
//     zich::Matrix mat1(vec,1,3);
//     zich::Matrix mat2(vec,1,3);
//     char action = 'g';
//     cout << "PLEASE ENTER mat1" << endl;
//     cin >> mat1;
//     cout << "PLEASE ENTER mat2" << endl;
//     cin >> mat2;
//     cout << "PLEASE ENTER +-*=!<> OR E to end" << endl;
//     cin >> action;
//     switch (action) {
//         case '+':
//             cout << "in" << endl;
//             try{
//                 cout << mat1 << endl;
//                 mat1+=mat2;
//                 cout << "hi" << endl;
//                 cout << mat1 << endl;
//             }
//             catch(...){
//                 action = 'E';
//             }
//             break;
//         case '-':
//             try{
//                 mat1-=mat2;
//                 cout << mat1 << endl;
//             }
//             catch(...){
//                 action = 'E';
//             }
//             break;
//         case '*':
//             try{
//                 mat1*=mat2;
//                 cout << mat1 << endl;
//             }
//             catch(...){
//                 action = 'E';
//             }
//             break;
//         case '=':
//             try{
//                 bool flag = (mat1==mat2);
//                 if (flag){
//                     cout << "true" << endl;
//                 }
//                 else{
//                     cout << "false" << endl;
//                 }
//             }
//             catch(...){
//                 action = 'E';
//             }
//             break;
//         case '!':
//             try{
//                 bool flag = (mat1!=mat2);
//                 if (flag){
//                     cout << "true" << endl;
//                 }
//                 else{
//                     cout << "false" << endl;
//                 }
//             }
//             catch(...){
//                 action = 'E';
//             }
//             break;
//         case '<':
//             try{
//                 bool flag = (mat1<mat2);
//                 if (flag){
//                     cout << "true" << endl;
//                 }
//                 else{
//                     cout << "false" << endl;
//                 }
//             }
//             catch(...){
//                 action = 'E';
//             }
//             break;
//         case '>':
//             try{
//                 bool flag = (mat1>mat2);
//                 if (flag){
//                     cout << "true" << endl;
//                 }
//                 else{
//                     cout << "false" << endl;
//                 }
//             }
//             catch(...){
//                 action = 'E';
//             }
//             break;
//         case 'E':
//             cout << "ends trial" << endl;
//             return 0;
//     }
//     return 0;
// }