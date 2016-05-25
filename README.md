# MyCPLApplet

## Description
There is an example of creating control panel applets in Windows.

## Requiremets
* [Visual Studio 2015 IDE](https://www.visualstudio.com/en-us/downloads/download-visual-studio-vs.aspx)

## How to get it
1. Download/Clone this repository.
2. Open solution file `.sln`.
3. Build the solution.

### Remarks
This sample writes in registry under `HKEY_LOCAL_MACHINE`. So you need to run this application with administator rights.

## How to create your own CPL applet
1. Open [Visual Studio 2015 IDE](https://www.visualstudio.com/en-us/downloads/download-visual-studio-vs.aspx).
2. Start project wizard

        File->New->Project
3. Select Visual C++ MFC Dll

        Visual C++->MFC->MFC DLL
4. Press `OK` and `Finish`.
5. Add extern applet function that initialize and handling your applet. For example see function `CplApplet` [here](https://github.com/gtrubach/MyCPLApplet/blob/master/MyCPLApplet/MyCPLApplet.cpp).

## How to debug CPL applets in Visual Studio IDE
1. Open project properties.
2. In `General` tab change `Target Extension` to `.cpl`.
3. In `Debugging` tab add

        Command : <Path to Rundll32.exe>\Rundll32.exe
        Command Arguments : shell32.dll, Control_RunDLL "$(TargetPath)"
4. Press `Ok`.

### Remarks
Here you can see examples of `Command`
    
        x86 configuration : C:\Windows\SysWOW64\Rundll32.exe
        x64 configuration : C:\Windows\System32\Rundll32.exe
        
## Access violation when you call the CPropertySheet::DoModal method
This exception is thrown because the CommCtl32.dll tries to modify the resources for the pages.

<justify>To avoid it you should change the font of the pages so they are not `MS Sans Serif`. MFC checks the dialog template font for the page. If it is not MS Sans Serif, MFC makes a copy of the resource in read/write memory, and then modifies the font and passes this to the C mCtl32.dll. When the DLL writes to the template for the page, it is writing to read/write memory. Therfore, an exception is not thrown.</justify>

Also you can read full article about this on [msdn](https://support.microsoft.com/en-us/kb/158552).