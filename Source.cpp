#include <iostream>

using namespace std;

int main()
{	

	int sum = 0;
	int sum2 = 0;

	srand(time(NULL));
	cout << "사람 :";
	for (int A = 1; A <= 3 ; A++)
	{
		int num = rand() % 10+1 ;
		cout << num << " ,";
		sum += num;

	}

	cout << "="<< sum << endl;
	cout << "컴퓨터 :";

	for (int B = 1; B <= 3; B++)
	{
		int num2 = rand() % 10+1;
		cout << num2 << " ,";
		sum2 += num2;

	}
	cout << "=" << sum2;
	cout << '\n';

	if (sum >= 21)
	{
		cout << "졌다";
	}
	else if (sum2 >= 21)
	{
		cout << "이겼다";
	}
	else if (sum > sum2)
	{
		cout << "이겼다";
	}
	else if (sum < sum2)
	{
		cout << "졌다";
	}
	else if (sum = sum2)
	{
		cout << "이겼다";
	}

	return 0;
}