#include <iostream>
#include <string>
using namespace std;

void displayPigLatin(char *);

int main() 
{
    string input;
    getline(cin, input);
    char *cstr, *p;
    cstr = new char[input.size() + 1];
    strcpy(cstr, input.c_str());
    p = strtok(cstr, " ");
    cout << "\n\nEnglish: " << input << endl;
    cout << "Pig Latin: ";
    while (p != NULL)
    {
          displayPigLatin(p);
          p = strtok(NULL, " ");
    }
    cout << "\n\n";
    system("pause");
    return 0;
}

void displayPigLatin(char *p)
{
     char temp[strlen(p) + 1];
     strcpy(temp, p);
     string str;
     for(int i = 0 ; i < strlen(p); i++)
     {
         if (i == strlen(p) - 1)
             str = str + temp[0] + "ay";
         else
             str += temp[i+1];
     }
     cout << str << " ";
}
