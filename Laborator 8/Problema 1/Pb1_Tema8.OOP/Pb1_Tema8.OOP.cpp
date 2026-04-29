#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <vector>

using namespace std;

struct CompareWords
{
    bool operator()(const pair<string, int>& a, const pair<string, int>& b)
    {
        if (a.second != b.second)
        {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

int main()
{
    ifstream file("input.txt");
    if (!file.is_open())
    {
        cout << "Fisierul input.txt nu a fost gasit!" << endl;
        return 1;
    }

    string phrase;
    getline(file, phrase);
    file.close();

    map<string, int> wordCount;
    string delimiters = " ,?!.";

    size_t start = phrase.find_first_not_of(delimiters);

    while (start != string::npos)
    {
        size_t end = phrase.find_first_of(delimiters, start);
        string word = phrase.substr(start, end - start);

        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] >= 'A' && word[i] <= 'Z')
            {
                word[i] += 32; 
            }
        }

        wordCount[word]++;
        start = phrase.find_first_not_of(delimiters, end);
    }

    priority_queue<pair<string, int>, vector<pair<string, int>>, CompareWords> pq;

    for (auto const& item : wordCount)
    {
        pq.push(item);
    }

    while (!pq.empty())
    {
        pair<string, int> top = pq.top();
        cout << top.first << " => " << top.second << endl;
        pq.pop();
    }

    return 0;
}