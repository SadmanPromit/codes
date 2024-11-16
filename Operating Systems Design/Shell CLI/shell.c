//Written by Sadman Sakib Khan Promit.
#include<stdio.h>
#include<time.h>
#include<conio.h>//for cls
#include <windows.h>//for tasklist, pc name for DWORD
#include <tlhelp32.h>//Tool Help Library for tasklist CreateToolhelp32Snapshot function
#include <tchar.h>//Generic-Text Mappings for _tprintf() in tasklist
#include <dirent.h>//format of directory entries for dir

int main()
{
    char cmdInpt[10];//command input
    printf("Windows Shell Lite [Version 1.02]\n(c) 2020 Sadman Sakib Khan Promit. All rights reserved.\n\n");
    while (1) {
        printf("Enter shell command (try 'help'): ");
        scanf("%s", cmdInpt);
        if (strcmp(cmdInpt,"date") == 0) {
            time_t t;//arithmetic time type (typically time since the epoch)
            time(&t);//Time manipulation function
            printf("%s\n", ctime(&t));//ctime() converts a time_t value to a textual representation
        }
        else if (strcmp(cmdInpt,"cls") == 0) {
            system("cls");//clear screen
        }
        else if (strcmp(cmdInpt,"shell") == 0) {
            printf("Windows Shell Lite [Version 1.02]\n(c) 2020 Sadman Sakib Khan Promit. All rights reserved.\n\n");
        }
        else if (strcmp(cmdInpt,"vol") == 0) {
            printf("Volume ");
            system("wmic path win32_physicalmedia get SerialNumber");//function for getting HDDs serial number
        }
        else if (strcmp(cmdInpt,"os") == 0) {
            #ifdef _WIN32 //preprocessor's if is evaluated at compile-time and the code for the false branch is not included in the compiled program and _WIN32 Defined as 1 when the compilation target is 32-bit ARM, 64-bit ARM, x86, or x64
            #ifdef _WIN64//_WIN64 Defined as 1 when the compilation target is 64-bit ARM or x64
                printf("Windows 64 bit\n");
            #else
                printf("Windows 32 bit\n");
            #endif
            #else
                printf("Not a Windows OS.\n");
            #endif
            printf("\n");
        }
        else if (strcmp(cmdInpt,"hostname") == 0) {
            char buffer[256] = "";//name string
            DWORD size = sizeof(buffer);//DWORD is a unsigned 32-bit integer for windows
            if (GetComputerName(buffer, &size))//Retrieves the NetBIOS name of the local computer
            {
                printf("Computer Name: %s\n\n", buffer);
            }
            else
                printf("Computer Name couldn't be found\n\n");
        }
        else if (strcmp(cmdInpt,"getmac") == 0) {
            system("getmac");//display the Media Access Control (MAC) addresses for each network adapter in the computer
            printf("\n");
        }
        else if (strcmp(cmdInpt,"shutdown") == 0) {
            system("c:\\windows\\system32\\shutdown /s");//opens the shutdown.exe
        }
        else if (strcmp(cmdInpt,"restart") == 0) {
            system("c:\\windows\\system32\\shutdown /r");
        }
        else if (strcmp(cmdInpt,"logoff") == 0) {
            system("c:\\windows\\system32\\shutdown /l");
        }
        else if (strcmp(cmdInpt,"ipconfig") == 0) {
               system("C:\\Windows\\System32\\ipconfig");// opens ipconfig.exe which displays all current TCP/IP network configuration values and refreshes Dynamic Host Configuration Protocol and Domain Name System settings
               printf("\n");
        }
        else if (strcmp(cmdInpt,"cmd") == 0) {
               system("cmd");//opens default windows command promt
               printf("\n");
        }
        else if (strcmp(cmdInpt,"winver") == 0) {
               system("winver");//open about windows
               printf("\n");
        }
        else if (strcmp(cmdInpt,"diskpart") == 0) {
               system("diskpart");//opens Microsoft DiskPart program
               printf("\n");
        }
        else if (strcmp(cmdInpt,"powershell") == 0) {
               system("powershell");//opens Windows PowerShell
               printf("\n");
        }
        //Written by Sadman Sakib Khan Promit.
        else if (strcmp(cmdInpt,"mkdir") == 0) {
            int check;
            char *dirname;//string
            dirname=malloc(25*sizeof(char));//malloc is used in C for dynamically allocate array size in runtime and char is 1 byte
            printf("Enter a name or directory path and name to be created (i.e. 'C:/FolderName' or 'nul' to stop): ");//used nul because it's a windows reserved keyword
            scanf("%s", dirname);
            if (strcmp(dirname,"nul") != NULL)
            check = mkdir(dirname);//mkdir() creates a directory and return 0. Upon failing it returns -1
            if (check != -1 && strcmp(dirname,"nul") != NULL)
                printf("Directory created\n\n");
            else
                printf("Unable to create directory\n\n");
        }
        else if (strcmp(cmdInpt,"dir") == 0) {
            struct dirent *de;// Pointer for directory entry
            DIR *dr = opendir(".");//DIR is a type representing a directory stream and opendir() returns a pointer of DIR type but returns NULL if could not open directory. The dot(.) in opendir(".") is used for retrieving the shell's current directory.
            if (dr == NULL)
                printf("Could not open current directory.\n\n" );
            while ((de = readdir(dr)) != NULL)//readdir() reads directory and upon successful completion, it returns a pointer to an object of type struct dirent. When an error is encountered, a null pointer is returned
                    printf("%s\n", de->d_name);//d_name[] is a name of entry within the dirent struct
            closedir(dr);//closes a directory stream
            printf("\n");
        }
        else if (strcmp(cmdInpt,"tasklist") == 0) {
            void printError(TCHAR* msg) {
                DWORD eNum;//Double word
                TCHAR sysMsg[256];//TCHAR is a Win32 character string that can be used to describe ANSI, DBCS, or Unicode strings. For ANSI and DBCS platforms
                TCHAR* p;//string
                eNum = GetLastError();//Retrieves the calling thread's last-error code value
                FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                         NULL, eNum,
                         MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
                         sysMsg, 256, NULL);//Formats a message string. Syntax: DWORD FormatMessage(DWORD dwFlags, LPCVOID lpSource, DWORD dwMessageId, DWORD dwLanguageId, LPTSTR lpBuffer, DWORD nSize, va_list *Arguments)
                  // Trim the end of the line and terminate it with a null
                p = sysMsg;
                while((*p > 31) || (*p == 9))
                    ++p;
                do {
                        *p-- = 0;
                } while((p >= sysMsg) && ((*p == '.') || (*p < 33 )));
                  // Display the message
                  _tprintf(TEXT("\n  WARNING: %s failed with error %d (%s)"), msg, eNum, sysMsg);//UNICODE compatible printf
            }
            //Traversing the Module List
            //ListProcessModules() takes a snapshot of the modules associated with a given process using the CreateToolhelp32Snapshot function, and then walks through the list using the Module32First and Module32Next functions
            BOOL ListProcessModules(DWORD dwPID){
                HANDLE hModuleSnap = INVALID_HANDLE_VALUE;//A handle is a pointer or index with no visible type attached to it.
                MODULEENTRY32 me32;//Structure to Describe an entry from a list of the modules belonging to the specified process.
                hModuleSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwPID);//CreateToolhelp32Snapshot(DWORD dwFlags, DWORD th32ProcessID) takes a snapshot of the specified processes, as well as the heaps, modules, and threads used by these processes.
                if(hModuleSnap == INVALID_HANDLE_VALUE){
                    printError(TEXT("CreateToolhelp32Snapshot (of modules)"));
                    return(FALSE);
                }
                me32.dwSize = sizeof(MODULEENTRY32);//Fill in the size of the structure before using it
                // Retrieve information about the first module and exit if unsuccessful
                if (!Module32First( hModuleSnap, &me32 )){
                printError(TEXT("Module32First"));//show cause of failure
                CloseHandle(hModuleSnap);//clean the snapshot object
                return(FALSE);
                }
                //Walking the module list of the process and display information about each module
                do {
                    _tprintf(TEXT("\n\n     MODULE NAME:     %s"), me32.szModule);
                    _tprintf(TEXT("\n     Executable     = %s"), me32.szExePath);
                    _tprintf(TEXT("\n     Process ID     = 0x%08X"), me32.th32ProcessID);
                    _tprintf(TEXT("\n     Ref count (g)  = 0x%04X"), me32.GlblcntUsage);//The load count of the module
                    _tprintf(TEXT("\n     Ref count (p)  = 0x%04X"), me32.ProccntUsage);//same as GlblcntUsage
                    _tprintf(TEXT("\n     Base address   = 0x%08X"), (DWORD) me32.modBaseAddr);
                    _tprintf(TEXT("\n     Base size      = %d"), me32.modBaseSize);//The size of the module, in bytes
                } while (Module32Next(hModuleSnap, &me32));
                CloseHandle(hModuleSnap);
                return(TRUE);
            }
            //Traversing the Threads List
            BOOL ListProcessThreads(DWORD dwOwnerPID) {
                HANDLE hThreadSnap = INVALID_HANDLE_VALUE;
                THREADENTRY32 te32;//Describes an entry from a list of the threads executing in the system when a snapshot was taken
                hThreadSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);//Take a snapshot of all running threads and also check line 136 for help
                if(hThreadSnap == INVALID_HANDLE_VALUE)
                    return(FALSE);
                te32.dwSize = sizeof(THREADENTRY32);//Fill in the size of the structure before using it
                //Retrieve information about the first thread and exit if unsuccessful
                if (!Thread32First(hThreadSnap, &te32)) {
                    printError(TEXT("Thread32First"));//show cause of failure
                    CloseHandle(hThreadSnap);//clean the snapshot object
                    return(FALSE);
                }
                //Now walking the thread list of the system and display information about each thread associated with the specified process
                do {
                    if (te32.th32OwnerProcessID == dwOwnerPID) {
                        _tprintf(TEXT("\n\n     THREAD ID      = 0x%08X"), te32.th32ThreadID);
                        _tprintf(TEXT("\n     Base priority  = %d"), te32.tpBasePri);
                        _tprintf(TEXT("\n     Delta priority = %d"), te32.tpDeltaPri);
                        _tprintf(TEXT("\n"));
                    }
                } while(Thread32Next(hThreadSnap, &te32));
                CloseHandle(hThreadSnap);
                return(TRUE);
            }
            HANDLE hProcessSnap;
            HANDLE hProcess;
            PROCESSENTRY32 pe32;//Describes an entry from a list of the processes residing in the system address space when a snapshot was taken
            DWORD dwPriorityClass;
            hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);// Take a snapshot of all processes in the system
            if(hProcessSnap == INVALID_HANDLE_VALUE )
                printError(TEXT("CreateToolhelp32Snapshot (of processes)"));
            pe32.dwSize = sizeof(PROCESSENTRY32);//Set the size of the structure before using it
            // Retrieve information about the first process and exit if unsuccessful
            if(!Process32First(hProcessSnap, &pe32)) {
                printError(TEXT("Process32First"));//Show cause of failure
                CloseHandle(hProcessSnap);//Clean the snapshot object
            }
            // Now walk the snapshot of processes and display information about each process in turn
            do {
                _tprintf(TEXT("\n\n====================================================="));
                _tprintf(TEXT("\nPROCESS NAME:  %s"), pe32.szExeFile);
                _tprintf(TEXT("\n-------------------------------------------------------"));
                //Retrieve the priority class
                dwPriorityClass = 0;
                hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);//Opens an existing local process object. Syntax: HANDLE OpenProcess(DWORD dwDesiredAccess, BOOL  bInheritHandle, DWORD dwProcessId)
                if(hProcess == NULL)
                    printError(TEXT("OpenProcess"));
                else {
                    dwPriorityClass = GetPriorityClass(hProcess);
                    if(!dwPriorityClass)
                        printError(TEXT("GetPriorityClass"));
                    CloseHandle(hProcess );
                }
                _tprintf(TEXT("\n  Process ID        = 0x%08X"), pe32.th32ProcessID);
                _tprintf(TEXT("\n  Thread count      = %d"), pe32.cntThreads);
                _tprintf(TEXT("\n  Parent process ID = 0x%08X"), pe32.th32ParentProcessID );
                _tprintf(TEXT("\n  Priority base     = %d"), pe32.pcPriClassBase);
                if(dwPriorityClass)
                    _tprintf( TEXT("\n  Priority class    = %d"), dwPriorityClass);
                //List the modules and threads associated with this process
                ListProcessModules(pe32.th32ProcessID);
                ListProcessThreads(pe32.th32ProcessID);
            } while( Process32Next(hProcessSnap, &pe32));
            CloseHandle(hProcessSnap);
            printf("\n");
        }
        else if (strcmp(cmdInpt,"exit") == 0) {
            printf("Windows Shell Lite is closing...\n");
            exit(0);//Exit Successfully
        }
        else if (strcmp(cmdInpt,"help") == 0) {
            printf("cls\t\tClear console screen\ncmd\t\tStart Windows command prompt\ndate\t\tShow date and time\ndir\t\tList directory content\ndiskpart\tVolume management\nexit\t\tExit the shell\nhelp\t\tShow command list\nhostname\tDisplay computer name\nipconfig\tDisplay IP network settings\nlogoff\t\tLogoff the computer\nmkdir\t\tcreate a new directory\nos\t\tCheck os with bit\npowershell\tStart Windows Powershell\nrestart\t\tRestart the computer\nshell\t\tDisplay about shell\nshutdown\tShutdown the computer\ntasklist\tDisplay running processes\nvol\t\tShow HDDs serial number(s)\nwinver\t\tShow about windows version\n\n");
        }
        else
            printf("'%s' is not recognized as an internal or external command, operable program or batch file.\n\n", cmdInpt);
    }
    return 0;
}
//Written by Sadman Sakib Khan Promit.
