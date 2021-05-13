:: 列出所有进程，并筛选出进程名为iperf3的进程
tasklist | findstr iperf3

:: 强制结束进程名为iperf3的所有进程
taskkill /f /im iperf3



:: 类似linux下的sleep 3，暂停3秒
timeout /t 3


