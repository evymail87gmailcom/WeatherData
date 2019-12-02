#include<chrono>
#include<string>
#include<iostream>
#include<fstream>
#include<vector>



using namespace std;

typedef std::chrono::high_resolution_clock Clock;

struct WeatherData {
	string date = "";
	float inDoorAverageTemp;
	float outDoorAverageTemp;

	int moltIndexIn;
	int moltIndexOut;

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

//För att byta värde på två minnesplatser
void swap(WeatherData* xp, WeatherData* yp)
{
	WeatherData temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void printVector(vector<WeatherData>& weather, int size)
{
	int i;
	for (i = 0; i < size; i++)
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
void bubbleSortDateLowToHigh(vector <WeatherData>& weather, int n)
{


	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < n - i - 1; j++)
			if (weather[j].date > weather[j + 1].date)
				swap(&weather[j], &weather[j + 1]);
}


//Skriver ut från högst datum till lägst
void bubbleSortDateHighToLow(vector <WeatherData>& weather, int n)
{
	int i, j;
	for (i = 0; i < n + 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < n - i - 1; j++)
			if (weather[j].date < weather[j + 1].date)
				swap(&weather[j], &weather[j + 1]);
}

//Sorterar från varmaste till kallaste dagen INOMHUS
void bubbleSortIndoorAverageTempHotToCold(vector <WeatherData>& weather, int n)
{

	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < n - i - 1; j++)
			if (weather[j].inDoorAverageTemp < weather[j + 1].inDoorAverageTemp)
				swap(&weather[j], &weather[j + 1]);
}

//Sorterar från kallaste till varmaste dagen INOMHUS
void bubbleSortIndoorAverageTempColdToHot(vector <WeatherData>& weather, int n)
{

	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < n - i - 1; j++)
			if (weather[j].inDoorAverageTemp > weather[j + 1].inDoorAverageTemp)
				swap(&weather[j], &weather[j + 1]);
}

//Sorterar från varmaste till kallaste dagen UTOMHUS
void bubbleSortOutdoorAverageTempHotToCold(vector <WeatherData>& weather, int n)
{

	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < n - i - 1; j++)
			if (weather[j].outDoorAverageTemp < weather[j + 1].outDoorAverageTemp)
				swap(&weather[j], &weather[j + 1]);
}

//Sorterar från kallaste till varmaste dagen UTOMHUS
void bubbleSortOutdoorAverageTempColdToHot(vector <WeatherData>& weather, int n)
{

	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < n - i - 1; j++)
			if (weather[j].outDoorAverageTemp > weather[j + 1].outDoorAverageTemp)
				swap(&weather[j], &weather[j + 1]);
}

//Sorterar från den torraste dagen till den fuktigaste dagen INOMHUS
void bubbleSortIndoorAverageHumDryToMoist(vector <WeatherData>& weather, int n)
{

	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < n - i - 1; j++)
			if (weather[j].inDoorAverageHum > weather[j + 1].inDoorAverageHum)
				swap(&weather[j], &weather[j + 1]);
}



//Sorterar från den fuktigaste dagen till den torraste dagen INOMHUS
void bubbleSortIndoorAverageHumMoistToDry(vector <WeatherData>& weather, int n)
{

	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < n - i - 1; j++)
			if (weather[j].inDoorAverageHum < weather[j + 1].inDoorAverageHum)
				swap(&weather[j], &weather[j + 1]);
}

//Sorterar från den torraste dagen till den fuktigaste dagen UTOMHUS
void bubbleSortOutdoorAverageHumDryToMoist(vector <WeatherData>& weather, int n)
{

	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < n - i - 1; j++)
			if (weather[j].outDoorAverageHum > weather[j + 1].outDoorAverageHum)
				swap(&weather[j], &weather[j + 1]);
}


//Sorterar från den fuktigaste dagen till den torraste dagen UTOMHUS
void bubbleSortOutdoorAverageHumMoistToDry(vector <WeatherData>& weather, int n)
{

	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < n - i - 1; j++)
			if (weather[j].outDoorAverageHum < weather[j + 1].outDoorAverageHum)
				swap(&weather[j], &weather[j + 1]);
}

//Sorterar från minst mögelrisk till mest mögelrisk INOMHUS
void bubbleSortIndoorAverageMoltIndexLowToHigh(vector <WeatherData>& weather, int n)
{

	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < n - i - 1; j++)
			if (weather[j].moltIndexIn > weather[j + 1].moltIndexIn)
				swap(&weather[j], &weather[j + 1]);
}



//Sorterar från mest mögelrisk till minst mögelrisk INOMHUS
void bubbleSortIndoorAverageMoltIndexHighToLow(vector <WeatherData>& weather, int n)
{

	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < n - i - 1; j++)
			if (weather[j].moltIndexIn < weather[j + 1].moltIndexIn)
				swap(&weather[j], &weather[j + 1]);
}
//Sorterar från minst mögelrisk till mest mögelrisk UTOMHUS
void bubbleSortOutdoorAverageMoltIndexLowToHigh(vector <WeatherData>& weather, int n)
{

	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < n - i - 1; j++)
			if (weather[j].moltIndexOut > weather[j + 1].moltIndexOut)
				swap(&weather[j], &weather[j + 1]);
}



//Sorterar från mest mögelrisk till minst mögelrisk UTOMHUS
void bubbleSortOutdoorAverageMoltIndexHighToLow(vector <WeatherData>& weather, int n)
{

	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < n - i - 1; j++)
			if (weather[j].moltIndexOut < weather[j + 1].moltIndexOut)
				swap(&weather[j], &weather[j + 1]);
}




int main() {

	auto t1 = Clock::now();

	string day, time, inOut, temperature, humidity, dates, searchDate;

	string currentDate = "";
	string	checkDate = "";

	int sizeIn;
	int sizeOut;
	int countIn = 0;
	int countOut = 0;
	int countTotal = 0;
	float tempInSum = 0;
	float tempOutSum = 0;
	float humInSum = 0;
	float humOutSum = 0;
	struct vector<WeatherData>weatherIn;
	struct vector<WeatherData>weatherOut;
	struct WeatherData in;
	struct WeatherData out;
	string input = "";





	string inFileName = "tempdata4long.txt";

	ifstream inFile;

	inFile.open(inFileName);


	if (inFile.is_open()) {


		//whileloopen ser till att filen fortsätter rad för rad.
		while (inFile) {
			getline(inFile, day, ' ');
			dates = day.substr(0, 4) + day.substr(5, 2) + day.substr(8, 2);
			getline(inFile, time, ',');
			getline(inFile, inOut, ',');
			getline(inFile, temperature, ',');
			getline(inFile, humidity);
			inFile >> ws;

			//Här räknas allt ut som sedan skall in i vectorn
			////////////////////////////////////////////////////////////////////////////////
			if (dates == checkDate) {
				if (inOut == "Inne") {
					tempInSum += stof(temperature);
					humInSum += stof(humidity);
					currentDate = dates;
					countIn++;
				}
				else {
					tempOutSum += stof(temperature);
					humOutSum += stof(humidity);
					currentDate = dates;
					countOut++;

				}
				countTotal++;
			}
			else {
				checkDate = dates;
				if (countTotal != 0) {

					in.date = currentDate;
					in.inDoorAverageTemp = (tempInSum / countIn);
					in.inDoorAverageHum = (humInSum / countIn);

					if ((in.inDoorAverageTemp >= 15 && in.inDoorAverageTemp < 50) && in.inDoorAverageHum > 78.15) {
						in.moltIndexIn = 1;
					}
					else if ((in.inDoorAverageTemp >= 0 && in.inDoorAverageTemp < 15) && in.inDoorAverageHum > 78.15) {
						in.moltIndexIn = 2;
					}
					else in.moltIndexIn = 3;

					weatherIn.push_back(in);

					out.date = currentDate;
					out.outDoorAverageTemp = (tempOutSum / countOut);
					out.outDoorAverageHum = (humOutSum / countOut);
					if ((out.outDoorAverageTemp >= 15 && out.outDoorAverageTemp < 50) && out.outDoorAverageHum > 78.15) {
						out.moltIndexOut = 1;
					}
					else if ((out.outDoorAverageTemp >= 0 && out.outDoorAverageTemp < 15) && out.outDoorAverageHum > 78.15) {
						out.moltIndexOut = 2;
					}
					else out.moltIndexOut = 3;

					weatherOut.push_back(out);

					tempInSum = 0;
					tempOutSum = 0;
					humInSum = 0;
					humOutSum = 0;

					countIn = 0;
					countOut = 0;
					countTotal = 0;



				}
			}

			if (!inFile)
			{
				break;
			}

		}





		sizeIn = weatherIn.size();
		sizeOut = weatherOut.size();



		do {

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
			cout << "Enter 15 for Fall" << endl;
			cout << endl;

			getline(cin, input);
			cout << endl;
			int inputCase = stoi(input);

			switch (inputCase)
			{

			case 1:
			{
				//SÖKER EFTER DATUM
				////////////////////////////////////////////////////////////////////////////////
				cout << "Enter SearchDate with format 'yyyymmdd': " << endl;
				getline(cin, searchDate);
				int c = search(weatherIn, searchDate);
				int k = search(weatherOut, searchDate);

				cout << "Temperature, AirHumidity and risk of molt indoor: " << endl;
				cout << weatherIn[c].date << "   " << weatherIn[c].inDoorAverageTemp << " " << weatherIn[c].inDoorAverageHum << " " << weatherIn[c].moltIndexIn << endl;

				cout << "Temperature, AirHumidity and risk of molt outdoor: " << endl;
				cout << weatherOut[k].date << "  " << weatherOut[k].outDoorAverageTemp << " " << weatherOut[k].outDoorAverageHum << " " << weatherOut[k].moltIndexOut << endl;
				break;
			}

			case 2:
			{

				//SORTERAR TEMPERATURER/DAG
				////////////////////////////////////////////////////////////////////////////////
				//Sortera från varmast till kallast och skriv ut de 5 varmaste dagarna INOMHUS
				bubbleSortIndoorAverageTempHotToCold(weatherIn, sizeIn);
				cout << "The 5 warmest days, indoor: " << endl;
				for (int i = 0; i <= 5; i++)
				{
					cout << weatherIn[i].date << "  " << weatherIn[i].inDoorAverageTemp << endl;
				}
				break;
			}

			case 3:
			{
				//sortera från kallast till varmast och skriv ut de 5 kallaste dagarna INOMHUS
				bubbleSortIndoorAverageTempColdToHot(weatherIn, sizeIn);
				cout << "The 5 coldest days, indoor: " << endl;
				for (int i = 0; i <= 5; i++)
				{
					cout << weatherIn[i].date << "  " << weatherIn[i].inDoorAverageTemp << endl;
				}
				break;
			}

			case 4:
			{
				//Sortera från varmast till kallast och skriv ut de 5 varmaste dagarna UTOMHUS
				bubbleSortOutdoorAverageTempHotToCold(weatherOut, sizeOut);
				cout << "The 5 warmest days, outdoor: " << endl;
				for (int i = 0; i <= 5; i++)
				{
					cout << weatherOut[i].date << "  " << weatherOut[i].outDoorAverageTemp << endl;
				}
				break;
			}

			case 5:
			{
				//sortera från kallast till varmast och skriv ut de 5 kallaste dagarna UTOMHUS
				bubbleSortOutdoorAverageTempColdToHot(weatherOut, sizeOut);
				cout << "The 5 coldest days, outdoor: " << endl;
				for (int i = 0; i <= 5; i++)
				{
					cout << weatherOut[i].date << " " << weatherOut[i].outDoorAverageTemp << endl;
				}
				break;
			}

			case 6:
			{
				//SORTERAR FUKT/DAG
				////////////////////////////////////////////////////////////////////////////////

				//Sorterar från den torraste dagen till den fuktigaste dagen INOMHUS
				bubbleSortIndoorAverageHumDryToMoist(weatherIn, sizeIn);
				cout << "The 5 driest days, indoor: " << endl;
				for (int i = 0; i <= 5; i++)
				{
					cout << weatherIn[i].date << "  " << weatherIn[i].inDoorAverageHum << endl;
				}
				break;
			}

			case 7:
			{
				//Sorterar från den fuktigaste dagen till den torraste dagen INOMHUS
				bubbleSortIndoorAverageHumMoistToDry(weatherIn, sizeIn);
				cout << "The 5 days with the highest humidity, indoor: " << endl;
				for (int i = 0; i <= 5; i++)
				{
					cout << weatherIn[i].date << "  " << weatherIn[i].inDoorAverageHum << endl;
				}
				break;
			}

			case 8:
			{

				//Sorterar från den torraste dagen till den fuktigaste dagen UTOMHUS
				bubbleSortOutdoorAverageHumDryToMoist(weatherOut, sizeOut);
				cout << "The 5 driest days, outdoor: " << endl;
				for (int i = 0; i <= 5; i++)
				{
					cout << weatherOut[i].date << "  " << weatherOut[i].outDoorAverageHum << endl;
				}
				break;
			}

			case 9:
			{
				//Sorterar från den fuktigaste dagen till den torraste dagen UTOMHUS
				bubbleSortOutdoorAverageHumMoistToDry(weatherOut, sizeOut);
				cout << "The 5 days with the highest humidity, outdoor: " << endl;
				for (int i = 0; i <= 5; i++)
				{
					cout << weatherOut[i].date << "  " << weatherOut[i].outDoorAverageHum << endl;
				}
				break;
			}

			case 10:
			{
				//SKRIV UT MÖGELINDEX 
				////////////////////////////////////////////////////////////////////////////////
				cout << "Risk of molt: 1 = High, 2 = Mediate, 3 = Low  : " << endl;

				//Sorterar från minst mögelrisk till mest mögelrisk INOMHUS
				bubbleSortIndoorAverageMoltIndexHighToLow(weatherIn, sizeIn);
				cout << "Days with lesser risk of molt, indoor: " << endl;
				for (int i = 0; i <= 5; i++)
				{
					cout << weatherIn[i].date << "  " << weatherIn[i].moltIndexIn << endl;
				}

			}break;

			case 11:
			{
				cout << "Risk of molt: 1 = High, 2 = Mediate, 3 = Low  : " << endl;
				//Sorterar från mest mögelrisk till minst mögelrisk INOMHUS
				bubbleSortIndoorAverageMoltIndexLowToHigh(weatherIn, sizeIn);
				cout << "Days with high risk of molt, indoor: " << endl;
				for (int i = 0; i <= 5; i++)
				{
					cout << weatherIn[i].date << "  " << weatherIn[i].moltIndexIn << endl;
				}
				break;
			}

			case 12:
			{
				cout << "Risk of molt: 1 = High, 2 = Mediate, 3 = Low  : " << endl;
				//Sorterar från minst mögelrisk till mest mögelrisk UTOMHUS
				bubbleSortOutdoorAverageMoltIndexHighToLow(weatherOut, sizeOut);
				cout << "Days with low risk of molt, outdoor: " << endl;
				for (int i = 0; i <= 5; i++)
				{
					cout << weatherOut[i].date << "  " << weatherOut[i].moltIndexOut << endl;
				}
				break;
			}

			case 13:
			{
				cout << "Risk of molt: 1 = High, 2 = Mediate, 3 = Low  : " << endl;
				//Sorterar från mest mögelrisk till minst mögelrisk UTOMHUS
				cout << "Days with high risk of molt, outdoor: " << endl;
				bubbleSortOutdoorAverageMoltIndexLowToHigh(weatherOut, sizeOut);
				for (int i = 0; i <= 5; i++)
				{
					cout << weatherOut[i].date << "  " << weatherOut[i].moltIndexOut << endl;
				}
				break;
			}

			case 14:
			{
				//DATUM FÖR METEOROLOGISK VINTER 
				////////////////////////////////////////////////////////////////////////////////
				int winterCount = 0;
				bubbleSortDateLowToHigh(weatherOut, sizeOut);
				for (int i = 0; i < sizeOut; i++)
				{
					if (out.outDoorAverageTemp <= 0.0) {
						winterCount++;
						if (winterCount == 5)
						{
							cout << "Winter arrived at: " << weatherOut[i - 5].date << endl;
							break;
						}
					}
					else winterCount = 0;
				}
				if (winterCount == 0)cout << "No winter occurred" << endl;
				break;
			}

			case 15:
			{
				//DATUM FÖR METEOROLOGISK HÖST MED SJUNKANDE VÄRDEN 
				////////////////////////////////////////////////////////////////////////////////
				int fallCount1 = 0;
				for (int i = 0; i < sizeOut; i++)
				{
					if (weatherOut[i].outDoorAverageTemp > 0.0 && weatherOut[i].outDoorAverageTemp < 10)
					{
						if (weatherOut[i].outDoorAverageTemp <= weatherOut[i - 1].outDoorAverageTemp)
						{
							fallCount1++;
							if (fallCount1 == 4)
							{
								cout << "Autumn arrived at: " << weatherOut[i - 4].date << endl;
								break;
							}
						}
						else fallCount1 = 0;
					}
				}
				if (fallCount1 == 0)cout << "Autumn arrived at August 1" << endl;


				//DATUM FÖR METEOROLOGISK HÖST UTAN SJUNKANDE VÄRDEN Kontrollera
				////////////////////////////////////////////////////////////////////////////////
				int fallCount = 0;
				for (int i = 0; i < sizeOut; i++)
				{
					if (weatherOut[i].outDoorAverageTemp > 0 && weatherOut[i].outDoorAverageTemp < 10)
					{
						fallCount++;
						if (fallCount == 5)
						{
							cout << "Alternative date for autumn: " << weatherOut[i].date << endl;
							break;
						}
					}
					else fallCount = 0;
				}
				if (fallCount == 0)cout << "Autumn arrived at August 1" << endl;
			}


			default:
				break;
			}

			cout << endl;
			cin.clear();

		} while (true);


		inFile.close();
	}
	else {
		cout << "Cannot open file; " << inFileName << endl;

	}

	auto t2 = Clock::now();
	cout << "Programmet tog " << chrono::duration_cast <chrono::seconds> (t2 - t1).count() << " sekunder att köra";

	string y;
	getline(cin, y);
	return 0;

}
