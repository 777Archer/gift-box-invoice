//Gift Box  
//invoice.cpp file


#include <iostream>
#include <string>
#include <iomanip>
#include "giftwrap.h"

using namespace std;

int main()
{
	string shopName = "Sally's Gifts";
	char selection;
	double  boxLen;
	double  boxWid;
	double  boxHigh;

	GiftWrap sallys(0.0925, 0.0025);

	do
	{
		/*Display user menu*/
		cout << "GIFT WRAP INVOICE GENERATOR\n"
			<< "-------------------------------\n"
			<< "a) Generate Gift Wrap Invoice\n"
			<< "q) Quit\n";

		cin >> selection;

		if (selection == 'a' || selection == 'A')
		{
			/*get box length from user*/
			cout << "Please enter length of box that needs wrapping: ";
			cin >> boxLen;

			while (sallys.setLength(boxLen) == false)
			{
				cout << "\n\nBox length cannot be less than 0. \nPlease enter the length of box that needs wrapping: ";
				cin >> boxLen;
			}

			/*User input; width*/
			cout << "Please enter width of box that needs wrapping: ";
			cin >> boxWid;

			while (sallys.setWidth(boxWid) == false)
			{
				cout << "\n\nBox width cannot be less than 0. \nPlease enter width of box that needs wrapping: ";
				cin >> boxWid;
			}

			/*User input; height*/
			cout << "Please enter height of box that needs wrapping: ";
			cin >> boxHigh;

			while (sallys.setHeight(boxHigh) == false)
			{
				cout << "\n\nBox height cannot be less than 0. \nPlease enter height of box that needs wrapping: ";
				cin >> boxHigh;
			}

			/*Display invoice*/
			cout << "\nGIFT WRAP INVOICE - " << shopName << "\n"
				<< "----------------------------------\n"
				<< "Box Length: " << fixed << setprecision(1) << sallys.getLength() << "\n"
				<< "Box Width:  " << fixed << setprecision(1) << sallys.getWidth() << "\n"
				<< "Box Height: " << fixed << setprecision(1) << sallys.getHeight() << "\n"
				<< "Price Per Inch: " << fixed << setprecision(4) << sallys.getPriceperInch() << "\n\n"
				<< "SUBTOTAL:" << setw(12) << fixed << setprecision(2) << sallys.calcSubTotal() << "\n"
				<< "TAX:" << setw(17) << fixed << setprecision(2) << sallys.calcTax() << endl
				<< "           ----------\n"
				<< "TOTAL:" << setw(15) << fixed << setprecision(2) << sallys.calcTotal() << "\n" << endl;
		}

		else if (selection != 'q' && selection != 'Q')
		{
			cout << "Invalid Selection\n";
		}

		else
		{
			cout << "You have chosen to quit the program. Please Come Again!\n";
		}
	} while (selection != 'q' && selection != 'Q');

	system("PAUSE");
	return 0;
}
