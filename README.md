<div align="center">
  <h1>✈️ SkyPort</h1>
  <h3>Advanced Airline Reservation & Management System</h3>
  <p><b>🏆 1st Place Winner out of 140+ Projects at Ain Shams University (FCIS)</b></p>
</div>

---

## 📖 About The Project
SkyPort is a high-performance desktop application designed to manage airline ticket reservations. Built entirely with **C++** and **Windows Forms**, the project completely bypasses standard libraries for its core engine. Instead, it relies on complex, custom-built data structures and algorithms engineered from scratch to ensure maximum efficiency, optimal memory management, and secure data handling.

## ✨ Key Features

### 👨‍💻 User Experience & Management
* **Core Management (CRUD):** Comprehensive control over flights and airplanes. Features full CRUD operations for flights, Create/Read/Update operations for airplanes, and static file-based data loading for airports.
* **Customer Support Chat:** A built-in, interactive messaging system that allows users to communicate directly with administrators for real-time support.
* **Gamified Checkout:** A unique, interactive "spin-the-box" mini-game integrated into the booking process, rewarding users with randomized discount rates on their tickets.

### ⚙️ Under The Hood (Technical Achievements)
* **Custom Dynamic Array (`std::vector` Clone):** Engineered a dynamic array data structure from scratch, fully mirroring the methods, capacity scaling, and memory management features of the standard C++ vector.
* **Optimized Quick Sort:** Implemented a highly refined Quick Sort algorithm tailored for the application's data models. Its execution speed rivals, and in specific edge cases outperforms, the native `std::sort` in C++.
* **High-Efficiency Hashing:** Designed and integrated a custom hashing algorithm to securely manage data with an exceptionally low collision rate of **0.005%**, ensuring reliable and secure credential handling.

## 🛠️ Tech Stack
* **Language:** C++ / C++/CLI
* **GUI Framework:** Windows Forms (.NET)
* **IDE & Tooling:** Visual Studio 2022

## 📂 Project Architecture
Based on the repository structure, the files are cleanly separated to isolate the UI from the application logic:

```text
SkyPort/
├── assets/                       # UI graphics, icons, and visual resources
├── src/                          # Main source code directory
│   ├── Core/                     # Core application logic and controllers
│   ├── DataBase/                 # File-based data loading and database management
│   ├── DataStructures/           # Custom C++ data structures (e.g., custom vector)
│   ├── Security/                 # Custom hashing algorithms and security handling
│   ├── UI/                       # Windows Forms screens and user controls
│   ├── include/                  # Header files
│   └── main.cpp                  # Application entry point
├── .gitignore                    # Configured to ignore VS build files (x64, .vs, obj)
├── skyPort.sln                   # Visual Studio Solution file
├── skyPort.vcxproj               # Visual Studio Project configuration
├── skyPort.vcxproj.filters       # Solution Explorer folder mappings (Filters)
└── skyPort.vcxproj.user          # Local user debugging properties
