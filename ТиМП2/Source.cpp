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
	ofstream fout("file2.txt");
	Queue<char> simbols(100);
	Queue<char> digits(100);
	Queue<char> signs(100);
	//if(((c >= -64) && (c <= -1)) || (c == -88) || (c == -72))
	//if(((c >= 65) && (c <= 90)) || ((c >= 95) && (c <= 122)))
	//if(((c >= 33) && (c <= 47)) || ((c >= 58) && (c <= 64)) || ((c >= 91) && (c <= 96)) || ((c >= 123) && (c <= 126)) || (c == -106))
	
	for (;;)
	{
		c = fin.get();
		if (fin.eof())
			break;
		if ((c >= 48) && (c <= 57))
			digits.set(c);
		if (((c >= -64) && (c <= -1)) || (c == -88) || (c == -72) || ((c >= 65) && (c <= 90)) || ((c >= 95) && (c <= 122)))
			simbols.set(c);
		if (((c >= 33) && (c <= 47)) || ((c >= 58) && (c <= 64)) || ((c >= 91) && (c <= 96)) || ((c >= 123) && (c <= 126)) || (c == -106))
			signs.set(c);
		if (c == '\n')
		{
			while (!simbols.isEmpty())
				fout << simbols.get();
			while (!digits.isEmpty())
				fout << digits.get();
			while (!signs.isEmpty())
				fout << signs.get();
			fout << "\n";
		}
	}
	fin.close();

	while (!simbols.isEmpty())
		fout << simbols.get();
	while (!digits.isEmpty())
		fout << digits.get();
	while (!signs.isEmpty())
		fout << signs.get();
	fout.close();

	return 0;
}
