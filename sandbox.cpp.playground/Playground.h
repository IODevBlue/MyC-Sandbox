/*
 * Playground.cpp
 *
 *  Created on: 6 Aug 2023
 *      Author: IO DevBlue
 */
#include <cstdio>
#include <iostream>
#include <random>
#include <string>
#include <exception>
#include <bitset>


namespace sandbox_playground {

struct alphabet_guessing_game {
	struct rand_int {
		rand_int(int start, int end): dist(start, end) {}

		double operator()() { return (dist(rd)); }

		private:
			std::random_device rd;
			std::uniform_int_distribution<> dist;
	};

	void exec() {
		rand_int rand(1, 26);
			int noOfTrials = 0;
			int b = rand();
			char d = 'A';
			for(int i=1; i!=b; i++) {
				++d;
			}
			std::cout<<"The Answer is: "; std::cout<<d<<'\n';

			std::cout<<"-----------------------------"<<'\n';
			std::cout<<"Random Alphabet Guessing Game"<<'\n';
			std::cout<<"-----------------------------"<<'\n';
			std::cout<<"I have picked a random Alphabet between 'A-Z',";
			std::cout<<" Can you guess that Alphabet?.\n";
			std::cout<<"\n***Your Answer should be in Uppercase***\n\n\t\tGo!!!\n";

			while(true) {
				std::cout<<"\nIt is: "<<'\n';
				std::string s;
				std::cin >> s;
				if(static_cast<int>(s.length()) > 1) {
					std::cout<<"\nThat is too long!, Guess just an Alphabet! Try again.\n";
				} else if(std::toupper(*s.c_str())!=*s.c_str()) {
					std::cout<<"Answer must be an Upper case Alphabet! Try again.\n";
				} else if(*s.c_str()!=d) {
					std::cout<<"\nWrong Answer! Try again.\n";
					++noOfTrials;
				} else if(*s.c_str()==d) {
					std::cout<<"\n-----------------------------"<<'\n';
					std::cout<<"Yay, Correct!.\n";
					std::cout<<"____________________________________\n";
					std::cout<<"Your Number of trials: ";
					std::cout<<noOfTrials<<'\n';
					std::exit(0);
				}
			}
	}
};

struct array_sum_calculator {

	void exec() {
		std::cout<<"---------------------------------------"<<'\n';
		std::cout<<"\tArray Sum Calculator"<<'\n';
		std::cout<<"---------------------------------------"<<'\n';
		while(true) {
			std::cout<<"\nInput the size of the array: ";
			int a;
			if(std::cin>>a) {
				int b[a];
				int i=0; int j=1; bool notDone=true;
				while(notDone) {
					if(i<a) {
						std::cout<<j<<": ";
						std::cin>>b[i]; ++i; ++j;
					} else {
						notDone = false;
					}
				}
				arrayAdd(b, a);
			} else {
				std::cout<<"\nThat is not an Integer! Try again.\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
	}

private:
	void arrayAdd(int a[], int size) {
		int c=0;
		std::string f;
		for(int i=0; i<size; ++i){
			c+=a[i];
			if(i != size-1)
				f+=std::to_string(a[i])+",";
			else
				f+=std::to_string(a[i]);
		}
		std::cout<<"\n__________________________________";
		std::cout<<"\nThe sum of the values in the array: ";
		std::cout<<f<<" is = "<<c<<'\n';
		std::cout<<"__________________________________\n\n";

	}

};

struct average_number_calculator {

	void exec() {
		std::cout<<"--------------------------------"<<'\n';
		std::cout<<"***Average Number Calculator***"<<'\n';
		std::cout<<"--------------------------------"<<'\n';
		std::cout<<"Type in the numbers you want to calculate";
		std::cout<<" an average of: \n\nType in 'Yes' when done.\n";
		bool notDone = false; int i=0; double sum=0;
		std::string falseInput;
		while(!notDone) {
			int input;
			std::cout<<"Number "<<i+1<<": ";
			if(std::cin>>input) {
				++i;
				sum+=input;
				continue;
			} else {
				std::cin.clear();
				std::cin>>falseInput;
				if(falseInput.starts_with("yes") || falseInput.starts_with("Yes")) {
					break;
				}
				std::cout<<"That is not a Number! Please try again.\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
		std::cout<<"The Average of these "<<i<<" numbers is = ";
		std::cout<<sum/2;
	}
};

struct binary_converter {

	void exec() {
		while(true) {
			std::cout<<"-------------------------- \n";
			std::cout<<"Input Number to Convert: \n";
			std::cout<<"-------------------------- \n";
			int b;
			if(std::cin>>b) {
				std::string xc = std::bitset<64>(b).to_string().substr(64-std::log2(b)-1);
				std::cout<<"The Binary form of "<<b<<" is "<<xc<<'\n'<<'\n';
				std::cout<<"Do you want to continue? Yes or No?.\n";
				std::string f;
				if(std::cin>>f) {
					if(f.starts_with("yes") || f.starts_with("Yes")) {
						std::cout<<"\n";
						continue;
					}
				} else {
					std::exit(0);
				}
			} else {
				std::cin.clear();
				std::cout<<"That is not a Number! Please Input a Number";
				continue;
			}
		}

	}
};

struct even_number_evaluator {

	void exec() {
		std::cout<<"---------------------\n";
		std::cout<<"Even Number Evaluator\n";
		std::cout<<"---------------------\n";
		while(true) {
			std::cout<<"\n"<<"_____________________\n";
			std::cout<<"Input n: ";
			int b;
			std::cin>>b; //Error is not caught here.
			int c=0;
			if(b<=0) {
				std::cout<<"\nn must be greater than zero!"<<"\n";
				continue;
			}
			int i=0;
			std::cout<<"\n"<<"The even numbers in "<<b<<" are "<<"\n";
			std::cout<<"0, ";
			while(i<b) {
				i++;
				if(i%2==0) {
					std::cout<<i<<", ";
					c+=i;
				} else {
					continue;
				}
			}
			std::cout<<"\nTheir sum is = "<<c<<"\n";
		}

	}
};

struct multiplications_table {

	void exec() {
		std::cout<<"\t|";
		for(int i=2; i<10; i++) {
			std::cout<<"  "<<i<<"\t";
		}
		std::cout<<"\n\t|"<<"\n";
		for(int i=2; i<10; i++) {
			std::cout<<i<<"\t|";
			for(int j=2; j<10; j++) {
				std::cout<<"  "<<i*j<<"\t";
			}
			std::cout<<"\n";
		}
	}
};

struct prime_factor_calculator {

	void exec() {
		std::cout<<"-----------------------------\n";
		std::cout<<"***PRIME FACTOR CALCULATOR***\n";
		std::cout<<"-----------------------------\n";
		while(true) {
			std::cout<<"\nEnter the number you want to find its Prime Numbers: ";
			int a;
			std::cin>>a;
			std::cout<<"The Prime Factors are: ";
			for(int i=2; i<=a; i++) {
				while(a%i==0) {
					std::cout<<i<<", ";
					a/=i;
				}
			}
			std::cout<<"\n\nDo you want to calculate again? Type in anything to proceed or 'No' to Exit: ";
			std::string s;
			if(std::cin>>s) {
				if(s.starts_with("No") || s.starts_with("no")) {
					std::exit(0);
				}
			} else {
				std::cin.clear();
				continue;
			}
		}
	}
};
}



