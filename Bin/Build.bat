@echo off
REM set PATH=C:\MinGW\bin;%PATH%
set COMPILER=g++
set SRCDIR=..\Source\
set CPPFILES=%SRCDIR%Main.cpp %SRCDIR%RestaurantList.cpp %SRCDIR%ErrorLog.cpp %SRCDIR%Inventory.cpp %SRCDIR%Restaurant.cpp %SRCDIR%OrderManager.cpp
set BUILDNAME=BestOrder.exe
%COMPILER% -o %BUILDNAME% %CPPFILES%
pause