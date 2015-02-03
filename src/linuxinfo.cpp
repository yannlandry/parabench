#include "hpp/linuxinfo.hpp"
#include <iostream>
#include <fstream>


LinuxInfo* LinuxInfo::_linuxInfo = nullptr;

LinuxInfo::LinuxInfo(): _cpuName(), _cpuCores(0), _cpuThreads(0) {
	std::ifstream cpuinfo("/proc/cpuinfo");
	std::string data;

	while(_cpuName.size() == 0 || _cpuCores == 0 || _cpuThreads == 0) {
		std::getline(cpuinfo, data);

		if(data.substr(0,10) == "model name")
			_cpuName = data.substr(data.find(":")+2);
		else if(data.substr(0,8) == "siblings")
			_cpuThreads = std::stoi(data.substr(data.find(":")+2));
		else if(data.substr(0,9) == "cpu cores")
			_cpuCores = std::stoi(data.substr(data.find(":")+2));
	}
}

LinuxInfo* LinuxInfo::get() {
	if(!_linuxInfo)
		_linuxInfo = new LinuxInfo;
	return _linuxInfo;
}

std::string LinuxInfo::getCpuName() {
	return _cpuName;
}

int LinuxInfo::getCpuCores() {
	return _cpuCores;
}

int LinuxInfo::getCpuThreads() {
	return _cpuThreads;
}