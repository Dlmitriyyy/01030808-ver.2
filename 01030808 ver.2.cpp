#include <iostream>
#include <array>
using namespace std;
int main()
{
	system("chcp 1251 > nul");
	int money, max_banknotes;
	int total_banknotes = 0;

	array <int, 10> banknote;
	array <int, 10> count;

	banknote = { 3000,1000,500,200,100,50,20,10,5,1 };
	count = { 0,0,0,0,0,0,0,0,0,0 };

	cout << "Введіть сумму яку бажаєте зняти з карточки: ";
	cin >> money;
	int remaining_money = money;

	for (int a = 0; a < banknote.size(); a++)
	{
		count[a] = remaining_money / banknote[a];
		if (count[a] > 0)
		{
			max_banknotes = 40 - total_banknotes;
			if (count[a] > max_banknotes)
			{
				count[a] = max_banknotes;
			}
			total_banknotes += count[a];
			remaining_money -= count[a] * banknote[a];
		}
	}

		cout << endl << "Ви можете отримати гроші наступними купюрами: " << endl << endl;

	for (int a = 0; a < count.size(); a++)
	{
		if (count[a] > 0)
		{
			cout << "Кількість купюр номіналом " << banknote[a] << " грн: " << count[a] << " шт." << endl;
		}
	}
		cout << endl << "Загальна кількість виданих купюр: " << total_banknotes << " шт." << endl;

	if (total_banknotes >= 40)
	{
		cout << endl << "Сумма яку не вдалось зняти з карточки у зв'язку з лімітом у 40 купюр за одне зняття: " << remaining_money << " грн." << endl;
	}
	return 0;
}