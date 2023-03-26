//Study questions: Victoria Barnett
#include <iostream>
#include <iomanip>
#include <unistd.h>

using namespace std;

void timer(int num){
    int minutes = num;
    int seconds = 0;
    int totalSeconds = num * 60;
    
    for(int i = totalSeconds; i > 0; --i){
        cout << minutes << ":" << seconds << endl;
        if (seconds == 0){
            seconds += 60;
            minutes--;
        }
        seconds--;
        sleep(1);
    }
}
