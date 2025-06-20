#include <iostream>
#include <cstdlib>
#include <cctype>
#include <limits>
using namespace std;

class gameCode
{
  private:
	string gameAuthor = "Nabir14";
	string gameVersion = "1.1";
  	int balance = 0;
	int level = 0;
	int durability = 100;	
  public:
	bool isGameRunning = false;

	void gameStart()
	{
		cout << "[   ***   ]" << endl;
		cout << "[ *  *  * ]" << endl;
		cout << "[*   *   *]" << endl;
		cout << "[    *    ]" << endl;
		cout << "[    *    ]" << endl;
		cout << "[    *    ]" << endl;
		cout << "[    *    ]" << endl;
		cout << "[Welcome To BitMiner]" << endl;
		cout << "[version: " << gameVersion << "]" << endl;
		cout << "[author: " << gameAuthor << "]" << endl;
		cout << "[Type 'H' for help]" << endl;
		isGameRunning = true;
	}
	void gameLoop()
	{
		while (isGameRunning == true)
		{
			cout << ">> ";
			char userInput;
			cin >> userInput;
			switch(toupper(userInput)){
				case 'H':
					cout << "'H': See All Available Actions" << endl;
					cout << "'M': Mine Bits" << endl;
					cout << "'D': Check Pickaxe Durability" << endl;
					cout << "'B': Check Balance" << endl;
					cout << "'S': Enter Pickaxe Shop" << endl;
					cout << "'Q': Quit Game" << endl;
					break;
				case 'M':
					if(durability > 0){
						durability -= 1;
						cout << "Mined: ";
						int minedBits = durability * (1 + (rand() % 10));
						cout << minedBits;
						cout << " bits" << endl;
						balance += minedBits;
					}else{
						cout << "You broke your Pickaxe!" << endl;
					}
					break;
				case 'Q':
					isGameRunning = false;
					cout << "Game Quit!" << endl;
					break;
				case 'D':
					cout << "Durability: ";
					cout << durability << endl;
					break;
				case 'B':
					cout << "Balance: ";
					cout << balance;
					cout << " bits" << endl;
					break;
				case 'S':
					{
					bool inShop = true;
					while (inShop) {
						cout << "(Pickaxe Shop)" << endl;
						cout << "<1> Basic Pickaxe [5000 Bits]" << endl;
						cout << "<2> Gold Pickaxe [50000 Bits]" << endl;
						cout << "<3> Diamond Pickaxe [500000 Bits]" << endl;
						cout << "<4> Exit shop" << endl;
						cout << "<?> ";
						int input;
						cin >> input;
						if(cin.fail()){
							cin.clear(); // clear fail state
							cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard input
							cout << "Invalid Item!" << endl;
							continue;
						}
						switch(input){
							case 1:
								if(balance >= 5000){
									balance -= 5000;
									durability += 100;
									cout << "You bought a Basic Pickaxe!" << endl;
								}else{
									cout << "Insufficient Balance!" << endl;
								}
								break;
							case 2:
								if(balance >= 50000){
									balance -= 50000;
									durability += 1000;
									cout << "You bought a Gold Pickaxe!" << endl;
								}else{
									cout << "Insufficient Balance!" << endl;
								}
								break;
							case 3:
								if(balance >= 500000){
									balance -= 500000;
									durability += 10000;
									cout << "You bought a Diamond Pickaxe!" << endl;
								}else{
									cout << "Insufficient Balance!" << endl;
								}
								break;
							case 4:
								inShop = false;
								break;
							default:
								cout << "Invalid Item!" << endl;
								break;
						}
					}
					}
					break;
				default:
					cout << "Invalid Action!" << endl;
					break;
			}
		}
	}
};
int main()
{
	gameCode bitminer;
	bitminer.gameStart();
	bitminer.gameLoop();
}
