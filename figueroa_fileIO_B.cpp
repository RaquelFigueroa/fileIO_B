//Name:Raquel Figueroa
//Date:22 October 2015
//Description: figueroa_fileIO_B.cpp

#include <iostream>//cin, cout
#include <fstream>//ofstream, ifstream
#include <cstdlib>//exit()
#include <iomanip>//setw()
using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    char fileName[12];
    string firstName, lastName, val, winnerFirst, winnerLast;
    double score, sum(0), average, highScore(0);
    int counter(0);

    cout << "Enter the file name you would like to open: ";
    cin >> fileName;

    fin.open(fileName);
    if (fin.fail())
    {
        cout << "Your specified file does not exist." << endl;
        exit(1);
    }
    
    fout.open("results.txt");
    if (fout.fail())
    {
        cout << "Your output file failed to open." << endl;
        exit(1);
    }
    
    for (int i = 0; i < 5; i++)
    {
        counter = 0;
        sum = 0;
        fin >> firstName >> lastName;
        {
            fout.setf(ios::fixed);
            fout.setf(ios::showpoint);
            fout.precision(1);
            fout.setf(ios::left);
            
            fout << setw(12) << firstName << setw(12) << lastName;
            
            for (int i = 0; i < 6; i++)
            {

                fin >> score;
                sum += score;
                if (i != 5)
                   fout << setw(6) << score;
                else
                    fout << setw(7) << setprecision(2) << score;
                counter++;
            }
            average = sum / counter;
            
            fout << setw(10) << "Average:" << setw(6) << average << endl;
            
            if (average > highScore)
            {
                highScore = average;
                winnerFirst = firstName;
                winnerLast = lastName;
            }
            
        }

    }
    
    fout << "\n";
    fout << "Highest score: " << winnerFirst << " " << winnerLast << endl;

    fin.close();

    return 0;
}
