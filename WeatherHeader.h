#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"WeatherHeader.h"
using namespace std;

struct WeatherData {
	string date = "";
	float inDoorAverageTemp;
	float outDoorAverageTemp;

	int moltIndexIn;
	int moltIndexOut;
	int timeIn;
	int timeOut;
	bool balconyIn;
	bool balconyOut;
	bool balconyDoor;

	float inDoorAverageHum;
	float outDoorAverageHum;

	float minIndoorAverageTemp;
	float minOutdoorAverageTemp;
	float maxIndoorAverageTemp;
	float maxOutdoorAverageTemp;

	float minIndoorAverageHum;
	float minOutdoorAverageHum;
	float maxIndoorAverageHum;
	float maxOutdoorAverageHum;
};
void swap(WeatherData* xp, WeatherData* yp);
void printVector(vector<WeatherData>& weather);
int search(vector<WeatherData>& weather, string x);
void bubbleSortDateLowToHigh(vector <WeatherData>& weather);
void bubbleSortDateHighToLow(vector <WeatherData>& weather);
void bubbleSortIndoorAverageTempHotToCold(vector <WeatherData>& weather);
void bubbleSortIndoorAverageTempColdToHot(vector <WeatherData>& weather);
void bubbleSortOutdoorAverageTempHotToCold(vector <WeatherData>& weather);
void bubbleSortOutdoorAverageTempColdToHot(vector <WeatherData>& weather);
void bubbleSortIndoorAverageHumDryToMoist(vector <WeatherData>& weather);
void bubbleSortIndoorAverageHumMoistToDry(vector <WeatherData>& weather);
void bubbleSortOutdoorAverageHumDryToMoist(vector <WeatherData>& weather);
void bubbleSortOutdoorAverageHumMoistToDry(vector <WeatherData>& weather);
void bubbleSortIndoorAverageMoltIndexLowToHigh(vector <WeatherData>& weather);
void bubbleSortIndoorAverageMoltIndexHighToLow(vector <WeatherData>& weather);
void bubbleSortOutdoorAverageMoltIndexLowToHigh(vector <WeatherData>& weather);
void bubbleSortOutdoorAverageMoltIndexHighToLow(vector <WeatherData>& weather);
void printMenu();