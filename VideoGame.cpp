  /*****************************************************************
 *      Program: CSC1310 program 1
 *      Filename: VideoGame.cpp
 *      Author: Riley Grimaud
 *      Date: 02/05/2023
 *      Purpose:
 * 
 * 
 ******************************************************************/  

#include "VideoGame.h"



/*************************************************************
 *  Function: constructor -- VideoGame()
 *  Purpose: This function should be called when all video game
 *           information is known and it will create a new 
 *           video game with this information
 *  
 ************************************************************/
VideoGame::VideoGame(Text* myTitle, Text* myDeveloper, Text* myPublisher, int myYear){
  title = myTitle;
  developer = myDeveloper;
  publisher = myPublisher;
  year = myYear;

}


/*************************************************************
 *  Function: destructor -- ~VideoGame()
 *  Purpose: This function is automatically called when a Video 
 *           game object is destroyed.  This function releases 
 *           the dynamically allocated text arrays in the Video 
 *           game.
 *  
 ************************************************************/
VideoGame::~VideoGame(){

  delete title;
  delete publisher;
  delete developer;

  cout << "VideoGame destructor: Released memory for VideoGame object." << endl;

}

/*************************************************************
 *  Function: printVideoGameDetails()
 *  Purpose: This function should be called when the user wants
 *           to print ALL the video game information to the screen.
 *  
 ************************************************************/
void VideoGame::printVideoGameDetails(){

  cout << "\t\t\tGame Title:\t" << endl;                    //print game title
  title->displayText();
  cout << "\n\n";

  cout << "\t\t\tDeveloper:\t" << endl;                     //print game developer
  developer->displayText();
  cout << "\n\n";

  cout << "\t\t\tPublisher:\t" << endl;                     //print game publisher
  publisher->displayText();
  cout << "\n\n";

  cout << "\t\t\tYear Released:\t" << endl;                 //print year realeased
  cout << year;
  cout << "\n\n";

  cout << "\n\n";

}

/*************************************************************
 *  Function: printVideoGameDetailsToFile()
 *  Purpose: This function should be called when the user wants
 *           to print ALL the video game information to the file.
 *  
 ************************************************************/
void VideoGame::printVideoGameDetailsToFile(ofstream &myFile){ 
  char dataHold[10000];

	strncpy(dataHold, title->getText(), 10000);               //use holder to retrieve and print title to the file
	myFile << dataHold << endl;

  strncpy(dataHold, developer->getText(), 10000);           //use holder to retrieve and print developer to the file
	myFile << dataHold << endl;

  strncpy(dataHold, publisher->getText(), 10000);           //use holder to retrieve and print publisher to the file
	myFile << dataHold << endl;

  myFile << year << endl;                                   //print year to the file

}

/*************************************************************
 *  Function: getVideoGameTitle()
 *  Purpose: returns a pointer to the Text object containing the
 *           video game title
 *  
 ************************************************************/
Text* VideoGame::getVideoGameTitle(){

  return title;
}