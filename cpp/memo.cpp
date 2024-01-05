#include "D:\Battleship-main\header\memo.h"
int memo::BoardRecordSize=6;

memo::memo(int n)
{
    this->MapPlaceRecord =new int*[memo::BoardRecordSize+1];
    for(int i=1;i<=memo::BoardRecordSize;i++)
        {
            this->MapPlaceRecord[i]=new int[memo::BoardRecordSize+1];
            for(int j=1;j<=memo::BoardRecordSize;j++)
            {
                this->MapPlaceRecord[i][j]=0;
                this->row=i;
                this->colum=j;
            }
        }
}
memo::memo(const memo& m1)
{
    this->MapPlaceRecord =new int*[memo::BoardRecordSize+1];
    for(int i=1;i<=memo::BoardRecordSize;i++)
        {
            this->MapPlaceRecord[i]=new int[memo::BoardRecordSize+1];
            for(int j=1;j<=memo::BoardRecordSize;j++)
            {
                this->MapPlaceRecord[i][j]=m1.MapPlaceRecord[i][j];
                this->row=i;
                this->colum=j;
            }
        }
}
memo::~memo()
{
    for(int i=1;i<7;i++)
    {
        delete[] this->MapPlaceRecord[i];
    }
    delete [] *(this->MapPlaceRecord);
}
int* memo::GetNode(int i,int j)
{
    return (&this->MapPlaceRecord[i][j]);
}
int memo::FindLargestValue()
{
    int largest=0;
    for(int i=1;i<7;i++)
        for(int j=1;j<7;j++)
            if(this->MapPlaceRecord[j][i]>largest) 
            {
                largest=this->MapPlaceRecord[j][i];
                this->row=i;
                this->colum=j;
            }
    return largest;
}
int memo::GetLargestNodeRow()
{
    int largest=this->FindLargestValue();
    for(int i=1;i<7;i++)
        for(int j=1;j<7;j++)
            if(this->MapPlaceRecord[j][i]==largest) return (this->row);
    return 0;
}
int memo::GetLargestNodeColum()
{
    int largest=this->FindLargestValue();
    for(int i=1;i<7;i++)
        for(int j=1;j<7;j++)
            if(this->MapPlaceRecord[j][i]==largest) return (this->colum);
    return 0;
}
void memo::DisplayMemo()
{
    for(int i=1;i<7;i++)
        {
            cout<<endl;
            for(int j=1;j<7;j++)
                cout<<"["<<this->MapPlaceRecord[j][i]<<"]";
        }
}
ifstream& operator>>(ifstream& myfile, memo& m) {
    for (int i = 1; i <= memo::BoardRecordSize; i++) {
        for (int j = 1; j <= memo::BoardRecordSize; j++) {
            int value;
            myfile >> value;
            *(m.GetNode(j, i)) = value;
        }
    }
    return myfile;
}
void memo::SetValueto0(int i,int j)
{
    *(this->GetNode(i,j))=0;
}
void memo::operator=(const memo& m1)
{
    for(int i=1;i<=memo::BoardRecordSize;i++)
        {
            for(int j=1;j<=memo::BoardRecordSize;j++)
            {
                this->MapPlaceRecord[i][j]=m1.MapPlaceRecord[i][j];
                this->row=i;
                this->colum=j;
            }
        }
}