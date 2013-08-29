#ifndef DROBOT_DEVICE_DRIVER_RS232_H
#define DROBOT_DEVICE_DRIVER_RS232_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <string.h>

#ifdef __linux__

#include <termios.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>

#else

#include <windows.h>

#endif

namespace drobot {
namespace device {
namespace driver {
namespace rs232 {

int OpenComport(int, int);
int PollComport(int, unsigned char *, int);
int SendByte(int, unsigned char);
int SendBuf(int, unsigned char *, int);
void CloseComport(int);
void cprintf(int, const char *);
int IsCTSEnabled(int);

int RS232_OpenPort(const char *deviceName, int baudRate, bool hardwareFlowControl, struct termios *initialPortSettings = NULL);
int RS232_SendBuffer(int portFileDescriptor, unsigned char *data, int size);
int RS232_ReceiveBuffer(int portFileDescriptor, unsigned char *data, int size);
void RS232_ClosePort(int portFileDescriptor, struct termios *initialPortSettings = NULL);

}
}
}
}

#ifdef __cplusplus

} /* extern "C" */

#endif

#endif
