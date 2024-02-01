#define MAIN

#ifdef MAIN

#include <iostream>
#include <string>
#include "MBOP.h"

using namespace std;

int main() {
	int mode, number, number2, sys;
	string sNumber;
	float flt;

	while (true) {
		cout << "Choose option: \n"
			<< "1) Dec to any\n"
			<< "2) Any to dec\n"
			<< "3) Oct to Bin\n"
			<< "4) Hex to Bin\n"
			<< "5) To SM\n"
			<< "6) To C1\n"
			<< "7) To C2\n"
			<< "8) Sum in C2\n"
			<< "9) Float to Bin\n"
			<< "10) Bin to Float\n"
			<< "> ";

		cin >> mode;

		switch (mode) {
		case 1:
			cout << "Number: ";
			cin >> number;
			cout << "System: ";
			cin >> sys;
			writeInt2Any(number, sys);
			break;
		case 2:
			cout << "Number: ";
			cin >> sNumber;
			cout << "System: ";
			cin >> sys;
			writeAny2Int(sNumber, sys);
			break;
		case 3:
			cout << "Number: ";
			cin >> sNumber;
			writeOct2Bin(sNumber);
			break;
		case 4:
			cout << "Number: ";
			cin >> sNumber;
			writeHex2Bin(sNumber);
			break;
		case 5:
			cout << "Number: ";
			cin >> number;
			writeSM(number);
			break;
		case 6:
			cout << "Number: ";
			cin >> number;
			writeC1(number);
			break;
		case 7:
			cout << "Number: ";
			cin >> number;
			writeC2(number);
			break;
		case 8:
			cout << "Number1: ";
			cin >> number;
			cout << "Number2: ";
			cin >> number2;
			cout << "Final result: " << BinSum(writeC2(number), writeC2(number2));
			break;
		case 9:
			cout << "Float Number: ";
			cin >> flt;
			writefloat2Bin(flt);
			break;
		
		case 10:
			cout << "Float Bin Number: ";
			cin >> sNumber;
			writeBin2float(sNumber);
			break;
		}

		cout << '\n';
	}

	return 0;
}

#endif
