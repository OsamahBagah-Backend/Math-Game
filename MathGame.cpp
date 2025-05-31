#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

struct stQueeze {
	int queezeNumber;
	int queezeLevel;
	int operationType;
	int wenner = 0;
};

enum enlevel { easy = 1, mid = 2, hard = 3, mix = 4 };
enum enoperator { add = 1, sub = 2, muli = 3, vid = 4, mix2 = 5 };

stQueeze information()
{
	stQueeze queeze;

	cout << "please enter how queezes you want : ";
	cin >> queeze.queezeNumber;
	cout << "please enter queeze level : [1] easy : [2] mid : [3] hard : [4] mix : ";
	cin >> queeze.queezeLevel;
	cout << "please enter aqueeze operation : [1] add : [2] sub : [3] muli : [4] div : [5] mix : ";
	cin >> queeze.operationType;

	return queeze;
}

int randnum(int from, int to)
{
	int randoom = rand() % (to - from + 1) + from;
	return randoom;
}

int result()
{
	int num;
	cin >> num;

	return num;
}

void generate_function(int number1, int number2, char operate)
{
	cout << number1 << endl;
	cout << number2 << " " << operate << endl;
	cout << "\n----------------\n";
}

int randy(int num)
{
	switch (num)
	{
	case 1:
		return randnum(1, 10);

	case 2:
		return randnum(10, 50);

	case 3:
		return randnum(50, 100);

	case 4:
		return randnum(1, 100);
	}
}

char typeOperate(int num)
{
	switch (num)
	{
	case 1:
		return '+';

	case 2:
		return '-';

	case 3:
		return '*';

	case 4:
		return '/';

	case 5:
		int randy = randnum(1, 5);
		return typeOperate(randy);
	}
}

int corect_result1(int num1, int num2, char operate)
{
	switch (operate)
	{
	case '+':
		return num1 + num2;

	case '-':
		return num1 - num2;

	case '*':
		return num1 * num2;

	case '/':
		return num1 / num2;
	}
}

void the_color(int num1, int num2)
{
	if (num1 != num2)
	{
		system("color 4F");
		cout << "wrong answer :-( \n";
		cout << "the right answer : " << num1;
	}

	else
	{
		system("color 2F");
		cout << "right answer :-)\n";
	}
}

string operation_type(int num)
{
	switch (num)
	{
	case enoperator::add:
		return "add";

	case enoperator::sub:
		return "sub";

	case enoperator::muli:
		return "muli";

	case enoperator::vid:
		return "Div";

	case enoperator::mix2:
		return "mix2";
	}
}

string quetion_level(int num)
{
	switch (num)
	{
	case enlevel::easy:
		return "easy";

	case enlevel::mid:
		return "mid";

	case enlevel::hard:
		return "hard";

	case enlevel::mix:
		return "mix";
	}
}

int the_wenner(int num1, int num2)
{
	int count = 0;
	if (num1 == num2)
	{
		count++;
	}

	return count;
}

void how_wen(int num1, int num2)
{
	if (num1 > num2)
	{
		cout << "the final result is sussecces :-)\n\n";
	}

	else
	{
		cout << "the final result is fail :-(\n\n";
	}
}

void print_the_queeze(stQueeze& queeze)
{

	for (int i = 0; i < queeze.queezeNumber; i++)
	{
		cout << "\n\nquetion [ " << queeze.queezeNumber << " \\ " << i + 1 << " ] \n";
		int num1 = randy(queeze.queezeLevel);
		int num2 = randy(queeze.queezeLevel);
		char operat = typeOperate(queeze.operationType);
		generate_function(num1, num2, operat);
		int result2 = result();
		int result3 = corect_result1(num1, num2, operat);
		the_color(result3, result2);
		queeze.wenner += the_wenner(result3, result2);
	}
}

void print_the_result(stQueeze queeze)
{
	int fail = queeze.queezeNumber - queeze.wenner;
	cout << "\n\n-----------------------------------------------\n";
	how_wen(queeze.wenner, fail);
	cout << "---------------------------------------------------\n";
	cout << "the game question is : " << queeze.queezeNumber << endl;
	cout << "the quetion level is : " << quetion_level(queeze.queezeLevel) << endl;
	cout << "the operation type is : " << operation_type(queeze.operationType) << endl;
	cout << "the right answer is : " << queeze.wenner << endl;
	cout << "the rong answer is : " << fail << endl;
	cout << "------------------------------------------------------\n\n";
}

void finish_the_game()
{
	char choose;
	stQueeze queeze;
	do
	{
		queeze = information();
		print_the_queeze(queeze);
		print_the_result(queeze);
		cout << "did you want to complete or no to compltet enetr y or Y  and N for exite : ";
		cin >> choose;

		if (choose == 'y' || choose != 'Y')
		{
			system("cls");
			system("color 0F");
		}

	} while (choose != 'N');
}

int main()
{
	srand((unsigned)time(NULL));

	finish_the_game();

	return 0;
}