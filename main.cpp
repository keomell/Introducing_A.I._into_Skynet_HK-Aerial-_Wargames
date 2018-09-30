/** Requirements ! = Completed
!-Modify your new C++ program for the Skynet HK-Aerial.
!-Add another AI player using the less efficient Linear search pattern.
!-Add another AI player using a random number guess between grid locations 1 and 64.
!-Add a human player, letting the human input grid numbers from the console.
!-The easiest way to code this would be for this program’s user interface to start with the human player and use a while loop until the human guesses the location the enemy while keeping track of the number of guesses the human uses. Then the random guess AI player should guess using their own while loop until they find the enemy location and keep track of how many guesses it took them. Then the linear Search AI player should guess using their own while loop until they find the enemy location, and then finally the Binary search AI should run it’s while loop and keep track of the number of guesses it takes to find the enemy location. Once all players AI and Human have found the enemy location, then this game is over. Display the stats of each player's number of guesses it took. You don't have to physically sort them, just display the number of guesses each drone pilot took to find the enemy.
!-Be sure to comment each line of code except cout statements, write very readable code using good coding standards.
!-The Grid does not need to be displayed, remember the grid is abstract. Think of this as more of a guess the number game like at the end of chapter two.
!-When all the players have found the enemies, the game is over, the console should ask the human player if they would like to play again. If the human player say's yes, then the game should reset all scores and play again.
!-Put this new project into a new GitHub repostiory and take a screenshot of it.
!-Your code should be well formatted and with lots of comments explaining your code.

 Notes:
 --Vars For each Search
    !-Human  Search
    !-Binary Search
    !-Linear Search
    !-Random Search
 */

#include <iostream>//PreProcess Directives
#import <cstdlib>//General Utilities
#import <ctime>//manipulate date and time
#import <algorithm>//Functions used on a range of elements

using std::cout;  //Print out to the console
using std::cin; //Receive use input
using std::endl; //Mark the end if the line
using std::string; //Use string
using std::min;// using min from algorithm import

int main() {

    srand(static_cast<unsigned int>(time(0))); //Seed random number

    //Initialize tries
    int humanTries  = 0;
    int binaryTries = 0;
    int linearTries = 0;
    int randomTries = 0;

    // Initialize search vars
    int humanSearch;
    int binarySearch;
    int linearSearch;
    int randomSearch;

    int lowestTries; //To get the lowest amount of tries

    int enemyLocation = (rand() % 64) + 1; //Generate Random number Get Enemy Location Number between 1 - 64
    int searchGridHighNumber = 64; //Initialize Grid High Number
    int searchGridLowNumber = 1; //Initialize Grid Low Number
    char start = 'y'; //Initialize start program
    string winner;//winner with the lowest tries


    //display enemy location for quick and easy testing
    cout << enemyLocation << " E \n";



    //Starting the game loop
    while(start =='y' || start =='Y'){
        cout << enemyLocation << " E \n";
        /********************************* Start of human search ****************************************************/
        cout << "Human Search Started \n";
        //Do while humanSearch is not equal to enemyLocation
        do{


            cout << "Enter a number: \n";
            cin >> humanSearch; //Getting human number form input


            if(humanSearch > enemyLocation){ //Checking of the number for input is greater than the enemy location

                cout << "Human Number too High \n";

            }else if(humanSearch < enemyLocation){//Checking of the number for input is less than the enemy location

                cout << "Human Number is too low \n";

            }

            humanTries++; //Adding 1 to human tries

        }while(humanSearch != enemyLocation);
        cout << "Human Search ended \n";
        /********************************* End of human search ****************************************************/


        /********************************* Start of linear Search *********************************/
        cout << "Linear A.I Search Started \n";
        for(int i = 0; i <= 64; i++){

            linearTries++;//Add one to linear tires
            linearSearch = i; // Linear search number equals the current number in the loop
            //For each number check if its equal to the enemy location
            if(linearSearch == enemyLocation){

                //if so, break out the loop
                break;
            }else{
                cout << "Linear Search A.I choose too low \n";
            }

        }

        cout << "Linear A.I Search Ended \n";
        /********************************* End of linear Search *********************************/


        /*********************************** Start of random search **********************************/
        cout << "Random A.I Search Started \n";
        do{
            randomTries++; //Add one to random tries
            randomSearch = (rand() % 64) + 1; //Guess a random number

            if(randomSearch > enemyLocation){
                cout << "Random Search A.I choose too low \n";
            }else{
                cout << "Random Search A.I choose too high \n";
            }

        }
        while(randomSearch != enemyLocation);

        cout << "Random A.I Search Ended \n";
        /*********************************** End of random search **********************************/


        /************************************ Start of Binary Search ************************************/
        cout << "Binary A.I Search Started \n";
        do{

            //Setting Initial prediction
            binarySearch = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;


            //Checking of enemy Location is greater than predication
            if(enemyLocation > binarySearch)
            {
                cout << "Binary Search A.I choose too low \n";

                //Setting lower number to current prediction and adding 1
                searchGridLowNumber = binarySearch + 1;

                //Getting a new prediction bases on new prams
                binarySearch = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;



            }
                //Checking of enemy Location is less than predication
            else if(enemyLocation < binarySearch)
            {

                cout << "Binary Search A.I choose too high \n";

                //Setting higher number to current prediction and taking away 1
                searchGridHighNumber = binarySearch - 1;


                //Getting a new prediction bases on new prams
                binarySearch = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;




            }

            binaryTries++; //Adding 1 to tries

        }
        while((enemyLocation != binarySearch));
        cout << "Binary A.I Search Ended \n";
        /************************************* End fo Binary search ************************************/

        //Getting the lowest tires
        lowestTries = min(humanTries, min(linearTries, min(randomTries, binaryTries)));

        //Finding out the winner
        if(lowestTries == humanTries){
            winner = "Human won";
        }else if(lowestTries == linearTries){
            winner = "Linear A.I won";
        }else if(lowestTries == randomTries){
            winner = "Random A.I won";
        }else if(lowestTries == binaryTries){
            winner = "Binary A.I won";
        }

        //Displaying the results.
        cout << "*************************************\n";
        cout << "* All drones have now found the enemy.\n";
        cout << "* The Enemy was hiding at grid location " << enemyLocation << "\n";
        cout << "* \n";
        cout << "* The Human Player using a human Search took " << humanTries << " guesses to find the enemy location final target prediction was " << enemyLocation << "\n";
        cout << "* The A.I Player using Linear Search took " << linearTries << " guesses to find the enemy location final target prediction was " << enemyLocation << "\n";
        cout << "* The A.I Player using Random Search took " << randomTries <<  " guesses to find the enemy location final target prediction was " << enemyLocation << "\n";
        cout << "* The A.I Player using Binary Search took " << binaryTries << " guesses to find the enemy location final target prediction was " << enemyLocation << "\n";
        cout << winner << "\n";
        cout << "*************************************\n";


        //Checking of the user whats to play again.
        cout << "Would you like to play again? Y/N \n";
        cin >> start;

        //Check of start is still equal to y
        if(start =='y' || start =='Y'){

            //Get a new enemy location
             enemyLocation = (rand() % 64) + 1;

             //Reset all tries to 0
             humanTries  = 0;
             binaryTries = 0;
             linearTries = 0;
             randomTries = 0;

            searchGridHighNumber = 64; //Reset Grid High Number
            searchGridLowNumber = 1; //Reset Grid Low Number
        }
    }

    return 0;

}


/** OUTPUT EXAMPLE

***********************************************
* All drones have now found the enemy.
* The Enemy was hiding at grid location 59
*
* The Human Player using a human Search took 3 guesses to find the enemy location final target prediction was 59
* The AI Player using Linear Search took 59 guesses to find the enemy location final target prediction was 59
* The AI Player using Random Search took 33 guesses to find the enemy location final target prediction was 59
* The AI Player using Binary Search took 6 guesses to find the enemy location final target prediction was 59
**********************************************
Would you like to play again? Y/N

 */