# Student Management System in C

A clean, console-based Student Management System built using **C Programming**. This intermediate-level academic project utilizes an **Array of Structures** to manage records dynamically in RAM and handles persistent binary data tracking through automated file synchronization.

---

## 🚀 Features

- **Add Student Records:** Capture essential fields including Roll Number, Full Name, Course, and GPA.
- **Data Validation:** Automatic scanning algorithm to prevent duplicate entries of the same Roll Number.
- **Robust Searching:** Instantly look up individual student profiles using a targeted linear search algorithm.
- **Performance Sorting:** An integrated **Bubble Sort Algorithm** to rank and display records by GPA (highest to lowest).
- **Persistent Binary File Storage:** Data automatically tracks into a binary system file (`students.dat`) upon exiting, allowing zero data loss when restarting the program.
- **Console Buffer Management:** Custom input flushing routines prevent common buffer overflows and text reading errors caused by lingering newline characters.

---

## 🛠️ System Components & Architecture

- **Language:** C (Standard C99 / C11)
- **Data Structure:** Flat Array of Custom `struct` blocks.
- **Storage Type:** Binary File I/O (`fread` and `fwrite`).
- **RAM Footprint:** Cache allocation system handles records seamlessly up to 100 concurrent profiles.

---

## 💻 How to Compile and Run

### Locally via Terminal
If you have a configured C compiler (like GCC) installed on your machine, run these standard terminal commands inside your project folder:

```bash
# 1. Compile the source code
gcc main.c -o student_system

# 2. Execute the application
./student_system
```

### Alternative Execution
If local system compilers are unavailable, this code can be executed smoothly inside any modern browser-based sandbox compiler (such as OnlineGDB) due to its standard universal standard library dependency setup.

---

## 📂 Project Structure

```text
├── main.c           # Primary source code containing core business logic and algorithms
└── students.dat     # Automatically generated binary data storage file (Auto-created at runtime)
```

---

## 📋 System Operations Menu Guide

When launched, the interactive command terminal displays the following operational options:
1. **Option 1 (Add Student):** Triggers size validation, unique identity loops, and securely saves strings using safe `fgets` methods.
2. **Option 2 (Display All):** Formats existing data structures into scannable multi-column read output displays.
3. **Option 3 (Search Student):** Performs deep linear key matching loops to trace specific student properties.
4. **Option 4 (Sort by GPA):** Restructures memory data orders utilizing descending sorting values.
5. **Option 5 (Save and Exit):** Commits current memory arrays back down onto the hardware disk and terminates execution cleanly.
