  /*****************************************************************
 *      Program: CSC1310 program 1
 *      Filename: VideoGameLibrary.cpp
 *      Author: Riley Grimaud
 *      Date: 02/05/2023
 *      Purpose:
 * 
 * 
 ******************************************************************/  
    
  #include "VideoGameLibrary.h"


  /*************************************************************
   *  Function: Constructor -- VideoGamesLibrary
   *  Purpose:
   *  
   ************************************************************/
  VideoGameLibrary::VideoGameLibrary(int maxNum){

    myPointer = new VideoGame * [maxNum];

    numGames = 0;
    maxGames = maxNum;

  }

  /*************************************************************
   *  Function: destructor -- ~VideoGameLibrary()
   *  Purpose: :  This function is automatically called when the
   *  VideoGame object is destroyed.  This releases the
   *  dynamically created individual video games and then deletes
   *  the array.
   *  
   ************************************************************/
  VideoGameLibrary::~VideoGameLibrary(){

    for (int i = 0; i < numGames; i++) {                    //cycle through each videoGame in the library
      delete myPointer[i];
    }

    delete [] myPointer;

    cout << "VideoGameLibrary destructor: Released memory for each game in the video game array and the array itself." << endl;

  }

  /*************************************************************
   *  Function: resizeVideoGameArray()
   *  Purpose: This function is called by addVideoGameToArray when
   *  the array size is not big enough to hold a new video game
   *  that needs to be added.  The function makes the array twice
   *  as big as it currently is and then moves all the video game
   *  pointers to this new array.
   *  
   ************************************************************/
  void VideoGameLibrary::resizeVideoGameArray(){

    int newMax = maxGames * 2;                               //double maximum size of the array

    cout << "Resizing myPointer array from " << maxGames << " to " << newMax << "." << endl;

    VideoGame ** newPointers = new VideoGame * [newMax];     //create a "holder" array

    for (int i = 0; i < numGames; i++){                      //cycle through myPointer and copy it into newPointers
      newPointers[i] = myPointer[i];
    }

    delete [] myPointer;

    maxGames = newMax;                                       //Set the original class attributes to their new values
    myPointer = newPointers;

  }

  /*************************************************************
   *  Function: addVideoGameToArray()
   *  Purpose:  This function should be called when you need to
   *  add a single video game to the video game library.  
   *  
   ************************************************************/    
  void VideoGameLibrary::addVideoGameToArray(){

    int yearHolder;
    char dataHolder[1000];

    cout << "\nVideo Game TITLE: ";                         //read in title and dynamically allocate Text object for it
    cin.getline(dataHolder, 1000);
    Text * gameTitle = new Text(dataHolder);

    cout << "\nVideo Game DEVELOPER: ";                     //read in developer and dynamically allocate Text object for it
    cin.getline(dataHolder, 1000);
    Text * gameDeveloper = new Text(dataHolder);          

    cout << "\nVideo Game PUBLISHER: ";                     //read in publisher and dynamically allocate Text object for it
    cin.getline(dataHolder, 1000);
    Text * gamePublisher = new Text(dataHolder);

    cout << "\nVideo Game YEAR: ";                          //read in year
    cin >> yearHolder;

    cin.ignore();

    VideoGame * newGame = new VideoGame(gameTitle, gameDeveloper, gamePublisher, yearHolder);

    if (numGames == maxGames) {                           //check if array is full and if it needs to be resized
      resizeVideoGameArray();
    }

    myPointer[numGames] = newGame;                        //add newGame to the array

    cout << "\n\n";

    numGames++;                                           //increment

  }

  /*************************************************************
   *  Function: displayVideoGames()
   *  Purpose: This function should be called when the user wants
   *  to have all the video games in the library printed to the
   *  screen.  
   *  
   ************************************************************/
  void VideoGameLibrary::displayVideoGames(){

    for (int i = 0; i < numGames; i++){                      //for loop to cycle through each video game in the library
      
      cout << "\t\t\t\t\t----------Video Game " << i + 1 << "----------" << endl;

      myPointer[i]->printVideoGameDetails();

    }
  }

  /*************************************************************
   *  Function: displayVideoGameTitles()
   *  Purpose: This function should be called when you want to
   *  print only the video game titles out of the video game
   *  library (when a user wants to remove a video game from
   *  library).  
   *  
   ************************************************************/
  void VideoGameLibrary::displayVideoGameTitles(){
    Text * titleHolder;

    for (int i = 0; i < numGames; i++) {                      //cycle through each video game in the library
      cout << "Video Game " << i + 1 << ": ";
      titleHolder = myPointer[i]->getVideoGameTitle();
      titleHolder->displayText();
      
    }
  }

  /*************************************************************
   *  Function:loadVideoGamesFromFile()
   *  Purpose: This function should be called when the user wants
   *  to read video game data from a file and add the video games
   *  to the video game library.  The file must have data in the
   *  following order: title, developer, publisher, year.  
   *  
   ************************************************************/
  void VideoGameLibrary::loadVideoGamesFromFile(char* fileName){

    char dataHold[10000];                                  //temporary spots for data read from file
    int yearHold;

    Text *title;
    Text *gameDeveloper;
    Text *gamePublisher;

    ifstream myFile;
    VideoGame * currentGame;
    int gameTracker = 0;                                   //to track num games specifically in the user provided file
    


    myFile.open(fileName);

    if (myFile.is_open()) {                                //check to make sure file has successfully opened

      myFile.getline(dataHold, 10000);
      while (!myFile.eof()) {                              //while loop until eof is reached
        
        title = new Text(dataHold);                    //read in title & dynamically create Text pointer for it

        myFile.getline(dataHold, 10000);                   //read in developer & dynamically create Text pointer for it
        gameDeveloper = new Text(dataHold);

        myFile.getline(dataHold, 10000);                   //read in publsiher & dynamically create Text pointer for it
        gamePublisher = new Text(dataHold);

        myFile >> yearHold;                                //read in year
        myFile.ignore();

        currentGame = new VideoGame(title, gameDeveloper, gamePublisher, yearHold);

        if(numGames == maxGames) {                          //check if maxGames has been reached, because if it
                                                            //has, more space needs to be allocated
          resizeVideoGameArray();
        }

        numGames++;                                         //incrementing
        gameTracker++;
        
        myPointer[numGames] = currentGame;

        title->displayText();
        cout << " was added successfully" << endl;

        myFile.getline(dataHold, 10000);                 //check if there's more data in the file before loop
                                                         //starts again, so the .eof() can be effective
      }

      cout << gameTracker << " video games were read from the file and added to your VideoGame library.\n" << endl;
    }
    
    else {                                                //else statement, when the file fails to
                                                          //open properly. Sends user back to menu.
      cout << "Sorry, I was unable to open the file." << endl;

    }

    myFile.close();

  }

  /*************************************************************
   *  Function: removeVideoGameFromArray()
   *  Purpose: This function should be called when the user wants
   *  to remove one single video game from the video game library. 
   *  The video game to be removed must is identified by the user
   *  and then removed.
   *  
   ************************************************************/
  void VideoGameLibrary::removeVideoGameFromArray(){

    if (numGames >= 1) {

      Text * titleHolder;
      int userChoice;

      cout << "\nChoose from the following video games to remove:\n" << endl;
      displayVideoGameTitles();                                                         //lists all video Game title

      do {                                                                              //forces user to enter valid number
        cout << "\nChoose a video game to remove between 1 & " << numGames << ":  ";
        cin >> userChoice;
      } while ((userChoice > numGames) || (userChoice < 1));

      cout << "\nThe video game \"";
      
      titleHolder = myPointer[userChoice]->getVideoGameTitle();
      titleHolder->displayText();
      
      cout <<"\" has been successfully deleted." << endl;

      delete myPointer[userChoice];

      for (int i = userChoice; i < numGames; i++) {                                      //moves all elements over by one index
        myPointer[i] = myPointer[i + 1];

      }

      myPointer[numGames] = NULL;

      numGames--;                                                                       //decrement vurrent number of games
    }

    else {                                                                              //in the event that no videogames have been entered yet

      cout << "\nThere must be at least one video game in the library in order to delete a video game.";

    }
  }

  /*************************************************************
   *  Function: saveToFile()
   *  Purpose:  This function should be called when the user wants 
   *  to print all the video game data from the video game library
   *  to a file.  The data is printed in the following order (one
   *  piece of data per line):  title, developer, publisher, year.
   *  
   ************************************************************/    
  void VideoGameLibrary::saveToFile(char* fileName){

    ofstream myFile;
    myFile.open(fileName);

    if (myFile.is_open()) {                                   //check to make sure file actually opened
      for(int i = 0; i < numGames; i++){                      //cycle through each game in the array
        myPointer[i]->printVideoGameDetailsToFile(myFile);

      }
    }

    else{                                                      //else statement, when the file fails to
      cout << "\nSorry, I was unable to open the file." << endl; //open properly. Sends user back to menu.

    }

    myFile.close();

    cout << "All video games in your library have been printed to " << fileName << endl;

  }