#include "LuckySums.h"
#include <fstream>
#include <iostream>
using namespace std;
LuckySums::LuckySums(int i1, int i2, int i3, int i4, int i5, int i6) : Ticket(i1, i2, i3, i4, i5, i6)
{
    ofstream out("LuckyTicket.txt", ios::app);

    for (i1 = 0; i1 < 10; i1++)
        for (i2 = 0; i2 < 10; i2++)
            for (i3 = 0; i3 < 10; i3++)
                for (i4 = 0; i4 < 10; i4++)
                    for (i5 = 0; i5 < 10; i5++)
                        for (i6 = 0; i6 < 10; i6++)
                            if (i1 + i2 + i3 == i4 + i5 + i6)
                            {
                                out << i1 << i2 << i3 << " " << i4 << i5 << i6 << "\n";
                                count3++;
                            }
    cout << "Number of lucky tickets is " << count3 << endl;
    out << "Number of lucky tickets is " << count3 << endl;
    out.close();
}



double LuckySums::Check()
{   
    return count3;
}
