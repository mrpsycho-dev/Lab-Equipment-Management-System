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
          else if (adminChoice == 6)
          {
            system("cls");
            cout << "\nALL BORROWING RECORDS\n\n";
            cout << "ID\tEquipment\t\tBorrower\tRoll\t\tStatus\n";
            cout << "------------------------------------------------------------------------\n";
            if (borrowCount == 0)
            {
              cout << "No records yet.\n";
            }
            for (int i = 0; i < borrowCount; i++)
            {
              cout << borrowId[i] << "\t"
                   << borrowEquipName[i] << "\t\t"
                   << borrowerName[i] << "\t"
                   << borrowerRoll[i] << "\t\t"
                   << borrowStatus[i] << "\n";
            }

            ////////////////////////////////////////////////////////////////
            // OPTION 7 - SORT EQUIPMENT
            ////////////////////////////////////////////////////////////////
          }
          else if (adminChoice == 7)
          {
            system("cls");
            cout
                << R"(

    |===========================================================|
    |                   SORT EQUIPMENT                          |
    |===========================================================|
    |   [1]   Price  - Ascending  (Lowest First)                |
    |   [2]   Price  - Descending (Highest First)               |
    |   [3]   Name   - A to Z                                   |
    |   [4]   Name   - Z to A                                   |
    |===========================================================|
    Choose option: 

)";
            int sortChoice;
            cin >> sortChoice;

            for (int i = 0; i < equipmentCount; i++)
            {
              for (int j = i + 1; j < equipmentCount; j++)
              {
                bool doSwap = false;

                if (sortChoice == 1 && equipmentPrice[i] > equipmentPrice[j])
                  doSwap = true;
                if (sortChoice == 2 && equipmentPrice[i] < equipmentPrice[j])
                  doSwap = true;
                if (sortChoice == 3 && equipmentName[i] > equipmentName[j])
                  doSwap = true;
                if (sortChoice == 4 && equipmentName[i] < equipmentName[j])
                  doSwap = true;

                if (doSwap)
                {
                  int tId = equipmentId[i];
                  equipmentId[i] = equipmentId[j];
                  equipmentId[j] = tId;
                  string tName = equipmentName[i];
                  equipmentName[i] = equipmentName[j];
                  equipmentName[j] = tName;
                  string tCat = equipmentCat[i];
                  equipmentCat[i] = equipmentCat[j];
                  equipmentCat[j] = tCat;
                  int tQty = equipmentQty[i];
                  equipmentQty[i] = equipmentQty[j];
                  equipmentQty[j] = tQty;
                  int tAvail = equipmentAvail[i];
                  equipmentAvail[i] = equipmentAvail[j];
                  equipmentAvail[j] = tAvail;
                  string tCond = equipmentCond[i];
                  equipmentCond[i] = equipmentCond[j];
                  equipmentCond[j] = tCond;
                  float tPrice = equipmentPrice[i];
                  equipmentPrice[i] = equipmentPrice[j];
                  equipmentPrice[j] = tPrice;
                }
              }
            }

            cout << "\nSorted! Result:\n\n";
            cout << "ID\tName\t\tCategory\tPrice\n";
            cout << "--------------------------------------------\n";
            for (int i = 0; i < equipmentCount; i++)
            {
              cout << equipmentId[i] << "\t"
                   << equipmentName[i] << "\t\t"
                   << equipmentCat[i] << "\t"
                   << equipmentPrice[i] << "\n";
            }

            ////////////////////////////////////////////////////////////////
            // OPTION 8 - VIEW EQUIPMENT BY CATEGORY
            ////////////////////////////////////////////////////////////////
          }
          else if (adminChoice == 8)
          {
            system("cls");
            cout << "\nVIEW EQUIPMENT BY CATEGORY\n\n";
            cout << "Enter category (Electronics/Chemistry/Physics/Biology): ";
            string searchCat;
            cin >> searchCat;

            bool found = false;
            cout << "\nID\tName\t\tQty\tAvail\tCondition\tPrice\n";
            cout << "------------------------------------------------------------------------\n";
            for (int i = 0; i < equipmentCount; i++)
            {
              if (equipmentCat[i] == searchCat)
              {
                cout << equipmentId[i] << "\t"
                     << equipmentName[i] << "\t\t"
                     << equipmentQty[i] << "\t"
                     << equipmentAvail[i] << "\t"
                     << equipmentCond[i] << "\t\t"
                     << equipmentPrice[i] << "\n";
                found = true;
              }
            }
            if (!found)
              cout << "No equipment found in this category!\n";
          }

          ////////////////////////////////////////////////////////////////
          // OPTION 9 - MANAGE TECHNICIANS
          ////////////////////////////////////////////////////////////////
          else if (adminChoice == 9)
          {
            system("cls");
            cout
                << R"(

    |===========================================================|
    |                 MANAGE TECHNICIANS                        |
    |===========================================================|
    |   [1]   View All Technicians                              |
    |   [2]   Add Technician                                    |
    |   [3]   Delete Technician                                 |
    |===========================================================|
    Choose option: 

)";
            int techMenuChoice;
            cin >> techMenuChoice;

            if (techMenuChoice == 1)
            {
              system("cls");
              cout << "\nALL TECHNICIANS\n\n";
              cout << "No.\tName\t\tUsername\n";
              cout << "------------------------------------\n";
              for (int i = 0; i < techCount; i++)
              {
                cout << i + 1 << "\t"
                     << techName[i] << "\t\t"
                     << techUsername[i] << "\n";
              }
            }
            else if (techMenuChoice == 2)
            {
              system("cls");
              cout << "\nADD TECHNICIAN\n\n";
              if (techCount >= 10)
              {
                cout << "Technician limit reached!\n";
              }
              else
              {
                cout << "Name: ";
                cin >> techName[techCount];
                cout << "Username: ";
                cin >> techUsername[techCount];
                techCount++;
                cout << "\nTechnician added! Default password is 123.\n";
              }
            }
            else if (techMenuChoice == 3)
            {
              system("cls");
              cout << "\nDELETE TECHNICIAN\n\n";
              cout << "Enter username to delete: ";
              string delUser;
              cin >> delUser;

              bool found = false;
              for (int i = 0; i < techCount; i++)
              {
                if (techUsername[i] == delUser)
                {
                  for (int j = i; j < techCount - 1; j++)
                  {
                    techName[j] = techName[j + 1];
                    techUsername[j] = techUsername[j + 1];
                  }
                  techCount--;
                  cout << "Technician deleted!\n";
                  found = true;
                  break;
                }
              }
              if (!found)
                cout << "Technician not found!\n";
            }
            else
            {
              cout << "Invalid option!\n";
            }

            ////////////////////////////////////////////////////////////////
            // OPTION 10 - ACTIVITY HISTORY
            ////////////////////////////////////////////////////////////////
          }
          else if (adminChoice == 10)
          {
            system("cls");
            cout << "\nACTIVITY HISTORY\n\n";
            if (historyCount == 0)
            {
              cout << "No history yet.\n";
            }
            for (int i = 0; i < historyCount; i++)
            {
              cout << i + 1 << ". [" << historyAction[i] << "] "
                   << historyItem[i] << " by " << historyBy[i] << "\n";
            }
          }

          ////////////////////////////////////////////////////////////////
          // OPTION 11 - LOGOUT
          ////////////////////////////////////////////////////////////////
          else if (adminChoice == 11)
          {
            cout << "\nLogging out...\n";
            getch();
            break;
          }
          else
          {
            cout << "\nInvalid option!\n";
          }

          cout << "\nPress any key to continue...";
          getch();
        }
      }

      ////////////////////////////////////////////////////////////////
      // TECHNICIAN SECTION
      ////////////////////////////////////////////////////////////////
    }
    else if (mainChoice == 2)
    {

      bool techLoggedIn = false;
      int loggedTechIdx = -1;

      for (int i = 0; i < 3; i++)
      {
        system("cls");
        cout << "\nTECHNICIAN LOGIN - Attempt " << i + 1 << " of 3\n\n";
        string username, password;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        for (int j = 0; j < techCount; j++)
        {
          if (techUsername[j] == username && password == "123")
          {
            techLoggedIn = true;
            loggedTechIdx = j;
            break;
          }
        }

        if (techLoggedIn)
        {
          cout << "\nWelcome, " << techName[loggedTechIdx] << "!\n";
          getch();
          break;
        }
        else
        {
          cout << "\nInvalid credentials!\n";
          getch();
        }
      }
      if (techLoggedIn)
      {
        while (true)
        {
          system("cls");
          cout << "\nLogged in as: " << techName[loggedTechIdx] << "\n";
          cout
              << R"(
    |===========================================================|
    |              LAB TECHNICIAN DASHBOARD                     |
    |===========================================================|
    |   [1]   View Available Equipment                          |
    |   [2]   Search Equipment                                  |
    |   [3]   Borrow Equipment                                  |
    |   [4]   Return Equipment                                  |
    |   [5]   My Issued Records                                 |
    |   [6]   View Active Borrowings                            |
    |   [7]   Equipment Details + ASCII Art                     |
    |   [8]   Borrowing History                                 |
    |   [9]   Logout                                            |
    |===========================================================|
    Choose option: 

)";
          int techOption;
          cin >> techOption;

          ////////////////////////////////////////////////////////////////
          // OPTION 1 - VIEW AVAILABLE EQUIPMENT
          ////////////////////////////////////////////////////////////////
          if (techOption == 1)
          {
            system("cls");
            cout << "\nAVAILABLE EQUIPMENT\n\n";
            cout << "ID\tName\t\tCategory\tAvailable\tCondition\n";
            cout << "------------------------------------------------------------------------\n";

            bool anyAvail = false;
            for (int i = 0; i < equipmentCount; i++)
            {
              if (equipmentAvail[i] > 0)
              {
                cout << equipmentId[i] << "\t"
                     << equipmentName[i] << "\t\t"
                     << equipmentCat[i] << "\t"
                     << equipmentAvail[i] << "\t\t"
                     << equipmentCond[i] << "\n";
                anyAvail = true;
              }
            }
            if (!anyAvail)
              cout << "No equipment available right now.\n";
          }

          ////////////////////////////////////////////////////////////////
          // OPTION 2 - SEARCH EQUIPMENT
          ////////////////////////////////////////////////////////////////
          else if (techOption == 2)
          {
            system("cls");
            cout << "\nSEARCH EQUIPMENT\n\n";
            cout << "Enter name: ";
            string searchName;
            cin >> searchName;

            bool found = false;
            cout << "\nID\tName\t\tCategory\tAvail\tCondition\n";
            cout << "------------------------------------------------------------\n";
            for (int i = 0; i < equipmentCount; i++)
            {
              if (equipmentName[i] == searchName)
              {
                cout << equipmentId[i] << "\t"
                     << equipmentName[i] << "\t\t"
                     << equipmentCat[i] << "\t"
                     << equipmentAvail[i] << "\t"
                     << equipmentCond[i] << "\n";
                found = true;
              }
            }
            if (!found)
              cout << "No equipment found!\n";
          }

          ////////////////////////////////////////////////////////////////
          // OPTION 3 - BORROW EQUIPMENT
          ////////////////////////////////////////////////////////////////
          else if (techOption == 3)
          {
            system("cls");
            cout << "\nBORROW EQUIPMENT\n\n";
            cout << "Enter equipment ID: ";
            int borrowEquipId;
            cin >> borrowEquipId;

            bool found = false;
            for (int i = 0; i < equipmentCount; i++)
            {
              if (equipmentId[i] == borrowEquipId)
              {
                found = true;
                if (equipmentAvail[i] <= 0)
                {
                  cout << "Sorry! This equipment is not available.\n";
                }
                else
                {
                  cout << "Equipment: " << equipmentName[i] << "\n";
                  cout << "Borrower Name: ";
                  string bName;
                  cin >> bName;
                  cout << "Roll Number: ";
                  string bRoll;
                  cin >> bRoll;
                  cout << "Borrow Date (DD/MM/YYYY): ";
                  string bDate;
                  cin >> bDate;
                  cout << "Return Date (DD/MM/YYYY): ";
                  string rDate;
                  cin >> rDate;

                  borrowId[borrowCount] = nextBorrowId++;
                  borrowEquipName[borrowCount] = equipmentName[i];
                  borrowerName[borrowCount] = bName;
                  borrowerRoll[borrowCount] = bRoll;
                  borrowDate[borrowCount] = bDate;
                  returnDate[borrowCount] = rDate;
                  borrowStatus[borrowCount] = "Borrowed";
                  borrowIssuedBy[borrowCount] = techName[loggedTechIdx];
                  borrowCount++;
                  equipmentAvail[i]--;

                  historyAction[historyCount] = "Borrowed";
                  historyItem[historyCount] = equipmentName[i];
                  historyBy[historyCount] = techName[loggedTechIdx];
                  historyCount++;

                  cout << "\nEquipment issued! Borrow ID: " << nextBorrowId - 1 << "\n";
                }
                break;
              }
            }
            if (!found)
              cout << "Equipment ID not found!\n";
          }

          ////////////////////////////////////////////////////////////////
          // OPTION 4 - RETURN EQUIPMENT
          ////////////////////////////////////////////////////////////////
          else if (techOption == 4)
          {
            system("cls");
            cout << "\nRETURN EQUIPMENT\n\n";
            cout << "Enter Borrow ID: ";
            int retId;
            cin >> retId;

            bool found = false;
            for (int i = 0; i < borrowCount; i++)
            {
              if (borrowId[i] == retId && borrowStatus[i] == "Borrowed")
              {
                found = true;
                cout << "Equipment : " << borrowEquipName[i] << "\n";
                cout << "Borrower  : " << borrowerName[i] << "\n";
                cout << "Confirm return? (y/n): ";
                char confirm;
                cin >> confirm;

                if (confirm == 'y' || confirm == 'Y')
                {
                  borrowStatus[i] = "Returned";
                  for (int j = 0; j < equipmentCount; j++)
                  {
                    if (equipmentName[j] == borrowEquipName[i])
                    {
                      equipmentAvail[j]++;
                      break;
                    }
                  }
                  historyAction[historyCount] = "Returned";
                  historyItem[historyCount] = borrowEquipName[i];
                  historyBy[historyCount] = techName[loggedTechIdx];
                  historyCount++;

                  cout << "Equipment returned successfully!\n";
                }
                else
                {
                  cout << "Return cancelled.\n";
                }
                break;
              }
            }
            if (!found)
              cout << "Borrow ID not found or already returned!\n";
          }

          ////////////////////////////////////////////////////////////////
          // OPTION 5 - MY ISSUED RECORDS
          ////////////////////////////////////////////////////////////////
          else if (techOption == 5)
          {
            system("cls");
            cout << "\nMY ISSUED RECORDS\n";
            cout << "Issued by: " << techName[loggedTechIdx] << "\n\n";
            cout << "ID\tEquipment\t\tBorrower\tStatus\n";
            cout << "------------------------------------------------------------\n";
            bool anyRecord = false;
            for (int i = 0; i < borrowCount; i++)
            {
              if (borrowIssuedBy[i] == techName[loggedTechIdx])
              {
                cout << borrowId[i] << "\t"
                     << borrowEquipName[i] << "\t\t"
                     << borrowerName[i] << "\t"
                     << borrowStatus[i] << "\n";
                anyRecord = true;
              }
            }
            if (!anyRecord)
              cout << "No records found.\n";
          }

          ////////////////////////////////////////////////////////////////
          // OPTION 6 - VIEW ACTIVE BORROWINGS
          ////////////////////////////////////////////////////////////////
        }
      }
    }
  }