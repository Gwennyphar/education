#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *buffer = NULL;
char *buffer1 = "H";
char string[900];
char string1[900];

char Text[1024];
char neu_Text[1024];
char Zwischen[1024];

int u;
int t;
int i;
int p;
int b;

int Anzahl;

char Buchstabe[100];

HWND        hButton;
HWND        hButton1;
HWND        hButton2;

HWND        hText;
HWND        hText1;
HWND        hText2;

char neu_ABC[100];
char neu_abc[100];

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
{
    HWND     hWnd;
    MSG      msg;
    WNDCLASS wc;
    WNDCLASSEX  WindowClass;  
    b=0;          
        

    const char szAppName[] = "Caesar";

    wc.style          = CS_HREDRAW | CS_VREDRAW;
    wc.cbClsExtra     = 0;
    wc.cbWndExtra     = 0;
    wc.hInstance      = hInstance;
    wc.hIcon          = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor        = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground  = GetSysColorBrush(COLOR_3DFACE);
    wc.lpszMenuName   = NULL;
    wc.lpfnWndProc    = WndProc;
    wc.lpszClassName  = szAppName;

    RegisterClass(&wc);

    hWnd = CreateWindow( szAppName,
                         "Caesar",
                         WS_OVERLAPPEDWINDOW| WS_VISIBLE,
                         CW_USEDEFAULT,
                         CW_USEDEFAULT,
                         600,
                         280,
                         NULL,
                         NULL,
                         hInstance,
                         NULL );

    ShowWindow(hWnd, iCmdShow);
    UpdateWindow(hWnd);
    
    strcpy(neu_ABC,"HIJKLMNOPQRSTUVWXYZABCDEFG");
    strcpy(neu_abc,"hijklmnopqrstuvwxyzabcdefg");
    
    hText = CreateWindow("STATIC", "Welche Verschiebung möchten Sie wählen? A = ",
                    WS_VISIBLE | WS_CHILD, 20,10, 230, 20, hWnd, NULL, hInstance, NULL);
    if(!hText) return FALSE;
   
    
    hText1 = CreateWindow("STATIC", "Geben Sie den verschlüsselten Code oder den Code, den Sie verschlüsseln wollen ein: ",
                    WS_VISIBLE | WS_CHILD, 20,40, 500, 20, hWnd, NULL, hInstance, NULL);
    if(!hText1) return FALSE;
    
    hText2 = CreateWindow("STATIC", "Ergebnis: ",
                    WS_VISIBLE | WS_CHILD, 20,130, 200, 20, hWnd, NULL, hInstance, NULL);
    if(!hText2) return FALSE;
    
    hButton1 = CreateWindow("BUTTON", "Verschlüsseln",
                       WS_VISIBLE | WS_CHILD, 20, 90, 200, 20,
                       hWnd, NULL, hInstance, NULL);
    if(!hButton1) return FALSE;
    
    hButton2 = CreateWindow("BUTTON", "Entschlüsseln",
                       WS_VISIBLE | WS_CHILD, 300, 90, 200, 20,
                       hWnd, NULL, hInstance, NULL);
    if(!hButton2) return FALSE;
        
    SendMessage(hText, WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT), TRUE);    
    SendMessage(hText1, WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT), TRUE);
    SendMessage(hText2, WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT), TRUE);
    SendMessage(hButton, WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT), TRUE);
    SendMessage(hButton1, WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT), TRUE);
    SendMessage(hButton2, WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT), TRUE);
    
    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
        static HWND hEdit;
        static HWND hEdit1;
        static HWND hEdit2;
        static HWND hEdit3;
        
        char ABC[]     =   {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
        char abc[]     =   {"abcdefghijklmnopqrstuvwxyz"};
        char Zeichen[] =   {"1234567890?!§$%&/()= ²³{[]}*+#'_-:.,;<>|^"};
        
        int iLength;
        
    switch(message)
    {
    case WM_CREATE:
        {
            hEdit = CreateWindowEx(WS_EX_CLIENTEDGE,
                                   "edit",
                                   buffer,    
                                   WS_VISIBLE | WS_CHILD,
                                   20, 60, 500, 20,
                                   hWnd,
                                   NULL,
                                   ((LPCREATESTRUCT) lParam) -> hInstance,
                                   NULL);

            free(buffer);
            
            
            hEdit1 = CreateWindowEx(WS_EX_CLIENTEDGE,
                                  "edit", 
                                  "",
                                  WS_VISIBLE | WS_CHILD, 
                                  20, 160, 500, 20, 
                                  hWnd,
                                  NULL,
                                  ((LPCREATESTRUCT) lParam) -> hInstance,
                                   NULL);
                                   
            hEdit2 = CreateWindowEx(WS_EX_CLIENTEDGE,
                                  "edit", 
                                  buffer1,
                                  WS_VISIBLE | WS_CHILD, 
                                  260, 10, 20, 20, 
                                  hWnd,
                                  NULL,
                                  ((LPCREATESTRUCT) lParam) -> hInstance,
                                   NULL);
            
            free(buffer1);
            
            SendMessage(hEdit, WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT), TRUE);
            SendMessage(hEdit1, WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT), TRUE);
            SendMessage(hEdit2, WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT), TRUE);
        
        return 0;

            
        }
        
    case WM_COMMAND:
                {        
                        if(lParam == (LPARAM)hButton1)        
                        {
                                  
                                  strcpy(string,"");
                                  iLength=0;
                                  
                                  iLength = GetWindowTextLength(hEdit2);
                                  buffer1 = malloc(iLength);
                                  GetWindowText(hEdit2, buffer1, iLength+1);
                                  strcpy(Buchstabe,buffer1);
                                  
                                  for(t=0;t<strlen(ABC);t++)
                                  {
                                                   if(Buchstabe[0]==ABC[t]||Buchstabe[0]==abc[t])
                                                   {
                                                                  for(i=t,p=0;i<strlen(ABC);i++,p++)
                                                                  {
                                                                             neu_ABC[p]=ABC[i];
                                                                             neu_abc[p]=abc[i];
                                                                  }
                                                                  for(i=0;i<t;i++,p++)
                                                                  {
                                                                             neu_ABC[p]=ABC[i];
                                                                             neu_abc[p]=abc[i];
                                                                  }
                                                                  strcpy(Buchstabe,"");              
                                                                  break;         
                                                   }
                                  }
                                  
                                  strcpy(neu_Text,"");
                                  strcpy(Text,"");
                                  strcpy(string,"");
                                  strcpy(Zwischen,"");
                                  SendMessage(hEdit1, WM_SETTEXT, 0,(LPARAM)"");
                                  iLength=0;
                                  Anzahl=0;
            
                                  iLength = GetWindowTextLength(hEdit);
                                  buffer = malloc(iLength);
                                  GetWindowText(hEdit, buffer, iLength+1);
                                  strcpy(Text,buffer);
                                  
                                  Anzahl=strlen(Text);
                                  
                                  for(u=0;u<Anzahl;u++)
                                  {
                                                for(t=0;t<40;t++)
                                                {
                                                                 if(Text[u]==ABC[t])
                                                                 {
                                                                                    neu_Text[u]=neu_ABC[t];
                                                                                    break;
                                                                 } 
                                                                 if(Text[u]==abc[t])
                                                                 {
                                                                                    neu_Text[u]=neu_abc[t];
                                                                                    break;
                                                                 }   
                                                                 if(Text[u]==Zeichen[t])
                                                                 {
                                                                                    neu_Text[u]=Zeichen[t];
                                                                                    break;
                                                                 }
                                                }         
                                  }
                                  strcpy(Zwischen,neu_Text);
                                  strcpy(neu_Text,"");
                                  strncat(neu_Text,Zwischen,Anzahl);
                                  SendMessage(hEdit1, WM_SETTEXT, 0,(LPARAM)neu_Text);
                                  UpdateWindow(hEdit1);
            
                                  
                            } 
                            
                            if(lParam == (LPARAM)hButton2)        
                            {
                                  strcpy(string,"");
                                  iLength=0;
                                  
                                  iLength = GetWindowTextLength(hEdit2);
                                  buffer1 = malloc(iLength);
                                  GetWindowText(hEdit2, buffer1, iLength+1);
                                  strcpy(Buchstabe,buffer1);
                                  
                                  for(t=0;t<strlen(ABC);t++)
                                  {
                                                   if(Buchstabe[0]==ABC[t]||Buchstabe[0]==abc[t])
                                                   {
                                                                  for(i=t,p=0;i<strlen(ABC);i++,p++)
                                                                  {
                                                                             neu_ABC[p]=ABC[i];
                                                                             neu_abc[p]=abc[i];
                                                                  }
                                                                  for(i=0;i<t;i++,p++)
                                                                  {
                                                                             neu_ABC[p]=ABC[i];
                                                                             neu_abc[p]=abc[i];
                                                                  }
                                                                  strcpy(Buchstabe,"");              
                                                                  break;         
                                                   }
                                  }
                                  
                                  strcpy(neu_Text,"");
                                  strcpy(Text,"");
                                  strcpy(string,"");
                                  strcpy(Zwischen,"");
                                  SendMessage(hEdit1, WM_SETTEXT, 0,(LPARAM)"");
                                  iLength=0;
                                  Anzahl=0;
            
                                  iLength = GetWindowTextLength(hEdit);
                                  buffer = malloc(iLength);
                                  GetWindowText(hEdit, buffer, iLength+1);
                                  strcpy(Text,buffer);
                                  
                                  Anzahl=strlen(Text);
                                  
                                  for(u=0;u<Anzahl;u++)
                                  {
                                                for(t=0;t<40;t++)
                                                {
                                                                 if(Text[u]==neu_ABC[t])
                                                                 {
                                                                                    neu_Text[u]=ABC[t];
                                                                                    break;
                                                                 } 
                                                                 if(Text[u]==neu_abc[t])
                                                                 {
                                                                                    neu_Text[u]=abc[t];
                                                                                    break;
                                                                 }   
                                                                 if(Text[u]==Zeichen[t])
                                                                 {
                                                                                    neu_Text[u]=Zeichen[t];
                                                                                    break;
                                                                 }
                                                }         
                                  }
                                  strcpy(Zwischen,neu_Text);
                                  strcpy(neu_Text,"");
                                  strncat(neu_Text,Zwischen,Anzahl);
                                  SendMessage(hEdit1, WM_SETTEXT, 0,(LPARAM)neu_Text);
                                  UpdateWindow(hEdit1);
            
                                  
                            } 
                      }    
                      break;    
        
    
    case WM_CLOSE:
        {
            DestroyWindow(hWnd);
            return 0;
        }
    case WM_DESTROY:
        {
            PostQuitMessage(0);
            return 0;
        }
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}
