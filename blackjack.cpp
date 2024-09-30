#include <iostream>
#include <random>

using namespace std;

random_device deck;
mt19937 cards(deck());
uniform_int_distribution<> shuffle(1, 11);
uniform_int_distribution<> shuffled(2, 21);
uniform_int_distribution<> play(1, 2);
int user,dealer,c1,c2,c3;
void pausing(),deal(),rounder(),win(),question();


void game()
{
    char answer;
    c1=shuffle(cards);
    c2=shuffle(cards);
    c3=shuffled(cards);

    dealer = c3;
    cout << "> The Dealer starts with a " << dealer<< endl;
    cout<< "> Your first cards: "<< c1 << ","<<c2<<endl;
    user =c1+c2;
    cout << "> Total: "<< user<< endl;
    if (user == 21){
        cout << "> Player wins by 21!"<<endl;
        return;
        }
    cout << "> hit? (y/n): ";
    cin >> answer;
    if (answer == 'y'){
        rounder();
    }else{
        pausing();
    }
}


void rounder()
{
    char answer;
    c1=shuffle(cards);
    user += c1;
    cout << "> Card: "<< c1 << endl;
    cout << "> Total: " <<user << endl;
    if (user >21)
    {
        cout << "> Dealer wins!\n";
        return;
    } 
    cout << "> hit? (y/n): ";
    cin >> answer;
    if (answer == 'y'){
        rounder();
    }else{
        pausing();
    }
}


void pausing()
{
    char a;
    cout << "> (c to continue)";
    cin >> a;
    cout << endl;
    //deal();
    if (a != 'c'){
        pausing();
    }
    deal();
}


void win()
{
    user -= 21;
    dealer -= 21;
    if( user > dealer){
        cout <<"> YOU BEAT THE DEALER!!" << endl;
        question();
    }else if( dealer > user){
        cout << "> The dealer wins :("<< endl;
        question();
    }else if( user == dealer){
        cout << "> There was a draw this time "<<endl;
        question();
    }
}


void deal()
{
    int go=play(cards);
    if (dealer < 17){
        c3=shuffle(cards);
        dealer += c3;
        cout <<"> Dealer gets a "<< c3<< endl;
        cout << "> Total: "<<dealer<<endl;
        pausing();
    }if (dealer > 21){
        cout << "> Dealer busted with "<< dealer<< endl;
        return;
    }if (go ==1){
        c3=shuffle(cards);
        dealer += c3;
        cout <<"> Dealer gets a "<< c3<< endl;
        cout << "> Total: "<<dealer<<endl;
    }if (dealer > 21){
        cout << "> Dealer busted with "<< dealer<< endl;
        return;
    }if (dealer ==21){
        cout << "> Dealer wins by 21!";
    }if( go == 2){
        cout << "> The Dealer holds with " << dealer << endl;
        win();
    }
    pausing();
}


void question()
{
    char answer, yes='y';

    cout << "> Do you want to play again y/n: ";
    cin >> answer;
    cout << endl;
    if( answer == yes){
        game();
        question();
    } 
    else{
        cout << "> Goodbye😁️\n";
        exit(0);
    }
}


int main(){
    game();
    question();
}
