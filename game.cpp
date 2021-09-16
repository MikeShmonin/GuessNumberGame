#include <iostream> 
#include <stdlib.h> 
#include <time.h> 
#include <string>


using namespace std; 

int RandomNumber(int x, int y) { 
srand(time(NULL)); 
int num = x + rand() % (y - x + 1); 
return num; 
} 

int main() 
{ 
string ans;
cout << "Привет это игра угадай число ^__^ " << endl;
system("read");
do {
    
    int CHISLO, lvl, count=0, n_count=0; 
    cout << "Выбери сложность: " << endl;
    cout << "1 - easy; 2 - medium, 3 - hard: "; 
    cin >> lvl; 
    switch (lvl) { 
        case 1: {CHISLO = RandomNumber(0, 100); count = 7; cout << "Отлично ты выбрал сложность 1. Диапазон чисел который я использую составит (0; 100)" << endl; break;}
        case 2: {CHISLO = RandomNumber(100, 1000); count = 10; cout << "Отлично ты выбрал сложность 2. Диапазон чисел который я использую составит (100; 1000)" << endl; break;}
        case 3: {CHISLO = RandomNumber(1000, 5000); count = 13; cout << "Отлично ты выбрал сложность 3. Диапазон чисел который я использую составит (1000; 5000))" << endl; break;}
    } 
    n_count=count-1;

    cout << "Я загадал число, давай начнем." << endl;
    system("read");
    cout << "Ты можешь задать мне вопрос следующим образом: " << endl;
    cout << "Искомое число x больше/меньше/равно выбранного тобою числа y? (x </>/= y?) " << endl;
    system("read");
    
    for (int i=0; i<count; i++) {
        cout << "Задавай вопрос тут: ";
        string input;
        int number = 0;
        cin >> input;

        for(int j = 0; j < input.length(); j++)
        {
            if (isdigit(input[j]))
            {
                int digit = (int)input[j] - (int)'0';
                number = number*10 + digit;
            }
        }
        

        if (CHISLO > number) {cout << "X больше " << number << endl;}
        if (CHISLO < number) {cout << "X меньше " << number << endl;}
        if (CHISLO == number) {break;}

        cout << "У тебя осталось " << n_count-- << " попыток" << endl;
        
        

    }
    if (n_count==-1)
    {
        cout << "Ты проиграл! Попытки закончились, загаданное число: " << CHISLO << endl; 
    
    }
    if (n_count!=-1)
    {
        cout << "Ты выиграл, загаданное число: " << CHISLO << endl; 
    }
    
    cout << "Игра закончилась! Хочешь продолжить?" << endl;
    cin >> ans;

} while (ans=="да");

return 0;

}