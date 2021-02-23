//TASK 2


#include <iostream>
#include <chrono>
#include <thread>
using namespace std;



static void createEmtyBar(char progressBar[], const unsigned int barBreakpoints, const char leftEnd, const char rightEnd, const char emptySymbol){
    progressBar[0]=leftEnd;
    progressBar[barBreakpoints-1]=rightEnd;
    for(int i=1;i<barBreakpoints-1;i++){
        progressBar[i]=emptySymbol;
    }
}

static void printBar(char progressBar[], const unsigned int barBreakpoints, const bool showPercentage, const double progress){
    for(int i=0;i<(barBreakpoints)/2;i++){
        cout << progressBar[i];
    }
    if (showPercentage){
        cout << progress*100 << '%';
    }
    for(int i=(barBreakpoints)/2;i<barBreakpoints;i++){
        cout << progressBar[i];
    }
}

static int min(const int a, const int b){
    return a > b ? a : b;
}

static void fillBarToProgress(char progressBar[], const double progress, const unsigned int barBreakpoints, const char fillSymbol){
    double fillTo = barBreakpoints * progress;
    for(int i=1; i<fillTo; i++){
        if (i<barBreakpoints-1){
            progressBar[i] = fillSymbol;
        }
    }
}



// 20ms sleep max
// 10 breakpoints min
// 100 breakpoints max

static unsigned int sleep_for(const unsigned int time, const unsigned int barBreakpoints){
    return min(time*1000/barBreakpoints,20);
}


static unsigned int add_to_progress(const unsigned int time, const unsigned int barBreakpoints){

}



void ProgressBar(int time, double progress=0, const char leftEnd='[', const char rightEnd=']', const bool showPercentage=1, const char fillSymbol='=', const char emptySymbol=' '){
unsigned barBreakpoints = min((time*10), 100);
    char progressBar[barBreakpoints];
    createEmtyBar(progressBar,barBreakpoints,leftEnd,rightEnd,emptySymbol);
    while(progress<=1.01){
        fillBarToProgress(progressBar,progress,barBreakpoints,fillSymbol);
        printBar(progressBar,barBreakpoints,showPercentage,progress);
        progress+=(1.0/barBreakpoints);    
        cout << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(sleep_for(time,barBreakpoints)));
    }

}



int main(){
    int time;
    cin >> time;
    ProgressBar(time);
    return 0;
}