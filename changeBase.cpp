#include <qlist.h>
#include "changeBase.h"

QList<int> changeBase(int num, int rank)
{
    QList<int> baseR;
    while(num!=0)
    {
        baseR.push_front(num%rank);
        num=num/rank;
    }
    return baseR;
}
