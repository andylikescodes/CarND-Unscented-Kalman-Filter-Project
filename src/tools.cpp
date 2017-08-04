#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
	VectorXd RMSE(4);
	RMSE << 0, 0, 0, 0;
	if ((estimations.size() != ground_truth.size()) || estimations.size() == 0){
		std::cout << "Incorrect size of estimations" << std::endl;
		return RMSE;
	}

	for (unsigned int i =0; i < estimations.size(); i++){
		VectorXd residual = estimations[i] - ground_truth[i];
		residual = residual.array()*residual.array();
		RMSE += residual;
	}

	RMSE = RMSE/estimations.size();
	RMSE = RMSE.array().sqrt();

	return RMSE;
}

void Tools::Debug(int i){
	cout << "Debug print " << i << endl;
}