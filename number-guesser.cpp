#include <iostream>
#include <cmath>

using namespace std;

void guessGame();

//function to play the guesser
void guesser(float high,float low)
{
    char answer = 'x', again ='x';
    float guess = (low+high)/2;
    //guess = round(guess);
    cout<< "Is it " << floor(guess) <<"? (h/l/c): ";
    cin >> answer;
    switch(answer){             //switch block to control high,low,correct
        case 'h':
            low = round(guess);
            break;
        case 'l':
            high = round(guess);
            break;
        case 'c':
            cout <<"Great! Do you want to play again? (y/n): ";
            cin >> again;
            if (again == 'y'){
                guessGame();
            }else{
                exit(0);
            }
    }
    guesser(high,low);  //if we exit the switch then run the program with updated numbers
}


void guessGame()                        // initialize the game
{
    float high=100,low=1;
    cout << "Guess a number between 1 and 100."<< endl;
    guesser(high,low);

}

int main()
{
    guessGame();        // put it all together
}
