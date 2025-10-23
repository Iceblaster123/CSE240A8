#include <iostream>
#include <cmath>
#include "leaderboard.hpp"
#include "players.hpp"

using namespace std;

int main(){
    Leaderboard leaderboard;
    leaderboard.Readleaders("leaders.txt");
    cout << "Welcome! Press 'q' to quit or any other key to continue:\n";
    char c;
    cin >> c;
    bool game_over = false;

    while(!game_over){
        if(c == 'q'){
            game_over = true;
            cout << "Bye Bye!\n";
            leaderboard.writeToFile();
            break;
        }else{
            Player current_player;
            srand(time(0));

            int randVal = rand() % (100 - 10 + 1) + 10;
            int guess = -1;
            string name;
            int num_tries = 0;

            cout << "Please enter your name to start: ";
            cin >> name;
            cout << sqrt(randVal) << " is the square root of what value?\n";
            do{
                cout << "Guess a value between 10 and 100: ";
                cin >> guess;
                num_tries++;

                if(guess == randVal){
                    cout << "You got it, baby!\n";
                    cout << "You made " << num_tries << " guesses\n";
                    current_player.setName(name);
                    current_player.setScore(num_tries);
                    leaderboard.addLeader(current_player);
                }else if(guess > randVal){
                    cout << "Too high, try again!\n";
                }else{
                    cout << "Too low, try again!\n";
                }
            }while(guess != randVal);
        }
        cout << "Current leaders are:\n";
        leaderboard.printLeaders();
        cout << "Press 'q' to quit or any other key to continue: ";
        cin >> c;
    }
}