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
microsoft.windowscommunicationsapps_8wekyb3d8bbwe:
        DisplayName:   Mail and Calendar
        FamilyName:    microsoft.windowscommunicationsapps_8wekyb3d8bbwe
        FullName:      microsoft.windowscommunicationsapps_16005.14326.21768.0_x64__8wekyb3d8bbwe
        Name:          microsoft.windowscommunicationsapps
        InstalledPath: C:\Program Files\WindowsApps\microsoft.windowscommunicationsapps_16005.14326.21768.0_x64__8wekyb3d8bbwe
windows.immersivecontrolpanel_cw5n1h2txyewy:
        DisplayName:   Settings
        FamilyName:    windows.immersivecontrolpanel_cw5n1h2txyewy
        FullName:      windows.immersivecontrolpanel_10.0.2.1000_neutral_neutral_cw5n1h2txyewy
        Name:          windows.immersivecontrolpanel
        InstalledPath: C:\Windows\ImmersiveControlPanel
----------
Forza Horizon 5
----------
Microsoft.624F8B84B80_8wekyb3d8bbwe:
        DisplayName:   Forza Horizon 5
        FamilyName:    Microsoft.624F8B84B80_8wekyb3d8bbwe
        FullName:      Microsoft.624F8B84B80_3.629.845.0_x64__8wekyb3d8bbwe
        Name:          Microsoft.624F8B84B80
        InstalledPath: C:\Program Files\WindowsApps\Microsoft.624F8B84B80_3.629.845.0_x64__8wekyb3d8bbwe
----------
Forza Motorsport 7
----------
Microsoft.ApolloBaseGame_8wekyb3d8bbwe:
        DisplayName:   Forza Motorsport 7
        FamilyName:    Microsoft.ApolloBaseGame_8wekyb3d8bbwe
        FullName:      Microsoft.ApolloBaseGame_1.174.4791.2_x64__8wekyb3d8bbwe
        Name:          Microsoft.ApolloBaseGame
        InstalledPath: C:\Program Files\WindowsApps\Microsoft.ApolloBaseGame_1.174.4791.2_x64__8wekyb3d8bbwe
```

# Key fields

**You usually want to search for/match based on the `FamilyName` field.**

| Field | Meaning |
|-------|---------|
| DisplayName | The actual name, that people see |
| Name | Usually publisher name and a 'product name', which may be a codename. Can also be random data |
| FamilyName | The `Name` field, combined with the publisher *ID*, which is derived from the signing certificate information |
| FullName | Really a unique identifier for a specific .msix/.appx. The `FamilyName` field, combined with the current version number and architecture |