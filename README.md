# minitalk 📡  
**A lightweight client-server message exchange program** using UNIX signals (SIGUSR1/SIGUSR2)  

[![42](https://img.shields.io/badge/42-Project-blue)](https://42.fr)
[![License](https://img.shields.io/badge/license-MIT-green)](LICENSE)

## 🌟 Features  
- **Bit-by-bit transmission**: Messages sent as binary signals (SIGUSR1=0, SIGUSR2=1)  
- **ACK system**: Server confirms each received character  
- **Unicode support**: Handles extended ASCII (8-bit encoding)  
- **Multi-client**: Server processes messages sequentially  

## 🛠️ Tech Stack  
- **Language**: C  
- **Signals**: `sigaction()`, `kill()`, `pause()`  
- **Tools**: `Makefile`, `printf` debugging  

## 🚀 Quick Start  
```bash
git clone https://github.com/your-username/minitalk.git  
cd minitalk  
make && ./server &  # Launch server in background  
./client <server_PID> "Hello, world!"
```
Output:
Server PID: 12345  
[Client] Sent: "Hello, world!"  
[Server] Received: "Hello, world!" 
📚 Documentation

    https://www.gnu.org/software/libc/manual/html_node/Signal-Handling.html

🧠 Learning Outcomes

    Mastered UNIX signal programming

    Implemented custom binary protocol

    Learned process synchronization techniques

---

### **Key Additions for Clarity**:  
1. **Visual Aids**: Badges + code blocks for quick testing.  
2. **Protocol Insight**: Explains the binary encoding approach.  
3. **Educational Focus**: Highlights kernel concepts learned.  

**Pro Tip**: Add a **`## 🐞 Known Issues`** section if you want contributors to help (e.g., *"Long messages may delay ACKs"*).  

Want it **more technical** or **whimsical**? Let me adjust! 🛠️
