#include <iostream>
#include <conio.h>
using namespace std;

int main()
{

  ////////////////////////////////////////////////////////////////
  // EQUIPMENT DATA ARRAYS
  ////////////////////////////////////////////////////////////////
  int n = 200;
  int equipmentCount = 5;
  int equipmentId[n] = {1, 2, 3, 4, 5};
  string equipmentName[n] = {"Microscope", "Oscilloscope", "BunsenBurner", "Voltmeter", "Centrifuge"};
  string equipmentCat[n] = {"Biology\t", "Electronics", "Chemistry", "Electronics", "Biology\t"};
  int equipmentQty[n] = {5, 3, 8, 6, 2};
  int equipmentAvail[n] = {5, 3, 8, 6, 2};
  string equipmentCond[n] = {"Good", "Good", "Fair", "Good", "Fair"};
  float equipmentPrice[n] = {15000, 25000, 2000, 5000, 50000};
  int nextEquipId = 6;

  ////////////////////////////////////////////////////////////////
  // BORROW DATA ARRAYS
  ////////////////////////////////////////////////////////////////
  int borrowCount = 0;
  int borrowId[n];
  string borrowEquipName[n];
  string borrowerName[n];
  string borrowerRoll[n];
  string borrowDate[n];
  string returnDate[n];
  string borrowStatus[n];
  string borrowIssuedBy[n];
  int nextBorrowId = 1;

  ////////////////////////////////////////////////////////////////
  // HISTORY DATA ARRAYS
  ////////////////////////////////////////////////////////////////
  int historyCount = 0;
  string historyAction[n];
  string historyItem[n];
  string historyBy[n];

  ////////////////////////////////////////////////////////////////
  // TECHNICIAN DATA ARRAYS
  ////////////////////////////////////////////////////////////////
  int techCount = 2;
  string techUsername[10] = {"tech1", "tech2"};
  string techName[10] = {"Dr.Sara", "Mr.Hamza"};
  ////////////////////////////////////////////////////////////////
  // MAIN LOOP
  ////////////////////////////////////////////////////////////////
  while (true)
  {
    system("cls");
    cout
        << R"(

    |===========================================================|
    |        LAB EQUIPMENT MANAGEMENT SYSTEM                    |
    |                        LEMS                               |
    |===========================================================|
    |   [1]   Admin Login                                       |
    |   [2]   Lab Technician Login                              |
    |   [3]   Exit                                              |
    |===========================================================|
    Choose option: 

)";
    int mainChoice;
    cin >> mainChoice;

    ////////////////////////////////////////////////////////////////
    // ADMIN SECTION
    ////////////////////////////////////////////////////////////////
    if (mainChoice == 1)
    {

      bool adminLoggedIn = false;

      for (int i = 0; i < 3; i++)
      {
        system("cls");
        cout << "\nADMIN LOGIN - Attempt " << i + 1 << " of 3\n\n";
        string username, password;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        if (username == "admin" && password == "123")
        {
          adminLoggedIn = true;
          cout << "\nLogin Successful!\n";
          getch();
          break;
        }
        else
        {
          cout << "\nInvalid credentials!\n";
          getch();
        }
      }

      if (adminLoggedIn)
      {
        while (true)
        {
          system("cls");
          cout
              << R"(

    |===========================================================|
    |                   ADMIN DASHBOARD                         |
    |===========================================================|
    |   [1]   Add Equipment                                     |
    |   [2]   View All Equipment                                |
    |   [3]   Search Equipment                                  |
    |   [4]   Update Equipment                                  |
    |   [5]   Delete Equipment                                  |
    |   [6]   View Borrowing Records                            |
    |   [7]   Sort Equipment                                    |
    |   [8]   View Equipment by Category                        |
    |   [9]   Manage Technicians                                |
    |  [10]   Activity History                                  |
    |  [11]   Logout                                            |
    |===========================================================|
    Choose option: 

)";
          int adminChoice;
          cin >> adminChoice;
        }
      }
    }
  }