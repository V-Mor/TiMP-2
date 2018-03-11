#include<iostream>
#include<fstream>
#include"Stack.h"
#include"Queue.h"
#include"Deq.h"
using namespace std;
int main()
{
	setlocale(0, "");
	char c;
	ifstream fin("file.txt");
	Queue<char> simbols(100);
	Queue<char> digits(100);
	Queue<char> signs(100);
	//if(((c >= -64) && (c <= -1)) || (c == -88) || (c == -72))
	//if(((c >= 65) && (c <= 90)) || ((c >= 95) && (c <= 122)))
	//if(((c >= 33) && (c <= 47)) || ((c >= 58) && (c <= 64)) || ((c >= 91) && (c <= 96)) || ((c >= 123) && (c <= 126)) || (c == -106))
	
	while (!fin.eof())
	{
		fin >> c;
		if ((c >= 48) && (c <= 57))
			digits.set(c);
		if (((c >= -64) && (c <= -1)) || (c == -88) || (c == -72) || ((c >= 65) && (c <= 90)) || ((c >= 95) && (c <= 122)))
			simbols.set(c);
		if (((c >= 33) && (c <= 47)) || ((c >= 58) && (c <= 64)) || ((c >= 91) && (c <= 96)) || ((c >= 123) && (c <= 126)) || (c == -106))
			signs.set(c);
	}
	fin.close();
	
	ofstream fout("file2.txt");
	while (!simbols.isEmpty())
		fout << simbols.get();
	while (!digits.isEmpty())
		fout << digits.get();
	while (!signs.isEmpty())
		fout << signs.get();
	fout.close();

	return 0;
}
