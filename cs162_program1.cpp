//Shang-Chun, Lin
//CS162

//This program is to calculate howThis program will tell you how much money should 
//be deposited in the bank at the end of the daily sale, and how much money should
//be left in the cash drawer along with the number of each denomination for the next day.

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	//Setting variables here
	
	int one = 0;		//the number of $1
	int five = 0;		//the number of $5
	int ten = 0;		//the number of $10
	int twenty = 0;		//the number of $20
	char answer = 'n'; 	//the answer for making sure the input is correct
	int price = 0;		//the price of the product which the client want to buy
	int pay = 0;		//the actual value of the client has paid
	int times = 0;		//how many times the sales happened in the day
	int i = 0;		//a variable for a loop
	int total = 0;		//total money the user have
	int total_left = 0;	//total money left in the cash drawer

	srand(time(0));	//initialize random number generator

	//Welcome the user and tell them the rules of the program
	
	cout<<"Welcome to use this program! This program will tell you how much"<<endl
	<<"money should be deposited in the bank at the end of the daily sale,"<<endl
	<<"and how much money should be left in the cash drawer along with the"<<endl
	<<"number of each denomination for the next day."<<endl<<endl;

	//Ask the user to enter the aount of $1’s, 5’s, 10’s, and 20’s in the drawer

	do
	{	
	cout<<"Please enter the amount of each denomination in this program"<<endl;
	cout<<"How many $1's do you have in the drawer? Please enter a number not a character."<<endl;
	cin >> one;
	cout<<"How many $5's do you have in the drawer? Please enter a number not a character."<<endl;
	cin >> five;
	cout<<"How many $10's do you have in the drawer? Please enter a number not a character."<<endl;
	cin >> ten;
	cout<<"How many $20's do you have in the drawer? Please enter a number not a character."<<endl;
	cin >> twenty;

	cout<<"You have "<< one <<" $1's and "<< five <<" $5's and "<<endl
	<< ten <<" $10's and "<< twenty <<" $20's in your drawer right now."<<endl<<endl;

	cout<<"Is it correct? Y for yes, N for no. If it isn't correct,"<<endl
	<<"then you need to enter again."<<endl;
	cin >> answer;

	}while( toupper(answer) != 'Y' || one<0 || five<0 || ten<0 || twenty<0 );


	//Use the random number generator to simulate each sale during the day and record the changing of each denomination
	
	cout<<"In this case, the program will simulate each sale randomly."<<endl
	<<"Therefore, you don't need to input anything in this part!"<<endl<<endl;
	
	cout<<"The price will be limited to be whole number and under 100$ each sale."<<endl<<endl;

	times = (rand() % 20)+1;		//The assignment says there are usually no more than 20 sales taking place in a day
	
	cout<<"We have "<< times <<" sales today!"<<endl<<endl;


	while(times - i > 0)
	{
		total = one*1 + five*5 + ten*10 + twenty*20;
		price = (rand() % 100)+1;
		pay = (rand() % 100)+1;
		
		while(price>pay) 	//the client needs to pay the actual number or larger than the price and get the change
		{
			pay = (rand() % 100)+1;
		}

		twenty += (pay/20);	//get the payment first
		ten += ((pay%20)/10);
		five += (((pay%20)%10)/5);
		one += (((pay%20)%10)%5);

		twenty -= ((pay-price)/20);      //give back the change
                ten -= (((pay-price)%20)/10);
                five -= ((((pay-price)%20)%10)/5);
                one -= ((((pay-price)%20)%10)%5);

		if(twenty < 0 || ten < 0 || five < 0 || one < 0 || total < pay-price)		//don't count the failed sample
		{
			twenty += ((pay-price)/20);      //the mirror of the last step
	                ten += (((pay-price)%20)/10);
        	        five += ((((pay-price)%20)%10)/5);
                	one += ((((pay-price)%20)%10)%5);

			twenty -= (pay/20);      //the mirror of the last step
	                ten -= ((pay%20)/10);
        	        five -= (((pay%20)%10)/5);
                	one -= (((pay%20)%10)%5);
		}

		else
		{
			++i;
		}
	}
	
	//Calculate how much money should the user deposit in the bank
	//and make sure the amount of each denomination satisfying the condition
	//Then inform the user about the information
	
	total = one*1 + five*5 + ten*10 + twenty*20;

	do
	{
		if(twenty > 2)							//extract the extra $20's
                {
                        twenty -= (rand() % (twenty-2))+1;
                        total_left = one*1 + five*5 + ten*10 + twenty*20;
                        if(total_left < 70)					//if over-extract it, then add it back
                        {
                                twenty += (rand() % (twenty-2))+1;
                        }
                }
		else
		{
			cout<<"Please break a $100 in the bank to make $20's larger than or equal to 2."<<endl;
			total -= (2 - twenty)*20;
			twenty = 2;
		}
		

		if(ten > 1)
                {
                        ten -= (rand() % (ten-1))+1;
                        total_left = one*1 + five*5 + ten*10 + twenty*20;
                        if(total_left < 70)
                        {
                                ten += (rand() % (ten-1))+1;
                        }
                }
		else
		{
			cout<<"Please break a $20 in the bank to make $10's larger than or equal to 1."<<endl;
                        total -= (1 - ten)*10;
                        ten = 1;
		}


		if(five > 2)
                {
                        five -= (rand() % (five-2))+1;
                        total_left = one*1 + five*5 + ten*10 + twenty*20;
                        if(total_left < 70)
                        {
                                five += (rand() % (five-2))+1;
                        }
                }
		else
		{
			cout<<"Please break a $20 in the bank to make $5's larger than or equal to 2."<<endl;
                        total -= (2 - five)*5;
                        five = 2;
		}


		if(one > 5)
		{
			one -= (rand() % (one-5))+1;
			total_left = one*1 + five*5 + ten*10 + twenty*20;
			if(total_left < 70)
			{
				one += (rand() % (one-5))+1;
			}
		}
		else
		{
			cout<<"Please break a $20 in the bank to make $1's larger than or equal to 5."<<endl;
                        total -= (5 - one)*1;
                        one = 5;
		}


		total_left = one*1 + five*5 + ten*10 + twenty*20;
	
	}while(total_left > 85);

	
	cout<<"You have "<< one <<" $1's and "<< five <<" $5's and "<<endl
	<< ten <<" $10's and "<< twenty <<" $20's in your cash drawer right now,"<<endl
	<<" which is totally: "<< total_left <<" $ ."<<endl<<endl;

	cout<<"Also, you need to deposit "<< total - total_left <<"$ in the bank today."<<endl;

	cout<<"Thank you for using this program!!"<<endl;


	return 0;
}
