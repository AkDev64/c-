Several modern books on network programming and socket APIs in C++ are available, with options covering both traditional socket APIs and more modern, library-based approaches like
Boost.Asio. The "best" book for you will depend on your existing C++ knowledge and what you want to accomplish. 
For beginners

    Networking Programming with C++: Build Efficient Communication Systems by GitforGits: This book is designed to bridge the gap between networking fundamentals and C++ programming for those new to the subject. It covers a wide range of topics, starting with foundational knowledge of TCP/IP and sockets, and progressing to more practical programming examples for creating TCP/UDP client-server connections and handling protocols like HTTP. It also includes exercises for hands-on practice.
        Focus: Practical application of network programming basics.
        Content: TCP/IP model, socket programming basics, TCP/UDP client-server, handling network errors, application-layer protocols, VPNs, wireless networking, and network monitoring. 

For developers using modern C++ and Boost.Asio

    Boost.Asio C++ Network Programming Cookbook by Dmytro Radchuk (Packt Publishing): For developers who want to use a powerful, modern library, this book provides over 25 recipes for creating robust and efficient cross-platform networked applications. Boost.Asio is the standard library for asynchronous I/O and networking in C++, and this book teaches its effective use.
        Focus: Practical, recipe-based approach for building network applications using the Boost.Asio library.
        Content: Cross-platform development, distributed applications, and asynchronous programming techniques.
    Boost.Asio Techniques and Applications by Richard Johnson (HiTeX Press): For a deep, foundational understanding of Boost.Asio, this book covers the core architectural principles of the library. It provides insight into the library's internal mechanisms, modern execution models, and coroutine support.
        Focus: Mastery of asynchronous programming with Boost.Asio, including underlying architectural principles.
        Content: TCP/UDP socket programming, asynchronous workflows, concurrency, performance tuning, and security concepts like OpenSSL integration. 

For a foundational understanding (systems-level)

    The Linux Programming Interface by Michael Kerrisk: Though it focuses on Linux and has a C-style interface, this is considered a definitive guide for low-level system and network programming. Understanding the POSIX API covered in this book provides a solid foundation that is portable to other platforms and is often used by higher-level C++ libraries.
        Focus: Deep dive into the fundamentals of Linux/UNIX system programming.
        Content: POSIX API, system calls, inter-process communication, and network programming on Linux.
    Advanced Programming in the UNIX Environment by W. Richard Stevens and Stephen A. Rago: A classic in the field, this book is renowned for its thorough explanations of the UNIX environment, including system programming and low-level networking. While its core examples are in C, the concepts are fundamental for any systems-level developer.
        Focus: In-depth coverage of UNIX system programming concepts.
        Content: File I/O, processes, inter-process communication (IPC), signals, and 
