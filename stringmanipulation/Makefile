all:
	@/usr/bin/ls -tr *.c *.pc *.cpp 2>&1 |\
	/usr/bin/tail -1 |\
	/usr/bin/grep -E -v "^$$" >/dev/null 2>&1;\
	Ret=$$?;\
	if [ 0 -ne $$Ret ];\
	then\
		echo "No C/C++/PRO*C files";\
	else\
		SRC=$$(/usr/bin/ls -tr *.pc *.c *.cpp 2>&1 |\
		/usr/bin/tail -1);\
		if [ "server.cpp" = "$$SRC" ];\
		then\
			BINARYNAME="./server";\
		else\
			BINARYNAME="./a.out";\
		fi;\
		if [ "sql_cursor_thread.cpp" = "$$SRC" ];\
		then\
			/usr/bin/make sql_cursor_thread;\
		elif [ ! -f $$BINARYNAME ];\
		then\
			echo "$$SRC" | /usr/bin/grep -E "\.c$$|\.C$$|\.cpp$$|\.CPP$$" >/dev/null 2>&1;\
			Ret=$$?;\
			if [ 0 -eq $$Ret ];\
			then\
				/usr/bin/grep -l "pthread_create" $$SRC >/dev/null 2>&1;\
				Ret=$$?;\
				if [ 0 -eq $$Ret ];\
				then\
					echo /usr/bin/g++.1 -g -Wall -lpthread $$SRC -o $$BINARYNAME;\
					/usr/bin/g++ -g -Wall -lpthread $$SRC -o $$BINARYNAME;\
				else\
					echo /usr/bin/g++.1 -g -Wall $$SRC -o $$BINARYNAME;\
					/usr/bin/g++ -g -Wall $$SRC -o $$BINARYNAME;\
				fi;\
			else\
				echo $$ORACLE_HOME/bin/proc \
				$$SRC \
				code=CPP \
				include='(/usr/lib/gcc/x86_64-redhat-linux/4.8.2/include,/usr/include/linux,/usr/include,/usr/lib/gcc/x86_64-redhat-linux/4.8.2/include,/usr/include/c++/4.8.2,/usr/include/c++/4.8.2/x86_64-redhat-linux)' \
				cpp_suffix=cpp;\
				$$ORACLE_HOME/bin/proc \
				$$SRC \
				code=CPP \
				include='(/usr/lib/gcc/x86_64-redhat-linux/4.8.2/include,/usr/include/linux,/usr/include,/usr/lib/gcc/x86_64-redhat-linux/4.8.2/include,/usr/include/c++/4.8.2,/usr/include/c++/4.8.2/x86_64-redhat-linux)' \
				cpp_suffix=cpp;\
				Ret=$$?;\
				if [ 0 -eq $$Ret ];\
				then\
					SRC=./sql_cursor_thread.cpp;\
					echo "/usr/bin/g++.3 -std=c++0x -g -Wall -lpthread $$SRC "$$ORACLE_HOME/lib/libsqlplus.a" -L$$ORACLE_HOME/lib -lclntsh -o ./sql_cursor_thread";\
					/usr/bin/g++ -std=c++0x -g -Wall -lpthread $$SRC "$$ORACLE_HOME/lib/libsqlplus.a" -L$$ORACLE_HOME/lib -lclntsh -o ./sql_cursor_thread;\
				fi;\
			fi;\
		else\
			/usr/bin/ls -tr $$BINARYNAME $$SRC 2>&1 |\
			/usr/bin/tail -1 |\
			/usr/bin/grep -E "$$BINARYNAME" >/dev/null 2>&1;\
			Ret=$$?;\
			if [ 0 -eq $$Ret ];\
			then\
				echo "$$BINARYNAME is up to date";\
			else\
				/usr/bin/grep -l "pthread_create" $$SRC >/dev/null 2>&1;\
				Ret=$$?;\
				if [ 0 -eq $$Ret ];\
				then\
					echo /usr/bin/g++.2 -g -Wall -lpthread $$SRC -o $$BINARYNAME;\
					/usr/bin/g++ -g -Wall -lpthread $$SRC -o $$BINARYNAME;\
				else\
					echo /usr/bin/g++.2 -g -Wall $$SRC -o $$BINARYNAME;\
					/usr/bin/g++ -g -Wall $$SRC -o $$BINARYNAME;\
				fi\
			fi;\
		fi;\
	fi
sql_cursor_thread:
	@SRC=./sql_cursor_thread.cpp;\
	echo "/usr/bin/g++.3 -g -Wall $$SRC "$$ORACLE_HOME/lib/libsqlplus.a" -L$$ORACLE_HOME/lib -lclntsh -o ./sql_cursor_thread";\
	/usr/bin/g++ -g -Wall $$SRC "$$ORACLE_HOME/lib/libsqlplus.a" -L$$ORACLE_HOME/lib -lclntsh -o ./sql_cursor_thread
clean:
	@UPTODATE="y";\
	for cleanfiles in a.out \
	server \
	sql_cursor_thread.lis \
	sql_cursor_thread \
	$$(/usr/bin/ls -tr core.[0-9]* 2>/dev/null);\
	do\
		if [ -f $$cleanfiles ];\
		then\
			echo "/usr/bin/rm $$cleanfiles";\
			/usr/bin/rm $$cleanfiles;\
			UPTODATE=$$?;\
		elif [ -d $$cleanfiles ];\
		then\
			echo "/usr/bin/rm -rf $$cleanfiles";\
			/usr/bin/rm -rf $$cleanfiles;\
			UPTODATE=$$?;\
		fi;\
	done;\
	if [ "y" = "$$UPTODATE" ];\
	then\
		echo "/usr/bin/make $@ is up to date";\
	fi
