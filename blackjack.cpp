#include <iostream>
#include <random>

using namespace std;


random_device deck;
mt19937 cards(deck());
uniform_int_distribution<> shuffle(1, 11);
uniform_int_distribution<> shuffled(2, 21);
uniform_int_distribution<> play(1, 2);
int user,dealer, card1=shuffle(cards),card2=shuffle(cards),card3=shuffled(cards),go=play(cards);
void pausing(),question();

void game()
{

   
    string round="> Do you want another card? (y/n): ",again="> Would you like to play again? (y/n): ";
    char yes='y',no='n',answer;
    cout << endl;
    
    user=0;
    dealer=0;

    dealer = card3;
    cout << "> The Dealer starts with a " << dealer<<endl;
    cout<< "> Your first cards: "<< card1 << ","<<card2<<endl;
    user=card1+card2;
    cout << "> Total:"<< user<< endl;
    if (user >21){
        cout << "> Dealer wins!\n";
        return;
    }
    cout << "> hit? (y/n): ";
    cin >> answer;
    cout << endl;
    if (answer == yes)
    {
        card1=shuffle(cards);
        user+=card1;
        cout << "> Card: "<< card1 << endl;
        cout << "> Total: " <<user << endl;
        if (user >21){
            cout << "> Dealer wins!\n";
            return;
        }
        cout << "> hit? (y/n): ";
        cin >> answer;
        cout << endl;
        if (answer == yes)
        {
            card1=shuffle(cards);
            user+=card1;
            cout << "> Card: "<< card1 << endl;
            cout << "> Total: " <<user << endl;
            if (user >21){
            cout << "> Dealer wins!\n";
            return;
            }
            cout << "> hit? (y/n): ";
            cin >> answer;
            cout << endl;
            if (user >21){
            cout << "> Dealer wins!\n";
            return;
            }
            if (answer == yes)
            {
                card1=shuffle(cards);
                user+=card1;
                cout << "> Card: "<< card1 << endl;
                cout << "> Total: " <<user << endl;
                if (user >21){
                cout << "> Dealer wins!\n";
                return;
                }
                cout << "> hit? (y/n): ";
                cin >> answer;
                cout << endl;
                if (answer == yes)
                {
                    card1=shuffle(cards);
                    user+=card1;
                    cout << "> Card: "<< card1 << endl;
                    cout << "> Total: " <<user << endl;
                    if (user >21){
                    cout << "> Dealer wins!\n";
                    return;
                    }
                }
            }
        }
    }
    pausing();
}


void deals()
{
    
    if (dealer > 21){
            cout << "> Dealer busted with "<< dealer;
            return;
        }

    go=play(cards);
    if (dealer >=17){
        cout << "> Dealer has "<< dealer << endl;
        if (go == 1|| dealer){
                card3=shuffle(cards);
                dealer += card3;
                cout <<"> Dealer gets a "<< card3<< endl;
                cout << "> Total: "<<dealer<<endl;
                if (dealer > 21){
                    cout << "> Dealer busted with "<< dealer<< endl;
                    return;
                    }   
            }else{
                dealer +=card3;
                pausing();
            }
            if ( go == 2){
                int x = 21- user;
                int y = 21 - dealer;
                cout << "> The Dealer holds\n";
                    if (x <y){
                        cout << "> YOU BEAT THE DEALER!!\n";
                    }else{
                        cout <<"> The dealer wins.\n";
                    }
                return;
            }
    
    } else{
        card3=shuffle(cards);
        dealer += card3;
        cout <<"> Dealer gets a "<< card3<< endl;
        cout << "> Total: "<<dealer<<endl;
    }
    if (go == 2){
        
        if (dealer >21){
            cout << "> YOU BEAT THE DEALER!!"<< endl;
            question();
        }
       int x = 21- user;
       int y = 21 - dealer;
       cout << "> The Dealer holds\n";
        if (x <y){
            cout << "> YOU BEAT THE DEALER!!"<< endl;
        }else if (x == y)
        {
            cout << "> There was a draw\n";/* code */
        }
        {
            cout <<"> The dealer wins.\n"<<endl;
        }
        return;
    }
    pausing();
}


void pausing()
{
    char a;
    a='a';
    cout << "> (c to continue)";
    cin >> a;
    cout << endl;
    deals();

    if (a != 'c'){
        pausing();
    }
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
    }
}
int main()
{
    game();
    question();
}
