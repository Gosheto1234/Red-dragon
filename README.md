# Red-dragon

**Red-dragon** is a dedicated network discovery tool built in C++ for Android devices using **Termux**.

This is the **No-root branch**, made for users who want to scan their own local network without using root access. Its main goal is to identify active devices on the same Wi-Fi/local network in a simple and fast way.

> [!IMPORTANT]
> **Requirements:** Android device, Termux, `nmap`, and a C++ compiler installed.
>
> Root access is **not required** for this branch.

## ✨ Main Purpose

The core mission of Red-dragon is **Total Network Mapping**.

It automates local network discovery and helps show which devices are active on your current network. This branch uses a non-root Nmap scan, so results may be more limited than the rooted version on some networks.

## Installation & Usage

### 1. Prerequisites

Install the needed packages in Termux:

`pkg update && pkg install nmap clang -y`

Optional, for showing the project image/logo in the terminal:

`pkg install termimage -y`

### 2. Setup

Clone the **No-root** branch and compile the binary:

`git clone -b No-root https://github.com/Gosheto1234/Red-dragon.git`

`cd Red-dragon`

`g++ main.cpp -o red-dragon`

### 3. Run

Execute the tool normally:

`./red-dragon`

The program will ask:

`Enter ip range:`

Enter only the number, for example:

`24`


## Simple Explanation of IP Ranges

The range controls how many addresses Nmap checks on your network.

For most home Wi-Fi networks, the normal choice is:

`24`

That means `/24`, which usually scans addresses like:

`192.168.1.1 - 192.168.1.255`

### Common Ranges

| Range | How many addresses | When to use |
|---|---:|---|
| `/32` | 1 address | Scan only one exact IP |
| `/30` | 4 addresses | Very tiny network |
| `/29` | 8 addresses | Very small network |
| `/28` | 16 addresses | Small test network |
| `/27` | 32 addresses | Small local network |
| `/26` | 64 addresses | Medium-small network |
| `/25` | 128 addresses | Medium network |
| `/24` | 256 addresses | Normal home Wi-Fi / most common |
| `/23` | 512 addresses | Larger network |
| `/16` | 65,536 addresses | Very large and slow scan |

### Recommended Choice

For normal home networks, use:

`24`

Use bigger ranges like `23` or `16` only if you know your network is large, because they can take much longer.

## Root vs No-root Branch

| Branch | Root needed? | Command style | Notes |
|---|---|---|---|
| `main` | Yes | Uses root scan | Better discovery on some networks |
| `No-root` | No | Uses normal `nmap -sn` scan | Easier to run, but results may be more limited |

## Project Structure

* `main.cpp`: The engine that handles network discovery logic.
* `color_console.hpp`: Header used for terminal output styling.
* `red_dragon.png`: Project mascot/logo.

> [!CAUTION]
> This tool is for **authorized network testing only**. Use it responsibly and only on networks you own or have explicit permission to scan.

## ⚖️ Disclaimer

This tool is designed for authorized network auditing and educational purposes. Always make sure you have permission to scan the network you are connected to.
