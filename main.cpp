#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

  srand(time(0));
  int numSimulation;
  int winCounter = 0;
  int winFirstCounter = 0;
  char choice;

  cout << "\nPlease enter how many simulations you would like to run: ";
  cin >> numSimulation;
  cout << "\nWould you like to switch doors? (y/n) ";
  cin >> choice;

  for (int i = 0; i < numSimulation; ++i) {

    int prizeDoor = (1 + rand() % 3);
    int firstChoice = (1 + rand() % 3);

    if (choice == 'n' && (firstChoice == prizeDoor)) {

      winFirstCounter++;
      winCounter++;

    }

    else if(choice == 'y' && (firstChoice != prizeDoor)) {

      winCounter++;
    }

  }

  int numLost = (numSimulation - winCounter);
  int winWithChange = (winCounter - winFirstCounter);
  int percWithChange = (winWithChange * 100) / numSimulation;;
  int percWithoutChange = (winFirstCounter * 100) / numSimulation;

  if (choice == 'n') {
    cout << winFirstCounter << "\tGames won without change" << endl;
    cout << numLost << "\tGames lost without change" << endl;
    cout << percWithoutChange << "%" << "\tPercent won without change" << endl;
  }

  else if (choice == 'y') {
    cout << winWithChange << "\tGames won with change" << endl;
    cout << numLost << "\tGames lost with change" << endl;
    cout << percWithChange << "%" << "\tPercent won with change" << endl;
  }

  return 0;

}
