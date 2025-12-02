/**
 *
 * kalman filter(KF) header
 *
 *
 * */

#pragma once
#ifndef _KALMAN_FILTER_H_
#define _KALMAN_FILTER_H_
#include <Eigen/Dense>  // Eigen头文件，<Eigen/Dense>包含Eigen库里面所有的函数和类

class KalmanFilter {

private:

	//state variable's dimenssion
	int stateSize_; 

	//measurement variable's dimession
	int measureSize_; 

	//control variables's dimenssion
	int uSize_; 

	// state vector
	Eigen::VectorXd x_;

	// control input vector
	Eigen::VectorXd u_;

	// state covariance matrix
	Eigen::MatrixXd P_;

	// state transition matrix
	Eigen::MatrixXd A_;

	// control transition matrix
	Eigen::MatrixXd B_; 

	// measurement matrix
	Eigen::MatrixXd H_;

	// process covariance matrix
	Eigen::MatrixXd Q_;

	// measurement covariance matrix
	Eigen::MatrixXd R_;


public:
	/**
	 * Constructor
	 */
	KalmanFilter(int stateSize, int measSize, int uSize);

	/**
	 * Destructor
	 */
	virtual ~KalmanFilter();

	/**
	 * Init Initializes Kalman filter
	 * @param x_0 Initial state
	 * @param P_0 Initial state covariance
	 * @param Q_0 Process covariance matrix
	 * @param R_0 Measurement covariance matrix
	 */
	void Init(const Eigen::VectorXd& x_0, const Eigen::MatrixXd& P_0, 
			const Eigen::MatrixXd& Q_0, const Eigen::MatrixXd& R_0);

	/**
	 * Prediction Predicts the state and the state covariance
	 * using the process model by ignoring control input vector
	 * @param A State transition matrix
	 * return x_
	 */
	void Predict(const Eigen::MatrixXd& A);

	/**
	 * Prediction Predicts the state and the state covariance
	 * using the process model by considering control input vector
	 * @param A State transition matrix
	 * @param B Control transition matrix
	 * @param u Control input vector
	 * return x_
	 */
	void Predict(const Eigen::MatrixXd& A, const Eigen::MatrixXd& B, const Eigen::VectorXd& u);

	/**
	 * Updates the state by using standard Kalman Filter equations
	 * @param z The measurement at k time(current)
	 * @param H Measurement Matrix
	 */
	Eigen::VectorXd Update(const Eigen::VectorXd& z, const Eigen::MatrixXd& H);

};

#endif /* _KALMAN_FILTER_H_ */
