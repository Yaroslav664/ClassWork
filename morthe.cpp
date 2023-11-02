#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class MorseCodeConverter {
private:
    const char letters[26];
    const string codes[36];

public:
    MorseCodeConverter() : letters{
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
        'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
    }, codes{
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
        "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
        "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."
    } {}

    string textToMorse(const string& text) {
        string morseCode = "";
        for (char c : text) {
            if (c == ' ') {
                morseCode += " ";
            }
            else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
                char upperC = (c >= 'a' && c <= 'z') ? c - 32 : c;
                int index = upperC - 'A';
                if ((upperC >= 'A' && upperC <= 'Z') && index >= 0 && index < 26) {
                    morseCode += codes[index] + " ";
                }
                else if (c >= '0' and c <= '9') {
                    int numIndex = c - '0' + 26;
                    morseCode += codes[numIndex] + " ";
                }
            }
        }
        return morseCode;
    }

    string morseToText(const string& morseCode) {
        string text = "";
        string currentSymbol = "";
        for (char c : morseCode) {
            if (c == ' ') {
                if (!currentSymbol.empty()) {
                    for (int i = 0; i < 36; ++i) {
                        if (currentSymbol == codes[i]) {
                            if (i < 26) {
                                text += letters[i];
                            }
                            else {
                                text += to_string(i - 26);
                            }
                            break;
                        }
                    }
                    currentSymbol = "";
                }
                else {
                    text += " ";
                }
            }
            else {
                currentSymbol += c;
            }
        }
        if (!currentSymbol.empty()) {
            for (int i = 0; i < 36; ++i) {
                if (currentSymbol == codes[i]) {
                    if (i < 26) {
                        text += letters[i];
                    }
                    else {
                        text += to_string(i - 26);
                    }
                    break;
                }
            }
        }
        return text;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    MorseCodeConverter converter;

    string input;
    cout << "Введите текст или код Морзе: ";
    cin >> input;

    if (input[0] == '.' || input[0] == '-') {
        string text = converter.morseToText(input);
        cout << "Дешифрованный текст: " << text << endl;
    }
    else {
        string morseCode = converter.textToMorse(input);
        cout << "Закодированный текст Морзе: " << morseCode << endl;
    }
}
