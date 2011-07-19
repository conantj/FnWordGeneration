#include "FnWord.h"
#include "Fn.h"
#include <iostream>
#include <math.h>
#include <qlist.h>
#include "changeBase.h"

int main()
{
    int i=0,j=0;
    int count=0;
    int length=0, rank=0;
    std::cout<<"Computing # of Separable Word of length, n, and rank, r."<<std::endl;
    std::cout<<"n: ";
    std::cin>>length;
    std::cout<<"r: ";
    std::cin>>rank;
    Basis base(rank);
    QString string;
    FnWord word;
    QList<int> wordGen;
    for(i=0;i<pow(2*rank,length);i++)
    {
        wordGen=changeBase(i, 2*rank);
        while(wordGen.size()<length)
        {
            wordGen.push_front(0);
        }
        string="";
        for(j=0;j<wordGen.size();j++)
        {
            string+=base.at(wordGen[j]);
        }
        word=string;
        word.tighten();
        if(word.size()==length&&word.isSeparable(base))
        {
            count++;
        }
    }
    std::cout<<count<<" out of "<<(2*rank*pow(2*rank-1,length-1))<<" words of ";
    std::cout<<"length "<<length<<" and rank "<<rank<<" are separable."<<std::endl;

    return 0;
}


