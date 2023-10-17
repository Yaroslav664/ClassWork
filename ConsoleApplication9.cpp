#include <iostream>
#include <ctime>
using namespace std;

class Figure {
protected:
    char* line;
    char** box;
public:
    string type;
    char symbol;

    Figure(string type, char symbol) {
        this->symbol = symbol;
        if (type == "line") {
            this->type = type;
            this->line = new char[4];
            for (int i = 0; i < 4; i++) {
                this->line[i] = this->symbol;
            }
            delete[] box;
        }
        else if (type == "box") {
            this->type = type;
            this->box = new char* [2];
            for (int i = 0; i < 2; i++) {
                this->box[i] = new char[2];
                for (int j = 0; j < 2; j++) {
                    this->box[i][j] = symbol;
                }
            }
            delete[] line;
        }
        else {
            this->type = "error";
        }
    }
};

class Field {
public:
    char** array = new char* [10];

    Field() {
        for (int i = 0; i < 10; i++) {
            this->array[i] = new char[10];
            for (int j = 0; j < 10; j++) {
                this->array[i][j] = ' ';
            }
        }
    }

    void addFigure(Figure figure) {
        int x = rand() % 10;
        int y = 0;  // Start from the top
        bool write = false;

        if (this->array[x][y] == ' ') {
            if (figure.type == "line") {
                if (x < 7) {
                    for (int i = x; i < x + 4; i++) {
                        if (this->array[i][y] == ' ') {
                            write = true;
                        }
                        else {
                            write = false;
                            break;
                        }
                    }
                    if (write) {
                        for (int i = x; i < x + 4; i++) {
                            this->array[i][y] = figure.symbol;
                        }
                    }
                }
            }
            else if (figure.type == "box") {
                if (x < 9) {
                    if (this->array[x][y] == ' ' && this->array[x + 1][y] == ' ' &&
                        this->array[x][y + 1] == ' ' && this->array[x + 1][y + 1] == ' ') {
                        this->array[x][y] = figure.symbol;
                        this->array[x + 1][y] = figure.symbol;
                        this->array[x][y + 1] = figure.symbol;
                        this->array[x + 1][y + 1] = figure.symbol;
                    }
                }
            }
        }
    }

    void showField() {
        for (int i = 0; i < 30; i++) {
            cout << '-';
        }
        cout << endl;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                cout << '|' << array[i][j] << '|';
            }
            cout << endl;
        }
        for (int i = 0; i < 30; i++) {
            cout << '-';
        }
    }
};

int main() {
    srand(time(NULL));
    Field game;
    Figure line{ "line", 'c' };
    Figure box{ "box", 's' };
    game.showField();
    game.addFigure(line);
    game.addFigure(box);
    cout << endl;
    game.showField();
}
