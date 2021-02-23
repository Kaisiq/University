#include <iostream>
#include <cstring>
using namespace std;


int bigger(int a, int b){
    return a > b ? a : b;
}

char** replaceSubstring(char** pSource, char** pFind, char** pReplace)
{
	int x;
    int count=0;

	for (x = 0; x < strlen(*pSource); x++)
	{
        for(int i=0; i<strlen(*pFind); i++){
            if(pFind[0][i]!=pSource[0][x+i]){
                count++;
            }
        }
        if(count==strlen(*pFind)){
            //swap
            for(int i=0; i<bigger(strlen(*pReplace),strlen(*pFind)); i++){
                if(i<=strlen(*pReplace)){
                    *pSource[x+i] = *pReplace[i];
                }
                else{
                    *pSource[x+i] = ' ';
                }
            }
        }
		
	}
	return pSource;
}


int main(){
    char* Source = "The lazy fox jumped over the lazy dog. Overall the two animals were lazy";
    char* Find = "lazy";
    char* Replace = "good";
    cout << replaceSubstring(&Source, &Find, &Replace);


    return 0;
}