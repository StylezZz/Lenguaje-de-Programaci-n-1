/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 21 de marzo de 2023, 9:18
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

/*
 * 
 */
class MyClass{
    public:
        int myNum;
        string myString;
};


int main(int argc, char** argv) {
    MyClass myObj;
    
    myObj.myNum = 15;
    myObj.myString = "Some text";
    
    cout<<myObj.myNum<<endl;
    cout<<myObj.myString;
    return 0;
}







