#include <ctime>


class Timer {

private:
	timespec _start;
	timespec _end;

	bool _running, _ran;
	double _runtime;

public:
	Timer();

	void start();
	void stop();
	void reset();

	bool isRunning();
	bool hasRun();
	double getRuntime();

};