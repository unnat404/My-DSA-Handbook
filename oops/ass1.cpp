#include <iostream>
using namespace std;
 
class Stopwatch
{
    int hrs, mins;
    static int ct;
 
public:
    void setTime()
    {
        cout << "Enter the value in hrs (0-12) of Stopwatch " << ct + 1 << ".\n";
        int x, y;
        cin >> x;
        while (x < 0 || x > 12)
        {
            cout << "Hour value out of range !\n";
            cout << "Hours must lie in the range 0 to 12.Enter the value of hrs again.\n";
            cin >> x;
        }
        cout << "Enter the value in mins (0-60) of Stopwatch " << ct + 1 << ".\n";
        cin >> y;
        while (y < 0 || y > 60)
        {
            cout << "Minutes value out of range !\n";
            cout << "Minutes must lie in the range 0 to 60.Enter the value of minutes again.\n";
            cin >> y;
        }
        hrs = x;
        mins = y;
        ct++;
    }
    int getHours()
    {
        return hrs;
    }
    int getMinutes()
    {
        return mins;
    }
    void operator++()
    {
 
        ++mins;
        mins %= 60;
        if (mins == 0)
        {
            ++hrs;
            hrs %= 12;
        }
    }
    void operator--()
    {
 
        --mins;
        mins += 60;
        mins %= 60;
        if (mins == 59)
        {
            --hrs;
            hrs += 12;
            hrs %= 12;
        }
    }
    void display()
    {
        cout << "Stopwatch " << ct << " HH : MM = ";
        (hrs < 10) ? cout << 0 << hrs : cout << hrs;
        cout << " : ";
        (mins < 10) ? cout << 0 << mins : cout << mins;
        cout << '\n';
    }
    static void getCount()
    {
        cout << "The value of count is " << ct + 1 << "\n";
    }
};
 
int Stopwatch::ct;
 
int main()
{
    Stopwatch a, b;
 
    // Set time for stopwatch a
    a.setTime();
 
    //  Incrementing stopwatch a for 65 mins
 
    a.display();
    for (int i = 0; i < 65; i++)
    {
        ++a;
        a.display();
    }
    cout << "\n";
 
    // Decrementing stopwatch b for 70 mins.
 
    // set time for stopwatch b
 
    b.setTime();
    b.display();
    for (int i = 0; i < 70; i++)
    {
        --b;
        b.display();
    }
 
    return 0;
}