//
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Увод в програмирането 2020/21
// Контролно 1
// 2020-11-29
//
// Начален час: 09:00
// Име: Даниел Даниел Иванов
// ФН: 45792
// Специалност: Информатика
// Курс: Първи
// Административна група: 4
// Използван компилатор: G++
//

#include <iostream>

using namespace std;



//0 0 0 1
//0 0 0 1
//0 0 1 0

int main(){ 
    bool a1,a2,a3,a4;
    bool b1,b2,b3,b4;
    bool c1,c2,c3,c4;
    bool d1,d2,d3,d4;
    bool e1,e2,e3,e4;
    bool alp1,alp2,alp3;
    bool allequal;
    bool result0,result1,result2,result3,result4;
    cin >> a1 >> a2 >> a3 >> a4;
    cin >> b1 >> b2 >> b3 >> b4;

    // if (a4 & b4 == 0){              //Това ми помогна, за да преосмисля какво точно трябва да напиша, затова го оставям
    //    result4 = (a4&b4);
    // }
    // else if(a4&b4 == 1){ 
    //     result4 = (!a4);
    // }
    // else {
    //     result4 = a4 | b4;
    // }

    //1^1 = 0
    //0^0 = 0
    //1^0 = 1
    //0^1 = 1

    c4 = (a4&b4) && 1;
    d4 = (a4&b4) && 0;
    e4 = a4|b4;
    result4 = d4 || e4;
    alp3 = c4;
    // c3 = (a3&1 && b3&1) || (a3&1 && alp3&1) || (b3&1 && alp3&1);

    d3 = (a3&b3) && 0;
    e3 = a3|b3;
    c3 = ((!d3)&&alp3)   ||  (e3&&alp3);
    alp2 = c3;
    allequal = (a3&b3&alp3) && 1;
    result3 = allequal   ||  d3   ||  (d3&&(!(e3&&alp3)));

    d2 = (a2&b2) && 0;
    e2 = a2|b2;
    c2 = ((!d2)&&alp2)   ||  (e2&&alp2);
    alp1 = c2;
    allequal = (a2&b2&alp2) && 1;
    result2 = allequal   ||  d2   ||  (d2&&(!(e2&&alp2)));

    d1 = !((a1&b1) && 0);
    e1 = a1|b1;
    c1 = ((!d1)&&alp1)   ||  (e1&&alp1);
    allequal = (a1&b1&alp1) && 1;
    result1 = allequal   ||  d1   ||  (!d1&&(!(e1&&alp1)));
    result0 = c1;
    
    
    //  1 0 0 1       1 0 0 0       0 0 0 0
    //  0 1 1 1       0 0 0 1       1 0 0 0
    //1 0 0 0 0     0 1 0 0 1     0 1 0 0 0

    cout << result0 << result1 << result2 << result3 << result4; 
    return 0;
}