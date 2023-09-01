  /*****************************************************************
 *      Program: CSC1310 program 1
 *      Filename: Text.cpp
 *      Author: Riley Grimaud
 *      Date: 02/05/2023
 *      Purpose:
 * 
 * 
 ******************************************************************/  

#include "Text.h"


/*************************************************************
 *  Function: Constructor -- Text
 *  Purpose: called automatically when Text object is created, 
 *           dynamically allocates a character array which 
 *           contains the character array passed to the function.
 *  
 ************************************************************/
Text::Text(const char* myArr){      

  textLength = strlen(myArr) + 1;
  char * newArray = new char [textLength];
  charArray = strcpy(newArray, myArr);

}

/*************************************************************
 *  Function: desturctor -- ~Text
 *  Purpose: release dynamically allocated memory for the 
 *           c-string in the Text object 
 *  
 ************************************************************/
Text::~Text(){

  delete [] charArray;

  cout << "Text destructor: Released memory for textArray." << endl;

}

/*************************************************************
 *  Function: displayText()
 *  Purpose: print the c-string (textArray) to the screen. 
 *           (c++ will let you just cout a char array)
 *  
 ************************************************************/
void Text::displayText() {

  cout << charArray;

}

/*************************************************************
 *  Function: getText()
 *  Purpose:  simple accessor function
 *  
 ************************************************************/
const char* Text::getText() {        

  return charArray; 
}

/*************************************************************
 *  Function: getLength()
 *  Purpose: simple accessor function
 *  
 ************************************************************/
int Text::getLength(){

  return textLength;
}