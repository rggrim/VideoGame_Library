  /*****************************************************************
 *      Program: CSC1310 program 1
 *      Filename: VideoGame.h
 *      Author: Riley Grimaud
 *      Date: 02/05/2023
 *      Purpose:
 * 
 * 
 ******************************************************************/  
#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "Text.h"

class VideoGame{            //NEED TO #INCLUDE TEXT FILE
    private:
        Text* title;       //pointer to Text object, holding the title of game
        Text* developer ;  //pointer to Text object, indicating who made game
        Text* publisher;   //pointer to Text object, indicating the publisher of game
        int year;          //integer representing year the game was released

    public:
        VideoGame(Text*, Text*, Text*, int);
        ~VideoGame();
        void printVideoGameDetails();
        void printVideoGameDetailsToFile(ofstream&);     //FIXME!!
        Text* getVideoGameTitle();      //should the asterisk be there?

};

#endif