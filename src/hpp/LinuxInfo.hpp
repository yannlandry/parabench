// class LinuxInfo: singleton to pull PC data

class LinuxInfo {

private:
	static LinuxInfo* _linuxInfo; // singleton

	string _cpuName;
	int _cpuCores;
	int _cpuThreads;

	LinuxInfo();
	// protect from copy
	LinuxInfo(const LinuxInfo&);
	void operator=(const LinuxInfo&);

public:
	static LinuxInfo* get();

	string getCpuName();
	int getCpuCores();
	int getCpuThreads();

};