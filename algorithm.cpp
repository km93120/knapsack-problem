#include "algorithm.h"

Algorithm::Algorithm()
{

    pair <int,int> p1,p2,p3,p4;
    maxWeight = 7;
    //value-weight pairs

    p1 = make_pair(1,1);
    p2 = make_pair(4,3);
    p3 = make_pair(5,4);
    p4 = make_pair(7,5);

    valueWeightsPairs.append(p1);
    valueWeightsPairs.append(p2);
    valueWeightsPairs.append(p3);
    valueWeightsPairs.append(p4);

    for (int i = 0; i < valueWeightsPairs.count();i++)
    {
        nodeMatrix.push_back(QVector<Node *>(maxWeight + 1));

    }







}

void Algorithm::setMatrix()
{
    int x,y;
    x = valueWeightsPairs.count();
    y = maxWeight + 1;

    //value-weight pairs

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

                if(workingValue < nodeMatrix[i-1][j]->getValue())
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
                    nodeMatrix[i][j]-> setPreviousNode(nodeMatrix[i-1][j]);

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
       cout << endl;
    }
   // std :: cout << std ::endl;
    //for(int i = 0,)
}

QVector<std::pair<int, int>> Algorithm::getSelectedItems()
{
    int x = valueWeightsPairs.count();
    int y = maxWeight + 1;
    bool ok = false;

    QVector<std::pair<int, int>> selectedItems;
    // cout << nodeMatrix[0][y-1]->getValue();
    if(nodeMatrix[0][y-1]->getValue() > nodeMatrix[x-1][y-1]->getValue() )
    {
        selectedItems.append(valueWeightsPairs.at(0));
    }

    else
    {
        for (int i = 1 ; i < x ; i++)
        {
            ok = true;

            for(int j = 0; j < y; j++)
            {

               if (nodeMatrix[i][j]->getPrev() != nullptr)
               {
                   ok = false;
                   cout << "valeur de i : " << i << endl;
                   cout << "valeur de j: "  << j << endl;


               }

            }

            if(ok)
            {
                selectedItems.append(valueWeightsPairs.at(i));
            }


        }
    }
    cout << endl;
    cout << selectedItems.count();
    for (int i = 0;i < selectedItems.count(); i++)
    {
         cout << "value : " << selectedItems.at(i).first<< endl << "weight : "<<selectedItems.at(i).second << endl;
    }
   // cout << "value : " << selectedItems.at(0).first<< endl << "weight : "<<selectedItems.at(0).second ;
    return selectedItems;
}
