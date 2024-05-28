#include <iostream>
#include <windows.h>

int main() {
    int seconds = 0;
    DWORD start = GetTickCount(); // 初始時間

    // 遊戲迴圈
    while (true) {
        // 模擬遊戲的處理時間
        Sleep(16); // 60 FPS

        // 檢查是否已經過了一秒
        DWORD end = GetTickCount();
        if (end - start >= 1000) { // 1000 毫秒 = 1 秒
            seconds++;
            std::cout << "Second: " << seconds << std::endl;

            // 重置計時器
            start = GetTickCount();
        }

        // 檢查遊戲是否結束的條件
        // 如果遊戲結束，跳出迴圈
        // 例如：按下退出鍵或達到遊戲結束條件
    }

    return 0;
}
