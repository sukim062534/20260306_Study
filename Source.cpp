#include <iostream> 
#include <string> //문자열

#define CARDSIZE    52

using namespace std;

int main()
{

	int Player[CARDSIZE];
	//Heart
	//0,1,2,3,4,5,6,7,8,9,10,11,12
	//Spade
	//13,14,15,16,17,18,19,20,21,22,23,24,25
	//Diamond
	//26,27,28,29,30,31,32,33,34,35,36,37,38
	//clover
	//39,40,41,42,43,44,45,46,47,48,49,50,51

	//똑같은 카드가 나오면 안됨

	int Cards[CARDSIZE] = { 0, };

	string CardType[4] = {"Heart","Spade","Diamond","Clover"};

	for (int i = 0; i < CARDSIZE; ++i)
	{
		Cards[i] = i;

	}

	//아무거나 - Random(난수)
	//srand(10); 계속 같은 값이 나옴
	//컴퓨터에서 계속 바뀌는 값 - 시간을 사용
	srand((unsigned int)time(nullptr)); //nullptr에 0을 넣어도 똑같음

	//Shuffle
	//Random(난수) 두개 선택 해서 교환
	//카드 10장 교환
	for (int i = 0; i < CARDSIZE * 10; ++i)
	{
		int FirstIndex = rand() % CARDSIZE;
		int SecondIndex = rand() % CARDSIZE;
		int Temp = Cards[FirstIndex];

		Cards[FirstIndex] = Cards[SecondIndex];
		Cards[SecondIndex] = Temp;
	}

	//Deal
	int ComputerCard[3];
	int PlayerCard[3];
	//0, 1
	//2, 3
	//4, 5
	for (int i = 0; i < 3; ++i)
	{
		ComputerCard[i] = Cards[i * 2];
		PlayerCard[i] = Cards[(i * 2) + 1];
	}

	//PreProcess
	int ComputerScore[3] = { 0, };
	int PlayerScore[3] = { 0, };

	for (int i = 0; i < 3; ++i)
	{
		ComputerScore[i] = (ComputerCard[i] % 13 + 1) > 10 ? 10 : (ComputerCard[i] % 13 + 1);

		PlayerScore[i] = PlayerCard[i] % 13 + 1;

		PlayerScore[i] = PlayerScore[i] > 10 ? 10 : PlayerScore[i];
	}
	//조건식 트루면 A 실행 Fales면 B 실행
	// 조건식 ? :
	int TotalComputerScore = ComputerScore[0] + ComputerScore[1] + ComputerScore[2];
	int TotalPlayerScore = PlayerScore[0] + PlayerScore[1] + PlayerScore[2];
	//Draw
	if (TotalComputerScore > 21)
	{
		cout << "Player Win" << endl;
	}
	else if (TotalPlayerScore > 21)
	{
		cout << "Player Lose" << endl;
	}
	else if (TotalComputerScore > TotalPlayerScore)
	{
		cout << "Player Lose" << endl;
	}
	else
	{
		cout << "Player Win" << endl;
	}
	cout << "\n==========================" << endl;
	cout << "Computer Deck" << endl;
	for (int i = 0; i < 3; ++i)
	{
		int CardTypeIndex = ComputerCard[i] / 13;

		cout << CardType[CardTypeIndex] << " " << ComputerScore[i] << endl;
	}
	cout << "Total : " << TotalComputerScore << endl;
	cout << "==========================\n" << endl;

	cout << "==========================" << endl;
	cout << "Player Deck" << endl;
	for (int i = 0; i < 3; ++i)
	{
		int CardTypeIndex = PlayerCard[i] / 13;

		cout << CardType[CardTypeIndex] << " " << PlayerScore[i] << endl;
	}
	cout << "Total : " << TotalPlayerScore << endl;
	cout << "==========================" << endl;

	return 0;
}