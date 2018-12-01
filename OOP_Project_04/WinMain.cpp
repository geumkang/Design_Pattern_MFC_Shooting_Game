#include <windows.h>
#include <mmsystem.h>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "CGameHost.h"
#include "resource.h"

#pragma comment(lib,"winmm")

#define DIALOG_HELP		1
#define DIALOG_RANK		2

using namespace std;

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
BOOL CALLBACK MsgDlgProc(HWND,UINT,WPARAM,LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("OOP Team Project04 - Shooting Game");

int DialogStatus;
int attack_count = 0;
string rankingList[10];

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow) {
		if(FindWindow(NULL,lpszClass)) { //If There is Same Window
		MessageBox(HWND_DESKTOP,TEXT("Game is running!"),TEXT("G A M E"),MB_OK); //Alert
		return 1; // Exit
	}
	g_hInst = hInstance;
	WNDCLASS WndClass = { CS_HREDRAW | CS_VREDRAW,WndProc,0,0,hInstance,
		LoadIcon(NULL,IDI_APPLICATION),LoadCursor(NULL,IDC_ARROW),
		(HBRUSH)GetStockObject(WHITE_BRUSH),MAKEINTRESOURCE(IDR_MENU1),lpszClass };
	RegisterClass(&WndClass);
	HWND hWnd = CreateWindow(lpszClass,lpszClass,WS_OVERLAPPED|WS_SYSMENU
		|WS_MINIMIZEBOX|WS_CAPTION,100,100,600,520,NULL,
		(HMENU)NULL,hInstance,NULL);
	ShowWindow(hWnd,nCmdShow);
	MSG Message;
	HACCEL hAccel=LoadAccelerators(hInstance,MAKEINTRESOURCE(IDR_ACCELERATOR1));
	while(GetMessage(&Message,NULL,0,0)) {
		if(!TranslateAccelerator(hWnd,hAccel,&Message)) {
			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}
	}
	return (int)Message.wParam;
}

CGameHost *GameHost; //Main Game

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc, hMemDC;
	HBITMAP OldBit;
	static HBITMAP hLoading;
	static BOOL bLoading;
	static int Time;
	TCHAR Str[128];
	int n, k;

	switch(iMessage) {
	case WM_CREATE:
		GameHost = NULL; //Init
		bLoading = TRUE;
		hLoading = LoadBitmap(g_hInst,MAKEINTRESOURCE(IDB_LOADING));
		// 로딩 시간 설정 부분
		SetTimer(hWnd,2,2000,NULL);
		// 로딩화면 음악 재생
		PlaySound("BGM\\loading.wav",NULL,SND_ASYNC|SND_LOOP);
		Time = 0;
		return 0;
	case WM_COMMAND:
		switch(LOWORD(wParam)) {
		case ID_MENUITEM40001: //Pause
			PlaySound("BGM\\warnning.wav",NULL,1);
			if(GameHost)
				GameHost->Pause();
			
			k = MessageBox(hWnd,TEXT("If you Continue?"),TEXT("Pause"),MB_OK);
			if(k==IDOK) {
				PlaySound("BGM\\pop_up.wav",NULL,1);
				GameHost->Release();
			}
			break;
		case ID_MENUITEM40002: //Restart
			PlaySound("BGM\\warnning.wav",NULL,1);
			if(GameHost)
			{
				GameHost->Pause();
				k = MessageBox(hWnd,TEXT("Do you want restart this Game?"),TEXT("Restart"),MB_YESNO);
				if(k==IDYES) {
					PlaySound("BGM\\pop_up.wav",NULL,1);
					GameHost = new CGameHost(g_hInst);
				} else {
					PlaySound("BGM\\pop_up.wav",NULL,1);
					GameHost->Release();
				}
			}
			break;
		case ID_MENUITEM40003: //Help
			PlaySound("BGM\\pop_up.wav",NULL,1);
			if(GameHost) GameHost->Pause();
			DialogStatus = DIALOG_HELP;
			n = DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG1),hWnd,MsgDlgProc);
			if(n==IDOK || n==IDCANCEL) {
				if(GameHost)
					GameHost->Release();
			}
			break;
		case ID_MENUITEM40004: //Ranking
			PlaySound("BGM\\pop_up.wav",NULL,1);
			if(GameHost) GameHost->Pause();
			fstream file;
			char str[50];
			file.open("Ranking.txt");
			for(int i=1; !file.eof();i++) {
				file.getline(str,50);
				rankingList[i-1].clear();
				rankingList[i-1].append(std::to_string(i));
				rankingList[i-1].append(": ");
				rankingList[i-1].append(str);
				// 띄어쓰기!!
			}
			file.close();
			DialogStatus = DIALOG_RANK;
			n = DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG1),hWnd,MsgDlgProc);
			if(n==IDOK || n==IDCANCEL) {
				if(GameHost)
					GameHost->Release();
			}
			break;
		}
		return 0;
	case WM_TIMER:
		if(wParam==1) { //Host Update Timer
			if(GameHost) {
			if(GetAsyncKeyState(VK_LEFT) & 0x8000) { //If Pressed Key
				GameHost->KeyUpdate(VK_LEFT);
				InvalidateRect(hWnd,0,0);
			} else if(GetAsyncKeyState(VK_RIGHT) & 0x8000) {
				GameHost->KeyUpdate(VK_RIGHT);
				InvalidateRect(hWnd,0,0);
			} else if(GetAsyncKeyState(VK_UP) & 0x8000) {
				GameHost->KeyUpdate(VK_UP);
				InvalidateRect(hWnd,0,0);
			} else if(GetAsyncKeyState(VK_DOWN) & 0x8000) {
				GameHost->KeyUpdate(VK_DOWN);
				InvalidateRect(hWnd,0,0);
			}  
			// 공격 부분
			if(GetAsyncKeyState('Z') & 0x8000) {
				if(attack_count==0)
					PlaySound("BGM\\attack.wav",NULL,1);
				attack_count++;
				GameHost->KeyUpdate('Z');
				InvalidateRect(hWnd,0,0);
				if(attack_count==4)
					attack_count=0;
			}
			// 필살기 부분
			else if(GetAsyncKeyState('X') & 0x8000) {
				GameHost->KeyUpdate('X');
				InvalidateRect(hWnd,0,0);
			}
			n = GameHost->Update();
			if(n==1) {
				delete GameHost;
				GameHost = NULL;
				PlaySound("BGM\\die.wav",NULL,1);
				k = MessageBox(hWnd,TEXT("Lose!! Retry it?"),TEXT("Game Over"),MB_YESNO);
				if(k==IDYES) {
					GameHost = new CGameHost(g_hInst);
					PlaySound("BGM\\pop_up.wav",NULL,1);
				} else {
					exit(1);
				}
			} else if(n==2) {
				delete GameHost;
				GameHost = NULL;
				PlaySound("BGM\\die.wav",NULL,1);
				ifstream file;
				char str[50];
				int rank[10]={0,};
				file.open("Ranking.txt");
				for(int i=0; !file.eof()&&i<10; i++) {
					int temp = 0;
					file.getline(str,50);
					temp = std::atoi(str);
					rank[i] = temp;
				}
				file.close();
				ofstream file2;
				file2.open("Ranking.txt");
				for (int i=0; i<10; i++)
				{
					if(Time<=rank[i]) {
						// 여기에 축하
						for(int j=8;j>=i;j--) {
							rank[j+1]=rank[j];
						}
						rank[i] = Time;
						PlaySound("BGM\\ranking_up.wav",NULL,1);
						k = MessageBox(hWnd,TEXT("Rank UP!!"),TEXT("Congratulation"),MB_OK);
						if(k==IDOK) {
							PlaySound("BGM\\pop_up.wav",NULL,1);
						}
						break;
					}
				}
				for(int i=0;i<10;i++) {
					file2<<rank[i]<<endl;
				}
				file2.close();
				wsprintf(Str,TEXT("Win! Time:%d\n Retry?"),(int)(Time));

				k = MessageBox(hWnd,Str,TEXT("Game Win"),MB_YESNO);
				if(k==IDYES) {
					GameHost = new CGameHost(g_hInst);
					PlaySound("BGM\\pop_up.wav",NULL,1);
				} else {
					exit(1);
				}
			}
			Time++;
			InvalidateRect(hWnd,NULL,FALSE);
			}
		} if(wParam==2) { //Loading Timer
			bLoading = FALSE; //Begin Game
			GameHost = new CGameHost(g_hInst);
			SetTimer(hWnd,1,25,NULL); //Set Host Update Timer
			InvalidateRect(hWnd,NULL,FALSE);
			KillTimer(hWnd,2);
		}
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd,&ps);
		if(GameHost)
		{
			static int count = 0;
			// Z키를 눌러야 시작 (임시 : 아무키나 누르도록 추후 수정)
			if(count==0)
			{
				GameHost->Pause();
				// Press Key
				if(GetAsyncKeyState('Z') & 0x8000) { 
					PlaySound(NULL,NULL,SND_ASYNC|SND_LOOP);
					PlaySound("BGM\\start.wav",NULL,1);
					Sleep(500);
					GameHost->Release();
					count++;
				}
			}
			else
				GameHost->Render(hdc); //Render
		}
		if(bLoading) { //While Loading
			hMemDC = CreateCompatibleDC(hdc);
			OldBit = (HBITMAP)SelectObject(hMemDC,hLoading);
			// 전체 창 크기
			BitBlt(hdc,0,0,600,500,hMemDC,0,0,SRCCOPY);
			SelectObject(hMemDC,OldBit);
			DeleteDC(hMemDC); //Draw Loading Bitmap
		}
		EndPaint(hWnd,&ps);
		return 0;
	case WM_DESTROY:
		KillTimer(hWnd,1); //DeInit
		if(GameHost)
			delete GameHost;
		DeleteObject(hLoading);
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hWnd,iMessage,wParam,lParam));
}

BOOL CALLBACK MsgDlgProc(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM lParam) {
	char *szHelp = {
		"이동: 방향키\r\n"
		"공격: Z\r\n"
		"필살기: X\r\n"
		"왼쪽 상단 게이지바: 플레이어의 체력\r\n"
		"오른쪽 상단 게이지바: 적의 체력\r\n"
	};
	switch(iMessage) {
	case WM_INITDIALOG:
		if(DialogStatus == DIALOG_HELP)
			SetDlgItemText(hDlg,IDC_EDIT1,szHelp);
		else if(DialogStatus == DIALOG_RANK){
			char temp[500] = "";
			
			for(int i=0; i<10;i++){
				strcat(temp,rankingList[i].c_str());
				strcat(temp,"\t");
			}
			SetDlgItemText(hDlg,IDC_EDIT1,temp);
		}
		return TRUE;
	case WM_COMMAND:
		switch(LOWORD(wParam)) {
		case IDOK:
			EndDialog(hDlg,IDOK);
			return TRUE;
		case IDCANCEL:
			EndDialog(hDlg,IDCANCEL);
			return TRUE;
		}
		break;
	}
	return FALSE;
}