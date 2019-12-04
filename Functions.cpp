#include<iostream>
#include<vector>
#include<string>
#include"WeatherHeader.h"
using namespace std;


//För att byta värde på två minnesplatser
void swap(WeatherData* xp, WeatherData* yp)
{
	WeatherData temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void printVector(vector<WeatherData>& weather)
{
	int i;
	for (i = 0; i < weather.size(); i++)
		cout << &weather[i] << " ";
	cout << endl;
}

//Sökfunktion
int search(vector<WeatherData>& weather, string x) {

	for (auto i = 0; i < weather.size(); i++)
	{
		if (weather[i].date == x) {
			return i;

		}

	}
	return -1;
}


//Skriver ut lägst till högst datum.
void bubbleSortDateLowToHigh(vector <WeatherData>& weather)
{


	int i, j;
	for (i = 0; i < weather.size() - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < weather.size() - i - 1; j++)
			if (weather[j].date > weather[j + 1].date)
				swap(&weather[j], &weather[j + 1]);
}



//Skriver ut från högst datum till lägst
void bubbleSortDateHighToLow(vector <WeatherData>& weather)
{
	int i, j;
	for (i = 0; i < weather.size() + 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < weather.size() - i - 1; j++)
			if (weather[j].date < weather[j + 1].date)
				swap(&weather[j], &weather[j + 1]);
}



//Sorterar från varmaste till kallaste dagen INOMHUS
void bubbleSortIndoorAverageTempHotToCold(vector <WeatherData>& weather)
{

	int i, j;
	for (i = 0; i < weather.size() - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < weather.size() - i - 1; j++)
			if (weather[j].inDoorAverageTemp < weather[j + 1].inDoorAverageTemp)
				swap(&weather[j], &weather[j + 1]);

		cout << "The 5 warmest days, indoor: " << endl;
		cout << "------------------------------------------------------------------------------------" << endl;
		for (int k = 0; k <= 5; k++)
		{
			cout << weather[k].date << "  " << weather[k].inDoorAverageTemp << endl;
		}
}


//Sorterar från kallaste till varmaste dagen INOMHUS
void bubbleSortIndoorAverageTempColdToHot(vector <WeatherData>& weather)
{

	int i, j;
	for (i = 0; i < weather.size() - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < weather.size() - i - 1; j++)
			if (weather[j].inDoorAverageTemp > weather[j + 1].inDoorAverageTemp)
				swap(&weather[j], &weather[j + 1]);
	
		cout << "The 5 coldest days, indoor: " << endl;
		cout << "------------------------------------------------------------------------------------" << endl;
		for (int i = 0; i <= 5; i++)
		{
			cout << weather[i].date << "  " << weather[i].inDoorAverageTemp << endl;
		}



}

//Sorterar från varmaste till kallaste dagen UTOMHUS
void bubbleSortOutdoorAverageTempHotToCold(vector <WeatherData>& weather)
{

	int i, j;
	for (i = 0; i < weather.size() - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < weather.size() - i - 1; j++)
			if (weather[j].outDoorAverageTemp < weather[j + 1].outDoorAverageTemp)
				swap(&weather[j], &weather[j + 1]);

		cout << "The 5 warmest days, outdoor: " << endl;
		cout << "------------------------------------------------------------------------------------" << endl;
		for (int i = 0; i <= 5; i++)
		{
			cout << weather[i].date << "  " << weather[i].outDoorAverageTemp << endl;
		}


}




//Sorterar från kallaste till varmaste dagen UTOMHUS
void bubbleSortOutdoorAverageTempColdToHot(vector <WeatherData>& weather)
{

	int i, j;
	for (i = 0; i < weather.size() - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < weather.size() - i - 1; j++)
			if (weather[j].outDoorAverageTemp > weather[j + 1].outDoorAverageTemp)
				swap(&weather[j], &weather[j + 1]);

		cout << "The 5 coldest days, outdoor: " << endl;
		cout << "------------------------------------------------------------------------------------" << endl;
		for (int i = 0; i <= 5; i++)
		{
			cout << weather[i].date << " " << weather[i].outDoorAverageTemp << endl;
		}




}

//Sorterar från den torraste dagen till den fuktigaste dagen INOMHUS
void bubbleSortIndoorAverageHumDryToMoist(vector <WeatherData>& weather)
{

	int i, j;
	for (i = 0; i < weather.size() - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < weather.size() - i - 1; j++)
			if (weather[j].inDoorAverageHum > weather[j + 1].inDoorAverageHum)
				swap(&weather[j], &weather[j + 1]);


		cout << "The 5 driest days, indoor: " << endl;
		cout << "------------------------------------------------------------------------------------" << endl;
		for (int i = 0; i <= 5; i++)
		{
			cout << weather[i].date << "  " << weather[i].inDoorAverageHum << endl;
		}




}




//Sorterar från den fuktigaste dagen till den torraste dagen INOMHUS
void bubbleSortIndoorAverageHumMoistToDry(vector <WeatherData>& weather)
{

	int i, j;
	for (i = 0; i < weather.size() - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < weather.size() - i - 1; j++)
			if (weather[j].inDoorAverageHum < weather[j + 1].inDoorAverageHum)
				swap(&weather[j], &weather[j + 1]);

	cout << "The 5 days with the highest humidity, indoor: " << endl;
	cout << "------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i <= 5; i++)
	{
		cout << weather[i].date << "  " << weather[i].inDoorAverageHum << endl;
	}

}

//Sorterar från den torraste dagen till den fuktigaste dagen UTOMHUS
void bubbleSortOutdoorAverageHumDryToMoist(vector <WeatherData>& weather)
{

	int i, j;
	for (i = 0; i < weather.size() - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < weather.size() - i - 1; j++)
			if (weather[j].outDoorAverageHum > weather[j + 1].outDoorAverageHum)
				swap(&weather[j], &weather[j + 1]);


	cout << "The 5 driest days, outdoor: " << endl;
	cout << "------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i <= 5; i++)
	{
		cout << weather[i].date << "  " << weather[i].outDoorAverageHum << endl;
	}



}


//Sorterar från den fuktigaste dagen till den torraste dagen UTOMHUS
void bubbleSortOutdoorAverageHumMoistToDry(vector <WeatherData>& weather)
{

	int i, j;
	for (i = 0; i < weather.size() - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < weather.size() - i - 1; j++)
			if (weather[j].outDoorAverageHum < weather[j + 1].outDoorAverageHum)
				swap(&weather[j], &weather[j + 1]);

	cout << "The 5 days with the highest humidity, outdoor: " << endl;
	cout << "------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i <= 5; i++)
	{
		cout << weather[i].date << "  " << weather[i].outDoorAverageHum << endl;
	}



}


//Sorterar från minst mögelrisk till mest mögelrisk INOMHUS
void bubbleSortIndoorAverageMoltIndexLowToHigh(vector <WeatherData>& weather)
{

	int i, j;
	for (i = 0; i < weather.size() - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < weather.size() - i - 1; j++)
			if (weather[j].moltIndexIn > weather[j + 1].moltIndexIn)
				swap(&weather[j], &weather[j + 1]);


	cout << "Risk of molt: 1 = High, 2 = Mediate, 3 = Low  : " << endl;
	cout << "Days with high risk of molt, indoor: " << endl;
	cout << "------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i <= 5; i++)
	{
		cout << weather[i].date << "  " << weather[i].moltIndexIn << endl;
	}


}



//Sorterar från mest mögelrisk till minst mögelrisk INOMHUS
void bubbleSortIndoorAverageMoltIndexHighToLow(vector <WeatherData>& weather)
{

	int i, j;
	for (i = 0; i < weather.size() - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < weather.size() - i - 1; j++)
			if (weather[j].moltIndexIn < weather[j + 1].moltIndexIn)
				swap(&weather[j], &weather[j + 1]);


	cout << "Risk of molt: 1 = High, 2 = Mediate, 3 = Low  : " << endl;
	cout << "Days with lesser risk of molt, indoor: " << endl;
	cout << "------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i <= 5; i++)
	{
		cout << weather[i].date << "  " << weather[i].moltIndexIn << endl;
	}
}


//Sorterar från minst mögelrisk till mest mögelrisk UTOMHUS
void bubbleSortOutdoorAverageMoltIndexLowToHigh(vector <WeatherData>& weather)
{

	int i, j;
	for (i = 0; i < weather.size() - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < weather.size() - i - 1; j++)
			if (weather[j].moltIndexOut > weather[j + 1].moltIndexOut)
				swap(&weather[j], &weather[j + 1]);
			cout << "Risk of molt: 1 = High, 2 = Mediate, 3 = Low  : " << endl;
			cout << "Days with high risk of molt, outdoor: " << endl;
			cout << "------------------------------------------------------------------------------------" << endl;
			for (int i = 0; i <= 5; i++)
			{
			cout << weather[i].date << "  " << weather[i].moltIndexOut << endl;
			}



}


//Sorterar från mest mögelrisk till minst mögelrisk UTOMHUS
void bubbleSortOutdoorAverageMoltIndexHighToLow(vector <WeatherData>& weather)
{

	int i, j;
	for (i = 0; i < weather.size() - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < weather.size() - i - 1; j++)
			if (weather[j].moltIndexOut < weather[j + 1].moltIndexOut)
				swap(&weather[j], &weather[j + 1]);
			cout << "Risk of molt: 1 = High, 2 = Mediate, 3 = Low  : " << endl;
			cout << "Days with low risk of molt, outdoor: " << endl;
			cout << "------------------------------------------------------------------------------------" << endl;
			for (int i = 0; i <= 5; i++)
				{
					cout << weather[i].date << "  " << weather[i].moltIndexOut << endl;
				}

}
void printMenu() {
	cout << "Menu:" << endl;
	cout<<"------------------------------------------------------------------------------------"<< endl;
	cout << "Enter 1 to search for specifik date" << endl;
	cout << "Enter 2 for the 5 warmest days, indoor" << endl;
	cout << "Enter 3 for the 5 coldest days, indoor" << endl;
	cout << "Enter 4 to get the 5 warmest days, outdoor " << endl;
	cout << "Enter 5 for the 5 coldest days, outdoor" << endl;
	cout << "Enter 6 for the 5 driest days, indoor " << endl;
	cout << "Enter 7 for the 5 days with the highest humidity, indoor " << endl;
	cout << "Enter 8 for the 5 driest days, outdoor " << endl;
	cout << "Enter 9 for the 5 days with the highest humidity, outdoor" << endl;
	cout << "Enter 10 for the 5 days with lesser risk of molt, indoor " << endl;
	cout << "Enter 11 for the 5 days with high risk of molt, indoor" << endl;
	cout << "Enter 12 for the 5 days with low risk of molt, outdoor " << endl;
	cout << "Enter 13 for the 5 days with high risk of molt, outdoor " << endl;
	cout << "Enter 14 for Winter " << endl;
	cout << "Enter 15 for Autumn" << endl;
	cout << "Enter 16 to know when the balconydoor was open" << endl;
	cout << endl;
	cout << "------------------------------------------------------------------------------------" << endl;
}
