#ifndef LeaderBoard
#define LeaderBoard
#include <iostream>
#include <fstream>
#include <string>
#include "players.hpp"

using namespace std;
/*
Leaderboard class, holds the array of players and the said size of the array
*/
class Leaderboard{
    public:
        /*
        Basic constructor
        */
        Leaderboard() {};

        /*
            This is a basic linear sort, taken from A5
        */
        void sortLeaders(){
            for(int i = 0; i < NUM_LEADERS - 1; i++){
                for(int j = i + 1; j < NUM_LEADERS; j++){
                    if(leaders[j].getScore() < leaders[i].getScore()){
                        Player temp = leaders[i];
                        leaders[i] = leaders[j];
                        leaders[j] = temp;
                    }
                }
            }
        }
        /*
            This just gives the size of the Leaderboard object
        */
        int size(){
            int size = 0;
            for(int i = 0; i < NUM_LEADERS; i++){
                if(!leaders[i].getName().empty()){
                    size++;
                }
            }

            return size;
        }
        /*
            This reads the file and adds it to the array
            For the beginning of the code mainly to make sure that any previous leaders that were given and saved
            are added to the current array.
        */
        void Readleaders(string filePath){
            ifstream MyReadFile(filePath);
            if(MyReadFile.peek() == EOF){
                return;
            }
            int i = 0;
            string nextLine;
            int guesses;
            while(i < NUM_LEADERS && MyReadFile >> nextLine >> guesses){
                leaders[i].setName(nextLine);
                leaders[i].setScore(guesses);
                i++;
            }

            MyReadFile.close();
        }
        /*
            Just adds a user to the array if there is room and it is small enough.
            Otherwise it doesnt get added.
            Then we sort it to make sure that any new players that have been added are in the right spot.
        */
        void addLeader(Player newPlayer){
            int currentsize = size();
            if (currentsize < NUM_LEADERS) {
                leaders[currentsize] = newPlayer;
            } else {
                if (newPlayer.getScore() < leaders[NUM_LEADERS - 1].getScore()) {
                    leaders[NUM_LEADERS - 1] = newPlayer;
                } else {
                    return;
                }
            }

            sortLeaders();
        }

        /*
            This is for when the user quits the code, it addes all the current leaderboard
            players to the file to save them for the next time the code is ran.
            Saves them in a: NAME SCORE format.
        */
        void writeToFile(){
            ofstream outputFile("leaders.txt");
            if(!outputFile.is_open()){
                return;
            }

            for(int i = 0; i < size(); i++){
                outputFile << leaders[i].getName() << " " << leaders[i].getScore() << endl;
            }
            outputFile.close();
        }

        void printLeaders(){
            for(int i = 0; i < size(); i++){
                cout << leaders[i].getName() << " made " << leaders[i].getScore() << " guesses\n";
            }
        }
    private:
        static const int NUM_LEADERS = 5;
        Player leaders[NUM_LEADERS];
};


#endif