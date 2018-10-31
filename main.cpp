#include <QCoreApplication>

#include <iostream>
#include "node.h"
#include "header.h"

#include "algorithm.h"


using namespace std;

int main(int argc, char *argv[])
{

  /* QVector<pair<int,int>> valueWeightsPairs;
   pair <int,int> p1,p2,p3,p4;

   //value-weight pairs

   p1 = make_pair(1,1);
   p2 = make_pair(4,3);
   p3 = make_pair(5,4);
   p4 = make_pair(7,5);

   valueWeightsPairs.append(p1);
   valueWeightsPairs.append(p2);
   valueWeightsPairs.append(p3);
   valueWeightsPairs.append(p4);

   int maxWeight = 7;
   int x,y;
   x = valueWeightsPairs.count();
   y = maxWeight + 1;

   Node * nodeMatrix[x][y];*/

   //setMatrix(valueWeightsPairs,y,nodeMatrix);


    Algorithm algorithm = Algorithm();
    algorithm.setMatrix();
    algorithm.getSelectedItems();




    return 0;
}
