// Logger.h
#include <iostream>
#include <fstream>
#include <pthread.h>
#include <deque>
#include <unistd.h>

using namespace std;

class Logger {
public:
	Logger(const char* cFilePath);
        //Push message into the Log file
	void Log(char* cMessage);
	//function to write into log
	void WriteToLogFile();
	//function to stop logger 
	//Alway call just before exiting the program
	void StopLogger();
	//Destructor:
	~Logger() {
		// release the mutext and conditional variable
	}
private:
	std::deque<char*> cMessageQueue; // collection to hold the messages
	pthread_t m_pTid; // Param to hold the Thread ID
	pthread_mutex_t m_Mutex; // Mutex
	pthread_cond_t m_Cond_Variable; // Condition variable
	std::ofstream m_LogFile; // Log File to write into
	short int m_bStopLogger; // Flag to stop the Logger thread
};

void* WriteToFIleHelper( void* args)
{
	static Logger* logger = NULL;
	if ( NULL == logger )
	{
		logger = (Logger*) args;
	}
	if ( NULL == logger )
	{
		cerr << "logger NULL\n";
		_exit(1);
	}
	logger->WriteToLogFile();
	return logger;
}

// Constructor: Open the log file in append mode.
// creates a logger thread.
Logger::Logger(const char* cFilePath) {
	m_bStopLogger = 0;
	// Open the log file in append mode
	m_LogFile.open(cFilePath, std::ios::app);
	printf("File created \n");
        //create the logger thread
        m_pTid = 1;
        pthread_create(&m_pTid, NULL, WriteToFIleHelper, (void*) this);
	//pthread_join(m_pTid, NULL);
	printf("Thread Created \n");
	//Initialize condition variable
	if (pthread_cond_init(&m_Cond_Variable, NULL) != 0) {
		printf("Condition variable initialization has failed \n");
	}
	printf("condition variable intialized \n");
        // Initialize the mutex variable	 
        if (pthread_mutex_init(&m_Mutex, NULL) !=0){
		printf("Mutex initialization has failed \n");
	}
	printf("Mutex initialized \n");
}

void Logger::WriteToLogFile() {
	while(1) {
		cout<< pthread_self() << " : Logger Thread LOCKING" <<endl;
		pthread_mutex_lock(&m_Mutex);
		cout<< pthread_self() << " : Logger Thread LOCKED" <<endl;
		// when the StopLogger is set from the main thread
		//if (m_bStopLogger) {
		if (m_bStopLogger && cMessageQueue.empty()) {
			 // unlock the mutex and exit the logger thread
			 cout<< pthread_self() << " : Logger Thread UNLOCKING" <<endl;
                         pthread_mutex_unlock(&m_Mutex);
			 cout<< pthread_self() << " : Logger Thread UNLOCKED" <<endl;
			 cout<< pthread_self() << " : Logger Thread Exiting" << endl;
                         pthread_exit(NULL);
                 }
	        // When the queue is empty and StopLogger is not set
		//while (m_bStopLogger == 0 && cMessageQueue.empty()) {
		while (cMessageQueue.empty()) {
	 		pthread_cond_wait(&m_Cond_Variable, &m_Mutex); // Wait for a message to be written into the queue.	
		}
		// When the queue is not empty
        	m_LogFile << (cMessageQueue.front()); // Write the message into the log file
		m_LogFile << endl;
		cMessageQueue.pop_front(); // Remove the message from the queue after it has been written
		printf("Log file written \n");
		cout<< pthread_self() << " : Logger Thread UNLOCKING" <<endl;
		pthread_mutex_unlock(&m_Mutex); // unlock the mutex
		cout<< pthread_self() << " : Logger Thread UNLOCKED" <<endl;
       	}
}

void Logger::Log(char* cMessage){
	printf("Log entered \n");
	cout<< pthread_self() << " : Main Thread LOCKING" <<endl;
	pthread_mutex_lock(&m_Mutex);
	cout<< pthread_self() << " : Main Thread LOCKED" <<endl;
	cMessageQueue.push_back(cMessage);
	printf("message added to the queue \n");
	cout<< pthread_self() << " : Main Thread UNLOCKING" <<endl;
	pthread_mutex_unlock(&m_Mutex);
	cout<< pthread_self() << " : Main Thread UNLOCKED" <<endl;
	cout << pthread_self() << " Before pthread_cond_signal\n";
	cout.flush();
	pthread_cond_signal(&m_Cond_Variable); // Signal the waiting thread to write the message into log file
	cout << pthread_self() << " After  pthread_cond_signal\n";
	cout.flush();
}

void Logger::StopLogger() {
	cout<< pthread_self() << " : Main Thread LOCKING" <<endl;
	pthread_mutex_lock(&m_Mutex);
	cout<< pthread_self() << " : Main Thread LOCKED" <<endl;
	m_bStopLogger = 1;
	cout<< pthread_self() << " : Main Thread UNLOCKING" <<endl;
	pthread_mutex_unlock(&m_Mutex);
	cout<< pthread_self() << " : Main Thread UNLOCKED" <<endl;
	cout << pthread_self() << " : Main Thread JOINING" << endl;
	pthread_join(m_pTid, NULL);
	cout << pthread_self() << " : Main thread JOINED" << endl;
}


//Driver for logger
int main() {
	Logger logger("/home/saja4018/SampleProgram/LogFile");
	for (int i = 0; i < 10; i++) {
	cout << i << endl;
		logger.Log((char*)("Hello World"));
		logger.Log((char*)("Hello Earth"));
		logger.Log((char*)("Hello Moon"));
	}	
	logger.StopLogger();
	return 0;
}	
