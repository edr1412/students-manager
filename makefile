all: Unit.h Chart.h Student.h Student.cpp StudentList.h StudentList.cpp main.cpp
	g++ Unit.h Chart.h Student.h Student.cpp StudentList.h StudentList.cpp main.cpp -o main

clean:
	rm main