#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int acc_no[100];
int total_acc;
string user_acc_no;
string read_data_file;
int user_data_index = 1000;
class get_data
{
public:
    void get_data_acc_no()
    {
        total_acc = 0;
        string myText;

        ifstream MyReadFile("accountno.txt");

        while (getline(MyReadFile, myText))
        {
            acc_no[total_acc] = stoi(myText);
            // cout << acc_no[total_acc];
            total_acc++;
        }
        total_acc--;
        MyReadFile.close();
    }
};
class get_input : public get_data
{
public:
    string user_data[1000];
    int user_data_line;
    int new_acc_no;
    int check_acc_choice;
    int age;
    float amount;
    string s_acc_no;
    string fname, phno, lname;
    void check_acc()
    {
        cout << "1. Open new account\n2. Already have account\n";
        cout << "Enter your choice : ";
        cin >> check_acc_choice;

        switch (check_acc_choice)
        {
        case 1:
            new_acc();
            data_put();
            // read_data_new();
            break;

        case 2:
            user_acc();
            // read_data();
            break;

        default:
            cout << "Plese enter valid input\n";
            check_acc();
            break;
        }
    }
    void new_acc()
    {
        new_acc_no = acc_no[total_acc] + 1;
        ofstream of;
        fstream f;

        of.open("accountno.txt", ios::app);
        if (!of)
            cout << "No such file found";
        else
        {
            of << "\n"
               << new_acc_no;
            // cout << "Data appended successfully\n";
            of.close();
            string word;
        }
        cout << "Enter your first name : ";
        cin >> fname;
        cout << "Enter last name : ";
        cin >> lname;
        cout << "Enter your age : ";
        cin >> age;
        if (age <= 0 || age > 101)
        {
            while (1)
            {
                if (age <= 0 || age > 100)
                {
                    cout << "-------------\n";
                    cout << "INVALID AGE!!\n";
                    cout << "-------------\n";
                    cout << "Enter valid age : ";
                    cin >> age;
                }
                else
                {
                    break;
                }
            }
        }
        cout << "Enter your phone no. : ";
        cin >> phno;
        if (phno.length() != 10)
        {
            while (1)
            {
                if (phno.length() != 10)
                {
                    cout << "-------------\n";
                    cout << "INVALID PHONE NO.!!\n";
                    cout << "-------------\n";
                    cout << "Enter valid phone no. : ";
                    cin >> phno;
                }
                else
                {
                    break;
                }
            }
        }
    }
    void data_put()
    {
        amount = 0.00;
        s_acc_no = "/Users/jaydeepahir/Documents/Study/Projects/Bank/Account Data/" + to_string(new_acc_no) + ".txt";
        ofstream MyFile1(s_acc_no);
        MyFile1 << fname << "\n"
                << lname << "\n"
                << age << "\n"
                << phno << "\n"
                << amount << "\n";
        MyFile1.close();
        user_acc_no = to_string(new_acc_no);
        // cout << user_acc_no;
    }
    void user_acc()
    {
        int i = 0, flag = 0;
        string temp_user_acc;
        cout << "Enter your account no : 180801";
        cin >> user_acc_no;
        user_acc_no = "180801" + user_acc_no;
        // cout << user_acc_no << endl << total_acc << endl;
        while (i <= total_acc)
        {
            // cout << acc_no[i] << endl;
            if (user_acc_no != to_string(acc_no[i]))
            {
                flag = 1;
            }
            else
            {
                flag = 0;
                break;
            }
            i++;
        }
        if (flag == 1)
        {
            cout << "--------------------\n";
            cout << "INVALID ACC NO.!!!!\n";
            cout << "--------------------\n";
            user_acc();
        }
    }
    void read_data()
    {
        string myText2;
        user_data_line = 0;
        // string read_data_file;
        read_data_file = "/Users/jaydeepahir/Documents/Study/Projects/Bank/Account Data/" + user_acc_no + ".txt";
        ifstream MyReadFile1(read_data_file);

        while (getline(MyReadFile1, myText2))
        {
            user_data[user_data_line] = myText2;
            user_data_line++;
        }
        MyReadFile1.close();
        amount = stoi(user_data[4]);
    }
    // void read_data_new()
    // {
    //     string myText2;
    //     user_data_line = 0;
    //     string read_data_file;
    //     read_data_file = "/Users/jaydeepahir/Documents/Study/Projects/Bank/Account Data/" + to_string(new_acc_no) + ".txt";
    //     ifstream MyReadFile1(read_data_file);

    //     while (getline(MyReadFile1, myText2))
    //     {
    //         user_data[user_data_line] = myText2;
    //         user_data_line++;
    //     }
    //     MyReadFile1.close();
    //     amount = stoi(user_data[4]);
    // }
};
class transaction : public get_input
{
    int transaction_choice;
    int deposit_amount;
    int i;
    int withdraw_amount;
    // string user_data[1000];
    // int user_data_line;
public:
    void user_choice()
    {
        while (1)
        {
            cout << "\n1. DEPOSIT\n2. WITHDRAWAL\n3. CHECK BALANCE\n4. MINISATEMENT\n";
            cout << "Enter your choice : ";
            cin >> transaction_choice;
            cout << endl;
            switch (transaction_choice)
            {
            case 1:
                deposit();
                deposit_data_put();
                break;

            case 2:
                withdraw();
                withdraw_data_put();
                break;

            case 3:
                check_balance();
                break;

            case 4:
                mini_statement();
                break;

            case 5:
                exit(0);

            default:
                cout << "ENTER VALID INPUT";
                user_choice();
                break;
            }
        }
    }
    // void read_data()
    // {
    //     string myText2;
    //     user_data_line = 0;
    //     string read_data_file;
    //     read_data_file = "/Users/jaydeepahir/Documents/Study/Projects/Bank/Account Data/180801" + user_acc_no + ".txt";
    //     ifstream MyReadFile1(read_data_file);

    //     while (getline(MyReadFile1, myText2))
    //     {
    //         user_data[user_data_line] = myText2;
    //         user_data_line++;
    //     }
    //     MyReadFile1.close();
    //     amount = stoi(user_data[4]);
    // }
    void deposit()
    {
        cout << "Enter amount to deposit : ";
        cin >> deposit_amount;
        amount = amount + deposit_amount;
        // cout << amount << endl;
    }
    void deposit_data_put()
    {
        i = 0;
        int temp1, temp2, p1 = 5, p2 = 6;
        temp1 = user_data_line - 1;
        while (temp1 >= p1)
        {
            user_data[temp1 + 1] = user_data[temp1];
            temp1--;
        }
        user_data_line++;
        user_data[p1] = "DEPOSIT";
        temp2 = user_data_line - 1;
        while (temp2 >= p2)
        {
            user_data[temp2 + 1] = user_data[temp2];
            temp2--;
        }
        user_data_line++;
        user_data[p2] = "   " + to_string(deposit_amount);
        user_data[4] = to_string(amount);
        // user_data[user_data_line] = "deposit";
        // user_data[user_data_line + 1] = to_string(deposit_amount);
        ofstream MyFile2(read_data_file);
        while (i < user_data_line + 2)
        {
            MyFile2 << user_data[i] << "\n";
            i++;
        }

        MyFile2.close();
        cout << "\n------------------------\n";
        cout << "Your amount is DIPOSITED !!!";
        cout << "\n------------------------\n\n";
    }
    void withdraw()
    {
        // cout << amount << endl;
        cout << "Enter amount to withdraw : ";
        cin >> withdraw_amount;
        if (withdraw_amount > amount)
        {
            cout << "----------------------\n";
            cout << "You have not suficient balance!!!\n";
            cout << "----------------------\n";
            withdraw();
        }
        amount = amount - withdraw_amount;
        // cout << amount << endl;
    }
    void withdraw_data_put()
    {
        i = 0;
        int temp1, temp2, p1 = 5, p2 = 6;
        temp1 = user_data_line - 1;
        while (temp1 >= p1)
        {
            user_data[temp1 + 1] = user_data[temp1];
            temp1--;
        }
        user_data_line++;
        user_data[p1] = "WIHTDRAW";
        temp2 = user_data_line - 1;
        while (temp2 >= p2)
        {
            user_data[temp2 + 1] = user_data[temp2];
            temp2--;
        }
        user_data_line++;
        user_data[p2] = "   " + to_string(withdraw_amount);
        user_data[4] = to_string(amount);
        // user_data[user_data_line] = "WITHDRAW";
        // user_data[user_data_line + 1] = to_string(withdraw_amount);
        ofstream MyFile3(read_data_file);
        while (i < user_data_line)
        {
            MyFile3 << user_data[i] << "\n";
            i++;
        }

        MyFile3.close();
        cout << "\n------------------------\n";
        cout << "Your amount is WITHDRAWED !!!";
        cout << "\n------------------------\n\n";
    }
    void check_balance()
    {
        cout << "------------------------------\n";
        cout << "BALANCE : " << to_string(amount);
        cout << "\n------------------------------\n\n";
    }
    void mini_statement()
    {
        int i = 5, j = 0;
        cout << "\n-------------------------\n";
        cout << "ACCOUNT NO.         : " << user_acc_no << endl;
        cout << "ACCOUNT HOLDER NAME : " << user_data[0] + " " + user_data[1] << endl;
        cout << "AGE                 : " << user_data[2] << endl;
        cout << "PHONE NO.           : " << user_data[3] << endl;
        cout << "BALANCE             : " << user_data[4] << endl;
        cout << "-------------------------\n";
        cout << "LAST FIVE TRANSACTION" << endl;
        while (i < user_data_line)
        {
            cout << user_data[i] << endl;
            i++;
            j++;
            if (j > 11)
            {
                break;
            }
        }
        cout << "-------------------------\n";
    }
};
int main()
{
    get_data g1;
    get_input g2;
    transaction t1;
    g1.get_data_acc_no();
    g2.check_acc();
    t1.read_data();
    t1.user_choice();
    return 0;
}