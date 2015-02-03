class Timer {

private:
	timespec _start;
	timespec _stop;

public:
	Timer();

	void start();
	void stop();
	double getRuntime();

};