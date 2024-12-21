import os
import time
import threading

def garbage(dir, max_count):
    while True:
        try:
            all_files = [os.path.join(dir, f) for f in os.listdir(dir) if os.path.isfile(os.path.join(dir, f))]
            if len(all_files) > max_count:
                all_files.sort(key = os.path.getmtime)
                files_to_delete = all_files[:-max_count]
                for file in files_to_delete:
                    os.remove(file)
        except Exception as e:
            pass
        finally:
            time.sleep(15)

os.makedirs(temp, exist_ok = True)
garbage_thread = threading.Thread(target = garbage, args = (temp, 9), daemon = True)
garbage_thread.start()