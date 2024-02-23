/*	CODE NUMBER 3
        Name		:	Deepthi Valachery
	Student ID	:	[redact]
	Course		:	[redact]
	Programme	:	3
*/

#include <iostream>
#include <fstream>

using namespace std;																									// peepeepoopoo <3

void printStars (int n) {
	int count;
	
	for (count=1; count<=n; count=count+1)
		cout << "*";
}

bool isNormal (int level) {																								// isNormal function
	if ((level >= 80) && (level <= 130)){
		return true;
	}
	else{
		return false;
	}
}

int difference (int day1, int day2){																					// Difference function
	int sub;
	if (day1 > day2)  {
		sub = day1 - day2;
	}
	else{
		sub = day2 - day1;
	}
}

int main () {
	cout << "CourseCode - Assignment 3 : Analysis of Blood Sugar Levels"<< endl;
	cout << "========================================================" << endl << endl;
	
	
	ifstream inputFile;																									// Variable declarations
	ofstream outputFile;
	
	int level, i, num, sum = 0, max = INT_MIN, maxDay1, maxDay2, diff;
	int glucose[500], tCount = 0, percentCount, n, val, zeroCount = 0, percentZero;
	int sCount = 0, spikeMax = INT_MIN, dMax = INT_MIN, spikeDay1, spikeDay2, maxG1, maxG2;
	int c70 = 0, c80 = 0, c90 = 0, c100 = 0, c110 = 0, c120 = 0, c130 = 0;
	int graph70, graph80, graph90, graph100, graph110, graph120, graph130;
	
	float avg;
	
	bool norm;
	
	inputFile.open("readings.txt");																						// Input and Output files
	outputFile.open("results.txt");
	
	if (!inputFile.is_open()) {																							// Checking if files open
		cout << "File could not be opened. Aborting...";
		exit (1) ;
	}
	else{
		cout << "Input file has been successfully opened!"<< endl << endl;
	}
	
	if (!outputFile.is_open()){
		cout << "File could not be opened. Aborting...";
		exit (1) ;
	}
	
	cout << "Working on Part (a)...";																					// Open file and read into array
	
		inputFile >> level;
		while (level != -1) {
		glucose[i] = level;
		i++;
		inputFile >> level;
	}
	cout << "Part (a) completed."<< endl << endl;
	
	num = i;
	
	cout << "Working on Part (b)...";
	
	for (i=0; i<num; i++){																								// Counting normal days
	norm = isNormal (glucose[i]) ;
	if (norm){
		tCount++;
	}
	}
	percentCount = (tCount*1.0 / num) * 100;																			// Percent of normal days
	
	outputFile << "b) Number of days blood glucose level was normal: " << tCount<< endl;								// Displaying count and percent
	outputFile << "   Percent of days blood glucose level was normal: " << percentCount << "%" << endl << endl;

	cout << "Part (b) completed." << endl << endl;
	
	cout << "Working on Part (c)...";																					// Highest blood sugar level
	
	for (i=0; i<num; i++){
		if (glucose[i] > max) {
			max = glucose[i];
			maxDay1 = i + 1;
			maxDay2 = i + 3;
		}
	}
	
	outputFile << "c) The highest blood sugar level was " << max << endl;												// Display highest and all ties
	outputFile << "   It occurred in the following day/s: " << maxDay1 << ", " << maxDay2 << endl << endl;
	
	cout << "Part (c) completed." << endl << endl;
	
	cout << "Working on Part (d)..." << endl;
	
	cout << "Please enter a value for recent n days: " ;																// Asking user to enter n days
	cin >> n;

	for (i=num; i>(num-n); i--) {																						//Finding average 
	sum = sum + glucose[i];
	}
	avg = sum/n;
	
	outputFile << "d) Over the last " << n << " days, the average blood sugar level was " << avg << endl << endl;		// Display average
	
	cout << "Part (d) completed." << endl << endl;
	
	cout << "Working on Part (e)...";

	cout << "Please enter a value for Blood Sugar Level: ";																// Ask the user to enter a value
	cin >> val;
	
	cout << "Checking for consecutive days..." << endl;
	
	outputFile << "e) Three consecutive days where the blood sugar level went above " << val << " are: " << endl;

	for (i=1; i< num; i++){																								// Finding 3 consecutive days
		if ((glucose[i] > val) && (glucose[i+1] > val) && (glucose[i+2] > val)){
			outputFile << "Days : " << i << "(" << glucose[i] << "), " << i+1 << "(" << glucose[i+1] << "), " << i+2 << "(" << glucose[i+2] << ")" << endl;
		}
	}
	outputFile << endl;
	
	cout << "Part (e) completed." << endl << endl;
	
	cout << "Working on Part (f)..." ;																					// Finding when 0 readings were taken

	for (i=0; i< num; i++) {
	if (glucose[i] == 0){
		zeroCount++;
		}
	}
	percentZero = (zeroCount*1.0/ num) * 100;																			// Percent of 0 readings
	
	outputFile << "f) Number of days no readings were taken: " << zeroCount << endl;									// Display findings and percent
	outputFile << "   Percent of days no readings were taken: " << percentZero << "%" << endl << endl;
	
	cout << "Part (f) completed." << endl << endl;
	
	cout << "Working on Part (g)...";

	
	for (i=0; i< num; i++) {																							// Finding spikes while skiiping 0s
		diff = difference(glucose[i], glucose[i+1]);
		if ((glucose[i] !=0) && (glucose[i+1] !=0) && (diff >= 40)) {
			sCount++;
		}
	}
	
	for (i=0; i< num; i++) {																							// Finding biggest spike
		diff = difference(glucose[i], glucose[i+1]);
		if ((glucose[i] !=0) && (glucose[i+1] !=0) && (diff > dMax)){
			dMax = diff;
		}
	}
	
	for (i=0; i< num - 2; i++)	{																						// Finding days of biggest spikes
		diff = difference(glucose[i], glucose[i+1]);
		if ((glucose[i] !=0) && (glucose[i+1] !=0)) {
			if (diff > spikeMax){
				spikeMax = diff;
				spikeDay1 = i+1;
				spikeDay2 = i+2;	
				maxG1 = glucose[i];
				maxG2 = glucose[i+1];
			}
		}
	}
				
	
	outputFile << "g) There were " << sCount << " spikes." << endl;
	outputFile << "   The biggest Spike was " << dMax << endl;
	outputFile << "   It occured from Day " << spikeDay1 << "(" << maxG1 << ") to Day " << spikeDay2 << "(" << maxG2 << ")" << endl;
	
	cout << "Part (g) completed." << endl << endl;
	
	cout << "Working on Part (h)..." << endl << endl;
 
	for (i=0; i< num; i++){																								// Counting each range
 	if ((glucose[i] > 69) && (glucose[i] < 80)){
 		c70++;
	 }
	 if ((glucose[i] > 79) && (glucose[i] < 90)){
 		c80++;
	 }
	 if ((glucose[i] > 89) && (glucose[i] < 100)){
 		c90++;
	 }
	 if ((glucose[i] > 99) && (glucose[i] < 110)){
 		c100++;
	 }
	 if ((glucose[i] > 109) && (glucose[i] < 120)){
 		c110++;
 	}
	 if ((glucose[i] > 119) && (glucose[i] < 130)){
	 	c120++;
	 }
	 if (glucose[i] >= 130){
 		c130++;
	 }
	}
 
	graph70 = c70/5;
	graph80 = c80/5;
	graph90 = c90/5;
	graph100 = c100/5;
	graph110 = c110/5;
	graph120 = c120/5;
	graph130 = c130/5;
	
	cout << "Histogram of Readings:" << endl << endl;																	// Display Histogram

	cout << "  70 - 79 | " ; printStars (graph70);
	cout << endl;
	cout << "  80 - 89 | " ; printStars (graph80);
	cout << endl;
	cout << "  90 - 99 | " ; printStars (graph90);
	cout << endl;
	cout << "100 - 109 | " ; printStars (graph100);
	cout << endl;
	cout << "110 - 119 | " ; printStars (graph110);
	cout << endl;
	cout << "120 - 129 | " ; printStars (graph120);
	cout << endl;
	cout << "   >= 130 | " ; printStars (graph130);
	cout << endl << endl;
	
	cout << "Part (h) completed." << endl << endl;
	
	cout << "Parts (a) to (h) completed. "<< endl << endl;
	
	cout << "Please check the file results.txt for results of the analysis.";

inputFile.close();																										// Close both files

outputFile.close();

return 0;
}
