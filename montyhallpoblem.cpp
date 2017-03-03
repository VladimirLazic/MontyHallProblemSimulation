#include<iostream>

#define NUMBER_OF_DOORS 3
#define NUMBER_OF_TRIES 1000

int numberOfCorrect = 0;
int numberOfIncorrect = 0;

using namespace std;

void start_the_quiz(bool *doors) {

    cout<<"Setting the doors"<<endl;
    for(int i = 0; i < NUMBER_OF_DOORS; i++) {
        doors[i] = false;
    }
    doors[rand()%NUMBER_OF_DOORS] = true;
}

int main() {

    bool doors[NUMBER_OF_DOORS];
    double probabilityRatio;
    start_the_quiz(doors);


    for(int i = 0; i < NUMBER_OF_TRIES; i++) {
        int my_pick = rand()%NUMBER_OF_DOORS;
        cout<<"Contestant has selected door number: "<< my_pick  <<endl;

        int eliminated_door;

        //Elimination of one false answer
        for(int j = 0; j < NUMBER_OF_DOORS; j++) {
            if(doors[j] == false && j != my_pick) {
                eliminated_door = j;
                break;
            }
        }
        cout<<"Host has eliminated door number: "<<eliminated_door<<endl;

        //New pick
        for(int j=0; j < NUMBER_OF_DOORS; j++) {
            if(j != my_pick && j != eliminated_door) {
                my_pick = j;
                break;
            }
        }
        cout<<"Contestant had changed his answer to door number: "<<my_pick<<endl;

        if(doors[my_pick] == true) {
            numberOfCorrect++;
            cout<<"Behind door number "<<my_pick<<" is a car!"<<endl;
        } else {
            numberOfIncorrect++;
            cout<<"Behind door number "<<my_pick<<" is a goat!"<<endl;
        }
        start_the_quiz(doors);
    }
    probabilityRatio = (float)numberOfCorrect/(float)NUMBER_OF_TRIES;

    cout<<"Number of Correct : "<<numberOfCorrect<<endl;
    cout<<"Number of Incorrect : "<<numberOfIncorrect<<endl;
    cout<<endl;

    cout<<"Probability ratio : "<< 100*probabilityRatio<<"%"<<endl;
    
    return 0;
}
