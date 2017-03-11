#ifndef HIGH_SCORE_H
#define HIGH_SCORE_H
#include"Game.h"
#include<fstream> 
//#include<iostream>
//#include<string>

class HighScore
{
private:
	void save(int kills, int time);
	string load();
public:
	HighScore(int kills, int time);
	~HighScore();
};


#endif // !HIGH_SCORE_H