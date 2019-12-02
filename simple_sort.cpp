#include<iostream>
using namespace std;

typedef int BOOL;
#define TRUE 1
#define FALSE 0

class Array
{
        protected:
                int *Arr;
                int size;

        public:
                Array(int value=10)//default+para constructor
                {
                        cout<<"Inside Constructor\n";
                        this->size=value;
                        this->Arr=new int[size];//new memory allocated using dynamic allocation
                }

                Array(Array &ref)//created reference like obj
                {
                        cout<<"Inside copy constructor\n";
                        this->size=ref.size;    //took size of previous size var
                        this->Arr=new int[this->size];//created new memory for thismarray

                        for(int i=0;i<this->size;i++)
                        {
                                this->Arr[i]=ref.Arr[i];
                        }
                }

                ~Array()
                {
                        cout<<"Inside Destructor\n";
                        delete []Arr;
                }

                //function declaration
                inline void Accept();
                inline void Display();

};//end of Array base class

//function definition
void Array::Accept()
{
        cout<<"Please Enter the values\n";

        for(int i=0;i<this->size;i++)
        {
                cin>>Arr[i];
        }
}

void Array::Display()
{
        cout<<"Elements are\n";
        for(int i=0;i<this->size;i++)
        {
                cout<<Arr[i]<<" ";
        }
        cout<<"\n";
}



class Sorting: public Array
{



	public:
		Sorting (int ino=10):Array(ino)
	{}
		void BubbleSort();
		void BubbleSortX();
		void SelectionSort();

		
};

void Sorting::BubbleSort()
{
	cout<<"Inside Bubblesort func\n";

	for(int pass=1; pass<size; pass++)
	{
		for(int i=0; i<size-pass;i++)
		{
			if(Arr[i]>Arr[i+1])
			{
				int temp=Arr[i];
				Arr[i]=Arr[i+1];
				Arr[i+1]=temp;
			}
		}
	}
}
void Sorting::BubbleSortX()
{
	cout<<"Inside BubblesortX func\n";

	for(int pass=1;pass<size;pass++)
	{
		BOOL sort=FALSE;
		for(int i=0; i<size-pass; i++)
		{
			if(Arr[i]>Arr[i+1])
				{
					int temp=Arr[i];
					Arr[i]=Arr[i+1];
					Arr[i+1]=temp;
					sort=TRUE;
				}
		}
		if(sort==FALSE)
		{
			break;
		}
	}
}

void Sorting::SelectionSort()
{
	int i=0, j=0, iMin=0, temp=0;

	cout<<"Inside Selectionsort func\n";

	for(i=0; i<size-1; i++)
	{
		iMin=i;
		for(j=i+1;j<size;j++)
		{
			if(Arr[j]<Arr[iMin])
			{
				iMin=j;
			}
		}

			if(i!=iMin)
			{
				temp=Arr[i];
				Arr[i]=Arr[i+1];
				Arr[i+1]=temp;
			}
		
	}
}


int main()
{
        cout<<"Inside main\n";

        Sorting sobj1(10);
        sobj1.Accept();
        sobj1.Display();


	sobj1.BubbleSort();
	sobj1.Display();
	sobj1.BubbleSortX();
	sobj1.Display();
	sobj1.SelectionSort();
	sobj1.Display();
return 0;
}

