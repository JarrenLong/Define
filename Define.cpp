#include "stdafx.h"
#include "Dict.h"

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
LPCWSTR szClassName = L"z80Dict";
LPCWSTR defString;
HINSTANCE g_hInst;
HWND list,hwnd,sub,edit,group,quit;
int mainSel=0,subSel=0;

int WINAPI WinMain (HINSTANCE hThisInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpszArgument,
	int nFunsterStil)

{
	MSG messages;
	WNDCLASSEX wincl;
	g_hInst=hThisInstance;

	wincl.hInstance = g_hInst;
	wincl.lpszClassName = szClassName;
	wincl.lpfnWndProc = WindowProcedure;
	wincl.style = CS_DBLCLKS;
	wincl.cbSize = sizeof (WNDCLASSEX);
	wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
	wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
	wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
	wincl.lpszMenuName = NULL;
	wincl.cbClsExtra = 0;
	wincl.cbWndExtra = 0;
	wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;
	if (!RegisterClassEx (&wincl)){return 0;}

	hwnd=CreateWindowEx(0,szClassName,L"z80 Assembly Instruction Dictionary",
		WS_OVERLAPPED,GetSystemMetrics(SM_CXSCREEN)/2-197,
		GetSystemMetrics(SM_CYSCREEN)/2-157,
		395,315,NULL,NULL,g_hInst,NULL);

	ShowWindow (hwnd, nFunsterStil);
	while (GetMessage (&messages, NULL, 0, 0))
	{
		TranslateMessage(&messages);
		DispatchMessage(&messages);
	}
	return messages.wParam;
}

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
		{
			defString=L"Instructions:\r\n\r\n1.)Click on any "
				L"instruction in the far left window\r\n\r\n2.)Click on the syntax you "
				L"would like to see in the middle window\r\n\r\n3.)Afterwards, the "
				L"definition will replace the text in this window\r\n\r\nCopyright(c) 2005 "
				L"JincS. All Rights Reserved.\r\n\r\n**This program was originally written "
				L"as a DOS program in C by (Kouri@juno.com), and was released on "
				L"August 6, 1998. This is not the original program, but it does use all "
				L"of the original author's definitions. Since the original program was "
				L"released as an open source program, this will also be open source, "
				L"ao that anyone who would like to use this program will be able to "
				L"under the rights of the GNU Greater Public License (GPL).\r\n\r\n"
				L"DON'T FORGET!! If you use any part of this code, be sure to give "
				L"Kouri@juno.com and I some credit!**";

			group=CreateWindowEx(0,L"BUTTON",L"z80 Definitions",WS_CHILD|WS_VISIBLE|
				BS_GROUPBOX|BS_CENTER,5,0,379,285,hwnd,NULL,g_hInst,NULL);
			list = CreateWindowEx(0,L"LISTBOX",NULL,WS_CHILD|WS_VISIBLE|WS_BORDER|
				WS_VSCROLL|LBS_NOTIFY,14,20,50,265,hwnd,(HMENU)ID_MAIN,g_hInst,NULL);
			sub = CreateWindowEx(0,L"LISTBOX",NULL,WS_CHILD|WS_VISIBLE|WS_BORDER|
				WS_VSCROLL|WS_HSCROLL|LBS_NOTIFY,74,20,75,267,hwnd,
				(HMENU)ID_SUB,g_hInst,NULL);
			edit = CreateWindowEx(0,L"EDIT",NULL,WS_CHILD|WS_VISIBLE|WS_BORDER|
				ES_MULTILINE|WS_VSCROLL|ES_READONLY,160,20,215,225,hwnd,
				(HMENU)ID_EDIT,g_hInst,NULL);
			quit=CreateWindowEx(0,L"BUTTON",L"Close This Window",WS_CHILD|
				WS_VISIBLE|BS_FLAT,160,254,215,24,hwnd,(HMENU)ID_QUIT,g_hInst,NULL);

			SendMessage(edit,WM_SETTEXT,0,(LPARAM)defString);
			for(int x=0;x<ENTRIES;x++)
			{SendMessage(list,LB_ADDSTRING,0,(LPARAM)(Dictionary[x].inst));}
		}
		break;
	case WM_COMMAND:
		{
			switch(LOWORD(wParam))
			{
			case ID_MAIN:
				switch(HIWORD(wParam))
				{
				case LBN_SELCHANGE:
					mainSel=SendMessage(list,LB_GETCURSEL,0,0);
					SendMessage(sub,LB_RESETCONTENT,0,0);
					for(int y=0;y<Nfo[mainSel].numOps;y++)
					{SendMessage(sub,LB_ADDSTRING,0,(LPARAM)(Nfo[mainSel].ops[y]));}
					break;
				}
			case ID_SUB:
				switch(HIWORD(wParam))
				{
				case LBN_SELCHANGE:
					subSel=SendMessage(sub,LB_GETCURSEL,0,0);
					SendMessage(edit,WM_SETTEXT,0,(LPARAM)(Nfo[mainSel].desc[subSel]));
					break;
				}
				break;
			case ID_QUIT:
				SendMessage(hwnd,WM_DESTROY,0,TRUE);
				break;
			}
		}
		break;
	case WM_DESTROY:
		DestroyWindow(hwnd);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc (hwnd, message, wParam, lParam);
	}
	return 0;
}
