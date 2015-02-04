#include "hpp/timer.hpp"
#include <stdexcept>


Timer::Timer() {
	reset();
}

void Timer::start() {
	if(_ran)
		throw std::logic_error("Timer has already run.");
	else if(_running)
		throw std::logic_error("Timer already running.");
	
	clock_gettime(CLOCK_THREAD_CPUTIME_ID, &_start);
	_running = true;
}

void Timer::stop() {
	if(!_running)
		throw std::logic_error("Timer not running.");
	
	clock_gettime(CLOCK_THREAD_CPUTIME_ID, &_end);
	_runtime = (_end.tv_sec - _start.tv_sec) + (_end.tv_nsec - _start.tv_nsec)
					/ (double)1000000000;

	_running = false;
	_ran = true;
}

void Timer::reset() {
	_running = false;
	_ran = false;
	_runtime = 0.0;

	_start.tv_sec = 0;
	_start.tv_nsec = 0;
	_end.tv_sec = 0;
	_end.tv_nsec = 0;
}

bool Timer::isRunning() {
	return _running;
}

bool Timer::hasRun() {
	return _ran;
}

double Timer::getRuntime() {
	return _runtime;
}