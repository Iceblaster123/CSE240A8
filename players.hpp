#ifndef PLAYERS_HPP
#define PLAYERS_HPP
#include <iostream>
#include <string>

using namespace std;

/*
Basic player class, holds the name and the number of guesses that the player has made.
Has appropriate getter and setter functions.
Constructor has the name() and score set because errors happened in the General Server
*/

class Player{
    public:
        Player() : name(""), score(1000000) {};
        Player(string name, int score) : name(name), score(score) {};
        int getScore(){return score;};
        void setScore(int score){this->score = score;};
        string getName(){return name;};
        void setName(string name){this->name = name;};
    private:
        string name;
        int score;
};

#endif