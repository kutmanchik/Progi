#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;

const int MAX = 999;

struct Student { /// The information of each student
    string  ID;
    string  name;
    string  gender;
    int     age;
};

int searchStudent( Student a[], string query, int Size) {

    for (int i = 0; i < Size; i++)
   {
      if ( a[i].ID.compare(query) == 0 ) /// Linear Search
         return i + 1;
   }

   return 0;
}


int main()
{
    int student_amount;

    while( cin >> student_amount ) {


        Student* student1 = new Student[student_amount];

        /// Storing Phase ///

        for(int i = 0 ; i < student_amount ; i++)
            cin >> student1[i].ID >> student1[i].name >> student1[i].gender >> student1[i].age;

        /// Searching Phase ///

        string  search_id;
        int     search_amount,
                found;

        cin >> search_amount;

        while( search_amount-- ) {

            cin >> search_id;
            found = searchStudent( student1, search_id, student_amount); /// Compare to the database

            if( !found ) cout << "No Answer!" << endl;

            else    cout << student1[found-1].ID     << " "
                         << student1[found-1].name   << " "
                         << student1[found-1].gender << " "
                         << student1[found-1].age    << endl;
        }

    }

    return 0;
}
