// Gematria Prime Vigenere Decipherer
// Version 1.1 Version March 17, 2021. 
// This program was made by Angelo Fiore. email: beautifulevilflower@gmail.com

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

string Rune(int input) { //the "runic" character for each value is printed in output
    switch (input) {      //to make cypher words more easy to discover
    case 0:               //by making the juxtapostion of the runes used more conveniently accessible
        return "F";
        break;
    case 1:
        return "U";
        break;
    case 2:
        return "TH";
        break;
    case 3:
        return "O";
        break;
    case 4:
        return "R";
        break;
    case 5:
        return "C";
        break;
    case 6:
        return "G";
        break;
    case 7:
        return "W";
        break;
    case 8:
        return "H";
        break;
    case 9:
        return "N";
        break;
    case 10:
        return "I";
        break;
    case 11:
        return "J";
        break;
    case 12:
        return "EO";
        break;
    case 13:
        return "P";
        break;
    case 14:
        return "X";
        break;
    case 15:
        return "S";
        break;
    case 16:
        return "T";
        break;
    case 17:
        return "B";
        break;
    case 18:
        return "E";
        break;
    case 19:
        return "M";
        break;
    case 20:
        return "L";
        break;
    case 21:
        return "NG";
        break;
    case 22:
        return "OE";
        break;
    case 23:
        return "D";
        break;
    case 24:
        return "A";
        break;
    case 25:
        return "AE";
        break;
    case 26:
        return "Y";
        break;
    case 27:
        return "IA";
        break;
    case 28:
        return "EA";
        break;
    default:
        return "Error: Out of Range";
    }
}


int main()
{
    string error_message("Your entry is invalid.  Please enter a value between 0 and 28.\nYour Input:");
    string raw_input(""); //the input is a string to make easier error handling for nonnumerical inputs
    int input_value(0); //converted value of input string to an int, so that input can be manipulated mathematically
    bool is_valid(0); //equals zero if input is not a number between 0 and 28

    cout << "Gematria Prime Vigenere Decipherer\nVersion 1 Release Version March 16, 2021.\nThis program was made by Angelo Fiore. email: beautifulevilflower@gmail.com" << endl
        << "This is a calculator for Vigenere cipher values of the Gemtria Prime\nEnter a rune\'s value from 0 to 28, then press \"enter\".\n\nYour Input:";

    for (;;) {
        //this loop ensures input is valid (a value between 0 & 28)
        //currently, this program cannot deduce values from input outside this range
        while (!is_valid) {
            cin >> raw_input;
            try { 
                input_value = stoi(raw_input);
                //this conditional ensures that calculations are only made for a value corresponding to a "rune" in the "Gematria Prime" cipher
                //the intention is to reduce the likelihood of a miscalculation based on a typo
                if ((0 <= input_value && input_value <= 28)) { is_valid = 1; }
                else { cout << error_message << flush; }
            }
            catch (const invalid_argument& ia) {
                cout << error_message << flush ;
            }
        }
        is_valid = 0; //resetting is_valid to allow the while loop to repeat next time
        
        //calculations are made by iteration
        //for each iteration a given value between 0 and 28 is simultaneously added and subtracted from the value of the input
        //the values of each iteration's addition & subtraction are printed side by side
        //allowing one to more easily compare and navigate values
        for (int i = 0; i < 29; i++) {
            int buffer_sum(0);
            int buffer_reduce(0);
            buffer_sum = input_value + i;
            if (buffer_sum > 28) {
                buffer_sum -= 28;
            }
            buffer_reduce = input_value - i;
            if (buffer_reduce < 0) {
                buffer_reduce += 28;
            }
            cout << setw(raw_input.length() + 1) << raw_input << " (is" << setw(3) << Rune(input_value) << ")"
                << " +" << setw(3) << i << " (is" << setw(3) << Rune(i) << ")"
                << " =" << setw(3) << buffer_sum << " (is" << setw(3) << Rune(buffer_sum) << ")" << " ||"
                << setw(raw_input.length() + 1) << raw_input << " (is" << setw(3) << Rune(input_value) << ")"
                << " -" << setw(3) << i << " (is" << setw(3) << Rune(i) << ")"
                << " =" << setw(3) << buffer_reduce << " (is" << setw(3) << Rune(buffer_reduce) << ")" << "\n";
        }
        cout << "\n" << "Your Input:" << flush;
        input_value = 0; //resetting input_value prevents an infinite loop
                         //which happens if input_value retains a valid value
                         //causing the same output to repeat itself automatically
    }
}