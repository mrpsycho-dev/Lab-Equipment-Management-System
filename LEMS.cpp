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

          ////////////////////////////////////////////////////////////////
          // OPTION 1 - ADD EQUIPMENT
          ////////////////////////////////////////////////////////////////
          if (adminChoice == 1)
          {
            system("cls");
            cout << "\nADD NEW EQUIPMENT\n\n";

            cout << "Name: ";
            cin >> equipmentName[equipmentCount];
            cout << "Category (Electronics/Chemistry/Physics/Biology): ";
            cin >> equipmentCat[equipmentCount];
            cout << "Quantity: ";
            cin >> equipmentQty[equipmentCount];
            equipmentAvail[equipmentCount] = equipmentQty[equipmentCount];
            cout << "Condition (Good/Fair/Poor): ";
            cin >> equipmentCond[equipmentCount];
            cout << "Price (PKR): ";
            cin >> equipmentPrice[equipmentCount];
            equipmentId[equipmentCount] = nextEquipId++;

            historyAction[historyCount] = "Added";
            historyItem[historyCount] = equipmentName[equipmentCount];
            historyBy[historyCount] = "Admin";
            historyCount++;

            equipmentCount++;
            cout << "\nEquipment added successfully!\n";
          }
          ////////////////////////////////////////////////////////////////
          // OPTION 2 - VIEW ALL EQUIPMENT
          ////////////////////////////////////////////////////////////////
          else if (adminChoice == 2)
          {
            system("cls");
            cout << "\nALL EQUIPMENT\n\n";
            cout << "ID\tName\t\tCategory\tQty\tAvail\tCondition\tPrice\n";
            cout << "----------------------------------------------------------------------------\n";
            for (int i = 0; i < equipmentCount; i++)
            {
              cout << equipmentId[i] << "\t"
                   << equipmentName[i] << "\t"
                   << equipmentCat[i] << "\t"
                   << equipmentQty[i] << "\t"
                   << equipmentAvail[i] << "\t"
                   << equipmentCond[i] << "\t\t"
                   << equipmentPrice[i] << "\n";
            }

            ////////////////////////////////////////////////////////////////
            // OPTION 3 - SEARCH EQUIPMENT
            ////////////////////////////////////////////////////////////////
          }
          else if (adminChoice == 3)
          {
            system("cls");
            cout << "\nSEARCH EQUIPMENT\n\n";
            cout << "Enter name: ";
            string searchName;
            cin >> searchName;

            bool found = false;
            cout << "\nID\tName\t\tCategory\tAvail\tCondition\tPrice\n";
            cout << "------------------------------------------------------------------------\n";
            for (int i = 0; i < equipmentCount; i++)
            {
              if (equipmentName[i] == searchName)
              {
                cout << equipmentId[i] << "\t"
                     << equipmentName[i] << "\t\t"
                     << equipmentCat[i] << "\t"
                     << equipmentAvail[i] << "\t"
                     << equipmentCond[i] << "\t\t"
                     << equipmentPrice[i] << "\n";
                found = true;
              }
            }
            if (!found)
              cout << "No equipment found!\n";

            ////////////////////////////////////////////////////////////////
            // OPTION 4 - UPDATE EQUIPMENT
            ////////////////////////////////////////////////////////////////
          }
          else if (adminChoice == 4)
          {
            system("cls");
            cout << "\nUPDATE EQUIPMENT\n\n";
            cout << "Enter equipment ID to update: ";
            int updateId;
            cin >> updateId;

            bool found = false;
            for (int i = 0; i < equipmentCount; i++)
            {
              if (equipmentId[i] == updateId)
              {
                found = true;
                cout << "\nCurrent Record:\n";
                cout << "Name\t\t: " << equipmentName[i] << "\n";
                cout << "Category\t: " << equipmentCat[i] << "\n";
                cout << "Quantity\t: " << equipmentQty[i] << "\n";
                cout << "Condition\t: " << equipmentCond[i] << "\n";
                cout << "Price\t\t: " << equipmentPrice[i] << "\n";

                cout << "\nEnter New Details:\n";
                cout << "Name: ";
                cin >> equipmentName[i];
                cout << "Category: ";
                cin >> equipmentCat[i];

                int oldQty = equipmentQty[i];
                cout << "Quantity: ";
                cin >> equipmentQty[i];
                int diff = equipmentQty[i] - oldQty;
                equipmentAvail[i] = equipmentAvail[i] + diff;
                if (equipmentAvail[i] < 0)
                  equipmentAvail[i] = 0;

                cout << "Condition: ";
                cin >> equipmentCond[i];
                cout << "Price: ";
                cin >> equipmentPrice[i];

                historyAction[historyCount] = "Updated";
                historyItem[historyCount] = equipmentName[i];
                historyBy[historyCount] = "Admin";
                historyCount++;

                cout << "\nEquipment updated successfully!\n";
                break;
              }
            }
            if (!found)
              cout << "Equipment ID not found!\n";

            ////////////////////////////////////////////////////////////////
            // OPTION 5 - DELETE EQUIPMENT
            ////////////////////////////////////////////////////////////////
          }
          else if (adminChoice == 5)
          {
            system("cls");
            cout << "\nDELETE EQUIPMENT\n\n";
            cout << "Enter equipment ID to delete: ";
            int deleteId;
            cin >> deleteId;

            bool found = false;
            for (int i = 0; i < equipmentCount; i++)
            {
              if (equipmentId[i] == deleteId)
              {
                found = true;
                cout << "Equipment: " << equipmentName[i] << "\n";
                cout << "Confirm delete? (y/n): ";
                char confirm;
                cin >> confirm;

                if (confirm == 'y' || confirm == 'Y')
                {
                  string deletedName = equipmentName[i];

                  for (int j = i; j < equipmentCount - 1; j++)
                  {
                    equipmentId[j] = equipmentId[j + 1];
                    equipmentName[j] = equipmentName[j + 1];
                    equipmentCat[j] = equipmentCat[j + 1];
                    equipmentQty[j] = equipmentQty[j + 1];
                    equipmentAvail[j] = equipmentAvail[j + 1];
                    equipmentCond[j] = equipmentCond[j + 1];
                    equipmentPrice[j] = equipmentPrice[j + 1];
                  }
                  equipmentCount--;

                  historyAction[historyCount] = "Deleted";
                  historyItem[historyCount] = deletedName;
                  historyBy[historyCount] = "Admin";
                  historyCount++;

                  cout << "Equipment deleted!\n";
                }
                else
                {
                  cout << "Deletion cancelled.\n";
                }
                break;
              }
            }
            if (!found)
              cout << "Equipment ID not found!\n";

            ////////////////////////////////////////////////////////////////
            // OPTION 6 - VIEW BORROWING RECORDS
            ////////////////////////////////////////////////////////////////
          }
        }
      }
    }
  }