#pragma once
#include<string>
#include<vector>

using namespace std;

template<class T>
class FileManager
{
public:
	static void readFile(string fileName);
	static void writeFile(string fileName);
};

template<class T>
inline void FileManager<T>::readFile(string fileName)
{

}

template<class T>
inline void FileManager<T>::writeFile(string fileName)
{

}
