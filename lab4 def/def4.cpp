#include <iostream>
#include <stdio.h>
#include <string>
#include <regex>
#include <fstream>
#include <sstream>

using namespace std;

bool col_fun(string col)
{
	int red = 0, green = 0, blue = 0;
	int type = col.size() == 3 ? 1 : 2;

	if ((col.size() == 3) || (col.size() == 6))
	{
		istringstream(col.substr(0, type)) >> std::hex >> red;
		istringstream(col.substr(type, type )) >> std::hex >> green;
		istringstream(col.substr(2 * type, type)) >> std::hex >> blue;
		return ((red > blue) && (green < red));
	}
	else
		return false;
}

int main()
{
	string str;
	ifstream file;
	int count = 0;
	smatch mat_ch;
	regex str_sear("(.*)\\{\\s*(.*)\\s*(((cursor\\s*:\\s*)(.+?\\s*;\\s*))|((color)\\s*:\\s*(#([a-fA-F0-9]{6})|#([a-fA-F0-9]{3})|red)\\s*;?))?\\s*(.*)\\s*(((cursor\\s*:\\s*)(.+?\\s*;\\s*))|((color)\\s*:\\s*(#([a-fA-F0-9]{6})|#([a-fA-F0-9]{3})|red)\\s*;?))\\s*(.*)\\s*\\}");

	file.open("test.css");
	if (!file.is_open()) {
		cout << "File is not found.";
		return 1;
	}
	getline(file, str, '\0');
	while (regex_search(str, mat_ch, str_sear))
	{
		if((mat_ch[15] != "")||((mat_ch[15]=="")&&(mat_ch[21]!="")&&(col_fun(mat_ch[21]))))
		{
			count++;
			cout << "Match #" << count << ": " << mat_ch[1] << endl;
		}
		str = mat_ch.suffix().str();
	}
	system("PAUSE");
}
