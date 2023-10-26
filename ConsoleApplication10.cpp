#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

string question[9] = { "Який фрукт є символом Ньютона?",
    "Який фрукт має червоний і жовтий різновид і використовується в салатах?",
    "Який фрукт вирощується на пальмі і використовується для виробництва олії?",
    "Який фрукт зазвичай використовується для приготування апельсинового соку?",
    "Який фрукт дуже кислий і використовується для приготування лимонаду?",
    "Який фрукт зазвичай використовується для приготування гуакамоле?",
    "Який фрукт є символом тропіків і часто зображується на обкладинках журналів?",
    "Який фрукт має тверду кірку і соковите рожеве м'ясо з чорним насінням усередині?",
    "Який фрукт, що має гострий смак, часто використовується в суші та японській кухні?" };
string answer[9] = { "Яблуко", "Персик", "Кокос", "Апельсин", "Лимон", "Авокадо", "Пальма", "Гранат", "Імбір" };

class Tables {
private:
    string question[9];
    string answer[9];
    int currentQuestionIndex;
public:
    Tables(string question[], string answer[]) {
        for (int i = 0; i < 9; i++) {
            this->question[i] = question[i];
            this->answer[i] = answer[i];
        }
        currentQuestionIndex = 0;
    }

    bool askQuestion() {
        if (currentQuestionIndex < 9) {
            cout << "Питання " << (currentQuestionIndex + 1) << ": " << question[currentQuestionIndex] << endl;
            string userAnswer;
            cout << "Ваша відповідь: ";
            getline(cin, userAnswer);

            if (userAnswer == answer[currentQuestionIndex]) {
                cout << "Правильно!" << endl;
            }
            else {
                cout << "Неправильно. Правильна відповідь: " << answer[currentQuestionIndex] << endl;
            }

            currentQuestionIndex++;
            return true;
        }
        else {
            cout << "Гра закінчена. Ви відповіли на всі питання." << endl;
            return false;
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Tables game{ question, answer };

    while (game.askQuestion()) {
        
    }
}
