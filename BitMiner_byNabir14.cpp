#include <iostream>
#include <random>
using namespace std;
class gameCode
{
  public:
	void gameTitle()
	{
		string gi =
			"[   ***   ]";
		string gii =
			"[ *  *  * ]";
		string giii =
			"[*   *   *]";
		string giv =
			"[    *    ]";
		string gv =
			"[    *    ]";
		string gvi =
			"[    *    ]";
		string gvii =
			"[    *    ]";
		string mainTitle =
			"[Welcome To BitMiner]";
		string gameVersion =
			"[version_1.0]";
		string gameCredits =
			"[Made By Nabir14]";
		cout << gi << endl
			 << gii << endl
			 << giii << endl
			 << giv << endl
			 << gv << endl
			 << gvi << endl
			 << gvii << endl
			 << mainTitle << endl
			 << gameVersion << endl
			 << gameCredits << endl;
	}
	int getInput()
	{
		while (1)
		{
			cout << "type `-m` to mine chunks" << endl
				 << ">> ";
			//int balanceBit = 0;
			string userInput;
			cin >> userInput;
			if (userInput == "-m")
			{
				cout << "you mined one chunk" << endl;
				random_device rd;
				mt19937 rng(rd());
				uniform_real_distribution<double> dist(0.0, 100.0);
				cout << "you got ";
				for (int i = 0; i < 1; i++)
					cout << dist(rng);
				cout << " bits" << endl;
			}
			else
			{
				cout << "invalid" << endl;
			}
		}
	}
};
int main()
{
	gameCode gameOpening;
	gameOpening.gameTitle();
	gameCode userInput;
	userInput.getInput();
}