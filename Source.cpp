#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
    string target;
    string searchTerm;
    int runMode = 0;

    // Tarkistetaan käytetäänkö ohjelmaa manuaalisesti vai hakutermin ja tiedostonimen avulla
    if (argc == 3)
    {
        searchTerm = argv[1];  // 2.argumentti eli hakutermi
        target = argv[2];  // 3.argumentti eli tiedostonimi josta termiä haetaan
        runMode = 1;
    }

    else 
    // Jos haku- ja tiedostonimiargumenttaja ei anneta, ajetaan softa ns. manuaalirunModessa
    {
        cout << "Give a string from which to search from: ";
        getline(cin, target);

        cout << "Give search string: ";
        getline(cin, searchTerm);
    }

    if (runMode == 1)
    //Jos ohjelma on käynnistetty tarvittavien argumenttien kanssa, suoritetaan annetun termin haku annetusta tiedostosta
    {
        ifstream file(target);

        //Jos tiedosto ei jostain syystä aukea, annetaan error-viesti
        if (!file) {
            cout << "Error: could not open file \"" << target << "\"" << endl;
            return 1;
        }

        //Suoritetaan itse haku
        size_t pos = 0;
        int lineNum = 1;
        string line;
        while (getline(file, line)) {
            pos = line.find(searchTerm);
            if (pos != string::npos) {
                cout << "Found \"" << searchTerm << "\" in \"" << line << "\" at position " << pos << " on line " << lineNum << endl;
            }
            lineNum++;
        }

        file.close();
    }

    else

    //Jos softaa ajetaan "manuaalisesti", suoritetaan termin haku annetusta stringistä
    {
        size_t position = target.find(searchTerm);
        if (position != string::npos) {
            cout << "\"" << searchTerm << "\" found in \"" << target << "\" at position " << position << endl;
        }
        else {
            cout << "\"" << searchTerm << "\" NOT found in \"" << target << "\"" << endl;
        }
    }

    return 0;
}
