This project demonstrates a basic use case of accessing a C# DLL functionality from within a MFC application. 

Source:
https://www.codeproject.com/Articles/16206/Call-C-code-from-C-and-read-an-array-of-struct-whi?msg=4849445#xx4849445xx

https://support.microsoft.com/en-in/help/828736/how-to-call-a-managed-dll-from-native-visual-c-code-in-visual-studio-n

Please note, run the RegAsm.exe on the C# DLL each time you do some changes in the associated C# code. If not, the changes will not be reflected in the loaded library. As you can see in the MFC application, we import the .tlb file, which is created by running the RegAsm.exe on the C# DLL. Thus, to get the latest code into the MFC program, run the RegAsm.exe each time some code is changed in the C# project.

This interaction is helpful. Assume you want to create a Twitter application in MFC (or if you want to integrate Twitter functionality into your existing MFC application). It is easier to use C# to interact with Twitter than it is by using MFC / C++. Also, if you want to integrate something like MongoDB, you have existing C# drivers for this, which makes your life easier. Thus, use the C# backend and use MFC / C++ as the front end. 
