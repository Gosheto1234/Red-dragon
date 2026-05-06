# Red-dragon 🐉

**Red-dragon** is a dedicated network discovery tool built in C++ for rooted Android devices using **Termux**. Its primary focus is to identify and map every active device on a local network quickly and efficiently.

> [!IMPORTANT]
> **Requirements:** Rooted Android device, Termux, and `nmap` installed.

## ✨ Main Purpose
The core mission of Red-dragon is **Total Network Mapping**. It automates the process of scanning your current network to provide a clear list of all connected hardware, making mobile reconnaissance seamless.

## 🚀 Installation & Usage

### 1. Prerequisites
Ensure you have `nmap` and a root manager like `tsu` installed in Termux:
```bash
pkg update && pkg install nmap tsu -y
```

### 2. Setup
Clone the repo and compile the binary:
```bash
git clone https://github.com
cd Red-dragon
g++ main.cpp -o red-dragon
```

### 3. Run
Execute the tool with root privileges to allow for full device discovery:
```bash
tsu -c ./red-dragon
```

> [!CAUTION]
> This tool is for **authorized network testing only**. Use it responsibly and only on networks you have explicit permission to audit.

## 📂 Project Structure
*   `main.cpp`: The engine that handles network discovery logic.
*   `color_console.hpp`: Header used for future output styling.
*   `red_dragon.png`: Project mascot.

## ⚖️ Disclaimer
This tool is designed for authorized network auditing and educational purposes. Always ensure you have permission to scan the network you are connected to.
