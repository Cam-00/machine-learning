/**
 * 
 * kalman Filter(KF) definition
 *
 * */

#include <math.h>
#include <iostream>
#include "kalman_filter.h"

using Eigen::MatrixXd;
using Eigen::VectorXd;

KalmanFilter::KalmanFilter(int stateSize = 0, int measSize = 0, int uSize = 0) : stateSize_(stateSize), measureSize_(measSize), uSize_(uSize) {
	if (stateSize_ == 0 || measureSize_ == 0)
	{	// std::cerr 与 std::cout 区别：std::cerr不需要缓冲，直接输出，而std::cout需要缓冲
		std::cerr << "Error, State size and measurement size must bigger than 0\n";
	}

	x_.resize(stateSize_);
	x_.setZero();

	A_.resize(stateSize_, stateSize_);
	A_.setIdentity();

	u_.resize(uSize_);
	u_.transpose();
	u_.setZero();

	B_.resize(stateSize_, uSize_);
	B_.setZero();

	P_.resize(stateSize_, stateSize_);
	P_.setIdentity();

	H_.resize(measureSize_, stateSize_);
	H_.setZero();

	Q_.resize(stateSize_, stateSize_);
	Q_.setZero();

	R_.resize(measureSize_, measureSize_);
	R_.setZero();
}

KalmanFilter::~KalmanFilter() {}

void KalmanFilter::Init(const Eigen::VectorXd& x_0, const Eigen::MatrixXd& P_0, 
						const Eigen::MatrixXd& Q_0, const Eigen::MatrixXd& R_0) {
	/**
	  * Initialize Kalman filter
	*/
	x_ = x_0;
	P_ = P_0;
	Q_ = Q_0;
	R_ = R_0;
}

void KalmanFilter::Predict(const Eigen::MatrixXd& A) {
	/**
	  * predict the state and the state covariance
	  * using process model by ignoring control input
	*/
	A_ = A;
	// 预测当前状态
	x_ = A_ * x_;
	MatrixXd A_T = A_.transpose();
	// 预测当前状态的协方差矩阵
	P_ = A_ * P_ * A_T + Q_;
	
}

void KalmanFilter::Predict(const Eigen::MatrixXd& A, const Eigen::MatrixXd& B, const Eigen::VectorXd& u) {
	/**
	  * predict the state and the state covariance
	  * using process model by considering control input
	*/
	A_ = A;
	B_ = B;
	u_ = u;
	x_ = A_ * x_ + B_ * u_;
	MatrixXd A_T = A.transpose();
	P_ = A_ * P_ * A_T + Q_;
	
}

VectorXd KalmanFilter::Update(const Eigen::VectorXd& z, const Eigen::MatrixXd& H) {
	/**
	  * update the state by using true measurement vector 
	  * and the predicted state
	*/
	H_ = H;
	
	MatrixXd H_T = H_.transpose();
	MatrixXd PH_T = P_ * H_T;
	MatrixXd S = H_ * PH_T + R_;
	MatrixXd S_inv = S.inverse();

	MatrixXd K = PH_T * S_inv; // kalman gain

	//update state and state covariance estimates
	x_ = x_ + K * (z - H_ * x_);
	MatrixXd I = MatrixXd::Identity(stateSize_, stateSize_);
	P_ = (I - K * H_) * P_;

	return x_;

}
