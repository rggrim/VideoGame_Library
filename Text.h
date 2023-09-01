  /*****************************************************************
 *      Program: CSC1310 program 1
 *      Filename: Text.h
 *      Author: Riley Grimaud
 *      Date: 02/05/2023
 *      Purpose:
 * 
 * 
 ******************************************************************/  

#ifndef TEXT_H
#define TEXT_H
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Text{
    private:
        char * charArray;  
        int textLength;         //int representing num of chars stored in textArray

    public:
        Text(const char*);      
        ~Text();
        void displayText();
        const char* getText();         
        int getLength();                //Returns length of string


};

#endif