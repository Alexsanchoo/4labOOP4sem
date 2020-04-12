#pragma once
#include<string>
#include<vector>

using namespace std;

template<class T>
class FileManager
{
public:
	static int readFile(string fileName, vector<T>& vec);
	static int writeFile(string fileName, vector<T>& vec);
};

template<class T>
inline int FileManager<T>::readFile(string fileName, vector<T>& vec)
{
	ifstream fin(fileName);
	if (!fin.is_open()) 
	{
		ofstream fout(fileName);
		if (!fout) { return 0; }
		fout.close();
		return 1;
	}

	if (!fin) { return 0; }
	while (true)
	{
		T obj;
		fin >> obj;
		if (fin.eof()) { break; }
		if (!fin) { return 0; }
		vec.push_back(obj);
	}
	fin.close();
	return 1;
}

template<class T>
inline int FileManager<T>::writeFile(string fileName, vector<T>& vec)
{
	ofstream fout(fileName, ios_base::trunc);
	if (!fout) { return 0; }
	for (size_t i = 0; i < vec.size(); i++)
	{
		fout << vec[i];
		if (!fout) { return 0; }
	}
	fout.close();
	return 1;
}
