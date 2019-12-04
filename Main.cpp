#include<chrono>
#include"WeatherHeader.h"
#include<string>
#include<iostream>
#include<fstream>
#include<vector>

using namespace std;
typedef std::chrono::high_resolution_clock Clock;

int main() {

	auto t1 = Clock::now();

	string day, time, inOut, temperature, humidity, dates, searchDate;

	string currentDate = "";
	string	checkDate = "";
	int countIn = 0;
	int countOut = 0;
	int countTotal = 0;
	int timeIn = 0;
	int timeOut = 0;
	float tempInSum = 0;
	float tempOutSum = 0;
	float humInSum = 0;
	float humOutSum = 0;
	struct vector<WeatherData>weatherIn;
	struct vector<WeatherData>weatherOut;
	struct WeatherData in;
	struct WeatherData out;
	string input = "";
	float temporaryIn = 0;
	float humTemporaryIn = 0;
	float temporaryOut = 0;
	float humTemporaryOut = 0;
	float tempIn;
	float humIn;
	float tempOut;
	float humOut;

	string inFileName = "tempdata4long.txt";
	ifstream inFile;
	inFile.open(inFileName);


	if (inFile.is_open()) {

		while (inFile) {
			getline(inFile, day, ' ');
			dates = day.substr(0, 4) + day.substr(5, 2) + day.substr(8, 2);
			getline(inFile, time, ',');
			getline(inFile, inOut, ',');
			getline(inFile, temperature, ',');
			getline(inFile, humidity);
			inFile >> ws;

			//Här räknas allt ut som sedan skall in i vectorn
			if (dates == checkDate) {
				if (inOut == "Inne") {
					int timeC = 0;
					tempInSum += stof(temperature);
					humInSum += stof(humidity);
					tempIn = stof(temperature);
					humIn = stof(humidity);
					
					//Om temp är sjunkande och hum är stigande så är balkongen inne kanske öppen. detta kollas sen mot utomhusvärden om de är stigande
					if (tempIn < temporaryIn && humIn>humTemporaryIn) 
					{
							in.balconyIn = true;
					}
					else
					{
						in.balconyIn = false;
					}
					temporaryIn = tempIn;
					humTemporaryIn = humIn;
					currentDate = dates;
					countIn++;
				}
				else 
				{
					tempOutSum += stof(temperature);
					humOutSum += stof(humidity);
					tempOut = stof(temperature);
					humOut = stof(humidity);

					if (tempOut > temporaryOut && humOut<humTemporaryOut)
					{
						out.balconyOut = true;
					}
					else
					{
						out.balconyOut = false;
					}
					temporaryOut = tempOut;
					humTemporaryOut = humOut;
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
					
					if ((in.inDoorAverageTemp >= 15 && in.inDoorAverageTemp < 50) && in.inDoorAverageHum > 78.15)
					{
						in.moltIndexIn = 1;
					}
					else if ((in.inDoorAverageTemp >= 0 && in.inDoorAverageTemp < 15) && in.inDoorAverageHum > 78.15)
					{
						in.moltIndexIn = 2;
					}
					else in.moltIndexIn = 3;

					weatherIn.push_back(in);
					out.date = currentDate;
					out.outDoorAverageTemp = (tempOutSum / countOut);
					out.outDoorAverageHum = (humOutSum / countOut);
					
					if (in.balconyIn == true && out.balconyOut == true) 
					{
						in.balconyDoor = "open";
						out.balconyDoor = "open";
					}
					else 
					{ 
						in.balconyDoor = "closed"; 
						out.balconyDoor = "closed";
					}
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

		do {
			

			printMenu();
			getline(cin, input);
			cout << endl;
			int inputCase = stoi(input);
			system("cls");
			switch (inputCase)
			{

			case 1:
			{
				//SÖKER EFTER DATUM
				cout << "Enter SearchDate with format 'yyyymmdd': " << endl;
				getline(cin, searchDate);
				cout<<"\n";
				int c = search(weatherIn, searchDate);
				int k = search(weatherOut, searchDate);

				cout << "Date,\t\tTemperature,\tHumidity\tRisk of molt indoor: " << endl;
				cout << weatherIn[c].date << "\t" << weatherIn[c].inDoorAverageTemp << "\t\t" << weatherIn[c].inDoorAverageHum << "\t\t" << weatherIn[c].moltIndexIn <<endl;

				cout << "Date, \t\tTemperature,\tHumidity\tRisk of molt outdoor: " << endl;
				cout << weatherOut[k].date << "\t" << weatherOut[k].outDoorAverageTemp << "\t\t" << weatherOut[k].outDoorAverageHum << "\t\t" << weatherOut[k].moltIndexOut <<endl;
				break;
			}
			case 2:
			{
				//Sortera från varmast till kallast och skriv ut de 5 varmaste dagarna INOMHUS
				bubbleSortIndoorAverageTempHotToCold(weatherIn);
				break;
			}
			case 3:
			{
				//sortera från kallast till varmast och skriv ut de 5 kallaste dagarna INOMHUS   funktion
				bubbleSortIndoorAverageTempColdToHot(weatherIn);
				break;
			}
			case 4:
			{
				//Sortera från varmast till kallast och skriv ut de 5 varmaste dagarna UTOMHUS funktion
				bubbleSortOutdoorAverageTempHotToCold(weatherOut);
				break;
			}
			case 5:
			{
				//sortera från kallast till varmast och skriv ut de 5 kallaste dagarna UTOMHUS funktion
				bubbleSortOutdoorAverageTempColdToHot(weatherOut);
				break;
			}
			case 6:
			{
				//Sorterar från den torraste dagen till den fuktigaste dagen INOMHUS funktion
				bubbleSortIndoorAverageHumDryToMoist(weatherIn);
				break;
			}
			case 7:
			{
				//Sorterar från den fuktigaste dagen till den torraste dagen INOMHUS funktion
				bubbleSortIndoorAverageHumMoistToDry(weatherIn);
				break;
			}
			case 8:
			{
				//Sorterar från den torraste dagen till den fuktigaste dagen UTOMHUS funktion
				bubbleSortOutdoorAverageHumDryToMoist(weatherOut);	
				break;
			}
			case 9:
			{
				//Sorterar från den fuktigaste dagen till den torraste dagen UTOMHUS funktion
				bubbleSortOutdoorAverageHumMoistToDry(weatherOut);
				break;
			}
			case 10:
			{
				//Sorterar från minst mögelrisk till mest mögelrisk INOMHUS
				bubbleSortIndoorAverageMoltIndexHighToLow(weatherIn);
				break;
			}
			case 11:
			{
				//Sorterar från mest mögelrisk till minst mögelrisk INOMHUS
				bubbleSortIndoorAverageMoltIndexLowToHigh(weatherIn);	
				break;
			}
			case 12:
			{
				//Sorterar från minst mögelrisk till mest mögelrisk UTOMHUS
				bubbleSortOutdoorAverageMoltIndexHighToLow(weatherOut);	
				break;
			}
			case 13:
			{
				//Sorterar från mest mögelrisk till minst mögelrisk UTOMHUS
				bubbleSortOutdoorAverageMoltIndexLowToHigh(weatherOut);
				break;
			}
			case 14:
			{
				//DATUM FÖR METEOROLOGISK VINTER 
				int winterCount = 0;
				bubbleSortDateLowToHigh(weatherOut);
				for (int i = 0; i < weatherOut.size(); i++)
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
				int fallCount1 = 0;
				for (int i = 0; i < weatherOut.size(); i++)
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
				

				//DATUM FÖR METEOROLOGISK HÖST UTAN SJUNKANDE VÄRDEN 
				int fallCount = 0;
				for (int i = 0; i < weatherOut.size(); i++)
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
				break;
			}

			//Beräkna om balkongdörren var öppen.
			case 16:
			{
				cout << "Dates with open doors: "<< endl;
				for (int i = 0; i < weatherOut.size(); i++)
				{
					if (weatherOut[i].balconyDoor == 'open') {
						cout << weatherOut[i].date <<" "<<weatherOut[i].balconyDoor<< endl;
					}
				}
			
			}


			default:
				break;
			}

			cout << endl;
			
			
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
