#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

#define pb push_back

struct Item
{
	string name;
	char check;
	int score;

	Item(string name, char check, int score) : name(name), check(check), score(score) {}

	bool operator <(const Item &rs) const
	{
		return rs.score > score;
	}
};

int main(void)
{
	vector<Item> v;

	v.clear();

	int num;
	string str;
	string command;
	char check;
	printf("Enter uva number: ");
	cin >> num;
	printf("Enter the problem name: ");
	getchar();
	getline(cin, str);
	printf("Is the problem done?\n");
	cin >> check;
	/*
	printf("Any command?\n");
	getchar();
	getline(cin, command);
	*/

	ifstream ifs("checklist.txt");
	string tmp;
	int j = 0;
	while(getline(ifs, tmp))
	{
		char num_char[100];
		char aks_tmp;
		int k = 0;
		int string_index = 0;

		if(tmp[6] == 'u' && tmp[7] == 'v' && tmp[8] == 'a')
		{
			if(tmp[3] == 'X')
			{
				aks_tmp = 'X';
			}
			else
			{
				aks_tmp = 'Y';
			}

			for(j = 0; tmp[j] != ' '; j++)
			{
				num_char[k] = tmp[j];
				k++;
			}

			string str_tmp;

			for(int s = j+3; s < tmp.size(); s++)
			{
				str_tmp += tmp[s];
			}

			int number = atoi(num_char);

			v.pb(Item(str_tmp, aks_tmp, number));
		}

		else
			continue;
	}	

	if(check == 'y' || check == 'Y')
		v.pb(Item(str, 'X', num));
	else if(check == 'n' || check == 'N')
		v.pb(Item(str, ' ', num));
	else
	{
		printf("Redo\n");
		return 0;
	}

	sort(v.begin(), v.end());

	for(int i = 0; i <	 v.size(); i++)
	{
		cout << v[i].check << ' ' << v[i].score << v[i].name << endl;
	}


/*
	ofstream ofs("checklist.txt");

	ofs << "# UVA" << '\n';
	ofs << '\n';
	for(int i = 0; i < v.size(); i++)
	{
		ofs << "* [" << v[i].check << "] uva" << v[i].score << "-" << v[i].name << '\n';
	}
*/
	return 0;
}