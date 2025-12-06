cd /d C:\Users\USER\OneDrive\Desktop\MyOpenGL
echo Current dir:
cd

set PATH=C:\msys64\ucrt64\bin;%PATH%

REM g++ SourceFiles\main.cpp \SourceFiles\shaderClass.cpp \ SourceFiles\VAO.cpp \ SourceFiles\VBO.cpp \ SourceFiles\EBO.cpp \ src\glad.c -Iinclude -Isrc -IHeaderFiles -LC:\msys64\ucrt64\lib -lglfw3 -lopengl32 -lgdi32 -o game.exe
g++ ^
  SourceFiles\main.cpp ^
  SourceFiles\shaderClass.cpp ^
  SourceFiles\VAO.cpp ^
  SourceFiles\VBO.cpp ^
  SourceFiles\EBO.cpp ^
  src\glad.c ^
  -Iinclude -Isrc -IHeaderFiles ^
  -LC:\msys64\ucrt64\lib -lglfw3 -lopengl32 -lgdi32 ^
  -o game.exe


game.exe
pause