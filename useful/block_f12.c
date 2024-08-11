#include <windows.h>
#include <stdio.h>

// Low-level keyboard hook callback
LRESULT CALLBACK KeyboardHookProc(int nCode, WPARAM wParam, LPARAM lParam) {
    KBDLLHOOKSTRUCT *pKeyBoard = (KBDLLHOOKSTRUCT *)lParam;
    switch (wParam) {
        case WM_KEYDOWN: {
            // Block F12 key
            if (pKeyBoard->vkCode == VK_F12) {
                return 1;
            }
            break;
        }
        case WM_KEYUP: {
            // Block F12 key
            if (pKeyBoard->vkCode == VK_F12) {
                return 1;
            }
            break;
        }
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

int main() {
    // Set the hook
    HHOOK hKeyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardHookProc, GetModuleHandle(NULL), 0);
    if (hKeyboardHook == NULL) {
        printf("Failed to install hook!\n");
        return 1;
    }

    // Message loop to keep the hook
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Unhook before exit
    UnhookWindowsHookEx(hKeyboardHook);
    return 0;
}
