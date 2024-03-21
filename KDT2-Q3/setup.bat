echo Start setup.bat

echo [vcpkg task]
call .\vcpkg\bootstrap-vcpkg.bat
.\vcpkg\vcpkg install rapidjson:x64-windows
.\vcpkg\vcpkg install boost:x64-windows
.\vcpkg\vcpkg integrate install


echo.
echo [done]
pause