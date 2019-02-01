#include "app_wrapper.h"


app::app() {
	this->input.open("input.txt");
	this->output.open("output.csv", ofstream::out | ofstream::trunc);
	sum = 0;
	mean = 0;
	meadian = 0;
	this->lower4th = 0;
	this->upper4th = 0;
	this->outlearVal = 0;
	this->XoutlearVal = 0;
	this->Xi = 0;
	this->SampleVarience = 0;




}
app::~app() {
	input.close();
	output.close();
	//	delete(original);
		//delete(ordered);
}

void app::read_in() {
	double value;
	while (input >> value) {
		sum += value;
		ordered.insert_inorder(value);
		original.insert(value);
	}
}
void app::store_all() {
	int i = ordered.get_size();
	Node* pCur = nullptr;

	output << "size:," << this->ordered.get_size() << ",,," << "upper4th:," << upper4th << ",,spread:," << spread << endl;
	output << "Sum:," << sum << ",,," << "lower4th:," << lower4th << ",,outlear value:," << outlearVal << "," << "extreme outlear val:," << XoutlearVal << endl;
	output << "mean:," << this->mean << ",,,outlear:,";
	for (int j = 0; j < outlear.get_size(); j++) {
		output << outlear.get_pos(j) << ",";
	}
	output << endl;
	output << "meadian:," << meadian << ",,,Extreme outlear:,";
	for (int j = 0; j < Xoutlear.get_size(); j++) {
		output << Xoutlear.get_pos(j) << ",";
	}
	output << endl;


	output << "Xi^2:," << Xi << ",,sample varience:," << SampleVarience << ",,stdev:," << StandardDev << endl;


	output << "original,,ordered" << endl;
	for (int j = 0; j < i; j++) {
		output << original.get_pos(j) << ",,";
		output << ordered.get_pos(j) << endl;
	}



}

void app::display_all() {
	int i = ordered.get_size();

	cout << "original: ";
	for (int j = 0; j < i; j++) {
		cout << original.get_pos(j) << " ";
	}
	cout << endl;

	cout << "ordered: ";
	for (int j = 0; j < i; j++) {
		cout << ordered.get_pos(j) << " ";
	}
}

void app::calculate_median() {

	int i = this->ordered.get_size() / 2;
	if (this->original.get_size() % 2 == 0) {


		this->meadian = (this->ordered.get_pos(i) + this->ordered.get_pos(i - 1)) / 2;

	}
	else {
		this->meadian = this->ordered.get_pos(i);
	}
}
void app::calculate_mean() {
	this->mean = this->sum / this->ordered.get_size();

}

void app::calculate_4th() {
	int adder = 0;
	int mid = 0;
	Node* pCur;


	if ((this->ordered.get_size() % 2) == 0) {
		mid = (this->ordered.get_size() / 2);

	}
	else {
		mid = (this->ordered.get_size() / 2) + 1;

	}
	if ((mid % 2) == 0) {
		adder = (mid / 2);

		double g = this->ordered.get_pos(mid + adder - 1);
		double h = this->ordered.get_pos(mid + adder - 2);
		upper4th = (g + h) / 2.0;
		lower4th = (this->ordered.get_pos(adder) + this->ordered.get_pos(adder - 1)) / 2.0;
	}
	else {
		adder = (mid / 2) + 1;
		upper4th = (this->ordered.get_pos(mid + adder));
		lower4th = this->ordered.get_pos(adder);

	}

	spread = upper4th - lower4th;

	outlearVal = spread * 1.5;

	XoutlearVal = spread * 3;

	for (int i = 0; i < ordered.get_size(); i++) {

		if (ordered.get_pos(i) > upper4th + outlearVal || ordered.get_pos(i) < lower4th - outlearVal) {
			if (ordered.get_pos(i) > upper4th + XoutlearVal || ordered.get_pos(i) < lower4th - outlearVal) {
				Xoutlear.insert(ordered.get_pos(i));
			}
			else {
				outlear.insert(ordered.get_pos(i));
			}
		}
	}

}



void app::calculateSampleVarience() {

	Node *pCur = this->original.getHead();
	double sum1 = 0;
	while (pCur != nullptr) {

		sum1 = sum1 + (pCur->get_value()*pCur->get_value());
		pCur = pCur->get_pNext();
	}
	Xi = sum1;
	double c = (double)(this->ordered.get_size());

	double a = (1.0 / (c - 1));

	double b = ((1.0 / c)*sum*sum);
	SampleVarience = a * (Xi - b);

}


void app::calculateStandardDev() {
	StandardDev = pow(SampleVarience, .5);
}