cl.exe `
  /std:c++20 `
  /EHsc `
  /Zi `
  /DEBUG `
  ole32.lib oleaut32.lib Kernel32.lib `
  find-forza.cpp `
  /link /MANIFEST:EMBED /MANIFESTINPUT:manifest.xml