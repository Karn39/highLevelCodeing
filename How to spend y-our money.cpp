#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct thing
{
	int cost;
	int cp;
};

int main()
{
	int N;
	cin >> N;

	int m;
	cin >> m;
		
	vector<thing> shop;
	while (m--)
	{
		thing v;
		cin >> v.cost >> v.cp;
		shop.push_back(v);
	}

	int first = 0;
	int add = 1;
	int maxValue = 0;
	
	while (1)
	{
		if (add > shop.size() - 1)
		{
			first++;
			add = first + 1;
		}
		if (first > shop.size() - 1)
		{
			cout << maxValue << endl;
			break;
		}

		int totalCost = shop[first].cost;
		int nowValue = shop[first].cost*shop[first].cp;
		for (int i = add; i < shop.size(); i++)
		{
			if (totalCost + shop[i].cost <= N)
			{
				totalCost = totalCost + shop[i].cost;
				nowValue = nowValue + shop[i].cost*shop[i].cp;
				if (nowValue > maxValue)
				{
					maxValue = nowValue;
				}
			}
		}
		add++;
	}
}
