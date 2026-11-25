#include <iostream>
#include <cstring>
using namespace std;

bool Find(char str[], int i);
void Change(char str[], int i);

#ifndef UNIT_TEST
int main(){
    char str[101];
    cout << "Введіть рядок (не більше 100 символів): ";

    cin.getline(str, 101);

    if(Find(str, 0) == true){
        cout << "*** знайдені" << endl;
    }else{
        cout << "*** НЕ знайдені" << endl;
    }

    Change(str, 0);

    cout << "Рядок після зміни: " << str << endl;

    return 0;
}
#endif

bool Find(char str[], int i){
    if(str[i] == '\0'){
        return false;
    }

    if(str[i] == '*' && str[i+1] == '*' && str[i+2] == '*'){
        return true;
    }

    return Find(str, i + 1);
}
void Change(char str[], int i){
    if(str[i] == '\0' || str[i + 1] == '\0' || str[i + 2] == '\0'){
        return;
    }

    if(str[i] == '*' && str[i+1] == '*' && str[i+2] == '*'){
        str[i] = '!';
        str[i+1] = '!';
        for(int j = i + 2; j < strlen(str); j++){
            str[j] = str[j + 1];
        }
        Change(str, i);
    }
    else{
        Change(str, i + 1);
    }
}