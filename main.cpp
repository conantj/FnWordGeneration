#include "FnWord.h"
#include "Fn.h"
#include <iostream>

int main(int argc, char *argv[])
{
    int i=0,j=0;
    int count=0;
    Basis base(2);
    FnWord word;
    for(i=4;i<5;i++)
    {
        count=0;
        for(j=0;j<1000000;j++)
        {
           word=base.at(rand()%4);
           while(word.size()<i)
           {
               word*=base.at(rand()%4);
           }
           //std::cout<<word.toStdString()<<std::endl;
           word=word.cyclicWord();
           if(word.isSeparable(base))
           {
               count++;
           }
        }
        std::cout << "S("<<i<< ",2)="<<count << std::endl;

    }

    return 0;
}
