
/* Name: Andrew Stade
Date: 12/4/2020
Section: COP 4530 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>

using namespace std;

void outputChr(std::map<string, pair<int, int>> &map, int Counter);		// display top 10 characters
void outputWord(std::map<string, pair<int, int>> &map, int Counter);	// display top 10 words
void outputNum(std::map<string, pair<int, int>> &map, int Counter);		// display top 10 numbers

void outputChr(map<string, pair<int, int>> &map, int Counter)
{
	int track = 0;
	
	std::map<string, pair<int, int>>::iterator temp = map.begin();
	
	if(Counter > 10)
	{
		Counter = 10;
	}
	
	if(Counter > map.size())
	{
		Counter = map.size();
	}
	
	cout << "Total " << map.size() << " different characters, " << Counter << " most used characters:" << endl;
	
	for(int i = 0; i < Counter; i++)
	{
		int data = 0;	// data must be 0 for loop to run
		
		for(std::map<string, pair<int, int> >::iterator it = map.begin(); it != map.end(); ++it)
		{
			if(it->second.first > data || (it->second.first == data && (it->second.second < temp->second.second)))
			{
				data = it->second.first;
				temp = it;
				track++;
			}
		}
		cout << "No. " << i << ": ";
		if(temp->first == "\t")
		{
			cout << "\\t" << "		" << data << endl;
		}
		else if(temp->first == "\n")
		{
			cout << "\\n" << "		" << data << endl;
		}
		else
		{
			cout << temp->first << "		" << data << endl;
		}
		map.erase(temp); // clear counters
	}
	
}

void outputWord(map<string, pair<int, int>> &map, int Counter)
{
	int track = 0;
	
	std::map<string, pair<int, int>>::iterator temp = map.begin();
	
	if(Counter > 10)
	{
		Counter = 10;
	}
	
	if(Counter > map.size())
	{
		Counter = map.size();
	}
	
	cout << endl << "Total " << map.size() << " different words, " << Counter << " most used words:" << endl;
	
	for(int i = 0; i < Counter; i++)
	{
		int data = 0;	// data must be 0 for loop to run
		
		for(std::map<string, pair<int, int>>::iterator it = map.begin(); it != map.end(); ++it)
		{
			if(it->second.first > data || (it-> second.first == data && (it->second.second < temp->second.second)))
			{
				data = it->second.first;
				temp = it;
				track++;
			}
		}
		cout << "No. " << i << ": " << temp->first << "		" << data << endl;
		map.erase(temp); // clear counters
	}
}
	
void outputNum(map<string, pair<int, int>> &map, int Counter)
{
	int track = 0;
	
	std::map<string, pair<int, int>>::iterator temp = map.begin();
	
	if(Counter > 10)
	{
		Counter = 10;
	}
	
	if(Counter > map.size())
	{
		Counter = map.size();
	}
	
	cout << endl << "Total " << map.size() << " different numbers, " << Counter << " most used numbers:" << endl;
	for(int i = 0; i < Counter; i++)
	{
		int data = 0;	// data must be 0 for loop to run
		
		for(std::map<string, pair<int, int>>::iterator it = map.begin(); it != map.end(); ++it)
		{
			if(it->second.first > data || (it->second.first == data && (it->second.second < temp->second.second)))
			{
				data = it->second.first;
				temp = it;
				track++;
			}
		}
		cout << "No. " << i << ": " << temp->first << "		" << data << endl;
		map.erase(temp); // clear counters
	}
}

int main()
{	
	// using map library to count and track characters, word, and numbers used
	int count = 0;		// Count number of chars
	int wordCount = 0;	// Count number of words
	int numCount = 0;	// Count number of ints
	char chr;			// Reads char input
	string character;	// Stores each char
	string word;		// Stores each word
	string number;		// Stores each num
	
	std::map<string, pair<int, int>> cMap; // map of chars
	std::map<string, pair<int, int>> wMap; // map of words
	std::map<string, pair<int, int>> nMap; // map of nums
	
	while(!cin.eof())	// Reads entire file
	{
		count++;
		cin.get(chr);		// Store each char input
		character += chr;	// acts as a counter to each char in the loop
		
		if(cin.fail() == true)	// Fixes an issue with double chars
		{
			if(word.size() >= 1)
			{
				if(wMap.find(word) == wMap.end())
				{
					wMap.insert(make_pair(word, make_pair(1, count)));
					wordCount++;
				}
				else
				{
					++wMap[word].first;
				}
				word = ""; // clear counters
			}
			else if(number.size() >= 1)
			{
				if(nMap.find(number) == nMap.end())
				{
					nMap.insert(make_pair(number, make_pair(1, count)));
					numCount++;
				}
				else
				{
					++nMap[number].first;
				}
				number = ""; // clear counters
			}
			break;	// seg fault
		}
		else if(isdigit(chr) != 0) // check for num
		{
			number += chr;
			
			if(word.size() >= 1)
			{
				if(wMap.find(word) == wMap.end())
				{
					wMap.insert(make_pair(word, make_pair(1, count)));
					wordCount++;
				}
				else
				{
					++wMap[word].first;
				}
				word = ""; // clear counters
			}
		}
		else if(isalpha(chr) != 0) // check for char
		{
			word += tolower(chr);
			
			if(number.size() >= 1)
			{
				if(nMap.find(number) == nMap.end())
				{
					nMap.insert(make_pair(number, make_pair(1, count)));
					numCount++;
				}
				else
				{
					++nMap[number].first;
				}
				number = ""; // clear counters
			}
		}
		else	// check for other symbol
		{
			if(word.size() >= 1)
			{
				if(wMap.find(word) == wMap.end())
				{
					wMap.insert(make_pair(word, make_pair(1, count)));
					wordCount++;
				}
				else
				{
					++wMap[word].first;
				}
				word = ""; // clear counters
			}
			else if(number.size() >= 1)
			{
				if(nMap.find(number) == nMap.end())
				{
					nMap.insert(make_pair(number, make_pair(1, count)));
					numCount++;
				}
				else
				{
					++nMap[number].first;
				}
				number = ""; // clear counters
			}
		}
		++cMap[character].first;
		character = ""; // clear counters
	}
	
	outputChr(cMap, count);			// display data
	outputWord(wMap, wordCount);	// display data
	outputNum(nMap, numCount);		// display data
	
	return 0;
}