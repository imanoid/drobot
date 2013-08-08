
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include "stdlib.h"
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <map>

#include "time.h"
#include "sys/time.h"

#include <pthread.h>

using namespace std;
#include "rs232.h"

namespace drobot {
namespace device {
namespace rs232 {

#ifdef __linux__   /* Linux */

int Cport[22],
    error;

struct termios new_port_settings,
       old_port_settings[22];

char comports[22][13]={"/dev/ttyS0","/dev/ttyS1","/dev/ttyS2","/dev/ttyS3","/dev/ttyS4","/dev/ttyS5",
                       "/dev/ttyS6","/dev/ttyS7","/dev/ttyS8","/dev/ttyS9","/dev/ttyS10","/dev/ttyS11",
                       "/dev/ttyS12","/dev/ttyS13","/dev/ttyS14","/dev/ttyS15","/dev/ttyUSB0",
                       "/dev/ttyUSB1","/dev/ttyUSB2","/dev/ttyUSB3","/dev/ttyUSB4","/dev/ttyUSB5"};

int OpenComport(int comport_number, int baudrate) {
  int baudr;

  if((comport_number>21)||(comport_number<0)) {
    printf("illegal comport number\n");
    return(1);
  }

  switch(baudrate) {
    case      50 : baudr = B50;
                   break;
    case      75 : baudr = B75;
                   break;
    case     110 : baudr = B110;
                   break;
    case     134 : baudr = B134;
                   break;
    case     150 : baudr = B150;
                   break;
    case     200 : baudr = B200;
                   break;
    case     300 : baudr = B300;
                   break;
    case     600 : baudr = B600;
                   break;
    case    1200 : baudr = B1200;
                   break;
    case    1800 : baudr = B1800;
                   break;
    case    2400 : baudr = B2400;
                   break;
    case    4800 : baudr = B4800;
                   break;
    case    9600 : baudr = B9600;
                   break;
    case   19200 : baudr = B19200;
                   break;
    case   38400 : baudr = B38400;
                   break;
    case   57600 : baudr = B57600;
                   break;
    case  115200 : baudr = B115200;
                   break;
    case  230400 : baudr = B230400;
                   break;
    case  460800 : baudr = B460800;
                   break;
    case  500000 : baudr = B500000;
                   break;
    case  576000 : baudr = B576000;
                   break;
    case  921600 : baudr = B921600;
                   break;
    case 1000000 : baudr = B1000000;
                   break;
    default      : printf("invalid baudrate\n");
                   return(1);
                   break;
  }

  Cport[comport_number] = open(comports[comport_number], O_RDWR | O_NOCTTY | O_NDELAY);
  if(Cport[comport_number]==-1) {
    perror("unable to open comport ");
    return(1);
  }

  error = tcgetattr(Cport[comport_number], old_port_settings + comport_number);
  if(error==-1) {
    close(Cport[comport_number]);
    perror("unable to read portsettings ");
    return(1);
  }

  memset(&new_port_settings, 0, sizeof(new_port_settings));  /* clear the new struct */

  new_port_settings.c_cflag = baudr | CS8 | CLOCAL | CREAD;
  new_port_settings.c_iflag = IGNPAR;
  new_port_settings.c_oflag = 0;
  new_port_settings.c_lflag = 0;
  new_port_settings.c_cc[VMIN] = 0;      /* block untill n bytes are received */
  new_port_settings.c_cc[VTIME] = 0;     /* block untill a timer expires (n * 100 mSec.) */
  error = tcsetattr(Cport[comport_number], TCSANOW, &new_port_settings);

  if(error==-1) {
    close(Cport[comport_number]);
    perror("unable to adjust portsettings ");
    return(1);
  }

  return(0);
}


int PollComport(int comport_number, unsigned char *buf, int size) {
  int n;

#ifndef __STRICT_ANSI__                       /* __STRICT_ANSI__ is defined when the -ansi option is used for gcc */
  if(size>SSIZE_MAX)  size = (int)SSIZE_MAX;  /* SSIZE_MAX is defined in limits.h */
#else
  if(size>4096)  size = 4096;
#endif

  n = read(Cport[comport_number], buf, size);

  return(n);
}


int SendByte(int comport_number, unsigned char byte) {
  int n;

  n = write(Cport[comport_number], &byte, 1);
  if(n<0)  return(1);

  return(0);
}


int SendBuf(int comport_number, unsigned char *buf, int size) {
  return(write(Cport[comport_number], buf, size));
}


void CloseComport(int comport_number) {
  close(Cport[comport_number]);
  tcsetattr(Cport[comport_number], TCSANOW, old_port_settings + comport_number);
}

/*
Constant  Description
TIOCM_LE  DSR (data set ready/line enable)
TIOCM_DTR DTR (data terminal ready)
TIOCM_RTS RTS (request to send)
TIOCM_ST  Secondary TXD (transmit)
TIOCM_SR  Secondary RXD (receive)
TIOCM_CTS CTS (clear to send)
TIOCM_CAR DCD (data carrier detect)
TIOCM_CD  Synonym for TIOCM_CAR
TIOCM_RNG RNG (ring)
TIOCM_RI  Synonym for TIOCM_RNG
TIOCM_DSR DSR (data set ready)
*/

int IsCTSEnabled(int comport_number) {
  int status;

  status = ioctl(Cport[comport_number], TIOCMGET, &status);

  if(status&TIOCM_CTS) return(1);
  else return(0);
}

int RS232_OpenPort(const char *deviceName, int baudRate, bool hardwareFlowControl, struct termios *initialPortSettings) {
    struct termios portSettings;
    int baudRateCode, portFileDescriptor;

    switch(baudRate) {
    case      50 : baudRateCode = B50;
                   break;
    case      75 : baudRateCode = B75;
                   break;
    case     110 : baudRateCode = B110;
                   break;
    case     134 : baudRateCode = B134;
                   break;
    case     150 : baudRateCode = B150;
                   break;
    case     200 : baudRateCode = B200;
                   break;
    case     300 : baudRateCode = B300;
                   break;
    case     600 : baudRateCode = B600;
                   break;
    case    1200 : baudRateCode = B1200;
                   break;
    case    1800 : baudRateCode = B1800;
                   break;
    case    2400 : baudRateCode = B2400;
                   break;
    case    4800 : baudRateCode = B4800;
                   break;
    case    9600 : baudRateCode = B9600;
                   break;
    case   19200 : baudRateCode = B19200;
                   break;
    case   38400 : baudRateCode = B38400;
                   break;
    case   57600 : baudRateCode = B57600;
                   break;
    case  115200 : baudRateCode = B115200;
                   break;
    case  230400 : baudRateCode = B230400;
                   break;
    case  460800 : baudRateCode = B460800;
                   break;
    case  500000 : baudRateCode = B500000;
                   break;
    case  576000 : baudRateCode = B576000;
                   break;
    case  921600 : baudRateCode = B921600;
                   break;
    case 1000000 : baudRateCode = B1000000;
                   break;
    default      : return -1;
                   break;
    }

    portFileDescriptor = open(deviceName, O_RDWR | O_NOCTTY | O_NDELAY);
    if(portFileDescriptor == -1) {
        return -1;
    }

    if(initialPortSettings != NULL) {
        if(tcgetattr(portFileDescriptor, initialPortSettings) == -1) {
            return -1;
        }
    }

    memset(&portSettings, 0, sizeof(portSettings));

    if(hardwareFlowControl) {
        portSettings.c_cflag 	= baudRateCode | CS8 | CLOCAL | CREAD | CRTSCTS;
    }
    else {
        portSettings.c_cflag 	= baudRateCode | CS8 | CLOCAL | CREAD;
    }

    portSettings.c_iflag 		= IGNPAR;
    portSettings.c_oflag 		= 0;
    portSettings.c_lflag 		= 0;
    portSettings.c_cc[VMIN] 	= 0;      	/* block until n bytes are received */
    portSettings.c_cc[VTIME] 	= 0;     	/* block until a timer expires (n * 100 mSec.) */

    if(tcsetattr(portFileDescriptor, TCSANOW, &portSettings) == -1) {
        close(portFileDescriptor);
        return -1;
    }

    return portFileDescriptor;
}

int RS232_SendBuffer(int portFileDescriptor, unsigned char *data, int size) {
    return write(portFileDescriptor, data, size);
}

int RS232_ReceiveBuffer(int portFileDescriptor, unsigned char *data, int size) {
    #ifndef __STRICT_ANSI__ 		// __STRICT_ANSI__ is defined when the -ansi option is used for GCC
        if(size>SSIZE_MAX) {
            size = (int)SSIZE_MAX; 	// SSIZE_MAX is defined in limits.h
        }
    #else
        if(size > 4096) {
            size = 4096;
        }
    #endif

    return read(portFileDescriptor, data, size);
}

void RS232_ClosePort(int portFileDescriptor, struct termios *initialPortSettings) {
    close(portFileDescriptor);

    if(initialPortSettings != NULL) {
        tcsetattr(portFileDescriptor, TCSANOW, initialPortSettings);
    }
}

#else         /* windows */

HANDLE Cport[16];

char comports[16][10]={"\\\\.\\COM1",  "\\\\.\\COM2",  "\\\\.\\COM3",  "\\\\.\\COM4",
                       "\\\\.\\COM5",  "\\\\.\\COM6",  "\\\\.\\COM7",  "\\\\.\\COM8",
                       "\\\\.\\COM9",  "\\\\.\\COM10", "\\\\.\\COM11", "\\\\.\\COM12",
                       "\\\\.\\COM13", "\\\\.\\COM14", "\\\\.\\COM15", "\\\\.\\COM16"};

char baudr[64];

int OpenComport(int comport_number, int baudrate) {
  if((comport_number>15)||(comport_number<0)) {
    printf("illegal comport number\n");
    return(1);
  }

  switch(baudrate) {
    case     110 : strcpy(baudr, "baud=110 data=8 parity=N stop=1");
                   break;
    case     300 : strcpy(baudr, "baud=300 data=8 parity=N stop=1");
                   break;
    case     600 : strcpy(baudr, "baud=600 data=8 parity=N stop=1");
                   break;
    case    1200 : strcpy(baudr, "baud=1200 data=8 parity=N stop=1");
                   break;
    case    2400 : strcpy(baudr, "baud=2400 data=8 parity=N stop=1");
                   break;
    case    4800 : strcpy(baudr, "baud=4800 data=8 parity=N stop=1");
                   break;
    case    9600 : strcpy(baudr, "baud=9600 data=8 parity=N stop=1");
                   break;
    case   19200 : strcpy(baudr, "baud=19200 data=8 parity=N stop=1");
                   break;
    case   38400 : strcpy(baudr, "baud=38400 data=8 parity=N stop=1");
                   break;
    case   57600 : strcpy(baudr, "baud=57600 data=8 parity=N stop=1");
                   break;
    case  115200 : strcpy(baudr, "baud=115200 data=8 parity=N stop=1");
                   break;
    case  128000 : strcpy(baudr, "baud=128000 data=8 parity=N stop=1");
                   break;
    case  256000 : strcpy(baudr, "baud=256000 data=8 parity=N stop=1");
                   break;
    default      : printf("invalid baudrate\n");
                   return(1);
                   break;
  }

  Cport[comport_number] = CreateFileA(comports[comport_number],
                      GENERIC_READ|GENERIC_WRITE,
                      0,                          /* no share  */
                      NULL,                       /* no security */
                      OPEN_EXISTING,
                      0,                          /* no threads */
                      NULL);                      /* no templates */

  if(Cport[comport_number]==INVALID_HANDLE_VALUE) {
    printf("unable to open comport\n");
    return(1);
  }

  DCB port_settings;
  memset(&port_settings, 0, sizeof(port_settings));  /* clear the new struct  */
  port_settings.DCBlength = sizeof(port_settings);

  if(!BuildCommDCBA(baudr, &port_settings)) {
    printf("unable to set comport dcb settings\n");
    CloseHandle(Cport[comport_number]);
    return(1);
  }

  if(!SetCommState(Cport[comport_number], &port_settings)) {
    printf("unable to set comport cfg settings\n");
    CloseHandle(Cport[comport_number]);
    return(1);
  }

  COMMTIMEOUTS Cptimeouts;

  Cptimeouts.ReadIntervalTimeout         = MAXDWORD;
  Cptimeouts.ReadTotalTimeoutMultiplier  = 0;
  Cptimeouts.ReadTotalTimeoutConstant    = 0;
  Cptimeouts.WriteTotalTimeoutMultiplier = 0;
  Cptimeouts.WriteTotalTimeoutConstant   = 0;

  if(!SetCommTimeouts(Cport[comport_number], &Cptimeouts)) {
    printf("unable to set comport time-out settings\n");
    CloseHandle(Cport[comport_number]);
    return(1);
  }

  return(0);
}


int PollComport(int comport_number, unsigned char *buf, int size) {
  int n;

  if(size>4096)  size = 4096;

/* added the void pointer cast, otherwise gcc will complain about */
/* "warning: dereferencing type-punned pointer will break strict aliasing rules" */

  ReadFile(Cport[comport_number], buf, size, (LPDWORD)((void *)&n), NULL);

  return(n);
}


int SendByte(int comport_number, unsigned char byte) {
  int n;

  WriteFile(Cport[comport_number], &byte, 1, (LPDWORD)((void *)&n), NULL);

  if(n<0)  return(1);

  return(0);
}


int SendBuf(int comport_number, unsigned char *buf, int size) {
  int n;

  if(WriteFile(Cport[comport_number], buf, size, (LPDWORD)((void *)&n), NULL)) {
    return(n);
  }

  return(-1);
}


void CloseComport(int comport_number) {
  CloseHandle(Cport[comport_number]);
}


int IsCTSEnabled(int comport_number) {
  int status;

  GetCommModemStatus(Cport[comport_number], (LPDWORD)((void *)&status));

  if(status&MS_CTS_ON) return(1);
  else return(0);
}


#endif


void cprintf(int comport_number, const char *text)  /* sends a string to serial port */ {
  while(*text != 0)   SendByte(comport_number, *(text++));
}

}
}
}
