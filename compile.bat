echo "Compile"
cmake -G "Visual Studio 17 2022" -A Win32 -S ./ -B "out"
cmake --build out --config Release
echo "Copy"
TASKKILL /IM GeometryDash.exe
timeout /t 5
copy .\out\Release\GDSplashes.dll "G:\steamus\steamapps\common\Geometry Dash\mods"