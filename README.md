# Sanchovi-Browser
Sanchovi is a lightweight web browser built from scratch using the WebKit engine and GTK in C. This project serves as an educational tool to demonstrate how web browsers work at a fundamental level and to provide a hands-on example of using WebKit and GTK for GUI applications.
Features:
   Basic web navigation (back, forward, reload)
    URL entry bar for browsing
    Lightweight and minimalistic interface
    Utilizes WebKitGTK for rendering web pages
    Built using C and GTK for a native Linux application

Installation
Prerequisites

Ensure you have the necessary development libraries installed:

sh

`sudo apt update`
`sudo apt install libgtk-3-dev libwebkit2gtk-4.0-dev`

Building SimpleBrowser

Clone the repository and build the project using gcc and pkg-config:

sh

`git clone https://github.com/RKirlew/sanchovi-browser.git
cd simplebrowser`
`gcc \`pkg-config --cflags --libs gtk+-3.0 webkit2gtk-4.0/` -o browser browser.c`

Usage

Run the compiled binary to start the browser:


`./browser`

Code Structure

    browser.c: The main source file containing the implementation of the browser.

Contributing

Contributions are welcome! If you have suggestions for improvements or new features, feel free to open an issue or submit a pull request.
License

This project is licensed under the MIT License. See the LICENSE file for details.
Acknowledgements

    GTK for the graphical toolkit
    WebKitGTK for the web rendering engine
