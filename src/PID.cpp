#include "PID.h"
#include "iostream"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;

  d_error = 0;
  i_error = 0;
  p_error = 0;

}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */

  // Derivative or rate of change from last error (d_error) to current error (cte)
  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;

}

double PID::Run(double cte) {
  /**
   * TODO:Get PID result
   */

  // Proportional Component
  double P = -Kp * p_error;
  std::cout << "P: " << P << std::endl;
  // Derivative Component
  double D = -Kd * d_error;
  std::cout << "D: " << D << std::endl;

  // Integral Component
  double I = -Ki * i_error;
  std::cout << "I: " << I << std::endl;

  //return (- Kp * p_error - Kd * d_error - Ki * i_error);
  return P + D + I;

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return 0.0;  // TODO: Add your total error calc here!
}