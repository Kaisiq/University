//
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Увод в Програмирането 2020/21
// Практически изпит - задачи
// 2021-02-01
//
// Име: Даниел Иванов
// ФН:45792
// Специалност:Информатика
// Курс: 1
// Административна група: 4
// Използван компилатор:GCC
//




#include <iostream>
#include <cstring>
using namespace std;


char*** createDictionary(int k){
    char*** dictionary = new(nothrow) char**[k];
    if(!dictionary){
        cout << "No mem";
        return nullptr;
    }
    for(int i=0; i<k; i++){
        dictionary[i] = new(nothrow) char*[2];
        if(!dictionary){
            cout << "No mem";
            return nullptr;
        }
        dictionary[i][0] = new(nothrow) char[1];
        if(!dictionary){
            cout << "No mem";
            return nullptr;
        }
        dictionary[i][1] = new(nothrow) char[100];
        if(!dictionary){
            cout << "No mem";
            return nullptr;
        }
    }
    return dictionary;
}


void enterDictionary(char*** dictionary, int k){
    for(int i=0; i<k; i++){
        cout << "enter symbol " << i+1 << " for the dictionary: "; 
        cin >> dictionary[i][0];    // symbol
        cout << "enter replacement " << i+1 << " for the dictionary: "; 
        cin >> dictionary[i][1];  // replacement of the symbol (text)
    }
}


int getlen(char* a){
    int count=0;
    while(a[count] != '\0'){
        count++;
    }
    return count;
}


void transferToLowChars(char* text){
    int textlen = getlen(text);
    for(int i=0; i<textlen; i++){
        if(text[i]<='Z' && text[i]>='A'){
            text[i] += 'a' - 'A';
        }
    }    
}


bool cryptateText(char*** dictionary, char* text, int dictionarylen){
    transferToLowChars(text);
    int textlen = getlen(text);
    int resultTextLen=textlen;
    bool charIsInDictionary;
    for(int i=0; i<textlen; i++){
        for(int j=0; j<dictionarylen; j++){
            if(text[i] == dictionary[j][0][0]){
                resultTextLen += getlen(dictionary[j][1]);
            }
        }
    }

    char* resultText = new(nothrow) char[resultTextLen];
    if(!resultText){
        cout << "No mem for resulttext";
        return 0;
    }
    
    int dictWordLen;
    int l=0;
    for(int i=0; i<resultTextLen; i++){
        charIsInDictionary=0;
        for(int j=0; j<dictionarylen; j++){
            if(text[l] == dictionary[j][0][0]){
                charIsInDictionary=1;
                dictWordLen = getlen(dictionary[j][1]);
                for(int k=0; k<dictWordLen; k++){
                    resultText[i+k] = dictionary[j][1][k];
                }
                i+=dictWordLen;
                break;
            }
        }
        if(!charIsInDictionary){
            resultText[i] = text[l];
        }
        l++;
    }
    for(int i=0; i<resultTextLen; i++){
        cout << resultText[i];
    }
    cout << endl;
    delete[] resultText;
    return 1;
}







bool deCryptateText(char*** dictionary, char* text, int dictionarylen){
    int textlen = getlen(text);
    int resultTextLen=textlen;
    bool wordIsInDictionary;
    for(int i=0; i<textlen; i++){
        for(int j=0; j<dictionarylen; j++){
            if(text[i] == dictionary[j][1][0]){
                int dictionaryWordLen = getlen(dictionary[j][1]);
                int k=1;
                for(k; k<dictionaryWordLen; k++){
                    if(text[i+k] != dictionary[j][1][k]){
                        break;
                    }
                }
                if(k==dictionaryWordLen){
                    resultTextLen -= (dictionaryWordLen-1);
                    break;
                }
            }
        }
    }

    char* resultText = new(nothrow) char[resultTextLen];
    if(!resultText){
        cout << "No mem for resulttext";
        return 0;
    }
    
    int dictWordLen;
    int l=0;
    for(int i=0; i<resultTextLen; i++){
        wordIsInDictionary=0;
        for(int j=0; j<dictionarylen; j++){
            if(text[i] == dictionary[j][1][0]){
                int dictionaryWordLen = getlen(dictionary[j][1]);
                for(int k=1; k<dictionaryWordLen; k++){
                    if(text[i+k] != dictionary[j][1][k]){
                        wordIsInDictionary = 1;
                        break;
                    }
                }
                if(wordIsInDictionary){
                    resultText[i] = dictionary[j][0][0];
                    l+=dictionaryWordLen;
                }
            }
        }
        if(!wordIsInDictionary){
            resultText[i] = text[l];
        }
        l++;
    }
    for(int i=0; i<resultTextLen; i++){
        cout << resultText[i];
    }
    cout << endl;
    delete[] resultText;
    return 1;
}











int main(){
    unsigned k;
    cin >> k;

    char*** dictionary = createDictionary(k);
    if(!dictionary){
        return 1;
    }

    enterDictionary(dictionary,k);


    unsigned n;
    cout << "enter n: ";
    cin >> n;
    char** textToCryptate = new(nothrow) char*[n];
    if(!textToCryptate){
        delete[] dictionary;
        cout << "no mem";
        return 1;
    }
    for(int i=0; i<n+1; i++){
        textToCryptate[i] = new(nothrow) char[1000];
    }
    char* a = new(nothrow) char[1000];
    for(int i=0; i<n+1; i++){
       cin.getline(a, 1000);
       textToCryptate[i] = a;
    }



    unsigned m;
    cout << "enter m: ";
    cin >> m;
    char** textToDeCryptate = new(nothrow) char*[m];
    if(!textToDeCryptate){
        delete[] dictionary;
        cout << "no mem";
        return 1;
    }
    for(int i=0; i<m+1; i++){
        textToDeCryptate[i] = new(nothrow) char[1000];
    }
    char* b = new(nothrow) char[1000];
    for(int i=0; i<m+1; i++){
       cin.getline(b, 1000);
       textToDeCryptate[i] = b;
    }




    for(int i=0; i<n; i++){
        cryptateText(dictionary,textToCryptate[i],k);
    }

    for(int i=0; i<m; i++){
        deCryptateText(dictionary,textToDeCryptate[i],k);
    }
    



    delete[] dictionary;
    return 0;
}