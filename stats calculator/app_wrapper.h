#include "linked_list.h"



class app {


public:
	app();
	~app();

	void read_in();
	void store_all();

	void display_all();

	void calculate_median();
	void calculate_mean();

	void calculate_4th();

	void calculateSampleVarience();
	
	void calculateStandardDev();


private:
	
	double sum; 
	double mean;
	double meadian;
	double upper4th;
	double lower4th;
	double spread;
	double outlearVal;
	double XoutlearVal;
	
	double Xi; //the sum of all values ^2
	double SampleVarience;
	double StandardDev;

	std::fstream input;
	std::fstream output;

	list original;
	list ordered;

	list outlear;
	list Xoutlear;

};