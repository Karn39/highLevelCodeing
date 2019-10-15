#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct thing
{
	int cost;
	int cp;
	int value;
};

int main()
{
	int N;
	cin >> N;

	int m;
	cin >> m;
		
	vector<thing> shop;
	vector<bool> take(m, false);
	while (m--)
	{
		thing v;
		cin >> v.cost >> v.cp;
		v.value = v.cost*v.cp;
		shop.push_back(v);
	}

	int first = 0;
	int add = 1;
	int maxValue = 0;

	while (1)
	{
		int totalCost = (shop[first].cost <= N) ? shop[first].cost : 0;
		int nowValue = (shop[first].cost <= N) ? shop[first].value : 0;
		int thisMax = 0;
		int Maxpos;
		bool Balance = false;
		for (int i = add; i < shop.size(); i++)
		{			
			if (totalCost + shop[i].cost <= N && !take[i])
			{
				if (nowValue + shop[i].value > thisMax)
				{
					thisMax = nowValue + shop[i].value;
					Maxpos = i;
					Balance = true;
				}
			}
			if (i == shop.size() - 1)
			{
				if (!Balance)
				{
					break;
				}
				nowValue = thisMax;
				totalCost = totalCost + shop[Maxpos].cost;
				take[Maxpos] = true;
				i = add;
				Balance = false;
			}
		}

		first++;
		add = first + 1;
		fill(take.begin(), take.end(), false);
		if (nowValue > maxValue)
		{
			maxValue = nowValue;
		}
		if (first > shop.size() - 1)
		{
			cout << maxValue << endl;
			break;
		}
	}
}
