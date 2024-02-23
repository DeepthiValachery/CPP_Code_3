# CPP_Code_3

It is important for persons with diabetes to check their blood sugar level on a daily basis. Such persons should aim for a blood sugar level between 80 mg/dl to 130 mg/dl before meals.

The file, readings.txt, contains the blood sugar level of a person with diabetes taken each day for several months (one reading per day). The readings are stored in the order in which they are taken. The number of values in the file is unknown beforehand but a value of -1 indicates that there is no more data.

Program Description

Write a program with the following functionality:

(a) Read all the data from the file and store it in an array, glucose. There are at most 500 readings in the file.

(b) (i) Write a function, isNormal, which accepts a value for a blood sugar level and returns true if the blood sugar level is between 80 mg/dl and 130 mg/dl, and false, otherwise. The function should be written as follows:

bool isNormal (int level) {
…
}

(ii) Using the function isNormal, find and display the number of days and the percentage of days the person’s blood sugar level was at normal levels.

(c) Find and display the day when the blood sugar level was the highest; if there are ties, all of them should be displayed.

(d) Find and display the average blood glucose value for the most recent n days, where n is input by the user at the keyboard.

(e) Find and display all the occasions (if any) when there were three consecutive days where the blood sugar level went above a certain number n, where n is input by the user at the keyboard.

(f) A blood glucose level of zero on any day indicates that the person did not measure his/her blood sugar level on that day. Find and display the number of days and the percentage of days the person did not measure his/her blood glucose level. 

(g) A spike is defined as a sudden increase or decrease in a person’s blood sugar level by at least 40 mg/dl in two consecutive days, provided that a measurement was taken on both days.

(i) Write a function, difference, which accepts the blood sugar level of two consecutive days as parameters and returns the difference between the two values, expressed as a positive integer. The function should be written as follows:

int difference (int day1, int day2) {
…
}

(ii) Using the function difference, find and display the number of spikes (if any) in the person’s blood sugar level. Also, find and display the biggest spike and indicate between which two days it occurred.

(h) For the seven ranges 70-79, 80-89, 90-99, 100-109, 110-119, 120-129, ≥130, draw a histogram showing the number of times the blood sugar level fell within each range. 

Output one asterisk (“*”) for every 5 times the blood sugar level was in that range. Fractional values should be rounded up using the ceil function.

The histogram should be formatted as follows (the actual shape depends on the data):

Histogram of Readings:

70 - 79    |***

80 - 89    |**

90 - 99    |****

100 - 109  |****

110 - 119  |***

120 - 129  |****

  >=130    |*********************
