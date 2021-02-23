//
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Увод в програмирането 2020/21
// Контролно 2
// 2021-01-17
//
// Начален час: 10:00
// Име: Даниел Даниел Иванов
// ФН: 45792
// Специалност: Информатика
// Курс: 1
// Административна група: 4
// Използван компилатор: GCC
//

#include <iostream>
#include <cstring>
using namespace std;



char* replaceWord(char* text, char* replacementWord, unsigned int& lenText, int wordtoreplacelen, int startindex){
    int replacementWordLen = 0;
    while(replacementWord[replacementWordLen]!=0){
        replacementWordLen++;
    }

    char* result = new(nothrow) char[lenText-wordtoreplacelen+replacementWordLen];

    for(int i=0; i<startindex; i++){
        result[i] = text[i];
    }
    int j=0;
    for(int i=startindex; i<startindex-wordtoreplacelen+replacementWordLen; i++){
        result[i] = replacementWord[j];
        j++;
    }
    j=0;
    for(int i=startindex-wordtoreplacelen+replacementWordLen; i<lenText-wordtoreplacelen+replacementWordLen; i++){
        result[i] = text[startindex+wordtoreplacelen+j];
        j++;
    }
    lenText = lenText-wordtoreplacelen+replacementWordLen;
    return result;
}

char* changeWordsFromDictionary(char* text, char** dictionary, unsigned int lengthDictionary,unsigned int& lenText){
    int count=0;
    for(int i=0;i<lengthDictionary-1; i+=2){
        int lenWordDictionary = 0;
        while(dictionary[i][lenWordDictionary]!=0){
            lenWordDictionary++;
        }
        for(int j=0;j<lenText;j++){
            for(int k=0; k<lenWordDictionary; k++){
                if(dictionary[i][k] != text[j]){
                    count=0;
                    break;
                }
                else{
                    count++;
                    if(count == lenWordDictionary){
                        text = replaceWord(text, dictionary[i+1], lenText, lenWordDictionary, j);
                        count = 0;
                        break;
                    }
                }
            }
        }
    }
    return text;
}





int main(){
    unsigned int n;
    cin >> n;
    char** dictionary = new(nothrow) char*[n*2];
    if(!dictionary){
        cout << "No Memory";
        return 1;
    }
    for(int i=0; i<n*2; i++){
        char* currentWord = new(nothrow) char[100];
        if(!currentWord){
            cout << "No Mem";
            delete[] dictionary;
            return 1;
        }
        cin >> currentWord;
        dictionary[i] = currentWord;

        delete[] currentWord;
    }
    
    unsigned int m;
    cin >> m;
    char* text = new(nothrow) char[m];
    if(!text){
        cout << "no mem";
        delete[] dictionary;
        return 1;
    }
    
    cin.getline(text,m);
    
    for(int i=0; i<m; i++){
        cout << text[i];
    }
    cout << endl;


    text = changeWordsFromDictionary(text, dictionary, n*2,m);
    for(int i=0; i<m; i++){
        cout << text[i];
    }


    delete[] dictionary;
    return 0;
}