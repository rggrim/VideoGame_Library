/*****************************************************************
 *      Program: CSC1310 program 1
 *      Filename: program1.cpp
 *      Author: Riley Grimaud
 *      Date: 02/05/2023
 *      Purpose:
 * 
 * 
 ******************************************************************/

#include "VideoGameLibrary.h"

int main(){
    
    int librarySize;
    int menuChoice;
    char fileName[100];

    cout << "How many video games can your library hold?" << endl;
    cin >> librarySize;

    VideoGameLibrary* myLibrary = new VideoGameLibrary(librarySize);


    do {

        cout << "What would you like to do?" << endl;
        cout << "\t1. Load video games from file." << endl;
        cout << "\t2. Save video games to a file." << endl;
        cout << "\t3. Add a video game." << endl;
        cout << "\t4. Remove a video game." << endl;
        cout << "\t5. Display all video games." << endl;
        cout << "\t6. Remove ALL video games from this library and end program." << endl;
        cout << "\nCHOOSE 1-6: ";

        cin >> menuChoice;

        while ((menuChoice > 6) || (menuChoice < 1)) {          //while-loop to force user to enter a num from 1-6
            cout << "That is not a valid choice." << endl;
            cout << "CHOOSE 1-6: ";

            cin >> menuChoice;
        }

        cin.ignore();


        switch(menuChoice) {
            case 1:

                cout << "\nWhat is the name of the file you want to load from? (example.txt)" << endl;
                cin >> fileName;

                myLibrary->loadVideoGamesFromFile(fileName);


                break;

            case 2:

                cout << "\nWhat do you want to name the file? (example.txt)" << endl;
                cin >> fileName;

                myLibrary->saveToFile(fileName);

                break;

            case 3:

                myLibrary->addVideoGameToArray();

                break;

            case 4:

                myLibrary->removeVideoGameFromArray();

                break;

            case 5:

                myLibrary->displayVideoGames();

                break;

            case 6:

                delete myLibrary;

                break;
                
            default:
                break;

        }

    } while (menuChoice != 6);

    cout << "\nGOODBYE!" << endl;

    return 0;
}