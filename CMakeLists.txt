﻿# CMakeList.txt: проект CMake для MathimaticalBasicOfProgrammming; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("MathimaticalBasicOfProgrammming")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (MathimaticalBasicOfProgrammming "main.cpp"  "Dev.cpp" "MBOP.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
