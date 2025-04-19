#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "Book.h"
#include"Rental.h"
using namespace std;

template <typename T>
class CSVLoader
{
public:
	static void load(const string& fileName, vector<T*>& container)
	{
		ifstream inFile;
		inFile.open(fileName);
		if (!inFile.is_open())
		{
			cerr << "파일을 열 수 없습니다." << endl;
			return;
		}
		string line;
		bool isFirstLine = true;
		while (getline(inFile, line))
		{
			if (isFirstLine)
			{
				isFirstLine = false;
				continue;
			}
			if (line.empty() || line[0] == '#') continue;
			container.push_back(T::deserialize(line));
		}
		inFile.close();
	}
	static void save(const string& fileName, vector<T*>& container)
	{
		ofstream outFile(fileName);
		if (!outFile.is_open())
		{
			cerr << "파일을 열 수 없습니다." << endl;
			return;
		}
		for (int i = 0; i < container.size(); i++)
		{
			container[i]->serialize(outFile);
		}
	}

};

template<>
class CSVLoader<Book>
{
public:
	static void load(const string& filename, vector<Book*>& out)
	{
		ifstream file(filename);
		if (!file.is_open())
		{
			cerr << "파일을 열 수 없습니다." << endl;
			return;
		}
		string line;
		bool isFirstLine = true;
		while (getline(file, line))
		{
			if (isFirstLine)
			{
				isFirstLine = false;
				continue;
			}
			if (line.empty() || line[0] == '#') continue;
			Book* tmp;

			try
			{
				tmp = Book::deserialize(line);
			}
			catch (const exception& e)
			{
				cerr << e.what() << endl;
				continue;
			}

			out.push_back(tmp);

		}
		file.close();
	}
	static void save(const string& filename, const vector<Book*>& in)
	{
		ofstream file(filename);
		if (!file.is_open())
		{
			cerr << "파일을 열 수 없습니다." << endl;
			return;
		}
		for (int i = 0; i < in.size(); i++)
		{
			in[i]->serialize(file);
		}
		file.close();
	}
	
};

template<>
class CSVLoader<Rental>
{
public:
	static void load(const string& filename, vector<Rental*>& out)
	{
		ifstream file(filename);
		if (!file.is_open())
		{
			cerr << "파일을 열 수 없습니다." << endl;
			return;
		}
		string line;
		bool isFirstLine = true;
		while (getline(file, line))
		{
			if (isFirstLine)
			{
				isFirstLine = false;
				continue;
			}
			if (line.empty() || line[0] == '#') continue;
			Rental* tmp;

			try
			{
				tmp = Rental::deserialize(line);
			}
			catch (const exception& e)
			{
				cerr << e.what() << endl;
				continue;
			}

			out.push_back(tmp);

		}
		file.close();
	}
	static void save(const string& filename, const vector<Rental*>& in)
	{
		ofstream file(filename);
		if (!file.is_open())
		{
			cerr << "파일을 열 수 없습니다." << endl;
			return;
		}
		for (int i = 0; i < in.size(); i++)
		{
			in[i]->serialize(file);
		}
		file.close();
	}
};
