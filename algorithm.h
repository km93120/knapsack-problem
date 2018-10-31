#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "node.h"
#include "QVector"
#include <iostream>

using namespace std;

class Algorithm
{

   QVector <QVector<Node *> >          nodeMatrix;
   QVector<std::pair<int,int>> valueWeightsPairs;
   int maxWeight;


public:
    Algorithm();
    void setMatrix();
    QVector<std::pair<int,int>> getSelectedItems();


};

#endif // ALGORITHM_H
