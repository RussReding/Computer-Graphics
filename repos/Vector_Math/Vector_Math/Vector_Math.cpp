// Vector_Math.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
using namespace std;

void printMenu(void);
void calcAngle(void);
void calcNormal(void);
void calcPlane(int plane);
void deterPlane(void);

int P[2];

int main() {   
	printMenu();
}

void printMenu() {
	int userChoice = 0;
	printf("Vector Math Menu \n");
	printf("--------------------------- \n");
	printf("1) Calculate the Angle between two 2D Vectors! \n");
	printf("2) Calculate the Normal Vectore between three points! \n");
	printf("3) Verify if points lie on a single plane \n");
	printf("Enter an option (1-3): ");
	cin >> userChoice;
	switch (userChoice) {
		case(1):
			calcAngle();
			break;
		case(2):
			calcNormal();
			break;
		case(3):
			calcPlane(0);
			calcPlane(1);
			deterPlane();
		default :
			//printf("ERROR: Invalid Input! \n");
			//system("CLS");
			printMenu();
	}
	printMenu();
}

void calcAngle() {
	double vector1[2];
	double vector2[2];
	double dotProduct;
	double mag_vector1;
	double mag_vector2;
	double angle;
	printf("Enter the first vector parameters separated by a space (i.e. X1 Y1): ");
	cin >> vector1[0];
	cin >> vector1[1];
	printf("Enter the second vector parameters separated by a space (i.e. X2 Y2): ");
	cin >> vector2[0];
	cin >> vector2[1];
	if (vector1[0] != NULL && vector1[1] != NULL && vector2[0] != NULL && vector2[1] != NULL) {
		dotProduct = (vector1[0] * vector1[1]) + (vector2[0] * vector2[1]);
		mag_vector1 = sqrt((vector1[0] * vector1[0]) + (vector1[1] * vector1[1]));
		mag_vector2 = sqrt((vector2[0] * vector2[0]) + (vector2[1] * vector2[1]));
		angle = dotProduct / (mag_vector1 * mag_vector2);
		printf("The angle is: %f \n", angle);
	}
}

void calcNormal() {
	//Points
	double point1[3];
	double point2[3];
	double point3[3];
	//Vectors
	double A[3]; //point2 - point1
	double B[3]; //point3 - point1

	double normal[3];

	printf("Enter the first point parameters separated by a space (i.e. X1, Y1, Z1): ");
	cin >> point1[0];
	cin >> point1[1];
	cin >> point1[2];
	printf("Enter the second point parameters separated by a space (i.e. X2, Y2, Z2): ");
	cin >> point2[0];
	cin >> point2[1];
	cin >> point2[2];
	printf("Enter the third point parameters separated by a space (i.e. X3, Y3, Z3): ");
	cin >> point3[0];
	cin >> point3[1];
	cin >> point3[2];
	if (point1 != NULL && point2 != NULL && point3 != NULL) {
		A[0] = point2[0] - point1[0];
		A[1] = point2[1] - point1[1];
		A[2] = point2[2] - point1[2];

		B[0] = point3[0] - point1[0];
		B[1] = point3[1] - point1[1];
		B[2] = point3[2] - point1[2];

		normal[0] = (A[1] * B[2]) - (A[2] * B[1]); //AyBz - AzBy
		normal[1] = (A[2] * B[0]) - (A[0] * B[2]); //AzBx - AxBz
		normal[2] = (A[0] * B[1]) - (A[1] * B[0]); //AxBy - AyBx

		printf("The normal Vector of the three points in %fi %fj %fk \n", normal[0], normal[1], normal[2]);
	}
}

void calcPlane(int plane) {
	//Points
	int point1[3];
	int point2[3];
	int point3[3];
	//Vectors
	int A[3]; //point2 - point1
	int B[3]; //point3 - point1

	int normal[3];

	printf("Enter the first point parameters separated by a space (i.e. X1, Y1, Z1): ");
	cin >> point1[0];
	cin >> point1[1];
	cin >> point1[2];
	printf("Enter the second point parameters separated by a space (i.e. X2, Y2, Z2): ");
	cin >> point2[0];
	cin >> point2[1];
	cin >> point2[2];
	printf("Enter the third point parameters separated by a space (i.e. X3, Y3, Z3): ");
	cin >> point3[0];
	cin >> point3[1];
	cin >> point3[2];
	if (point1 != NULL && point2 != NULL && point3 != NULL) {
		A[0] = point2[0] - point1[0];
		A[1] = point2[1] - point1[1];
		A[2] = point2[2] - point1[2];

		B[0] = point3[0] - point1[0];
		B[1] = point3[1] - point1[1];
		B[2] = point3[2] - point1[2];

		normal[0] = (A[1] * B[2]) - (A[2] * B[1]); //AyBz - AzBy
		normal[1] = (A[2] * B[0]) - (A[0] * B[2]); //AzBx - AxBz
		normal[2] = (A[0] * B[1]) - (A[1] * B[0]); //AxBy - AyBx

		if (normal[0] == 0 && normal[1] == 0 && normal[2] == 0) {
			printf("The three points do not lie on a single plane! \n");
			P[plane] = 0;
		}
		else {
			printf("The points do lie on a single plane! \n");
			P[plane] = 1;
		}
	}
}

void deterPlane() {
	if (P[0] == 1 && P[1] == 1) {
		printf("P1 and P2 lie on the same plane! \n");
	}
	else {
		printf("P1 and P2 do not lie on the same plane! \n");
	}
}