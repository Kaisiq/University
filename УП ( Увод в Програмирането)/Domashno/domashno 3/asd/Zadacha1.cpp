#include <iostream>
using namespace std;



int biggestNumberInUnsignedArrayIndex(unsigned int* arr, int length){
    int maxindex = 0;
    for(int i=1; i<length; i++){
        if(arr[maxindex] < arr[i]){
            maxindex = i;
        }
    }
    return maxindex;
}
    


int smallestNumberInUnsignedArray(unsigned int* arr, int length){
    int min = arr[0];
    for(int i=1; i<length; i++){
        if(min > arr[i]){
            min = arr[i];
        }
    }
    return min;
}


bool removeElementAtIndexUnsigned(unsigned int* arr, int index, int length){
    unsigned int* result = new(nothrow) unsigned int[length-1];
    if(!result){
        cout << "No Memory";
        return 0;
    }
    for(int i=0; i<index; i++){
        result[i] = arr[i];
    }
    for(int i=index; i<length-1; i++){
        result[i] = arr[i+1];
    }

    for(int i=0; i<length-1; i++){
        arr[i] = result[i];
    }

    delete[] result;
    return 1;
}


int biggestNumberInDoubleArrayIndex(double* arr, int length){
    int maxindex = 0;
    for(int i=1; i<length; i++){
        if(arr[maxindex] < arr[i]){
            maxindex = i;
        }
    }
    return maxindex;
}



bool removeElementAtIndexDouble(double* arr, int index, int length){
    double* result = new(nothrow) double[length-1];
    if(!result){
        cout << "No Memory";
        return 0;
    }
    for(int i=0; i<index; i++){
        result[i] = arr[i];
    }
    for(int i=index; i<length-1; i++){
        result[i] = arr[i+1];
    }

    for(int i=0; i<length-1; i++){
        arr[i] = result[i];
    }

    delete[] result;
    return 1;
}



bool removeFromAllArrays(int index, int length, unsigned int* indexes, unsigned int* minutes, unsigned int* points, double* weight){
    if (!removeElementAtIndexUnsigned(indexes, index, length)){
        delete[] indexes;
        delete[] minutes;
        delete[] points;
        delete[] weight;
        return 0;
    }
    if (!removeElementAtIndexUnsigned(minutes, index, length)){
        delete[] indexes;
        delete[] minutes;
        delete[] points;
        delete[] weight;
        return 0;
    }
    if (!removeElementAtIndexUnsigned(points, index, length)){
        delete[] indexes;
        delete[] minutes;
        delete[] points;
        delete[] weight;
        return 0;
    }
    if (!removeElementAtIndexDouble(weight, index, length)){
        delete[] indexes;
        delete[] minutes;
        delete[] points;
        delete[] weight;
        return 0;
    }
}





int main(){
    unsigned int tasksCount;
    cin >> tasksCount;
    unsigned int* indexes = new(nothrow) unsigned int[tasksCount];
    if(!indexes){
        cerr << "No Memory";
        return 1;
    }
    unsigned int* minutes = new(nothrow) unsigned int[tasksCount];
    if(!minutes){
        cerr << "No Memory";
        delete[] indexes;
        return 1;
    }
    unsigned int* points = new(nothrow) unsigned int[tasksCount];
    if(!points){
        cerr << "No Memory";
        delete[] indexes;
        delete[] minutes;
        return 1;
    }
    double* weight = new(nothrow) double[tasksCount];
    if(!weight){
        cerr << "No Memory";
        delete[] indexes;
        delete[] minutes;
        delete[] points;
        return 1;
    }

    for(int i=0; i<tasksCount; i++){
        cin >> indexes[i];
        cin >> minutes[i];
        cin >> points[i];
        weight[i] = (double)points[i] / (double)minutes[i];
    }

    unsigned int daysLeft;
    cin >> daysLeft;
    unsigned int minutesLeft = 0;
    int a;
    for(int i=0; i<daysLeft; i++){
        cin >> a;
        minutesLeft += a;
    }
    

    cout << "Tasks: ";
    while(tasksCount > 0){
        int mostPointsindex = biggestNumberInUnsignedArrayIndex(points, tasksCount);
        int mostWeightIndex = biggestNumberInDoubleArrayIndex(weight, tasksCount);
        if(minutesLeft >= minutes[mostWeightIndex]){
            unsigned int minutesWithoutMostWeightTask = minutesLeft - minutes[mostWeightIndex];
            if(smallestNumberInUnsignedArray(minutes,tasksCount) > minutesWithoutMostWeightTask){
                int sumMins=0;
                int sumPoints=0;
                int* indexesOfComb = new(nothrow) int[tasksCount];
                if(!indexesOfComb){
                    delete[] indexes;
                    delete[] minutes;
                    delete[] points;
                    delete[] weight;
                    return 1;
                }
                int j=0;
                for(int i=0; i<tasksCount; i++){
                    if(minutes[i]!=minutes[mostWeightIndex] && sumMins+minutes[i]<=minutesLeft){
                        sumMins += minutes[i];
                        sumPoints += points[i];
                        indexesOfComb[j] = i;
                        j++;
                    }
                }
                if(sumPoints > points[mostWeightIndex]){
                    minutesLeft -= sumMins;
                    for(int i=0; i<j; i++){
                        cout << indexes[indexesOfComb[i]] << ", ";
                        if (!removeElementAtIndexUnsigned(indexes, indexesOfComb[i], tasksCount)){
                            delete[] indexes;
                            delete[] minutes;
                            delete[] points;
                            delete[] weight;
                            return 1;
                        }
                        if (!removeElementAtIndexUnsigned(minutes, indexesOfComb[i], tasksCount)){
                            delete[] indexes;
                            delete[] minutes;
                            delete[] points;
                            delete[] weight;
                            return 1;
                        }
                        if (!removeElementAtIndexUnsigned(points, indexesOfComb[i], tasksCount)){
                            delete[] indexes;
                            delete[] minutes;
                            delete[] points;
                            delete[] weight;
                            return 1;
                        }
                        if (!removeElementAtIndexDouble(weight, indexesOfComb[i], tasksCount)){
                            delete[] indexes;
                            delete[] minutes;
                            delete[] points;
                            delete[] weight;
                            return 1;
                        }
                    }
                    delete[] indexesOfComb;
                }
                else{
                    minutesLeft -= minutes[mostWeightIndex];
                    cout << indexes[mostWeightIndex] << ", ";
                }
            }
            else{
                minutesLeft -= minutes[mostWeightIndex];
                cout << indexes[mostWeightIndex] << ", ";
            }
        }
        if (!removeElementAtIndexUnsigned(indexes, mostWeightIndex, tasksCount)){
            delete[] indexes;
            delete[] minutes;
            delete[] points;
            delete[] weight;
            return 1;
        }
        if (!removeElementAtIndexUnsigned(minutes, mostWeightIndex, tasksCount)){
            delete[] indexes;
            delete[] minutes;
            delete[] points;
            delete[] weight;
            return 1;
        }
        if (!removeElementAtIndexUnsigned(points, mostWeightIndex, tasksCount)){
            delete[] indexes;
            delete[] minutes;
            delete[] points;
            delete[] weight;
            return 1;
        }
        if (!removeElementAtIndexDouble(weight, mostWeightIndex, tasksCount)){
            delete[] indexes;
            delete[] minutes;
            delete[] points;
            delete[] weight;
            return 1;
        }

        tasksCount--;
    }
    cout << endl;
    cout << "Time remaining: " << minutesLeft/60 << ":" << minutesLeft - (minutesLeft/60)*60;

    delete[] indexes;
    delete[] minutes;
    delete[] points;
    delete[] weight;
    return 0;
}