/*****************************************************************
 *      Program: CSC1310 program 1
 *      Filename: VideoGame.h
 *      Author: Riley Grimaud
 *      Date: 02/05/2023
 *      Purpose:
 * 
 * 
 ******************************************************************/

#ifndef VIDEOGAMELIBRARY_H
#define VIDEOGAMELIBRARY_H

#include "VideoGame.h"


class VideoGameLibrary {
    
    private:
        VideoGame ** myPointer;
        int numGames;
        int maxGames;
    
    public:
        void resizeVideoGameArray();
        VideoGameLibrary(int);
        ~VideoGameLibrary();
        void addVideoGameToArray();
        void displayVideoGames();
        void displayVideoGameTitles();
        void loadVideoGamesFromFile(char*);
        void removeVideoGameFromArray();
        void saveToFile(char*);

};

#endif