// oop3_2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Rectangle.h"
using namespace std;

void ReadFile(const char *fileName, CRectangle &rectangle)
{
	string action;
	ifstream inputFile(fileName);
	
	while (inputFile)
	{
		inputFile >> action;
		if (action == "Rectangle")
		{
			int width, height, left, top;
			inputFile >> left >> top >> width >> height;
			rectangle.SetLeft(left);
			rectangle.SetTop(top);
			rectangle.SetWidth(width);
			rectangle.SetHeight(height);
		}
		if (action == "Move")
		{
			int dx, dy;
			inputFile >> dx >> dy;
			rectangle.Move(dx, dy);
		}
		if (action == "Scale")
		{
			int sx, sy;
			inputFile >> sx >> sy;
			rectangle.Scale(sx, sy);
		}
	}
}

void PrintRectangleCondition(const CRectangle &rectangle)
{
	cout << "Left Top : " << rectangle.GetLeft() << " ; " << rectangle.GetTop() << "\n";
	cout << "Size : " << rectangle.GetWidth() << " * " << rectangle.GetHeight() << "\n";
	cout << "Right Bottom : " << rectangle.GetRight() << " ; " << rectangle.GetBottom() << "\n";
	cout << "Area : " << rectangle.GetArea() << "\n";
	cout << "Perimeter : " << rectangle.GetPerimeter() << "\n";
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		puts("Command line argument is missing");
		getchar();
		return 1;
	}

	CRectangle rectangle1, rectangle2;
	ReadFile(argv[1], rectangle1);
	cout << "Rectangle1:\n";
	PrintRectangleCondition(rectangle1);
	ReadFile(argv[2], rectangle2);
	cout << "Rectangle2:\n";
	PrintRectangleCondition(rectangle2);
	rectangle1.Intersect(rectangle2);
	cout << "Intersection rectangle:\n";
	PrintRectangleCondition(rectangle1);
	getchar();
	return 0;
}

