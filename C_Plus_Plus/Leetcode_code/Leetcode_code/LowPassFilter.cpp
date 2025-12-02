#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>  //用于保留小数点有效位数
//#define _USE_MATH_DEFINES // 在某些编译器（如Visual Studio）中需要此行来启用M_PI的定义

using namespace std;

// 低通滤波器类
class LowPassFilter {
public:
	LowPassFilter(double sample_rate, double cutoff_frequency) {
		// 后向差分离散化
		/*double Ts = 1.0 / sample_rate;
		double RC = 1.0 / (cutoff_frequency * 2.0 * M_PI);
		alpha_ = Ts / (Ts + RC);*/

		// 双线性变换法--来离散化
		double Ts = 1.0 / sample_rate;
		alpha_ = 2.0 / (Ts * 2 * M_PI * cutoff_frequency);

		pre_input_ = 0.0;
		pre_output_ = 0.0;
	}

	// 更新滤波器输出
	double update(double input) {
		// double output = alpha_ * input + (1.0 - alpha_) * prev_output_; // 后向差分离散化

		double output = 1.0 / (1 + alpha_) * input + 1.0 / (1 + alpha_) * pre_input_ - (1 - alpha_) / (1 + alpha_) * pre_output_;
		pre_output_ = output;
		pre_input_ = input;
		return output ;
	}

private:
	double alpha_;
	double pre_input_;
	double pre_output_;
};

int main() {
	// 输入信号
	vector<double> input_signal = { 0.0,
						   0.0399893341866342,
						   0.0799146939691727,
						   0.119712207288919,
						   0.159318206614246,
						   0.198669330795061,
						   0.237702626427135,
						   0.276355648564114,
						   0.314566560616118,
						   0.352274233275090,
						   0.389418342308651,
						   0.425939465066000,
						   0.461779175541483,
						   0.496880137843737,
						   0.531186197920883,
						   0.564642473395035,
						   0.597195441362392,
						   0.628793024018469,
						   0.659384671971473,
						   0.688921445110551,
						   0.717356090899523,
						   0.744643119970859,
						   0.770738878898969,
						   0.795601620036366,
						   0.819191568300998,
						   0.841470984807897,
						   0.862404227243338,
						   0.881957806884948,
						   0.900100442176505,
						   0.916803108771767,
						   0.932039085967226,
						   0.945783999449539,
						   0.958015860289225,
						   0.968715100118265,
						   0.977864602435316,
						   0.985449729988460,
						   0.991458348191686,
						   0.995880844537640,
						   0.998710143975583,
						   0.999941720229966 };
	// 保留5位小数，写一次即可
	cout << fixed << setprecision(5);

	// 采样率和截止频率
	double sample_rate = 100.0;      // 单位：Hz
	double cutoff_frequency = 1.0;  // 单位：Hz

	// 创建低通滤波器
	LowPassFilter filter(sample_rate, cutoff_frequency);

	// 对输入信号进行滤波
	vector<double> output_signal;
	for (double input : input_signal) {
		double output = filter.update(input);
		output_signal.emplace_back(output);
	}

	// 计算 dy/dt --- 三点后向差分求导
	vector<double> dy_dt_data;
	dy_dt_data.emplace_back(0);
	dy_dt_data.emplace_back((-4.0 * output_signal[0] + 3.0 * output_signal[1])* sample_rate / 2.0);
	for(int i = 2; i < output_signal.size(); i++){
		double dy_dt = (output_signal[i-2] - 4 * output_signal[i-1] + 3 * output_signal[i]) * sample_rate / 2.0;
		dy_dt_data.emplace_back(dy_dt);
	}
	
	// 输出滤波结果
	for (int i = 0; i < input_signal.size(); i++) {
		cout << "x = " << input_signal[i] << "," 
			 << "y = " << output_signal[i] << "," 
			 << "dy/dt = " << dy_dt_data[i] << endl;
	}

	return 0;
}