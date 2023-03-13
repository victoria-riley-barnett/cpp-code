#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
        const int OPTIONS = 3;
        string names[OPTIONS] = {"Carnitas", "Pollo", "Veggie"};
        float prices[OPTIONS] = {6.95, 6.25, 5.95};
        string *sptr;
        float *fptr;

        sptr = names;
        for (int i=0; i<OPTIONS; i++)
        {
                string type = *(names+i);
                type = type + " Especial";
                *(sptr+i) = type;
        }

        fptr = prices;
        for (int i=0; i<OPTIONS; i++)
        {
                float type = *(prices+i);
                type = type + 2.00;
                *(fptr+i) = type;
        }

        cout << "Menu:" << endl;
        for (int i=0; i<OPTIONS; i++)
        {
                cout << i+1 << ". ";
                cout << *(sptr+i);
                cout << " - ";
                cout << *(fptr+i) << endl;
        }
        return 0;
}