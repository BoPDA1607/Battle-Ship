#include <iostream>
#include <fstream>
using namespace std;
class memo
{
    private:
        int** MapPlaceRecord;
        int row;
        int colum;
        static int BoardRecordSize;
    public:
        memo(int =7);
        memo(const memo&);
        ~memo();
        int* GetNode(const int=1,const int =1);
        int FindLargestValue();
        void SetValueto0(int=1,int=1);
        int GetLargestNodeRow();
        int GetLargestNodeColum();
        void DisplayMemo();
        friend ifstream& operator>>(ifstream& myfile,memo&);
        void operator=(const memo&);
};