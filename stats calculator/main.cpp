#include "app_wrapper.h"



int main() {

	cout << 1 / 2 << endl;

	app a;

	a.read_in();
	a.display_all();
	a.calculate_mean();
	a.calculate_median();
	a.calculate_4th();
	a.calculateSampleVarience();
	a.calculateStandardDev();
	a.store_all();
}