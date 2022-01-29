#include <iostream>
#include <cstring>
#include <malloc.h>
using namespace std;
 
struct MobileComp
{
    long PartNumber;
    char PartName[40];
    double UnitPrice;
    MobileComp *Next;
};
 
class Mobile
{
 
    int size;
    MobileComp *Head;
 
public:
    Mobile()
    {
        size = 0;
        Head = NULL;
    }
    int getSize()
    {
        return size;
    }
    void Add(MobileComp *Item)
    {
        MobileComp *temp = Head;
        if (temp == NULL)
        {
            Head = Item;
            return;
        }
        while (temp->Next != NULL)
        {
            temp = temp->Next;
        }
        temp->Next = Item;
        size++;
    }
    MobileComp *Retrieve(int pos)
    {
        MobileComp *temp = Head;
        if (pos + 1 > size)
        {
            cout << "Invalid position \n";
            return NULL;
        }
        else
        {
            int ct = 0;
            while (ct != pos)
            {
                temp = temp->Next;
                ct++;
            }
            return temp;
        }
    }
    bool checkEqualStrings(char *p, char *q)
    {
        int sz1 = strlen(p);
        int sz2 = strlen(q);
        if (sz1 != sz2)
            return false;
        int i = 0;
        int j = 0;
        while (i < sz1 && j < sz2)
        {
            if (p[i] != p[j])
                return false;
            i++;
            j++;
        }
        return true;
    }
    bool Find(MobileComp *item)
    {
        MobileComp *temp = Head;
        if (temp == NULL)
            return false;
        while (temp != NULL)
        {
 
            if (checkEqualStrings(temp->PartName, item->PartName) && temp->PartNumber == item->PartNumber && temp->UnitPrice == item->UnitPrice)
            {
                return true;
            }
            temp = temp->Next;
        }
        return false;
    }
    void displayComponentInfo(MobileComp *Item)
    {
        cout << "Part Name : " << Item->PartName << "\n"
             << "Part Number : " << Item->PartNumber << "\n"
             << "Unit Price : " << Item->UnitPrice << "\n\n";
    }
    void getDisplay()
    {
        MobileComp *temp = Head;
        if (temp == NULL)
        {
            cout << "No components to display.\n";
        }
        else
        {
            while (temp != NULL)
            {
                displayComponentInfo(temp);
                temp = temp->Next;
            }
        }
    }
};
 
int main()
{
    Mobile samsung;
    int noOfComponents;
    cout << "Enter the number of mobile components.\n";
    cin >> noOfComponents;
    MobileComp *mob = (MobileComp *)malloc(noOfComponents * sizeof(MobileComp));
    for (int i = 0; i < noOfComponents; i++)
    {
        cout << "Enter the Part Number , Part Name and Unit Price of component number " << i + 1 << ".\n";
        cin >> mob[i].PartNumber >> mob[i].PartName >> mob[i].UnitPrice;
    }
 
    for (int i = 0; i < noOfComponents; i++)
    {
        samsung.Add(mob + i);
    }
 
    cout << '\n';
    // Testing Add method
    samsung.getDisplay();
 
    // Testing Find method
 
    int noOfComps;
    cout << "Enter the number of mobile components you want to search for.\n";
    cin >> noOfComps;
    MobileComp *mobs = (MobileComp *)malloc(noOfComps * sizeof(MobileComp));
    for (int i = 0; i < noOfComps; i++)
    {
        cout << "Enter the Part Name , Part Number and Unit Price of component number " << i + 1 << ".\n";
        cin >> mobs[i].PartName >> mobs[i].PartNumber >> mobs[i].UnitPrice;
    }
    for (int i = 0; i < noOfComps; i++)
    {
        cout << "Component " << i + 1;
        samsung.Find(mobs + i) ? cout << " is present\n" : cout << " was not present\n";
    }
 
    return 0;
}