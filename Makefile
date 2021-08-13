
OBJS = AppDriver.o Reminder.o Appointment.o Day.o Calendar.o
EXE = calApp

CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
WFLAG = -w

$(EXE): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(EXE)

AppDriver.o : Reminder.o Appointment.o Day.o Calendar.o
	$(CC) $(CFLAGS) AppDriver.cpp

Reminder.o : Reminder.h
		$(CC) $(CFLAGS) Reminder.cpp

Appointment.o : Appointment.h 
		$(CC) $(CFLAGS) Appointment.cpp

Day.o :  Day.h 
		$(CC) $(CFLAGS)  Day.cpp

Calendar.o :  Calendar.h 
		$(CC) $(CFLAGS) $(WFLAG)  Calendar.cpp

clean:
	rm *.o $(EXE) *~ -v
