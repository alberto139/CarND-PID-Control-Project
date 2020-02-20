# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

## PID Comonents

![PID](https://classroom.udacity.com/nanodegrees/nd013/parts/01a340a5-39b5-4202-9f89-d96de8cf17be/modules/3e2b027e-1822-4638-a58a-def1e64258a8/lessons/48c5e9c4-f72b-4c7c-8375-ea4eda220e39/concepts/db31b93d-6741-4e5c-b63c-fa6dd5c170ff#)
From Udacity

# Proportional

 The derivative is the rate of change between the last error and the current error. This term is helpful in not overshooting the controller’s goal and then having an error in the opposite direction. 

`P = -Kp * p_error;` In this care the `p_error` is equal to the cross track error.


# Derivative

The derivative component is really the rate of change of the last error and the current error. Substracting this difference from the <b>P</b> component, we will not overshoot the 

`D = -Kd * d_error;`, where `d_error` is the difference between the current error and the previous error


# Integral

The integral component is the summation of the previous errors. This helps when the system consistently has a small amount of error. The accumulation over time of a small error would then be amplified as a much larger error by the integral component and then corrected by the controller.

`I = -Ki * i_error;`, where `i_error` is the sumation of all previoius errors.

# Parameter Tunning

The parameter where tuned manually but with intuition as to what each of them would work in isolation.
For <b>Kp</b> parameter, I started at 1.0 and slowly decreased the value until the car in the simulator was oscillating back and forth similar to the blue line in the image above. I actually went very low with this value until the car could do wide turns, but if the value is too small the steering response will also be too small when the error is large. So quite a bit of oscillating is acceptable because our next component will mitigate it.

Next, I set the For <b>Kd</b> parameter. For this one I also started at 1.0 and at this point the car could get around the course! I made it a little smaller than that to have smoother stearing values.

Lastly I set the <b>Ki</b>. The integral component is not really necessary for this particular case, but I found it to make the car slightly smoother. The <b>Kd</b> value should a few orders of magnitude smaller that the Propertional or Derivative parameters since it will be multiplied by the accumulated error over time, which can get very large very quickly. For this one I started at 0.1 and made it a whole order of magnitue smaller after every test.


---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

Fellow students have put together a guide to Windows set-up for the project [here](https://s3-us-west-1.amazonaws.com/udacity-selfdrivingcar/files/Kidnapped_Vehicle_Windows_Setup.pdf) if the environment you have set up for the Sensor Fusion projects does not work for this project. There's also an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3).

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./

## How to write a README
A well written README file can enhance your project and portfolio.  Develop your abilities to create professional README files by completing [this free course](https://www.udacity.com/course/writing-readmes--ud777).

