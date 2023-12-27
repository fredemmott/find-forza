# What is this?

A proof of concept for getting the installation path for MS store apps from non-UWP standard C++.

# What is the output?

The paths of all MS store apps, followed by specifically the installation paths for Forza Horizon 5 and Forza Motorsport 7, if found.

# How do I get the executable path?

You can't, but you don't need it, and shouldn't use it.
- To launch the app, you should call `Launch()` on the `winrt::Windows::ApplicationModel::Package` object
- To see if it's running, just see if any running executable is from the installation path

# Example output

```
... lots of packages ...
c5e2524a-ea46-4f67-841f-6a9465d9d515_10.0.19041.3636_neutral_neutral_cw5n1h2txyewy:
        DisplayName:    File Explorer
        InstalledPath:  C:\Windows\SystemApps\Microsoft.Windows.FileExplorer_cw5n1h2txyewy
microsoft.windowscommunicationsapps_16005.14326.21768.0_x64__8wekyb3d8bbwe:
        DisplayName:    Mail and Calendar
        InstalledPath:  C:\Program Files\WindowsApps\microsoft.windowscommunicationsapps_16005.14326.21768.0_x64__8wekyb3d8bbwe
windows.immersivecontrolpanel_10.0.2.1000_neutral_neutral_cw5n1h2txyewy:
        DisplayName:    Settings
        InstalledPath:  C:\Windows\ImmersiveControlPanel
----------
Forza Horizon 5
----------
Microsoft.624F8B84B80_3.629.845.0_x64__8wekyb3d8bbwe:
        DisplayName:    Forza Horizon 5
        InstalledPath:  C:\Program Files\WindowsApps\Microsoft.624F8B84B80_3.629.845.0_x64__8wekyb3d8bbwe
----------
Forza Motorsport 7
----------
Microsoft.ApolloBaseGame_1.174.4791.2_x64__8wekyb3d8bbwe:
        DisplayName:    Forza Motorsport 7
        InstalledPath:  C:\Program Files\WindowsApps\Microsoft.ApolloBaseGame_1.174.4791.2_x64__8wekyb3d8bbwe
PS C:\Users\fred\code\find-forza> 
```