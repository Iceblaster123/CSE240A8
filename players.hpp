#ifndef PLAYERS_HPP
#define PLAYERS_HPP
#include <iostream>
#include <string>

using namespace std;

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