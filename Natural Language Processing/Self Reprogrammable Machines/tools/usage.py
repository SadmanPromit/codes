# usage: v1 © 2024 Sadman Sakib Khan Promit
import time
import subprocess
import psutil
import os

def get_ram(pid):
    try:
        process = psutil.Process(pid)
        mem_info = process.memory_info()
        return mem_info.rss / (1024 * 1024 * 1024)
    except Exception as e:
        return 0

def get_gpu():
    try:
        output = subprocess.check_output(
            ["nvidia-smi", "--query-gpu=utilization.gpu,memory.used", "--format=csv,noheader,nounits"],
            text = True
        ).strip()
        lines = output.splitlines()
        for line in lines:
            gpu_util, mem_used = line.split(",")
            gpu_util = float(gpu_util)
            mem_used = int(mem_used)
            return gpu_util, mem_used
    except Exception as e:
        return 0, 0

def usage(pid, interval):
    try:
        with open("usage_log.txt", "a") as f:
            timestamp = 0
            while True:
                cpu = psutil.cpu_percent(interval = 1)
                ram = get_ram(pid)
                gpu, vram = get_gpu()
                if cpu or gpu:                        
                    log_string = f"T + {timestamp}m: CPU: {cpu:.1f}% RAM: {ram:.1f}GB GPU: {gpu:.1f}% VRAM: {vram}MB\n"
                    f.write(log_string)
                    f.flush()
                    print(log_string, end = "")
                timestamp = timestamp + 1
                time.sleep(interval)
    except Exception as e:
        pass

if __name__ == "__main__":
    self_pid = os.getpid()
    for proc in psutil.process_iter():
        if proc.name() == "python.exe":
            if proc.pid != self_pid:
                target_pid = proc.pid
    usage(target_pid, 60)