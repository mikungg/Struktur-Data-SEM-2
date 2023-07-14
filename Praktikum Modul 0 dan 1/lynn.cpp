#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
    deque<string> dqinput;
    deque<string> dqoutput;

    int m, n, i;                                                    
    i = 0;
    char str[20];

    scanf("%d %d", &m, &n);                                 //input banyak kata dan command algoritma pengucapan

    if(m == 0)
    {   
        printf("Apa itu nol?");                             //jika banyak kata yang dimasukkan adalah 0
    }

    while(i != m)
    {
        scanf("%s", str);                                   //input kata
        dqinput.push_back(str);                             //push kata ke belakan deque
        i++;                                                //iterasi ++
    }

    if(n == 0)                                              //jika command 0
    {
        int gnjgnp;
        gnjgnp = 1;                                         //deklarasi variabel untuk ganjil genap

        while(m != 0)
        {   
            if(gnjgnp%2 == 1)                               //jika ganjil
            {
                dqoutput.push_back(dqinput.front());        //push kata dari depan deque input ke deque output
                dqinput.pop_front();                        //pop kata dari depan deque
                gnjgnp++;
            }
            else                                            //jika genap
            {
                dqoutput.push_back(dqinput.back());         //push kata dari belankang deque input ke deque output
                dqinput.pop_back();                         //pop kata dari belakang deque
                gnjgnp++;
            }

            m--;
        }

        while(!dqoutput.empty())
        {
            cout << dqoutput.front() << " ";                //algoritma print seluruh kata pada deque outtput
            dqoutput.pop_front();
        }
    }
    else if(n == 1)                                         //jika command 1
    {
        int gnjgnp;                                         //mirip seperti command 0 hanya saja order dari algortimanya diubah
        gnjgnp = 1;                                         //yang ganjil memiliki kode genap & yang genap memiliki kode ganji

        while(m != 0)
        {   
            if(gnjgnp%2 == 1)
            {
                dqoutput.push_back(dqinput.back());
                dqinput.pop_back();
                gnjgnp++;
            }
            else
            {
                dqoutput.push_back(dqinput.front());
                dqinput.pop_front();
                gnjgnp++;
            }

            m--;
        }

        while(!dqoutput.empty())
        {
            cout << dqoutput.front() << " ";
            dqoutput.pop_front();
        }
    }
    else
    {
        return 0;                                       //jika command diluar 0 dan 1 exit program
    }
}