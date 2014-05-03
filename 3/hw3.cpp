#include "D_LinkedList.h"
#include <fstream>
#include <iomanip>

 //bool setValue (ifstream &, List &);
 bool setVal(istream &, List &);
 int main()
 {
	 ifstream input;
	 input.open("big_ints.txt");

	 while (!input.eof())
	 {
		 List val1, val2, sum;
		 List *addrLargest;
		 while (setVal(input, val1));
		 setVal(input, val2);
		 while (setVal(input, val2));

		 sum.getSum(val1, val2);
		 sum.getLargest(val1, val2, addrLargest);

		 if (val1.getCount() != 0 && val2.getCount() != 0)
		 {
			 cout << "Number 1: " << setw(sum.getCount() - val1.getCount() + 1);
			 val1.printF();
			 cout << "\nNumber 2: " << setw(sum.getCount() - val2.getCount() + 1);
			 val2.printF();
			 cout << "\nSum     : ";
			 sum.printF();
			 cout << "\nLargest : " << setw(sum.getCount() - addrLargest->getCount() + 1);
			 addrLargest->printF();
			 cout << endl << endl;
		 }
	 }

	 system("PAUSE");
	 return 0;
 }


 bool setVal(istream &input, List &list)
 {
	 char inChar;
	 if (input.get(inChar) && inChar != '\n')
	 {
		
		 int a = inChar - '0';
		 list.push(a);
		 return true;
	 }
	 return false;
 }

