#include "LuckySequense.h"
#include <fstream>
#include <iostream>
using namespace std;
LuckySequense::LuckySequense(int i1, int i2, int i3, int i4, int i5, int i6) : Ticket(i1, i2, i3, i4, i5, i6)
{

    ofstream out("LuckyTicket.txt", ios::app);

    for (i1 = 0; i1 < 10; i1++)
        for (i2 = 0; i2 < 10; i2++)
            for (i3 = 0; i3 < 10; i3++)
                for (i4 = 0; i4 < 10; i4++)
                    for (i5 = 0; i5 < 10; i5++)
                        for (i6 = 0; i6 < 10; i6++)
                            if (i1 + i2 == i3 + i4 && i3 + i4 == i5 + i6)//если 101010 и 121212
                            {
                                out << i1 << i2 << i3 << i4 << i5 << i6 << "\n";
                                count2++;
                            }
    out <<"_______________________\n";
      for (i1 = 0; i1 < 10; i1++)
        for (i2 = 0; i2 < 10; i2++)
            for (i3 = 0; i3 < 10; i3++)
                for (i4 = 0; i4 < 10; i4++)
                    for (i5 = 0; i5 < 10; i5++)
                        for (i6 = 0; i6 < 10; i6++)
                            if (i1 == i2 == i3 == i4 == i5 == i6)// 111111
                            {
                                out << i1 << i2 << i3 << i4 << i5 << i6 << "\n";
                                count2++;
                            }
      out << "_______________________\n";
      for (i1 = 0; i1 < 10; i1++)
          for (i2 = 0; i2 < 10; i2++)
              for (i3 = 0; i3 < 10; i3++)
                  for (i4 = 0; i4 < 10; i4++)
                      for (i5 = 0; i5 < 10; i5++)
                          for (i6 = 0; i6 < 10; i6++)
                              if (i1 == i4 && i2 == i5 && i3 == i6)//123123
                              {
                                  out << i1 << i2 << i3 << " " << i4 << i5 << i6 << "\n";
                                  count2++;
                              }
      out << "_______________________\n";
      for (i1 = 0; i1 < 10; i1++)
          for (i2 = 0; i2 < 10; i2++)
              for (i3 = 0; i3 < 10; i3++)
                  for (i4 = 0; i4 < 10; i4++)
                      for (i5 = 0; i5 < 10; i5++)
                          for (i6 = 0; i6 < 10; i6++)
                              if (i1 == i6 && i2 == i5 && i3 == i4)//123321
                              {
                                  out << i1 << i2 << i3 << " " << i4 << i5 << i6 << "\n";
                                  count2++;
                              }
      out << "_______________________\n";
      for (i1 = 0; i1 < 10; i1++)
          for (i2 = 0; i2 < 10; i2++)
              for (i3 = 0; i3 < 10; i3++)
                  for (i4 = 0; i4 < 10; i4++)
                      for (i5 = 0; i5 < 10; i5++)
                          for (i6 = 0; i6 < 10; i6++)
                              if (i6 != 1 && i6 != 2 && i6 != 3 && i6 != 4 && i6 != 5)
                              {
                                  if(i5 == i6 - 1 && i4 == i6 - 2 && i3 == i6 - 3 && i2 == i6 - 4 && i1 == i6 - 5)//987654
                                  {
                                         out << i1 << i2 << i3 << " " << i4 << i5 << i6 << "\n";
                                       count2++;
                                  }
                              }

    cout << "Number of lucky tickets is " << count2 << endl;
    out.close();
}



double LuckySequense::Check()
{
    
    return  count2;
}
