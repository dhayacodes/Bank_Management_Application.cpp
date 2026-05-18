/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string name;
    float balance;

public:
    void createAccount()
    {
        cout << "\nEnter Account Number: ";
        cin >> accountNumber;

        cin.ignore();

        cout << "Enter Customer Name: ";
        getline(cin, name);

        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void showAccount() const
    {
        cout << "\nAccount Number : " << accountNumber;
        cout << "\nCustomer Name  : " << name;
        cout << "\nBalance         : " << balance << endl;
    }

    int getAccountNumber() const
    {
        return accountNumber;
    }

    float getBalance() const
    {
        return balance;
    }

    void deposit(float amount)
    {
        balance += amount;
    }

    bool withdraw(float amount)
    {
        if (amount > balance)
        {
            return false;
        }

        balance -= amount;
        return true;
    }

    void writeToFile()
    {
        ofstream outFile("bank.dat", ios::binary | ios::app);

        outFile.write(reinterpret_cast<char*>(this), sizeof(*this));

        outFile.close();
    }

    static void displayAllAccounts()
    {
        BankAccount acc;

        ifstream inFile("bank.dat", ios::binary);

        if (!inFile)
        {
            cout << "\nFile not found.\n";
            return;
        }

        cout << "\n===== ACCOUNT DETAILS =====\n";

        while (inFile.read(reinterpret_cast<char*>(&acc), sizeof(acc)))
        {
            acc.showAccount();
            cout << "---------------------------\n";
        }

        inFile.close();
    }

    static bool searchAccount(int accNo, BankAccount &acc)
    {
        ifstream inFile("bank.dat", ios::binary);

        while (inFile.read(reinterpret_cast<char*>(&acc), sizeof(acc)))
        {
            if (acc.accountNumber == accNo)
            {
                inFile.close();
                return true;
            }
        }

        inFile.close();
        return false;
    }

    static void updateAccount(BankAccount updatedAcc)
    {
        fstream file("bank.dat", ios::binary | ios::in | ios::out);

        BankAccount acc;

        while (file.read(reinterpret_cast<char*>(&acc), sizeof(acc)))
        {
            if (acc.accountNumber == updatedAcc.accountNumber)
            {
                int position = (-1) * sizeof(acc);

                file.seekp(position, ios::cur);

                file.write(reinterpret_cast<char*>(&updatedAcc), sizeof(updatedAcc));

                break;
            }
        }

        file.close();
    }
};

int main()
{
    int choice;
    BankAccount acc;

    do
    {
        cout << "\n====== BANK MANAGEMENT SYSTEM ======\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Balance Inquiry\n";
        cout << "5. Display All Accounts\n";
        cout << "6. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            acc.createAccount();
            acc.writeToFile();

            cout << "\nAccount Created Successfully.\n";
            break;
        }

        case 2:
        {
            int accNo;
            float amount;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            BankAccount temp;

            if (BankAccount::searchAccount(accNo, temp))
            {
                cout << "Enter Deposit Amount: ";
                cin >> amount;

                temp.deposit(amount);

                BankAccount::updateAccount(temp);

                cout << "\nAmount Deposited Successfully.\n";
            }
            else
            {
                cout << "\nAccount Not Found.\n";
            }

            break;
        }

        case 3:
        {
            int accNo;
            float amount;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            BankAccount temp;

            if (BankAccount::searchAccount(accNo, temp))
            {
                cout << "Enter Withdrawal Amount: ";
                cin >> amount;

                if (temp.withdraw(amount))
                {
                    BankAccount::updateAccount(temp);

                    cout << "\nWithdrawal Successful.\n";
                }
                else
                {
                    cout << "\nInsufficient Balance.\n";
                }
            }
            else
            {
                cout << "\nAccount Not Found.\n";
            }

            break;
        }

        case 4:
        {
            int accNo;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            BankAccount temp;

            if (BankAccount::searchAccount(accNo, temp))
            {
                cout << "\n===== ACCOUNT DETAILS =====\n";
                temp.showAccount();
            }
            else
            {
                cout << "\nAccount Not Found.\n";
            }

            break;
        }

        case 5:
        {
            BankAccount::displayAllAccounts();
            break;
        }

        case 6:
        {
            cout << "\nThank You for Using the System.\n";
            break;
        }

        default:
        {
            cout << "\nInvalid Choice.\n";
        }
        }

    } while (choice != 6);

    return 0;
}