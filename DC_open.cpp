#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<cstring>
#include<stdio.h>
using namespace std;
const int MAX=100;
int iCurTran=0,iNextBit,iNextTran,iNonzero=-1;
int fun(int iNextBit)
{
	if(iNextBit==0)
	{
		return iCurTran;
	}
	if(iNextBit==1)
	{
		if(iCurTran!=0)
		{
			iCurTran=0;
			return 0;
		}
		else
		{
			iNonzero=iNonzero*-1;
			iCurTran=iNonzero;
			return (iNonzero);
		}
	}
}
int main()
{
	int arr[MAX];
	FILE *fp;
	int y;
	int output[MAX];
	int i,j,n;
	cout<<"\n     **********************************************************";
	cout<<"\n\n\tImplementing Multi Level Transmission in 3 levels:\t\n";
	cout<<"\n     **********************************************************\n\n";
	
	while(1)
	{
		label1:
		cout<<"Enter number of bits\t:";
		cin>>n;
		cout<<"Enter "<<n<<" bits\t:";
		for(i=0;i<n;i++)
		{
			cin>>arr[i];	
		}
		cout<<"\nEntered bits are:\t\n";	
		for(i=0;i<n;i++)
		{
			cout<<"\t"<<arr[i];	
		}
		for(i=0;i<n;i++)
		{
			iNextBit=arr[i];
			y=fun(iNextBit);
			output[i]=y;
		}
		int ch;
		label:
		cout<<"\nYour Choices :\t";
		cout<<"\n\t1.Show transitons \n\t2.Plot the graph\n\t3.Enter new data\n\t4.Exit\n\n";
		cout<<"\nEnter your choice\t:";
		
		cin>>ch;
		int y;
		switch(ch)
		{
			case 1: cout<<"\nTransition levels for given bits\n\n";
					cout<<"\t||bits||"<<"           ||transition level|| \n";
					char str[4];
					for(i=0;i<n;i++)
					{
						if(output[i]==1)
							strcpy(str,"     +ve V");
						else if(output[i]==-1)
							strcpy(str,"     -ve V");
						else 
							strcpy(str,"      0 V ");
						cout<<"\t|  "<<arr[i]<<"   |\t   |"<<str<<"        |";
						cout<<endl;
					}
					cout<<endl<<endl;
					goto label;
					break;
			case 2: fp=fopen("MLT3Plot.dat","w");
					for(i=0;i<n;i++)
					{
						y=output[i];
						fprintf(fp,"%d\t%d\n",i,y);
						fprintf(fp,"%d\t%d\n",i+1,y);
					}
					fclose(fp);
					cout<<"Plot created Successfully!\n";
					break;
			case 3: goto label1;
			case 4 :exit(0);
					
		}	
	}
	return 0;
}

