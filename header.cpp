#include "header.h"

using namespace std;

QVector<std::pair<int,int>> setMatrix(QVector<std::pair<int,int>> valueWeightsPairs,int maxWeight )
{
   int x,y;
   x = valueWeightsPairs.count();
   y = maxWeight + 1;

   //value-weight pairs
   Node * nodeMatrix[x][y];

   for (int i = 0 ; i < 1 ; i++)
   {

       int workingValue = valueWeightsPairs.at(i).first;
       int workingWeight = valueWeightsPairs.at(i).second;

       for(int j = 0; j < y; j++)
       {
           //cout << workingValue << endl << workingWeight;
           nodeMatrix [i][j] =  workingWeight <= j ? new Node(workingValue) : new Node(0);
       }
   }

   for(int i = 1; i < x; i++)
   {
     //  int prevWorkingValue  = valueWeightsPairs.at(i-1).first;
     //  int prevWorkingWeight = valueWeightsPairs.at(i-1).second;

       int workingValue  =  valueWeightsPairs.at(i).first;
       int workingWeight =  valueWeightsPairs.at(i).second;

       for(int j = 0; j < y; j++)
       {
           cout << endl;
           cout << i;
           cout << endl;
           int differentialWeight = j - workingWeight;



           if(differentialWeight < 0)
           {
               int prev = nodeMatrix[i-1][j]->getValue();
               nodeMatrix[i][j] = new Node(prev);
           }

           else if (differentialWeight == 0)
           {

               if(workingValue <= nodeMatrix[i-1][j]->getValue())
               {
                   nodeMatrix[i][j] = new Node(nodeMatrix[i-1][j]->getValue());
                   nodeMatrix[i][j]->setPreviousNode(nodeMatrix[i-1][j]);

               }
               else
               {
                    nodeMatrix[i][j] = new Node(workingValue);
               }
           }

           else
           {

               if(workingValue + nodeMatrix[i-1][differentialWeight]->getValue() > nodeMatrix[i-1][j]->getValue())
               {
                   nodeMatrix[i][j] = new Node(workingValue + nodeMatrix[i-1][differentialWeight]->getValue() );
               }

               else
               {
                   nodeMatrix[i][j] = new Node(nodeMatrix[i-1][j]->getValue());
                   nodeMatrix[i][j]->setPreviousNode(nodeMatrix[i-1][j]);

               }

           }



       }


   }

   for (int i = 0 ; i < x ; i++)
   {
       for(int j = 0; j < y; j++)
       {

           std :: cout << nodeMatrix[i][j]->getValue();
           cout << " ";

       }
      cout <<endl;
   }
  // std :: cout << std ::endl;
   //for(int i = 0,)


}



int getMaxValue(Node *, Node *)
{


}
