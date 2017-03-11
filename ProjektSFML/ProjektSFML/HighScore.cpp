#include "HighScore.h"



void HighScore::save(int kills, int time)
{
	int attempt;
	int numLines = 0;
	ifstream in("HighScore.txt");
	if (in)
	{
		std::string unused;
		while (std::getline(in, unused))
		{
			numLines++;
		}
		attempt = numLines;
	}
	else
	{
		attempt = 1;
	}
	ofstream out;
	out.open("HighScore.txt");
	out._Seekend;
	out << "Attempt number: " + to_string(attempt) + " Confirmed Kills: " + to_string(kills) + " Time Survived: " + to_string(time) << endl;
	attempt++;
}

string HighScore::load()
{
	string highScore;
	ifstream in;
	if (!in)
	{
		//no highScore
	}
	else
	{
		in.open("High Score.txt");
		int numLines = 0;
		std::string unused;
		while (std::getline(in, unused))
		{
			numLines++;
		}
		for (int i = 0; i < numLines; i++)
		{
			in >> highScore;//TODO rekrusiv kallese på highScore, eller en string här som sedan plusass på på highScore
		}
	}

	if (in)
	{

	}
	return highScore;
}

HighScore::HighScore(int kills, int time)
{
	save(kills, time);
}


HighScore::~HighScore()
{
}
