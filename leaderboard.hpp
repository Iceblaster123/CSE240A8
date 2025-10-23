#ifndef LeaderBoard
#define LeaderBoard
#include <iostream>
#include <fstream>
#include <string>
#include "players.hpp"

using namespace std;

class Leaderboard{
    public:
        Leaderboard() {};
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

        int size(){
            int size = 0;
            for(int i = 0; i < NUM_LEADERS; i++){
                if(!leaders[i].getName().empty()){
                    size++;
                }
            }

            return size;
        }

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