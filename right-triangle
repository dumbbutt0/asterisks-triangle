#include <iostream>
using namespace std;

void triangle()
{
    char sign;
    int times,x,y;
    cout << "Pick your character: " ;
    cin >> sign ;
    cout << "\nHow many times to replay: ";
    cin >> times;
    for ( x =1 ; x <= times; x++)    // loop number of {times}
    {                               // for (use var=x; while int==x; do x++)
        for (y =1; y <= x; y++)    //Nested for-loop
        {
            cout << sign;        //while y<=x do whatever is in the loop
        }
        cout << endl;

    }                                
             
}

void question()
{
    char answer, yes='y';

    cout << "Do you want to go again y/n: ";
    cin >> answer;
    cout << endl;
    if( answer == yes){
        triangle();
        question();
    } 
    else{
        cout << "Goodbye😁️\n";
    }
}

int main()
{
    triangle();
    question();
    return 0;
}
